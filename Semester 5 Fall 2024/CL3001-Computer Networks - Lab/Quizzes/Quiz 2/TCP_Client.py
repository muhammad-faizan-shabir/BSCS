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
        print("Client running!")
        print("")

        # Get input from the user
        file_id = input("Enter File Id (Integer): ")
        chunk_id = input("Enter Chunk Id (Integer): ")
        data = input("Enter Data: ")

        chunk = file_id+"-"+chunk_id+"-"+data

        # Send the message to the server
        client_socket.sendall(chunk.encode())
        print("")
        print("Chunk sent to server!")

    except socket.error as e:
        print(f"Error: {e}")

    finally:
        # Close the socket
        client_socket.close()
        print("Socket Closed")

main()