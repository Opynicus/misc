code segment
            assume cs:code
            org    1290h
      start:
      ; 写T1方式控制字
            mov    dx,0043h
            mov    al,72h        ;控制字0111 0010，选择通道1，先读低字节后读高字节，方式1（硬触发），2进制计数
            out    dx,al
      ; 写T1计数初值
            mov    dx,0041h
            mov    al,00h
            out    dx,al
            mov    al,07Ah
            out    dx,al
            jmp    $
code ends
end start