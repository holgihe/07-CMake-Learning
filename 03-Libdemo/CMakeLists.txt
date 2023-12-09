# cd builds/03-Libdemo
# cmake -DCMAKE_BUILD_TYPE=Debug ../../03-Libdemo/
# make
# make install 

cmake_minimum_required(VERSION 3.25.0)

set(CMAKE_INSTALL_PREFIX /home/jr/Dokumente/90-nextcloud/webdav-sync/10-Programmierung/src-holgi/07-CMake-Learning )

project(libdemo)

add_library(${PROJECT_NAME} libdemo.cpp)

# Set variable PUBLIC_HEADER for libdemo.h file
set_target_properties(libdemo PROPERTIES PUBLIC_HEADER libdemo.h)

# Now we can install libdemo.a in one directory, and header libdemo.h in another 
install( TARGETS libdemo LIBRARY DESTINATION lib PUBLIC_HEADER DESTINATION include )