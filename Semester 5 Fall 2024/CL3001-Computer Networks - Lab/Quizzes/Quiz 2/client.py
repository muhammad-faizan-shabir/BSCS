import socket

def main():
    # Create a socket (IPv4, TCP)
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print("Socket Created")
    
    # Server address configuration
    server_address = ('127.0.0.1', 2000)
    
    # Connect to the server
    try:
        client_socket.connect(server_address)
        print("Connected to Server")
    except socket.error as e:
        print(f"Connection Failed. Error: {e}")
        return
    
    try:
        # Get input from the user
        client_message = input("Enter Message: ")
        
        # Send the message to the server
        client_socket.sendall(client_message.encode())
        
        # Receive the response from the server
        server_message = client_socket.recv(2000).decode()
        print(f"Server Message: {server_message}")
    
    except socket.error as e:
        print(f"Error: {e}")
    finally:
        # Close the socket
        client_socket.close()
        print("Socket Closed")

if __name__ == "__main__":
    main()