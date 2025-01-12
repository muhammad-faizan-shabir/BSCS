import socket

def main():
    # Create a UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # Bind the socket to the server address and port
    server_address = ('127.0.0.1', 2000)
    sock.bind(server_address)

    print("Socket created and bound")
    print("Listening for messages...\n")

    database=[] # list used as database

    while True:
        try:
            # Receive the message from the client
            client_message, client_address = sock.recvfrom(2000)
            print(f"Received message from IP: {client_address[0]} and Port No: {client_address[1]}")
            print(f"Client Message: {client_message.decode()}")
            client_message=client_message.decode()

            if client_message[-2::]=="CI":
                if client_message[0:-3] in database:
                    reply= "You are already here."
                else:
                    database.append(client_message[0:-3])
                    reply= "Welcome Student "+ client_message[0:-3]
            elif client_message[-2::]=="CO":
                if client_message[0:-3] in database:
                    reply= "GoodBye Student "+str(client_message[0:-3])+"! Have a nice day."
                    database.remove(client_message[0:-3])
                else:
                    reply="You didn’t check in today. Contact System Administrator."
            else:
                reply="Invalid Message"

            print("Database Members are:")
            for rollNo in database:
                print(rollNo)
            print("\n",end="")

            # Send a message back to the client
            sock.sendto(reply.encode(), client_address)

        except Exception as e:
            print(f"An error occurred: {e}")
            break

    # Closing the socket
    sock.close()

if __name__ == "__main__":
    main()