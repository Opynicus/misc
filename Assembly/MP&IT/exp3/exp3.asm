code segment
            assume cs:code
            org    1290h
      start:
      ; 写T0方式控制字
            mov    dx,0043h
            mov    al,36h        ;控制字0011 0110，选择通道0，先读低字节后读高字节，方式3（方波发生器），2进制计数
            out    dx,al
      ; 写T0计数初值
            mov    dx,0040h
            mov    al,00h
            out    dx,al
            mov    al,0ffh
            out    dx,al
      ; 写T1方式控制字
            mov    dx,0043h
            mov    al,76h        ;控制字0111 0110，选择通道1，先读低字节后读高字节，方式3（方波发生器），2进制计数
            out    dx,al
      ; 写T1计数初值
            mov    dx,0041h
            mov    al,02h
            out    dx,al
            mov    al,0h
            out    dx,al
            jmp    $
code ends
end start
