
cmake_minimum_required(VERSION 2.4)

project(socket_sample)

add_executable(server server.cpp)
add_executable(client client.cpp)

find_package(Boost REQUIRED system)
add_executable(boost_server boost_server.cpp)
target_link_libraries(boost_server ${Boost_LIBRARIES})
add_executable(boost_client boost_client.cpp)
target_link_libraries(boost_client ${Boost_LIBRARIES})
