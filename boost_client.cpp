/*
 * boost_client.cpp
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
	tcp::socket socket(io_service);

	boost::system::error_code error;
	socket.connect(tcp::endpoint(asio::ip::address::from_string("127.0.0.1"),12345),error);

	if(error){
		std::cerr << "connect failed:" << error.message() << std::endl;
	}
	else{
		std::cout << "connected" << std::endl;
	}
	return 0;
}
