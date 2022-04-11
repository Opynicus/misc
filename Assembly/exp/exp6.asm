stack segment
db 10 dup(?)
stack ends
data segment
;显示提示语句
string_1 db 'input num a: $'
string_2 db 0ah,0dh,'input num b: $'
string_3 db 0ah,0dh,'input operator c: $'
string_4 db 0ah,0dh,'a+b= $'
string_5 db 0ah,0dh,'a-b= $'
string_6 db 0ah,0dh,'a*b= $'
string_7 db 0ah,0dh,'a/b= $'
data ends
code segment
assume cs:code,ds:data,ss:stack
start:
mov ax,data
mov ds,ax
;显示提示
lea dx,string_1
mov ah,09h
int 21h
;读取第一个数 
mov ah,01h
int 21h
sub al,30h;去ascii码
mov bl,al
lea dx,string_2
mov ah,09h
int 21h
;读取第二个数
mov ah,01h
int 21h
sub al,30h
mov cl,al
;判断符号
lea dx,string_3
mov ah,09h
int 21h
;读取运算符
mov ah,01h
int 21h
xchg cl,al
cmp cl,'+'
jz plus
cmp cl,'-'
jz minus
cmp cl,'*'
jz times
cmp cl,'/'
jz divide
;跳转+-*/
plus:
lea dx,string_4
mov ah,09h
int 21h
xor ah,ah
add al,bl
AAA
push ax; 保护ax
;输出结果的高位
add ah,30h
mov dl,ah
mov ah,02h
int 21h
pop ax
;输出结果的低位
add al,30h
mov dl,al
mov ah,02h
int 21h
mov ax,4c00h
int 21h
minus:
lea dx,string_5
mov ah,09h
int 21h
;将最后的结果放入al中 AAA是关键 
xor ah,ah
xchg ax,bx
sub al,bl
AAA
push ax; 保护ax
;输出结果的高位
add ah,30h
mov dl,ah
mov ah,02h
int 21h
pop ax
;输出结果的低位
add al,30h
mov dl,al
mov ah,02h
int 21h
mov ax,4c00h
int 21h
times:
lea dx,string_6
mov ah,09h
int 21h
;将最后的结果放入al中 AAM是关键 
xor ah,ah
mul bl
AAM
push ax; 保护ax
;输出结果的高位
add ah,30h
mov dl,ah
mov ah,02h
int 21h
pop ax
;输出结果的低位
add al,30h
mov dl,al
mov ah,02h
int 21h
mov ax,4c00h
int 21h
divide:
lea dx,string_7
mov ah,09h
int 21h
;将最后的结果放入al中 AAD是关键 
xor ah,ah
xchg ax,bx
div bl
AAD
push ax; 保护ax
;输出结果的高位
add ah,30h
mov dl,ah
mov ah,02h
int 21h
pop ax
;输出结果的低位
add al,30h
mov dl,al
mov ah,02h
int 21h
mov ax,4c00h
int 21h
code ends
end start