# import socket module
from socket import *
import threading


def webThreads(connectionSocket):
    try:
        message = connectionSocket.recv(1024)
        filename = message.split()[1]
        f = open(filename[1:])
        outputdata = f.read();
        # Send one HTTP header line into socket
        header = ' HTTP/1.1 200 OK\nContent-Type: text/html\ncharset=utf-8\n\n'
        connectionSocket.send(header.encode())

        # Send the content of the requested file to the client
        for i in range(0, len(outputdata)):
            connectionSocket.send(outputdata[i].encode())
        connectionSocket.close()
        print('Gotcha')
    except IOError:
        # Send response message for file not found
        header = ' HTTP/1.1 404 NOT FOUND'
        connectionSocket.send(header.encode())

        # Close client socket
        connectionSocket.close()


def main():
    serverSocket = socket(AF_INET, SOCK_STREAM)
    # Prepare a sever socket
    HOST = "127.0.0.1"
    PORT = 6789
    ADDR = (HOST, PORT)
    serverSocket.bind(ADDR)
    serverSocket.listen(4)
    while True:
        # Establish the connection
        print('Ready to serve...')
        connectionSocket, addr = serverSocket.accept()
        thread = threading.Thread(target=webThreads, args=[connectionSocket])
        thread.start()
    serverSocket.close()


if __name__ == '__main__':
    main()
