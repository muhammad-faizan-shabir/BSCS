import socket
import sys

def main():
    # Create a TCP/IP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Connect the socket to the port where the server is listening
    server_address = ('localhost', 10003)
    print('Connecting to %s Port %s' % server_address, file=sys.stderr)
    sock.connect(server_address)
    print('\n',end='')
    try:
        flag=True

        while(flag==True):
            message = sock.recv(1024)
            message = message.decode()
            print("Message from server: ")
            print(message,end="")

            if "end" not in message.lower():
                reply = input()
                sock.sendall(reply.encode())
            else:
                print("")
                flag=False

    finally:
        print('Closing Socket', file=sys.stderr)
        sock.close()

if __name__ == "__main__":
    main()
