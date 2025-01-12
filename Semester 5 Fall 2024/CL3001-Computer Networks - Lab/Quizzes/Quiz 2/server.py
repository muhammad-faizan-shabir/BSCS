import socket

def main():
    # Create a socket (IPv4, TCP)
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print("Socket Created")
    
    # Server configuration
    server_address = ('127.0.0.1', 2000)
    
    # Bind the socket to the address and port
    try:
        server_socket.bind(server_address)
        print("Bind Done")
    except socket.error as e:
        print(f"Bind Failed. Error: {e}")
        return
    
    # Listen for incoming connections
    server_socket.listen(1)  # Allow only one connection in the backlog
    print("Listening for Incoming Connections...")
    
    try:
        # Accept a connection
        client_socket, client_address = server_socket.accept()
        print(f"Client Connected with IP: {client_address[0]} and Port No: {client_address[1]}")
        
        # Receive the message from the client
        client_message = client_socket.recv(2000).decode()
        print(f"Client Message: {client_message}")
        
        # Send the same message back to the client
        server_message = client_message
        client_socket.sendall(server_message.encode())
        
        print("Message Sent Back to Client")
    
    except socket.error as e:
        print(f"Error: {e}")
    finally:
        # Close the client and server sockets
        client_socket.close()
        server_socket.close()
        print("Sockets Closed")

if __name__ == "__main__":
    main()