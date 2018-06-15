#EVANS WAHOME GICHUKI
#P15/36969/2016

import socket
import datetime

newval1 = []
newval2 = []
offset = []

s = socket.socket()


def  main():
		
	port = 12345
	s.connect(('127.0.0.1',port))

	mess = "What is the time"

	send = mess.encode('utf-8')#has to be encoded as it requires to be in byte format for strings


	dep = datetime.datetime.now()#to get the time it was sent so as to calculate the offset
	print(dep)
	dep2 =str(dep)
	hrs2 = list(dep2)
	cleaned = [ x for x in hrs2 if x.isdigit() ]#removes all signs and symbols

	

	print(cleaned)


	s.send(b'%s'%send)



	#(s.recv(1024))#receives the time 
	time = s.recv(1024)
	print(time)
	time = str(time)
	time2 = list(time)
	cleaned2 = [ x for x in time2 if x.isdigit() ]#removes all signs and symbols
	#print(cleaned2)

	#subtracting(cleaned,cleaned2)

	for i in cleaned:# convert the time into integers so as to subtract
		i = int(i)
		newval1.append(i)

	for j in cleaned2:
		j = int(j)
		newval2.append(j)

		

	for k in range(0,len(cleaned)):#find the offset
		off = (newval2[k] - newval1[k])/2#assume time taken to send is the same as time taken to return
		offset.append(int(off))

		

	
	final=[]
	#add the offset to the new time 
	for n in range(0,len(cleaned)):#find the offset
		fin = abs(newval2[n]) + abs(offset[n])
		final.append(fin)
	print(final)
	final = str(final)

#formating the output (not important)
	year = final[0:12]
	month = final[13:18]
	day = final[19:24]
	hr = final[25:30]
	minu = final[31:36]
	sec = final[37:42]
	msec = final[43:]

	makeitastring = ''.join(map(str, final))
	#ftime = year +'-'+month+'- '+day +' *** '+hr+'-'+minu+'-'+sec+'-'+msec
	print(makeitastring)



if __name__ == '__main__':
	main()


s.close()