DATA SEGMENT

OUTPUT DB 5 DUP(20H),'$'

DATA ENDS

CODE SEGMENT

    ASSUME CS:CODE,DS:DATA

START:

    MOV AX,DATA

    MOV DS,AX

    MOV BX,200          ;��100��ʼѰ��

    MOV CL,7            ;����CL=7

    S0:

    MOV AX,BX

    DIV CL              ;CL=7

    CMP AH,0            ;��7������Ϊ0��ʾ�ܱ�7������ת����һ��

    JZ NEXT           

    LEA SI,OUTPUT+4

    CALL DISP           ;�Ѳ��ܱ�7��������ת���ɶ�Ӧ��ASCII���ַ�

    MOV AH,09H

    LEA DX,OUTPUT

    INT 21H

    NEXT:

    INC BX 

    CMP BX,300          ;�ж��������û�г���200

    JNZ S0

    MOV AX,4C00H

    INT 21H

    DISP:

    PUSH BX

    MOV AX,BX

    MOV BX,10

    S1:

    MOV DX,0

    DIV BX

    CMP AX,0

    JZ RETE

    ADD DL,30H          ;ת���ɶ�Ӧ��ASCII��ֵ

    MOV [SI],DL

    DEC SI

    JMP S1

    RETE:

    ADD DL,30H

    MOV [SI],DL

    POP BX

    RET

    CODE ENDS

END START