/*  
*
* FakeSkype : Skype reverse engineering proof-of-concept client
*
* Ouanilo MEDEGAN (c) 2006
* http://www.oklabs.net
*
* Feel free to modifiy, update or redistribute (Quotation appreciated ;))
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

unsigned char function_idx[128] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 
	0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 
	0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 
	0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 
	0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 
	0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 
	0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 
	0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08
};

/*
X = FUNC ID BYTE IN TCP/IP PACKET
Y = X AND 0x7F
IF Y < 0x80 GOOD
Z = (X AND 0x8F) SHR 1
IF Z < 0x80 GOOD

JUMP TO ..function_table[function_idx[Z]]
*/

/*

	unsigned char SendBuffer[] = {0x3A, 0xCA, 0x02, 0xD1, 0x90, 0x44, 0x1F, 0xC8, 0xA8, 0x76, 0xA7, 0x66, 0xD8, 0xFA, 0xCA, 0x95,
						0x75, 0xD9, 0xF6, 0xAE, 0x3C, 0xC0, 0x38, 0x4D, 0xEF, 0x5D, 0x19, 0x30, 0xE5, 0x6F, 0x98};


	SOCKET	sock;
	sockaddr_in SendrAddr;
	sockaddr_in RecvrAddr;
	int		err, idx, data_idx, RecvBufferSz;
	unsigned char	RecvBuffer[65536];
 
	RecvBufferSz = 65536;


	for (idx = 0; Hosts[idx].port != 0; idx++)
	{
		sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (sock == INVALID_SOCKET)
		{
			printf("UDPSocket Error : <%d>\n", WSAGetLastError());
			return (0xBADF00D);
		}
		SendrAddr.sin_family = AF_INET;
		SendrAddr.sin_port = htons(Hosts[idx].port);
		SendrAddr.sin_addr.s_addr = inet_addr(Hosts[idx].ip);
		printf("Sending datagram to host : %s..\n", Hosts[idx].ip);
		printf("%d Bytes sent..\n", sendto(sock, (const char *)&SendBuffer[0], sizeof(SendBuffer), 0, (SOCKADDR *) &SendrAddr, sizeof(SendrAddr)));
		
		Sleep(500);
		
		RecvrAddr.sin_family = AF_INET;
		printf("%d Bytes in response..\n-> ", recvfrom(sock, (char *)&RecvBuffer[0], RecvBufferSz, 0, (SOCKADDR *) &RecvrAddr, &RecvBufferSz));

		for (data_idx = 0; data_idx < RecvBufferSz - 1; data_idx++)
			printf("%#2x, ", RecvBuffer[data_idx]);
		printf("%#2x\n", RecvBuffer[data_idx]);

		closesocket(sock);
	}
*/
