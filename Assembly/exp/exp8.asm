CurrentCur equ 1645H ;定义显示位置
attrib equ 71h ;定义时钟显示颜色，白底蓝色
code segment
assume cs:code,ds:code
start:
jmp go ;转到程序预处理，设置中断并驻留
OriginalCur dw ? 
Original1C DW 2 DUP(?) ;用于保存原来的 int 1c 入口地址
NEWINT1C: ;新的 int 1c 入口
PUSHF ;标志压栈
CALL DWORD PTR CS:Original1C ;调用原来的 int 1c 中断
push ax
PUSH BX
PUSH CX
PUSH DX
XOR BH,BH
MOV AH,3
INT 10H ;取当前光标位置

MOV CS:OriginalCur,DX ;当前光标位置存入CS:OriginalCur
MOV AH,2
xor bh,bh
MOV DX,CurrentCur ;DX=CurrentCur=45h
INT 10H ;设置光标位置
MOV AH,2
INT 1AH ;读取系统时钟
PUSH DX
PUSH CX
POP BX ;小时分钟数给BX
PUSH BX
CALL SHOWTIME ;调用子程序显示小时，小时在bh中
CALL SHOWOP ;调用子程序显示时间分隔符 ":"
POP BX
XCHG BH,BL ;分钟给bh
CALL SHOWTIME ;调用子程序显示分钟，bh是分钟数
CALL SHOWOP ;调用子程序显示时间分隔符 ":"
POP BX ;秒数给bh
CALL SHOWTIME ;调用子程序显示秒数
MOV DX,CS:OriginalCur ;读取备份的光标位置
MOV AH,2
XOR BH,BH
INT 10H ;还原原来的光标位置
POP DX
POP CX
POP BX
POP AX
IRET ;中断返回

SHOWTIME PROC NEAR ;BCD值显示子程序，BCD值在BH中
PUSH BX ;压栈BX值，以防冲掉
MOV CL,4 ;以下代码BH中BCD十位值转ASCLL码
MOV AL,BH
SHR AL,CL
ADD AL,30H
CALL SHOW ;调用子程序显示AL，当前AL为时间值十位上的数值
CALL CURMOVE ;调用子程序后移光标
POP BX ;还原BX值
MOV AL,BH ;以下代码BH中BCD个位值转ASCLL码
AND AL,0FH
ADD AL,30H
CALL SHOW ;调用子程序显示AL，当前AL为时间值个位上的数值
CALL CURMOVE ;调用子程序后移光标
RET
SHOWTIME ENDP

SHOWOP PROC NEAR ;显示字符 ":" 子程序，用于时间分隔符
MOV AL,':'
CALL SHOW ;调用子程序显示":"
CALL CURMOVE ;调用子程序后移光标
RET
SHOWOP ENDP

CURMOVE PROC NEAR ;光标后移子程序
PUSH AX
PUSH BX
PUSH CX
PUSH DX
MOV AH,3
MOV BH,0
INT 10H ;取光标位置
INC DL ;光标列位置加1
MOV AH,2
INT 10H ;设光标位置
POP DX
POP CX
POP BX
POP AX
RET
CURMOVE ENDP

SHOW PROC NEAR ;显示一个ASCLL字符子程序，AL为所显字符
PUSH AX
PUSH BX
PUSH CX
MOV AH,09H
MOV BX,attrib ;BH/BL=字符背景色/字符颜色 ，attrib=71h
MOV CX,1 ;显示个数 1
INT 10H
POP CX
POP BX
POP AX
RET
SHOW ENDP

GO:
PUSH CS
POP DS
MOV AX,351CH ;取时钟中断 int 1c中断原入口
INT 21H
MOV Original1C,BX ;保存原中断向量
MOV BX,ES
MOV Original1C+2,BX
MOV DX,OFFSET NEWINT1C ;设置新的时钟中断 int 1c 入口
MOV AX,251CH
INT 21H
MOV DX,OFFSET GO
SUB DX,OFFSET START ;计算驻留内存字节数
MOV CL,4
SHR DX,CL ;驻留内存值转换为节
ADD DX,11H ;内存数加11节

CODE ENDS
END START