;***
;
; Copyright (c) 2008 ����Ӣ��ʱ���Ƽ����޹�˾����������Ȩ����
;
; ֻ�������� EOS ����Դ����Э�飨�μ� License.txt���е��������ʹ����Щ���롣
; ����������ܣ�����ʹ����Щ���롣
;
; �ļ���: loader.asm
;
; ����: �����ںˡ�
;
; 
;
;*******************************************************************************/


; ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;                               loader.asm
;
; ϵͳ�����ڴ��ַ���ں�ӳ���ַ��ҳ�����ַ���������ò�����
;
SYSTEM_VIRTUAL_BASE		equ 0x80000000
IMAGE_VIRTUAL_BASE		equ 0x80010000
MAX_IMAGE_SIZE			equ	0x90000
PTE_BASE				equ 0xC0000000
;
; ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;
; ���������ʱ��BIOS �� 512 �ֽڵ������������ص� 0000:0x7C00 ������ʼִ�У�Ȼ
; �����������ٰ� Loader.bin ���ص� 0000:0x1000 ������ʼִ�С�
;
	org 0x1000
	jmp	Start
	nop					; ��� nop ������

;+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;								��������
;
; FAT12��������ͷ��
;
BOOT_ORG				equ 0x7C00			; �����������ڴ��е�λ��

;
; ���ڶ����������ĺꡣ
; �÷�: Descriptor Base, Limit, Attr
;
%macro Descriptor 3
	dw	%2 & 0xFFFF							; �ν��� 1						(2 �ֽ�)
	dw	%1 & 0xFFFF							; �λ�ַ 1						(2 �ֽ�)
	db	(%1 >> 16) & 0xFF					; �λ�ַ 2						(1 �ֽ�)
	dw	((%2 >> 8) & 0x0F00) | (%3 & 0xF0FF); ���� 1 + �ν��� 2 + ���� 2	(2 �ֽ�)
	db	(%1 >> 24) & 0xFF					; �λ�ַ 3						(1 �ֽ�)
%endmacro ; �� 8 �ֽ�

;
; ���������Զ��塣
;
DA_32					equ	0x4000			; 32 λ��
DA_LIMIT_4K				equ	0x8000			; �ν�������Ϊ 4K �ֽ�
DA_DRW					equ	0x92			; ���ڵĿɶ�д���ݶ�����ֵ
DA_CR					equ	0x9A			; ���ڵĿ�ִ�пɶ����������ֵ
PG_ATTR					equ 3				; ���ڵĿɶ�д����ִ�е�ϵͳҳ

;
; ȫ�������������������ݶκʹ���ε���������
;
;			������			�λ�ַ,		�ν���,		������
GDT:		Descriptor		0,			0,			0								; ��������
CS_DESC:	Descriptor		0,			0x0FFFFF,	DA_CR  | DA_32 | DA_LIMIT_4K	; 0 ~ 4G �Ĵ����
DS_DESC:	Descriptor		0,			0x0FFFFF,	DA_DRW | DA_32 | DA_LIMIT_4K	; 0 ~ 4G �����ݶ�

;
; �������������ַ����С�Լ�ѡ���Ӷ��塣
; ע�⣺�����������������Ķ���֮�£���������㽫�����
;
GDT_VA					equ	SYSTEM_VIRTUAL_BASE + GDT	; ȫ����������������ַ
GDT_SIZE				equ	$ - GDT						; ȫ����������ĳ���
CS_SELECTOR				equ	CS_DESC - GDT				; �����ѡ����
DS_SELECTOR				equ	DS_DESC - GDT				; ���ݶ�ѡ����

;
; �ַ����������塣
;
szKernelFileName		db	"KERNEL  DLL",0
szNoKernel				db	"File kernel.dll not found!",0
szInvalidFileSize		db	"The file size of kernel.dll must less than 576KB!",0
szLoading				db	"Loading kernel.dll...",0
szInvalidImageSize		db	"The image size of kernel.dll must less than 0x90000!",0
szInvalidImageBase		dd	"Invalid image base address of kernel.dll!",0

;
; LOADER_PARAMETER_BLOCK �ṹ�嶨�塣
;
PhysicalMemorySize		dd	0
MappedMemorySize		dd	0
SystemVirtualBase		dd	SYSTEM_VIRTUAL_BASE
PageTableVirtualBase	dd	PTE_BASE
FirstFreePageFrame		dd	0
ImageVirtualBase		dd	IMAGE_VIRTUAL_BASE
ImageSize				dd	0
ImageEntry				dd	0

va_LoaderBlock			equ	SYSTEM_VIRTUAL_BASE + PhysicalMemorySize
va_ImageEntry			equ	SYSTEM_VIRTUAL_BASE + ImageEntry
va_PhysicalMemorySize	equ SYSTEM_VIRTUAL_BASE + PhysicalMemorySize

;
;+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;								ʵģʽ����
;
Start:
    
	;
	; �õ������ڴ�Ĵ�С
	call GetMemorySize
	mov dword [PhysicalMemorySize], eax
	
	push dx                                   ;����int10h�ж���ʾ�ַ���ʱ��ͨ��dh��dl�������кţ�����Ƚ�dxֵ��ջ���棬Ȼ�������ַ���0��0����ʾ
	mov dx, 0
                                              ;�����ں��ļ����������ַ��Ӧ�������ڴ���
	push dword szLoading
	call TextOut                              ;��ʾ��"Loading kernel.dll..."
    pop dx
	
	;��дһ��ReadFile����ִ��600�������Ķ�����,������kernel�������ڴ�0x10000��
	call NewReadFile
	
	;
	; ����ں�ӳ��������ַ��ӳ���С�Ƿ����Լ����Loader ��֧���ں��ض�λ��
	;
	; ��ʹ es:bx ָ�� IMAGE_NT_HEADER �ṹ��
	;
	mov	ax, (IMAGE_VIRTUAL_BASE - SYSTEM_VIRTUAL_BASE) >> 4
	mov	es, ax								; es <- BaseOfKernelFile
	mov	bx, [es:0 + 0x3C]					; bx = IMAGE_DOS_HEADER::e_lfanew���� IMAGE_NT_HEADER �Ķ���ƫ�Ƶ�ַ	
	
	;
	; �����ַ������Լ��Ҫ������ʾ������ѭ��
	;
	mov eax, [es:bx + 0x34]					; eax = IMAGE_OPTIONAL_HEADER::ImageBase
	cmp eax, IMAGE_VIRTUAL_BASE
	je	.VALID_IMAGE_BASE
	push word szInvalidImageBase
	call TextOut
	jmp $
	
	;
	; ����ں�ӳ���С����Լ�����ֵ����ʾ������ѭ����
	;
.VALID_IMAGE_BASE:
	mov eax, [es:bx + 0x50]					; eax = IMAGE_OPTIONAL_HEADER::SizeOfImage
	mov [ImageSize], eax					; ImageSize = eax
	cmp eax, MAX_IMAGE_SIZE
	jbe .VALID_IMAGE_SIZE
	push word szInvalidImageSize
	call TextOut
	jmp $

	;
	; ��ȡӳ�����ڵ�ַ
.VALID_IMAGE_SIZE:							
	mov	eax, [es:bx + 0x28]					; eax = IMAGE_OPTIONAL_HEADER::AddressOfEntryPoint
	add eax, IMAGE_VIRTUAL_BASE
	mov [ImageEntry], eax

	;
	; ����׼�����뱣��ģʽ
	cli
	
	;
	; ����ȫ����������
	push dword GDT
	push word GDT_SIZE
	movzx eax, sp
	lgdt [eax]
	add sp, 6
	
	;
	; �򿪵�ַ�� A20
	in	al, 0x92
	or	al, 0x02
	out	0x92, al
	
	;
	; ���� cr0 �ı�����־λ
	mov	eax, cr0
	or	eax, 1
	mov	cr0, eax
	
	;
	; ��תִ�б���ģʽ����
	jmp	dword CS_SELECTOR:ProtectionMode

;----------------------------------------------------------------------------
; ������: void TextOut(char* Text)
; ��  ��: ��ʾһ���ַ���
;----------------------------------------------------------------------------
TextOut:
;{
	push bp
	mov bp, sp
	
	; �����ַ����ĳ���
	xor cx, cx
	mov di, word [bp + 4]
.LOOP:
	cmp byte [di], 0
	je .DO_BIOS_CALL
	inc di
	inc cx
	jmp .LOOP
	
.DO_BIOS_CALL:
	mov bp, [bp + 4]
	mov ax, 0x1301
	mov bx, 0x07
	mov dl, 0
	int 0x10
	
	pop bp
	ret 2
;}


;----------------------------------------------------------------------------
; ��	����DWORD GetMemorySize()
; ��	�ã����������ڴ�Ĵ�С
;----------------------------------------------------------------------------
GetMemorySize:
;{
	push bp
	mov bp, sp
	
	; �����ջ����
	sub sp, 4					; ��¼�����ڴ���ߵ�ַ�ı���
	sub sp, 20					; ��ַ��Χ�������ṹ�壨Address Range Descriptor Structure������
	
	xor eax,eax
	mov dword [bp - 4], eax
	mov	di, sp					; es:di ָ���ַ��Χ�������ṹ��
	mov	ebx, 0					; ebx = ����ֵ, ��ʼʱ��Ϊ 0

.LOOP:
	mov	eax, 0xE820				; eax = 0xE820
	mov	ecx, 20					; ecx = ��ַ��Χ�������ṹ�Ĵ�С
	mov	edx, 0x534D4150			; edx = 'SMAP'
	int	0x15
	cmp	dword [es:di + 16], 1	; ����Ƿ��ǿ�ʹ���ڴ�
	jne	.CONTINUE				; ����ʹ�ÿ飬��������Ϣ
	
	mov	eax, [es:di]			; �����ڴ�����Ļ�ַ
	add	eax, [es:di + 8]		; �����ڴ�����Ľ�����ַ = ��ַ + ����
	cmp	eax, [bp - 4]			;
	jbe	.CONTINUE				;
	
	mov	[bp - 4], eax			;
	
.CONTINUE:
	cmp ebx, 0
	jne	.LOOP
	
	mov eax, [bp - 4]			; ���÷���ֵ
	leave						; �ָ�����ǰ�Ķ�ջ֡
	ret
;}

;----------------------------------------------------------------------------
; ��    ��: ReadSector(WORD wSector, WORD wCount, WORD wBase, WORD wOffset)
; ��    ��: �ӵ� wSector ��������ʼ, �� wCount(1~255) ���������� wBase:wOffset ��
;----------------------------------------------------------------------------
ReadSector:
;{
	push bp
	mov	bp, sp
	push es
	
	;
	; ���� ����š���ʼ���� �� ��ͷ��
	; ��������Ϊ x
	;                           �� ����� = y >> 1
	;       x           �� �� y ��
	; -------------- => ��      �� ��ͷ�� = y & 1
	;  ÿ�ŵ�������     ��
	;                   �� �� z => ��ʼ������ = z + 1
	;
	mov ax, [bp + 4]			; ax = wSector
	mov	bl, 18	; bl: ����
	div	bl						; y �� al ��, z �� ah ��
	inc	ah						; z ++
	mov	cl, ah					; cl <- ��ʼ������
	mov	dh, al					; dh <- y
	shr	al, 1					; y >> 1 (��ʵ�� y / Heads, ���� Heads = 2)
	mov	ch, al					; ch <- �����
	and	dh, 1					; dh & 1 = ��ͷ��
	mov	dl, 0		; �������� (0 ��ʾ A ��)
	
	
	mov ax, [bp + 8]
	mov es, ax
	mov bx, [bp + 10]
.GoOnReading:
	mov	ah, 2					; ��
	mov	al, [bp + 6]			; �� al ������
	int	0x13
	jc	.GoOnReading			; �����ȡ���� CF �ᱻ��Ϊ 1, ��ʱ�Ͳ�ͣ�ض�, ֱ����ȷΪֹ

	; �ָ���ջ������
	pop es
	leave
	ret 8
;}

;��kernel.dll�Ӵ����϶����ڴ�0x10000��
NewReadFile:
;{

	push ds                       ;ʹ����Щ�Ĵ�����������������Ƚ��Ĵ�����ֵ��ջ����
	push fs
	push gs

	mov ax, 0x0FE0
	mov ds, ax                    ;��������ʱ��esֵ�ȱ��浽ds�Ĵ�����
	mov ax, 600
	mov fs, ax                    ;��ѭ���������뵽cs�Ĵ�����loopѭ��ÿ�λὫcx-1��ֱ��Ϊ0
	mov ax, 5
	mov gs, ax                    ;�ӵ�6������ʼд�������ٽ�ÿ��ѭ����Ϻ����ʼ������+1����
	
	mov cx, 600
fifty:
    mov ax, ds
	add ax, 0x20                  ;ÿ��ѭ���ڻ�ַ�Ļ���������20��ע���һ�ν���ʱ�Ļ�ַ           
    mov es, ax
    mov ds, ax                    ;������ѭ����ֵ���浽ds�У��´�ѭ������
    mov bx, 0
    push bx                       ;��ջ����
	push es
    
                                  ;��������Readsector�Ĳ���
    mov ax, gs                    ;��gs�б����ֵ����ax�У�����+1���ٱ��浽gs��
    inc ax
    mov gs, ax
    dec ax                        ;������ʱ��ʹ��gs�б����ֵ
	mov cl, 1                     ;ÿ�ζ�1������
	
	push cx                       ;��Ϊ������ܻ��õ�ax��cx�Ĵ�������˿����Ƚ�Ԥ���ֵ��ջ����
	push ax
	
	call ReadSector               ;���ö���������
	
	mov cx, fs                    ;�����ﴦ��һ��cx�Ĵ�����ֵ
	dec cx
	mov fs, cx                    ;������õ�cxֵ���浽fs���´���
	
	loop fifty                    ;ѭ��

	
	pop gs                        ;ִ����Ϻ󣬽�ǰ���õ��ļĴ���ά��֮ǰ��״̬
	pop fs
	pop ds
	
	ret                           ;ѭ��ִ����Ϻ���������
    
;}

;
;+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;								����ģʽ����
[SECTION .s32]
ALIGN	32
[BITS	32]

ProtectionMode:
	mov	ax, DS_SELECTOR
	mov	ds, ax
	mov	es, ax
	mov	fs, ax
	mov	gs, ax
	mov	ss, ax
	mov esp, 0x10000
	mov ebp, esp

	;
	; ����Ҫӳ��������ڴ�Ĵ�С�������ڴ��1/8�����϶��뵽4M�߽��Ҳ�����256MB����
	;
	mov eax, [PhysicalMemorySize]
	cmp eax, 0x80000000
	jb .DIVIDE

	mov dword [MappedMemorySize], 0x20000000
	jmp .INIT_PDE

.DIVIDE:
	shr eax, 3					; eax = eax/8
	add eax, (0x400000 - 1)
	and eax, ~(0x400000 - 1)
	mov [MappedMemorySize], eax

	;
	; ��ȫ��ҳĿ¼��������ʼ����
	;
.INIT_PDE:
	xor eax, eax
	mov edi, [MappedMemorySize]
	mov ecx, 1024
.LOOP_1:
	stosd
	dec ecx
	jnz .LOOP_1

	;
	; ��������ӳ���ڴ��ҳ���ҳ�����ҳĿ¼���档
	;
	mov	eax, 0 | PG_ATTR		; ҳ��������
	mov ecx, [MappedMemorySize]
	shr ecx, 12
.LOOP_2:
	stosd
	add	eax, 4096				; ��һҳ��ӳ��������ڴ�ĵ�ַ
	dec ecx
	jnz .LOOP_2
	
	;
	; ������ǰ���ҳ���ٳ�ʼ��һ�ſ�ҳ��
	;
	xor eax, eax
	mov ecx, 1024
.LOOP_3:
	stosd
	dec ecx
	jnz .LOOP_3

	;
	; ҳ�������ڴ��������ڴ档
	;
	shr edi, 12
	mov [FirstFreePageFrame], edi

	;
	; ����ҳĿ¼�ӳ�������ڴ档
	;

	mov eax, [MappedMemorySize]
	mov ecx, eax
	shr ecx, 22					; ecx����ӳ���ڴ��ҳĿ¼����
	mov edi, eax				; ediָ���һ��ҳĿ¼��
	add eax, 4096				; eaxָ���һ��ҳ��
	or eax, PG_ATTR

	;
	; ��0-4MB�����ڴ�ӳ�䵽�����ַ0-4MB�ϡ�
	;
	mov [edi], eax

	;
	; ��0-MappedMemorySize�����ڴ�ӳ�䵽�����ַSYSTEM_VIRTUAL_BASE����
	;
	add edi, SYSTEM_VIRTUAL_BASE >> 20	; ediָ��ϵͳ��ʼ��ַ��Ӧ��ҳĿ¼��
.LOOP_4:
	stosd
	add	eax, 4096						; ��һ��ҳ��ĵ�ַ
	dec ecx
	jnz .LOOP_4
	
	;
	; ��ʱeax��ָ����ʼ����һ��ҳ����֮����Ϊҳ��ռ���4M�ռ��ҳ��
	;
	mov edi, [MappedMemorySize]
	add edi, PTE_BASE >> 20
	mov [edi+4], eax
	
	;
	; ������ҳ��ӳ�䵽ҳ��ռ䣬��ҳĿ¼�䵱ӳ��ҳ���ҳ��
	;
	mov eax, [MappedMemorySize]
	or eax, PG_ATTR
	mov [edi], eax

	;
	; ������ҳ����
	;
	mov	eax, [MappedMemorySize]
	mov	cr3, eax
	mov	eax, cr0
	or	eax, 0x80000000
	mov	cr0, eax
	jmp	dword CS_SELECTOR:(SYSTEM_VIRTUAL_BASE+.NOP)	; ��ת�������ַ��ִ��
.NOP:
	nop
	
	;
	; ����ջָ�룬����ӳ���ڴ����ߴ�����������
	;
	mov esp, [MappedMemorySize]
	add esp, SYSTEM_VIRTUAL_BASE
	mov ebp, esp

	;
	; ���¼��� GDT��ʹ GDTR ָ�� GDT �������ַ
	;
	push dword GDT_VA
	push word GDT_SIZE
	lgdt [esp]
	add esp, 6

	;
	; �ر������ַ 0~4M �������ڴ� 0~4M ��ӳ�䡣
	;
	mov dword [PTE_BASE + (PTE_BASE>>10)], 0
	mov eax, cr3
	mov cr3, eax	; ˢ�¿��

	;
	; ��ʼ���ں˾��񣬽�ӳ���ڵĽڶ��뵽��������λ�á�
	;
	push dword IMAGE_VIRTUAL_BASE
	call InitKernelImage
	
	;
	; �����ں�
	;
	push dword va_LoaderBlock
	call dword [va_ImageEntry]
	
;----------------------------------------------------------------------------
; ��	����VOID MemCopy(DWORD *pDst, DWORD *pSrc, DWORD dwCountOfDWORD)
; ��	�ã���˫�ֵ�λ�����ڴ渴�ơ�
;----------------------------------------------------------------------------
MemCopy:
;{
	push ebp
	mov ebp, esp
	
	mov edi, [ebp + 8]
	mov esi, [ebp + 12]
	mov ecx, [ebp + 16]
	mov eax, ecx
	dec eax
	shl eax, 2
	add edi, eax
	add esi, eax

.LOOP:
	cmp ecx, 0
	je .BREAK
	
	mov eax, [esi]
	mov [edi], eax
	sub esi, 4
	sub edi, 4
	dec ecx
	jmp .LOOP
.BREAK:

	leave
	ret 12
;}

;----------------------------------------------------------------------------
; ��	����VOID MemClear(DWORD *pDst, DWORD dwCountOfDWORD)
; ��	�ã���˫�ֵ�λ�����ڴ����㡣
;----------------------------------------------------------------------------
MemClear:
;{
	push ebp
	mov ebp, esp
	
	xor eax, eax
	mov edi, [ebp + 8]
	mov ecx, [ebp + 12]
.LOOP:
	cmp ecx, 0
	je .BREAK
	stosd
	dec ecx
	jmp .LOOP
.BREAK:

	leave
	ret 8
;}
	
;----------------------------------------------------------------------------
; ��	����VOID InitKernelImage(DWORD dwImageBase)
; ��	�ã����ļ������ӳ��չ��Ϊ�ڶ��롣
;----------------------------------------------------------------------------
InitKernelImage:
;{
	push ebp
	mov ebp, esp
	sub esp, 8

	dwSections		equ -4
	pSectionHeader	equ -8	

	mov ecx, [ebp + 8]					;ecx = dwImageBase = &IMAGE_DOS_HEADER
	mov eax, [ecx + 0x3C]				;eax = IMAGE_DOS_HEADER::e_lfanew
	add eax, ecx						;eax = &IMAGE_NT_HEADERS = dwImageBase + IMAGE_DOS_HEADER::e_lfanew
	mov ecx, eax						;ecx =  &IMAGE_NT_HEADERS
	xor ebx, 0
	mov WORD bx, [ecx + 0x06]			;ebx = IMAGE_FILE_HEADER::NumberOfSections
	mov [ebp + dwSections], ebx			;dwSections = IMAGE_FILE_HEADER::NumberOfSections - 1
	mov eax, 0x28						;eax = sizeof(IMAGE_SECTION_HEADER)
	mul ebx								;eax *= dwSections
	sub eax, 0x28
	add eax, 0xF8						;eax += sizeof(IMAGE_NT_HEADERS)
	add eax, ecx						;eax += &IMAGE_NT_HEADERS
	mov [ebp + pSectionHeader], eax		;pSectionHeader = eax, Address of last section header
	
.LOOP:
	cmp dword [ebp + dwSections], 0		; while(dwSections != 0)
	je .BREAK

	mov ecx, [ebp + pSectionHeader]
	mov eax, [ecx + 0x08]				;eax = pSectionHeader->VirtualSize
	cmp eax, 0							;if(eax == 0)
	je	.CONTINUE						;	continue

	mov edi, [ecx + 0x0C]				;edi = pSectionHeader->VirtualAddress
	mov esi, [ecx + 0x14]				;esi = pSectionHeader->PointerToRawData
	cmp esi, edi						;if(edi == esi)
	je	.CONTINUE						;	continue
	
	add eax, 3							;eax += 3;
	shr eax, 2							;eax /= 4;
	cmp esi, 0							;if(esi == 0) MemClear() else MemCopy()
	jne	.MEM_COPY

	push eax
	add edi, dword [ebp + 8]
	push edi
	call MemClear
	jmp .CONTINUE

.MEM_COPY:
	push eax
	mov eax, [ebp + 8]					;��
	add esi, eax
	push esi							;
	add edi, eax
	push edi							;��	MemCopy(edi, esi, eax)
	call MemCopy						;��
	
.CONTINUE:
	sub dword [ebp + pSectionHeader], 0x28	; pSectionHeader --
	dec dword [ebp + dwSections]			; wNumberOfSections --
	jmp .LOOP
	
.BREAK:
	leave
	ret 4
;}
