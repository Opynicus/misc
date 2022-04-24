from socket import *
import time

serverName = '127.0.0.1'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)  # create udp socket
clientSocket.settimeout(1)  # 1s
DestinServerAddr = (serverName, serverPort)

for i in range(0, 10):
    sendTime = time.time()
    message = ('UDP case {} {}'.format(i + 1, sendTime)).encode()
    try:
        clientSocket.sendto(message, DestinServerAddr)  # send msg to server
        modifiedMessage, serverAddress = clientSocket.recvfrom(1024)
        rtt = time.time() - sendTime
        print('Case %d: Reply from %s    RTT = %.3fs' % (i + 1, serverName, rtt))
    except Exception as e:
        print('Case %d: Request timed out' % (i + 1))

clientSocket.close()