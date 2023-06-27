#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <time.h>
#include <errno.h>

#define IP "10.32.92.219"
#define PORT (5001)
#define IMAGES (1000)
#define FRAMES (23)
#define UDP (8000) // 6500 and 7000 the best so far
#define BUFFER_SIZE (IMAGES * FRAMES * UDP)

char buffer[BUFFER_SIZE];

void data(uint8_t* buffer, size_t length){
	for (size_t i=0; i<length; i++){
		buffer[i] = (rand() % 255) + 1;
	}
}

//nst char IP = '10.32.92.219';
//int port = 5001;
//char message = 'data';



int main() {
	struct sockaddr_in target_addr;
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	target_addr.sin_family = AF_INET;
	target_addr.sin_addr.s_addr = inet_addr(IP);
	target_addr.sin_port = htons(PORT);
	data(buffer, sizeof(buffer));
	
	while (1){
		sendto(sock, buffer, UDP, 0, (struct sockaddr*)&target_addr, sizeof(target_addr));
	}
		
	return 0;
	}
