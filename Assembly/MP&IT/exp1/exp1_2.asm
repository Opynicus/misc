; 74LS244、74LS273的片选信号可以改变，若244/273的片选信号改为与地址总线单元中的FF30H、FFA0H相连，应如何修改程序中相应地址。
CSEG SEGMENT
        ASSUME CS:CSEG
        ORG    19D0H       ;程序初始地址
  START:
        MOV    DX, 0FF30H  ;244地址，被修改为连接0FF30H
        IN     AL, DX      ;244地址值
        MOV    DX, 0FFA0H  ;273地址，被修改为连接0FFA0H
        OUT    DX, AL      ;AL内容写到273输出端口
        JMP    START
CSEG ENDS
  END START