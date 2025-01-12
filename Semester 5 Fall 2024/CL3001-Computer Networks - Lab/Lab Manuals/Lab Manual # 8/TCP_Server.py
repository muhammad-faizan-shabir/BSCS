import socket
import threading

lock =threading.Lock()

def credentialsMatch(name,cnic):
    try:
        file = open('Voters_List.txt', 'r')
        for line in file:
            if (name in line and cnic in line):
                return True

        file.close()
        return False

    except FileNotFoundError:
        print("Error! Voters_List.txt did not open!")

def alreadyCastedVote(name,cnic):
    try:
        file = open('Votes.txt', 'r')
        with lock:
            for line in file:
                if (name in line and cnic in line):
                    return True

            file.close()
            return False

    except FileNotFoundError:
        return False

def saveVoteRecord(name,cnic,symbol):
    try:
        file = open("Votes.txt", 'a')
        with lock:
            file.write(name + "/" + cnic + "/" + symbol)
            file.write("\n")

        file.close()

    except FileNotFoundError:
        print("Error! Votes.txt did not open!")

def handle_client(sock):
    message="Enter your name: "
    sock.sendall(message.encode())
    name=sock.recv(1024).decode()

    message="Enter your CNIC: "
    sock.sendall(message.encode())
    cnic= sock.recv(1024).decode()

    if(credentialsMatch(name,cnic)):
        if(alreadyCastedVote(name,cnic)==False):
            try:
                file = open("Candidates_List.txt", 'r')
                message = file.read()
                file.close()

            except FileNotFoundError:
                print("Error! Candidates_List.txt did not open!")

            message=message+"\nEnter symbol: "
            sock.sendall(message.encode())
            symbol =sock.recv(1024).decode()

            if(symbol in message):
                saveVoteRecord(name,cnic,symbol)
                message = "Success! Vote casted. End of Session"
                sock.sendall(message.encode())
            else:
                message= "Error! Invalid symbol. End of Session"
                sock.sendall(message.encode())
        else:
            message="Error! You already casted vote. End of session."
            sock.sendall(message.encode())
    else:
        message= "Error! Invalid name or CNIC! End of session."
        sock.sendall(message.encode())

    sock.close()

def main():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('localhost', 10003))
    server.listen(5)
    print("Server started on port 9999")

    while True:
        client_socket, addr = server.accept()
        print(f"Accepted connection from {addr}")
        # create a thread to handle client
        client_handler = threading.Thread(target=handle_client, args=(client_socket,))
        # start the thread
        client_handler.start()

main()