import socket
import sys
import random
import time

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
        message = input("Enter message: ")
        print('Sending to Server: "%s"' % message, file=sys.stderr)
        sock.sendall(message.encode())  # Encode the message to bytes

        data = sock.recv(1024)
        print('Received from Server: "%s"' % data.decode(), file=sys.stderr)  # Decode the received bytes back to string
        print('\n',end='')

        data = data.decode()
        words = data.split()
        size = len(words)
        for i in range(0, size):
            if (isVowelWord(words[i]) == False):
                words[i] = words[i][::-1]
        data = " ".join(words)

        print("Message After Reversing Non-Vowel Words: " + data)
        print('\n', end='')

    finally:
        print('Closing Socket', file=sys.stderr)
        sock.close()

def isVowelWord(word):
    for i in range(0,len(word)):
        if word[i] in ['a','e','i','o','u','A','E','I','O','U']:
            return True

    return False

if __name__ == "__main__":
    main()
