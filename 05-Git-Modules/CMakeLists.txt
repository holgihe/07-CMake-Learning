# firsttime:  to connect to submodule from github via git - example with glfw library:
#      git submodule add https://github.com/glfw/glfw.git external/glfw


# cd builds/03-Libdemo
# cmake -DCMAKE_BUILD_TYPE=Debug ../../03-Libdemo/
# make
# make install 

cmake_minimum_required(VERSION 3.25.0)

set(CMAKE_INSTALL_PREFIX /home/jr/Dokumente/90-nextcloud/webdav-sync/10-Programmierung/src-holgi/07-CMake-Learning )

project(gitmodules)

add_executable(${PROJECT_NAME} main.cpp)

# Telling CMake to add our git-submodule into the build process:
add_subdirectory(external/glfw)

# target_include_directories = where to find/put header files *.h
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/../include )
# target_link_directories = where to find/put library files  *.a
target_link_directories (${PROJECT_NAME}  PUBLIC ${CMAKE_SOURCE_DIR}/../lib/ )
# target_link_libraries = which libraries *.a or *.so to use for the linker 
target_link_libraries(${PROJECT_NAME} libdemo glfw)

install( TARGETS gitmodules DESTINATION bin )