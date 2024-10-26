DATA SEGMENT

OUTPUT DB 5 DUP(20H),'$'

DATA ENDS

CODE SEGMENT

    ASSUME CS:CODE,DS:DATA

START:

    MOV AX,DATA

    MOV DS,AX

    MOV BX,200          ;从100开始寻找

    MOV CL,7            ;除数CL=7

    S0:

    MOV AX,BX

    DIV CL              ;CL=7

    CMP AH,0            ;除7，余数为0表示能被7整除，转到下一个

    JZ NEXT           

    LEA SI,OUTPUT+4

    CALL DISP           ;把不能被7整除的数转换成对应的ASCII码字符

    MOV AH,09H

    LEA DX,OUTPUT

    INT 21H

    NEXT:

    INC BX 

    CMP BX,300          ;判断这个数有没有超过200

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

    ADD DL,30H          ;转换成对应的ASCII码值

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