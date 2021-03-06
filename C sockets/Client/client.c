// ============================================================================
// File: HW24/Client/client.c
// ============================================================================
// Programmer: Phillip Stewart
// Date: Late May 2012
// Class: CSCI 223 ("C Programming")
// Time: TR 4-6
// Instructor: Mr. Edwards
// Project: Client network socket
// Description: 
// ============================================================================



#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/socket.h>


#define WORD_LEN 80



// ==== MAIN ==================================================================
int main(void)
{
	auto char		worded[WORD_LEN];
	auto int		sckFD;
	auto int		numByteSent;
	auto FILE*		cpFile;
	auto int		fileSize;
	auto char*		fileDatums;
	
	auto struct sockaddr_in servAd;// = {AF_UNIX, "server_socket"};
	
	printf("Enter filename: ");
	fgets(worded, WORD_LEN, stdin);
	*(strchr(worded, '\n')) = '\0';
	
	//Determine filesize
	cpFile = fopen(worded, "r");
	fseek(cpFile, 0, SEEK_END);
	fileSize = ftell(cpFile) / sizeof(char);
	rewind(cpFile);
	fileDatums = calloc(fileSize, sizeof(char));
	
	//
	sckFD = socket(AF_INET, SOCK_STREAM, 0);
	memset(servAd, 0, sizeof(servAd);
	servAd.sin_family = AF_INET;
	strcpy(servAd.sin_add.s_addr, inet_addr("127.0.0.1"));
	servAd.sin_port = htons(51003);//i think that's the right port...
	
	connect(sckFD, (struct sockaddr*)&servAd, sizeof(servAd));
	
	//send filename
	//numByteSent = send(sckFD, worded, strlen(worded) + 1, 0);
	//not send()...
	
	//send file
	fread(fileDatums, sizeof(char), fileSize, cpFile);
	


		
	
	close(sckFD);
	fclose(cpFile);
	free(fileDatums);
	
	return 0;
}
