# cd builds/02-trim
# cmake -DCMAKE_BUILD_TYPE=Debug ../../02-trim/
# make
# make install 

cmake_minimum_required(VERSION 3.25.0)

set(CMAKE_INSTALL_PREFIX /home/jr/Dokumente/90-nextcloud/webdav-sync/10-Programmierung/src-holgi/07-CMake-Learning )

project(trim)

add_executable(${PROJECT_NAME} trim.cpp)

install( TARGETS trim DESTINATION bin )