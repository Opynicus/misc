; 若将A口作为输出，B口作为输入
CSEG SEGMENT
ASSUME CS:CSEG
ORG	11B0H	            ;8255首地址11B0H
CTRLP DW 0FF2BH         ;控制端口地址
CTRLWD DB 82H           ;设置控制字,10000010,ＰA端口(基本I/O)，PA端口输出，PC端口高４位输出，ＰB端口(基本I/O)，PB端口输入，PC端口低４位输入
PA DW 0FF29H            ;PA端口地址，待输出
PB DW 0FF28H            ;PB端口地址，待输入
START:
  MOV DX, CTRLP
  MOV AL, CTRLWD
  OUT DX, AL
PC:
  MOV DX, PA
  IN AL, DX
  MOV DX, PB
  OUT DX, AL
  JMP PC
CSEG ENDS
  END START