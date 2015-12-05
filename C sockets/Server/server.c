// ============================================================================
// File: HW23/Server/server.c
// ============================================================================
// Programmer: Phillip Stewart
// Date: Late May 2012
// Class: CSCI 223 ("C Programming")
// Time: TR 4-6
// Instructor: Mr. Edwards
// Project: Server network socket
// Description: 
// ============================================================================



#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/un.h>
#include <unistd.h>


#define LEN				256
//#define SOCKET_NAME		



// ==== MAIN ==================================================================
// ============================================================================
int main(void)
{
	auto	char		buf[LEN];
	auto	int			server_sockfd;
	auto	int			client_sockfd;
	auto	socklen_t	client_len;
	auto	ssize_t		num_client_bytes;
	
	auto	struct sockaddr_un server_address;
	auto	struct sockaddr_un client_address;
	
	//create new socket
	unlink(SOCKET_NAME);
	server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
	
	//bind the address to a name
	server_address.sun_family = AF_UNIX;
	strcpy(server_address.sun_path, SOCKET_NAME);
	if (bind(server_sockfd, (struct sockaddr*)&server_address, sizeof(server_address)))
		{
		perror("server -- bind failed");
		}
	
	//create connection queue, await clients
	if (listen(server_sockfd, 5))
		{
		perror("server -- listen failed");
		}
	
	//announce server is waiting for client connections
	puts("server waiting");
	
	//accept a connection
	client_len = sizeof(client_address);
	client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address
										, &client_len);
	
	//read filename from client
	do	{//then read file which will immediately follow filename
		memset(buf, 0, LEN);
		
		//num_client_bytes = recv(client_sockfd, buf, LEN, 0);
		
		if (-1 == num_client_bytes)
			{
			perror("server -- recv failed");
			}
		else{
			//write data to file
			}
		}while(//file still is being sent...);
	
	//remove the local socket file and close the sockets
	unlink(SOCKET_NAME);
	close(client_sockfd);
	close(server_sockfd);
	
	return 0;
}//end of main


