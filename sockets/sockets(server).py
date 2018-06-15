#EVANS WAHOME GICHUKI
#P15/36969/2016

import socket

ssocket = socket.socket() #create a socket
print('socket creation successfull')

port = 12345 #assign port
ssocket.bind(('127.0.0.1',port))#this makes the server listen to requests
print('socket bind is successfull')
ssocket.listen(5)#number of queued connections i.e the 5
print('the server is running')
while True:
	csocket,address = ssocket.accept()
	print('connection found')

	data = csocket.recv(1024)
	print(data)

	result = data[::-1]#reverses the string


	csocket.send(result)
	csocket.close()#close the connection with the client
	

	