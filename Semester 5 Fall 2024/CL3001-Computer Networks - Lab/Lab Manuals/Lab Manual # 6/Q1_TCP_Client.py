import socket
import sys
import random

def main():
    # Create a TCP/IP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Connect the socket to the port where the server is listening
    server_address = ('localhost', 10000)
    print('Connecting to %s Port %s' % server_address, file=sys.stderr)
    sock.connect(server_address)
    print('\n',end='')
    try:
        # Send data
        message = 'Hello I am client and My id is ' + str(random.randint(0,9))+ '.'
        print('Sending to Server: "%s"' % message, file=sys.stderr)
        print('\n',end='')
        sock.sendall(message.encode())  # Encode the message to bytes

        data = sock.recv(1024)
        print('Received from Server: "%s"' % data.decode(), file=sys.stderr)  # Decode the received bytes back to string
        print('\n',end='')

    finally:
        print('Closing Socket', file=sys.stderr)
        sock.close()

if __name__ == "__main__":
    main()
