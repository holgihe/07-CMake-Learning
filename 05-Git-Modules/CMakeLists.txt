# firsttime:  to connect to submodule from github via git - example with glfw library:
#      git submodule add https://github.com/glfw/glfw.git external/glfw
# later times - if needed to reclone or update:
# git submodule update --init --recursive


# cd builds/03-Libdemo
# cmake -DCMAKE_BUILD_TYPE=Debug ../../03-Libdemo/
# make
# make install 

cmake_minimum_required(VERSION 3.25.0)

set(CMAKE_INSTALL_PREFIX /home/jr/Dokumente/90-nextcloud/webdav-sync/10-Programmierung/src-holgi/07-CMake-Learning )

project(gitmodules)

add_executable(${PROJECT_NAME} main.cpp)

# Sub-Modules from git or github - check, download, update as needed
find_package(Git QUIET)
# Alert:  adjust location of .git below.  I inserted /../.git because working in subdirectories like 05-Git-Modules
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/../.git")
 #Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

#           CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

# Telling CMake to add our git-submodule into the build process:
add_subdirectory(external/glfw)

# target_include_directories = where to find/put header files *.h
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/../include )
# target_link_directories = where to find/put library files  *.a
target_link_directories (${PROJECT_NAME}  PUBLIC ${CMAKE_SOURCE_DIR}/../lib/ )
# target_link_libraries = which libraries *.a or *.so to use for the linker 
target_link_libraries(${PROJECT_NAME} libdemo glfw)

install( TARGETS gitmodules DESTINATION bin )