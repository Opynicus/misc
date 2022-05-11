code segment
          assume cs:code
          org    1290h
    start:
          ; 写T0方式控制字
          mov    dx,0043h
          mov    al,30h      ;控制字0011 0000，选择通道0，先读低字节后读高字节，方式0（软触发），2进制计数
          out    dx,al
          ; 写T0计数初值
          mov    dx,0040h
          mov    al,00h
          out    dx,al
          mov    al,0ffh
          out    dx,al
          jmp    $
code ends
end start