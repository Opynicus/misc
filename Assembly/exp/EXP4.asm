ASSUME	CS:CSEG,DS:DSEG
DSEG SEGMENT
DATA	DB	1,2,3,4,5,6,7,8
COUNT	DB	8
MEANP	DB	0
MEANM	DB	0
DSEG ENDS
CSEG SEGMENT
START:
    mov ax,DSEG
	mov DS,ax
	lea bp,DATA
	mov cl,COUNT
	xor ax,ax			;ax为正数,dh为数量
	xor bx,bx			;bx为负数,dl为数量
LoopJudge:
    mov ch,byte ptr ds:[bp]
	cmp ch,0
	jg	GREATER
	je	CalMEANP
	neg ch
	sub bl,ch
	inc dl
	jmp CalMEANP
GREATER:
	add al,ch
	inc dh
CalMEANP:
    inc bp
	dec cl
	jne	LoopJudge
	test dh,dh			;算平均
	je	CALCN
	div dh
	mov MEANP,al
	xor ax,ax
CALCN:	
    test dl,dl
	je	FIN
	cmp bh,0
	jne	CalMEANM
	or	bh,0ffh
CalMEANM:
    mov ax,bx
	idiv dl
	mov MEANM,al
FIN:
	mov ah,4ch
	int 21h
cseg ENDS
END START