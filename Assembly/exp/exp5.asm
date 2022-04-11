ASSUME	CS:CSEG,DS:DSEG
DSEG 	SEGMENT
;DATA1	DB	1h,2h,3h,4h,32h
DATA1	DB	-1h,-2h,-3h,-4h,-32h
;DATA2	DB	13h,5h,7h,10h,24h
DATA2	DB	-13h,-5h,-7h,-10h,-24h
LEN	DW	5
SUM	DB	20 dup(?)	
DSEG	ends
CSEG	SEGMENT
GETFABS PROC
	MOV	CX,LEN

Judge:	
    MOV	AL,[SI]
	OR	AL,AL			
	JS	Minus			;负数，跳转Minus
	JNS	POS				;正数，跳转POS
Minus:	
    mov	dL,0			;负数的话，用0减去这个数，
	sub	dL,[SI]
	MOV	[SI],DL			;再把结果返回到[SI]中
POS:
	INC	SI				;取下个数据
	LOOP Judge				
	RET						
GETFABS ENDP

GETSUM	PROC			;数据求和
	MOV	CX,LEN				
	MOV	DI,OFFSET SUM
	CLC
LOOPPLUS:	
    MOV	AL,[SI]		;取数据
	MOV	BL,[DI]
	ADC	BL,AL			;相加，求和
	MOV	[DI],BL			;存入SUM单元中
	ADD	SI,1			;取下个数据
	ADD	DI,1
	LOOP LOOPPLUS				
	RET						
GETSUM	ENDP	

start:  
    MOV	AX,DSEG			;初始化程序
	MOV	DS,AX	
	MOV	SI,OFFSET DATA1		;取偏移量
	CALL GETFABS			;求绝对值
	MOV	SI,OFFSET DATA2
	CALL GETFABS
	MOV	SI,OFFSET DATA1
	CALL GETSUM;求和
	MOV	SI,OFFSET DATA2
	CALL GETSUM
	MOV	AX,4C00H
	INT	21H
CSEG	ends
	end	start
