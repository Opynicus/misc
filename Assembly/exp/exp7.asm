SSEG SEGMENT STACK 
DB 80H DUP(0)
SSEG ENDS
DSEG SEGMENT
FileInputTips1 DB 'Original File Name: $'
FileInputTips2 DB 'New File Name: $'
FileName DB 14,0,14 DUP(?)
ErrorTips DB 'FILE ERROR! $'
BUFF DB 1024 DUP(?)
WrName DB 14,0,14 DUP(?)
DSEG ENDS
CSEG SEGMENT
ASSUME CS:CSEG,DS:DSEG,SS:SSEG
FILE PROC FAR
    PUSH DS
    XOR AX,AX
    PUSH AX
    MOV AX,DSEG
    MOV DS,AX
    LEA DX,FileInputTips1;提示信息的首地址
    MOV AH,09H
    INT 21H ;输出DS:DX指向的字符串
    LEA DX,FileName;
    MOV AH,0AH;把键盘输入的字符存入缓冲区（即DS:DX），然后把实际输入的数量存入FileName+1
    INT 21H;
    MOV DL,0AH;这是换行符
    MOV AH,2;输出DL的字符到屏幕
    INT 21H;
    MOV BL,FileName+1
    MOV BH,0;这里是为了把BL扩展到BX；
    MOV [BX+FileName+2],BH  ;文件名的最后放上一个0,BX是文件名的长度
    LEA DX,FileName+2      ;把文件名的首地址取给DX
    MOV AX,3D00H      ;AH的3D是打开文件的功能，AL的内容是3种打开文件的格式，0=读，1=写，2=读和写
    INT 21H;
    JC EXIT            ;如果文件打开出错的话跳转到EXIT
    MOV BX,AX;
AGAIN:
    MOV CX,1024    ;每次读入的字节数,最多1024bytes
    LEA DX,BUFF        ;把缓冲区的偏移地址取给DX，这样就可以把文件内容读进DX
    MOV AH,3FH          ;读取文件内容，如果读到文件尾部，AX是0，否则是实际读入数
    INT 21H
    JC EXIT            ;如果出错了跳转
    MOV CX,AX          ; 把实际读到的字节数给CX
    CMP CX,1024          ;没读完继续读
    JE AGAIN
    MOV AH,3EH        ;关文件
    INT 21H;
WRITEFILE:
    LEA DX,FileInputTips2;提示信息的首地址
    MOV AH,09H
    INT 21H ;输出DS:DX指向的字符串（即提示信息）
    LEA DX,WrName
    MOV AH,0AH;把键盘输入的字符存入缓冲区（即DS:DX），然后把实际输入的数量存入FileName+1
    INT 21H
    MOV BL,WrName+1
    MOV BH,0
    MOV [BX+WrName+2],BH
    LEA DX,WrName+2
    MOV AX,3D01H;只写方式打开
    INT 21H
    JC EXIT
    MOV BX,AX
    LEA DX,BUFF
    MOV AH,40H
    INT 21H
    JC EXIT
    MOV AH,3EH
    INT 21H
    RET
EXIT:
    LEA DX,ErrorTips
    MOV AH,9
    INT 21H
    RET
FILE ENDP
CSEG ENDS
END FILE