cmake_minimum_required(VERSION 3.14)
project(ClionCppCode)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ClionCppCode
        JNIHelloWorld.cpp)

include_directories($JAVA_HOME/include)
include_directories($JAVA_HOME/include/linux)
link_directories($JAVA_HOME/include)
link_directories($JAVA_HOME/include/linux)