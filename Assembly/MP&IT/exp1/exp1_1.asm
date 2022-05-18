; 如果想K1-K4开关向下，让L1-L4发光二极管灯灭，而其它发光二极管灯保持不变
CSEG SEGMENT
        ASSUME CS:CSEG
        ORG    19D0H       ;程序初始地址
  START:
        MOV    DX, 0FF80H  ;244地址
        IN     AL, DX      ;244地址值
        XOR    AL, 0FH     ;异或运算，低4位换，高4位不变c
        MOV    DX, 0FF90H  ;273地址
        OUT    DX, AL      ;AL内容写到273输出端口
        JMP    START
CSEG ENDS
  END START