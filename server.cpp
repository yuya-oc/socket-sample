
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
using namespace std;

int main(int argc, char** argv){
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd < 0){
		cerr << "Socket open failed" << endl;
		exit(1);
	}

	sockaddr_in server_address;
	const int port = 12345;
	bzero(&server_address, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port);
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_len = sizeof(server_address);

	bind(socket_fd, (sockaddr*)&server_address, sizeof(server_address));
	listen(socket_fd, 5);

	sockaddr_in client_address;
	socklen_t socklen = sizeof(client_address);
	int socket = accept(socket_fd, (sockaddr*)&client_address, &socklen);

	while(true){
		char buffer[1];
		read(socket, buffer, 1);
		cout << "Received:" << buffer[0] << endl;
		write(socket, buffer, 1);
		cout << "Sended:" << buffer[0] << endl;
	}

	close(socket);
	close(socket_fd);

	return 0;
}
