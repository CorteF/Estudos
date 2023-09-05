import socket
import concurrent.futures

ip = input("Digite o IP:")


def scan_port(port):
    meusocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    meusocket.settimeout(1)

    if meusocket.connect_ex((ip, port)) == 0:
        try:
            banner = meusocket.recv(1024)
            print("Porta", port, "[ABERTA]", banner.decode('utf-8'))
        except socket.timeout:
            print("Porta", port, "[ABERTA] (Timeout)")
        finally:
            meusocket.close()


# Use um ThreadPoolExecutor para paralelizar o escaneamento, altere o max_workers de acordo com a capacidade do seu sistema
with concurrent.futures.ThreadPoolExecutor(max_workers=50) as executor: 
    # Escaneie as portas em paralelo
    executor.map(scan_port, range(1, 65536))

