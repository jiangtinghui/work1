cmake_minimum_required(VERSION 3.26)
project(show)

set(CMAKE_CXX_STANDARD 17)
set(DLL_PATH "E:/MyDll/cmake-build-debug/libMyDll.dll")
add_executable(show main.cpp)
target_link_libraries(show  ${DLL_PATH})




