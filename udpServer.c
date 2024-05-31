#include <stdio.h>      // Standard I/O library for functions like printf and perror
#include <stdlib.h>     // Standard library for functions like exit and atoi
#include <string.h>     // String handling library for functions like memset and strcpy
#include <sys/socket.h> // Library for socket functions
#include <sys/types.h>  // Library for data types used in socket programming
#include <netinet/in.h> // Library for Internet address family
#include <arpa/inet.h>  // Library for functions like inet_addr and htons

int main(int argc, char **argv) // Main function with command line arguments
{
    // through command line argument I will get the PORT number of the UDP Server
    if (argc != 2) // Check if the correct number of arguments is provided
    {
        printf("Usage: %s <port>\n", argv[0]); // Print usage message
        printf("Please provide a port number for the server through command line argument.\n");
        exit(0); // Exit the program if the number of arguments is incorrect
    }

    // argc => the number of arguments
    // argv => the array of arguments
    // When we run the program, we write ./udpServer 5566 in the terminal
    // So here argc = 2 and argv[0] = ./udpServer and argv[1] = 5566
    // If we run the program, we write ./udpServer in the terminal
    // So here argc = 1 and argv[0] = ./udpServer

    char *ip = "127.0.0.1";   // the IP address of the server
    int port = atoi(argv[1]); // Convert the port number from a string to an integer

    int sockfd; // Socket file descriptor
    // A file descriptor is an unsigned integer used by a process to identify an open file.
    // socket file descriptor is a unique integer identifier that the operating system assigns to a socket when it is created.
    // This identifier is used by the program to reference the socket in subsequent network communication operations.
    //  The file descriptor is passed to other socket functions like bind, sendto, and recvfrom to perform various network operations.

    struct sockaddr_in server_address, client_address;
    // This sockaddr_in structure is defined in the header file <netinet/in.h>
    // And I've defined the structure variable server_addressess and client_addressess

    char buffer[1024];   // Buffer to hold message data received from or to be sent to the udp client
    socklen_t addr_size; // Variable to hold the size of the address of the socket

    sockfd = socket(AF_INET, SOCK_DGRAM, 0); // Create a UDP socket
    // AF_INET refers to the IPv4 address family, which is used for IPv4 Internet protocols
    // SOCK_DGRAM indicates that the socket is of type datagram, which is used for UDP (User Datagram Protocol).
    // The value 0 indicates that the system should automatically select the appropriate protocol based on the specified domain and type.
    // For AF_INET and SOCK_DGRAM, this will be the UDP protocol.

    if (sockfd < 0) // Check if the socket was created successfully. If socket() returns -1, then socket creation failed
    {
        perror("Socket creation failed\n"); // Print an error message if socket creation failed
        exit(1);                          // terminate the program with a non-zero status which indicates an error
    }
    else
    {
        printf("UDP Socket created successfully !\n"); // Socket creation successful
        // A UDP socket enables simple IP communication using the User Datagram Protocol (UDP).
        // UDP is a connectionless protocol that runs on top of the Internet Protocol (IP)
    }

    memset(&server_address, '\0', sizeof(server_address)); // memset is used to fill a block of memory with a specific value and '\0' means NULL character
    server_address.sin_family = AF_INET;                   // It sets the address family to AF_INET, which is used for IPv4 addresses.
    server_address.sin_port = htons(port);                 // It sets the port number for the socket. And htons(port) converts the port number from host byte order to network byte order (big-endian). htons stands for "host to network short"
    server_address.sin_addr.s_addr = inet_addr(ip);        // It sets the IP address for the server.
    // `inet_addr(ip)` converts the IP address in the ip string from the standard dot notation ("127.0.0.1") to a format suitable for the sin_addr.s_addr field of the `sockaddr_in` structure

    int n = bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
    // After the creation of the socket, the bind function binds the socket to the address and port number
    // (struct sockaddr*)&server_addresses: It's a pointer to the sockaddr_in structure that contains the address to which the socket will be bound.
    // It needs to be cast to a struct sockaddr* as the bind function expects this type.

    if (n < 0) // if bind() returns -1, then socket binding is unsuccessfull
    {
        perror("Socket binding failed\n"); // Print an error message if binding failed
        exit(1);                 // Exit the program
    }
    else // bind successfull
    {
        printf("Socket binded successfully to IP: %s and Port: %d\n", ip, port);
    }

    // Now recieve and send message data 
    bzero(buffer, 1024); // this bzero() clears the buffer to ensure it does not contain any leftover data.
    addr_size = sizeof(client_address); // Set the size of the client address structure

    recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr *)&client_address, &addr_size); // Receive data from a client

    printf("\nMessage recieved from Client: %s\n", buffer); // Print the received data

    bzero(buffer, 1024); // Clear the buffer again

    // Type message through terminal and sends it to the Client
    printf("Enter message to send to client: ");
    fgets(buffer, sizeof(buffer), stdin);
    // The fgets function is used to read a line of text from a specified input stream,
    // which in this case is stdin (the standard input, typically the terminal).

    sendto(sockfd, buffer, 1024, 0, (struct sockaddr *)&client_address, sizeof(client_address)); // Send the welcome message to the client

    printf("\nMessage sent to Client: %s\n", buffer); // Print the sent message

    return 0; // Return 0 to indicate successful execution
}
