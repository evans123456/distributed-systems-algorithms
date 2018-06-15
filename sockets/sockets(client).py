#EVANS WAHOME GICHUKI
#P15/36969/2016

import socket
s = socket.socket()

port = 12345
s.connect(('127.0.0.1',port))

mess = input('Énter Message ')

send = mess.encode('utf-8')#has to be encoded as it requires to be in byte format for strings
s.send(b'%s'%send)
print (s.recv(1024))
s.close()