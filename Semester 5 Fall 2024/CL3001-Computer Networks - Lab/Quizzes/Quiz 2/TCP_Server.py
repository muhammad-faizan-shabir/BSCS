import socket

def processChunks(chunks):
    # sort by file id
    chunks.sort(key=lambda x:x[0])

    # sort by chunk id
    chunks.sort(key=lambda x:x[1])

    # make a dictionary
    dict = {}
    size = len(chunks)

    # add data into dictionary with key as file id
    for i in range(0, size):
        dict[chunks[i][0]] = dict.get(chunks[i][0], "") + chunks[i][2]

    # print constructed files in the dictionary
    print("Files Constructed so far: ")
    for fileId in dict:
        print("File Id", fileId, end=": ")
        print(dict[fileId])

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
    server_socket.listen(5)  # Allow only one connection in the backlog
    print("Listening for Incoming Connections...")

    chunks = []

    try:
        while(True):
            # Accept a connection
            client_socket, client_address = server_socket.accept()
            print("")
            print(f"Client Connected with IP: {client_address[0]} and Port No: {client_address[1]}")

            # Receive the message from the client
            message = client_socket.recv(2000).decode()
            print("Chunk received from client: ", message)

            # divide message into parts
            lst = message.split("-")
            #convert data into tuple
            chunk = (int(lst[0]), int(lst[1]), lst[2])
            # add tuple into the list
            chunks.append(chunk)
            # process the list to construct files
            processChunks(chunks)

    except socket.error as e:
        print(f"Error: {e}")

    finally:
        # Close the client and server sockets
        client_socket.close()
        server_socket.close()
        print("Sockets Closed")

main()