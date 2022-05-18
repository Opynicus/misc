CODE SEGMENT                                                                     ;H8259.ASM
           ASSUME CS:CODE
 INTPORT1  EQU    0FF80H
 INTPORT2  EQU    0FF81H
 INTQ3     EQU    INTREEUP3
           ORG    12D0H
 START:    JMP    START0
 BUF       DB     ?,?,?,?,?,?
 intcnt    db     ?
 data1:    db     0c0h,0f9h,0a4h,0b0h,99h,92h,82h,0f8h,80h,90h,88h,83h,0c6h,0a1h
           db     86h,8eh,0ffh,0ch,89h,0deh,0c7h,8ch,0f3h,0bfh,8FH
 START0:   
           CLD                                                                   ;初始化命令字程序
           CALL   WRINTVER                                                       ;WRITE INTRRUPT
           MOV    AL,13H
           MOV    DX,INTPORT1                                                    ;设置ICW1，高电平/边沿触发，单片8259，要写ICW4
           OUT    DX,AL
           MOV    AL,08H
           MOV    DX,INTPORT2                                                    ;设置ICW2，中断类型码为08H
           OUT    DX,AL
           MOV    AL,09H                                                         ;设置ICW4，一般完全嵌套，带缓冲，正常中断结束，86系统
           OUT    DX,AL
           MOV    AL,0FBH                                                        ;屏蔽除了中断请求2以外的所有信号请求
           OUT    DX,AL
           MOV    intcnt,01H                                                     ;TIME=1
           STI

           MOV    BL,0FEH
 WAITING:  
           MOV    AL,BL
           ROR    BL,1
           MOV    DX,0FF90H                                                      ;273口地址
           OUT    DX,AL
           MOV    CX,0
           LOOP   $
           JMP    WAITING

 WRINTVER:                                                                       ;初始化中断向量表程序
           MOV    AX,0H
           MOV    ES,AX
           MOV    DI,0028H                                                       ;中断序号为2的变量地址
           LEA    AX,INTQ3
           STOSW
           MOV    AX,0000h
           STOSW
           RET
 INTREEUP3:
           PUSH   AX
           PUSH   BX
           PUSH   DX
           CLI
           MOV    BH,0AH
           MOV    AL,0FBH                                                        ;屏蔽除了中断请求2以外的所有信号请求
 L1:       
           MOV    DX,0FF90H                                                      ;273的cs端
           OUT    DX,AL
           MOV    CX,0
           LOOP   $
           XOR    AL,08
           OUT    DX,AL
           MOV    CX,0
           LOOP   $
           XOR    AL,08
           DEC    BH
           JNZ    L1
           MOV    AL,20H
           MOV    DX,0FF80H                                                      ;8259的cs端
           OUT    DX,AL
           STI
           POP    DX
           POP    BX
           POP    AX
           IRET

CODE ENDS
END  START