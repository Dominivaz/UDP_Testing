import socket 

ip = '10.32.92.219'
port = 5001
message = b'data'

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

sock.bind((ip, port))

while True:
	data, addr = sock.recvfrom(32768)
	print('Received: %s' % data)
