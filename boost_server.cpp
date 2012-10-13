/*
 * boost_server.cpp
 *
 *  Created on: 2012/10/13
 *      Author: yuya-oc
 */

#include <iostream>
#include <boost/asio.hpp>

namespace asio = boost::asio;
using namespace asio::ip;

int main(int argc, char** argv){
	asio::io_service io_service;
	tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(),12345));
	tcp::socket socket(io_service);

	boost::system::error_code error;
	acceptor.accept(socket,error);

	if(error){
		std::cerr << "connect failed:" << error.message() << std::endl;
	}
	else{
		std::cout << "connected" << std::endl;
		int i=5;
		asio::write(socket,asio::buffer(&i,sizeof(int)));
		std::cout << i << std::endl;
	}
	return 0;
}
