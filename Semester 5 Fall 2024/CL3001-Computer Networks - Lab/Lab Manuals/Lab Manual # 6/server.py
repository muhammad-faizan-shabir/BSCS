import socket

def main():
    # Define server address and port
    server_ip = '127.0.0.1'
    server_port = 2000

    # Create UDP socket
    try:
        udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        udp_socket.bind((server_ip, server_port))
        print("Socket Created and Bound")
    except socket.error as err:
        print(f"Could not create or bind socket. Error: {err}")
        return

    print("Listening for Messages...\n")

    # Receive the message from the client
    try:
        client_message, client_address = udp_socket.recvfrom(2000)
        print(f"Received Message from IP: {client_address[0]} and Port No: {client_address[1]}")
        print(f"Client Message: {client_message.decode()}")
    except socket.error as err:
        print(f"Receive Failed. Error: {err}")
        return

    # Send the message back to the client
    try:
        udp_socket.sendto(client_message, client_address)
    except socket.error as err:
        print(f"Send Failed. Error: {err}")
        return

    # Close the socket
    udp_socket.close()

if _name_ == "_main_":
    main()