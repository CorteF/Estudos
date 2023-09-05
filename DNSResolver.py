import socket
host = input("Digite o Host:")

print (host, "--->",socket.gethostbyname(host))
