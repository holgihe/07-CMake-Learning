# cd builds/04-Libusage
# cmake -DCMAKE_BUILD_TYPE=Debug ../../04-Libusage/
# make
# make install 

cmake_minimum_required(VERSION 3.25.0)

set(CMAKE_INSTALL_PREFIX /home/jr/Dokumente/90-nextcloud/webdav-sync/10-Programmierung/src-holgi/07-CMake-Learning )

project(libusage)

add_executable(${PROJECT_NAME} main.cpp)

# target_link_directories = where to find library files  *.a
target_link_directories (${PROJECT_NAME}  PUBLIC ${CMAKE_SOURCE_DIR}/../lib/ )
# target_link_libraries = which libraries *.a or *.so to link 
target_link_libraries(${PROJECT_NAME} libdemo)

install( TARGETS libusage DESTINATION bin )