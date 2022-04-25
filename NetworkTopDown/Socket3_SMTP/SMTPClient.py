from socket import *
import base64
msg = "\r\n I love computer networks!"
endmsg = "\r\n.\r\n"
ori_email = "zenguncle224@gmail.com"
destin_email = "zenguncle@outlook.com"

PORT = 465
PASSWORD = input("Enter password for {}：".format(ori_email))

username = base64.b64encode(ori_email.encode()).decode()
password = base64.b64encode(PASSWORD.encode()).decode()
# Choose a mail server (e.g. Google mail server) and call it mailserver
mailserver = "smtp.gmail.com"
# Create socket called clientSocket and establish a TCP connection with mailserver
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((mailserver, PORT))

recv = clientSocket.recv(1024).decode()
print(recv)
if recv[:3] != '220':
    print('220 reply not received from server.')

# Send HELO command and print server response.
heloCommand = 'HELO Opynicus\r\n'
clientSocket.send(heloCommand.encode())
recv1 = clientSocket.recv(1024).decode()
print(recv1)
if recv1[:3] != '250':
    print('250 reply not received from server.')
# AUTH LOGIN
clientSocket.send('AUTH LOGIN\r\n'.encode())
recv2 = clientSocket.recv(1024).decode()
print(recv2)
if recv2[:3] != '334':
    print('334 reply not received from server')
# base64 username
clientSocket.send((username + '\r\n').encode())
recv3 = clientSocket.recv(1024).decode()
print(recv3)
if recv3[:3] != '334':
    print('334 reply not received from server')
# base64 password
clientSocket.send((password + '\r\n').encode())
recv4 = clientSocket.recv(1024).decode()
print(recv4)
if recv4[:3] != '235':
    print('235 reply not received from server')
# Send MAIL FROM command and print server response.
clientSocket.send(('MAIL FROM: <{}>\r\n'.format(ori_email)).encode())
recv5 = clientSocket.recv(1024).decode()
print(recv5)
if recv5[:3] != '250':
    print('250 reply not received from server')

# Send RCPT TO command and print server response.
clientSocket.send(('RCPT TO: <{}>\r\n'.format(destin_email)).encode())
recv6 = clientSocket.recv(1024).decode()
print(recv6)
if recv6[:3] != '250':
    print('250 reply not received from server')

# Send DATA command and print server response.
clientSocket.send('DATA\r\n'.encode())
recv7 = clientSocket.recv(1024).decode()
print(recv7)
if recv7[:3] != '354':
    print('354 reply not received from server')

# Send message data.
message = "from:" + ori_email + "\r\n" + \
          "to:" + destin_email + "\r\n" + \
          "subject:test\r\n" + \
          msg + \
          endmsg

# Message ends with a single period.
clientSocket.send(endmsg.encode())
recv8 = clientSocket.recv(1024).decode()
print(recv8)
if recv8[:3] != '250':
    print('250 reply not received from server')

# Send QUIT command and get server response.
clientSocket.send('QUIT\r\n'.encode())

clientSocket.close()
