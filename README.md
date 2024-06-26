# Client and Server Program using both TCP and UDP

A Client and Server Program using TCP ensures reliable, connection-oriented communication. The server listens on a specific port and waits for client requests, establishing a connection to exchange data with guaranteed delivery. Conversely, a UDP based program offers connectionless, faster communication, where the server receives and processes datagrams from clients without establishing a dedicated connection, making it suitable for applications where speed is prioritized over reliability. Both protocols serve distinct needs based on the application's requirements for data integrity and transmission speed.

![TCP-UDP-Data-Communication](./assets/TCP_and_UDP_data_sending.png)

## Installation

### TCP Client Server Program

* **Step 1**: Complie The Program
  ```bash
  gcc tcpServer.c -o tcpServer # after compiling tcpServer.c, It instructs the compiler to output the compiled executable with the name tcpServer.
  gcc tcpClient.c -o tcpClient # after compiling tcpClient.c, It instructs the compiler to output the compiled executable with the name tcpClient.
  ```
* **Step 2**: Run the Program
  ```bash
  ./tcpServer
  ./tcpClient # run it in another terminal window
  ```

### UDP Client Server Program

* **Step 1**: Complie The Program

  ```bash
  gcc udpServer.c -o udpServer 
  gcc udpClient.c -o udpClient 
  ```
* **Step 2**: Run the Program

  ```bash
  ./udpServer 5566 # send the port number through argument
  ./udpClient 5566 # run it in another terminal window
  ```

## What is Socket Programming?

Socket programming is a way to connect two nodes on a network to communicate with each other. It uses socket APIs to establish communication links between local and remote processes. Sockets are a combination of an IP address and software port number that allows communication between multiple processes.

![socket-programming](./assets/Socket-Programming.png)

## What is Socket?

* A socket is effectively a type of file handle.
* A file handle in C is a pointer to a file. It is a data structure that holds information about the file
* You can read and write it (mostly) like any other file handle and have the data go to and come from the other end of the session.
* The specific actions you're describing are for the server end of a socket.
* A server establishes (binds to) a socket which can be used to accept incoming connections.
* Upon acceptance, you get *another* socket for the established session so that the server can go back and listen on the original socket for more incoming connections.
* A socket allows an application to "plug in" to the network and communicate with other applications that are also plugged in to the same network.
* Information written to the socket by an application on one machine can be read by an application on a different machine, and vice versa.

## TCP Client Server Diagram

![tcp-client-server](./assets/tcp_server_client.png)

## UDP Client Server Diagram

![udp-client-server](./assets/udp_server-client.png)

## TCP vs UDP

| Basis                    | TCP                                               | UDP                                                    |
| ------------------------ | ------------------------------------------------- | ------------------------------------------------------ |
| Connection               | Connection Oriented                               | connectionless                                         |
| Usage                    | High reliability, critical-less transmission time | fast, efficient, small queries, huge number of clients |
| Ordering of data packets | rearranges packets in order                       | No inherent order                                      |
| Reliability              | Yes                                               | No                                                     |
| Streaming od Data        | Read as a Byte Stream                             | Sent and read individually                             |
| Error Checking           | Error Checking and Recovery                       | Simply error checking, no error recovery               |
| Acknowledgement          | Acknowledgement segments                          | No acknowledgment                                      |

## TCP Client Server Program Result

![tcp-client-server-program-result](./assets/TCP_Client_Server_OutPut.png)

## UDP Client Server Program Result

![udp-client-server-program](./assets/UDP_Client_Server_OutPut.png)
