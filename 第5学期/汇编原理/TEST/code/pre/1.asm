ASSUME   CS: C, DS: D
D  SEGMENT 
    MSG1  DB  10, 13, 'Please input a num: $'
    MSG2  DB  10, 13, 'The  Sum = $'
    ZH  DB  0 
D  ENDS

C  SEGMENT              ;�����
START:

    MOV   AX, D
    MOV   DS, AX
    MOV   CX, 15

IN_X:
    LEA   DX, MSG1
    MOV   AH, 9         ;��ʾ�ַ���
    INT   21H

IN_1:
    MOV   AH, 7         ;���뵥���ַ�
    INT   21H 
    CMP   AL, '-'
    JE    IN_F          ;����
    CMP   AL, '0'
    JB    IN_X          ;С��'0'����������
    CMP   AL, '9'
    JA    IN_X
    MOV   DL, AL
    MOV   AH, 2         ;��ʾ
    INT   21H
    MOV   AL, DL
    SUB   AL, '0'       ;��ԭΪ����
    MOV   BL,  0AH
    MUL   BL
    ADD   ZH, AL        ;���                   

IN_2:
    MOV   AH, 7         ;���뵥���ַ�
    INT   21H  
    MOV   DL, AL
    MOV   AH, 2         ;��ʾ
    INT   21H
    MOV   AL, DL
    SUB   AL, '0'
    ADD   ZH, AL
    JMP   IN_E

IN_F:
    MOV   DL, AL
    MOV   AH, 2         ;��ʾ
    INT   21H
    MOV   AH, 7         ;���뵥���ַ�.
    INT   21H
    CMP   AL, '0'
    JB    IN_X          ;С��'0'����������.
    CMP   AL, '9'
    JA    IN_X
    MOV   DL, AL
    MOV   AH, 2         ;��ʾ
    INT   21H

IN_E:
    LOOP  IN_X
    LEA   DX, MSG2
    MOV   AH, 9         ;��ʾ�ַ���
    INT   21H
    MOV   AL, ZH
    MOV   AH, 0
    CALL  DISP
    MOV   AH, 4CH       ;���˽���
    INT   21H

DISP:

    MOV   BX, 10
    MOV   CX, 0

D_1:
    MOV   DX, 0
    DIV   BX
    ADD   DL, '0'
    PUSH  DX
    INC   CX
    CMP   AX, 0
    JNE   D_1
    MOV   AH, 2

D_2:POP   DX
    INT   21H
    LOOP  D_2
    RET

C  ENDS
    END  START