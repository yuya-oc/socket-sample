
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

int main(int argc, char** argv){
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd < 0){
		cerr << "Socket open failed" << endl;
		exit(1);
	}
	return 0;
}
