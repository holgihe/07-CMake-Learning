# cd builds/01-intro
# cmake -DCMAKE_BUILD_TYPE=Debug ../../01-Intro/
# make
# make install 

cmake_minimum_required(VERSION 3.25.0)

set(CMAKE_INSTALL_PREFIX /home/jr/Dokumente/90-nextcloud/webdav-sync/10-Programmierung/src-holgi/07-CMake-Learning )

project(intro)

add_executable(${PROJECT_NAME} intro.cpp)

install( TARGETS intro DESTINATION bin )