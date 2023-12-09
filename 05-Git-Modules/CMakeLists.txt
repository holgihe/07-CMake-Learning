# firsttime:  to connect to submodule from github via git - example with glfw library
git submodule add https://github.com/glfw/glfw.git external/glfw


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

# Now we can install libdemo.a in one directory (LIBRARY DESTINATION), and header libdemo.h in another (PUBLIC_HEADER DESTINATION)
install( TARGETS libdemo LIBRARY DESTINATION lib PUBLIC_HEADER DESTINATION include )