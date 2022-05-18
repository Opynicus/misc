; 源程序.K1-K8开关向上，L1-L4发光二极管灯灭
CSEG SEGMENT
        ASSUME CS:CSEG
        ORG    19D0H       ;程序初始地址
  START:
        MOV    DX, 0FF80H  ;244地址
        IN     AL, DX      ;244地址值
        MOV    DX, 0FF90H  ;273地址
        OUT    DX, AL      ;AL内容写到273输出端口
        JMP    START
CSEG ENDS
  END START