cmake_minimum_required(VERSION 3.17)
project(Images_classification_IA)

set(CMAKE_CXX_STANDARD 14)

add_executable(Images_classification_IA main.cpp Sources/Input/Input.cpp Sources/Libraries/Input.h Sources/Input/Iris.cpp Sources/Libraries/Iris.h Sources/Input/Image.cpp Sources/Libraries/Image.h Sources/Services/Service.cpp Sources/Libraries/Service.h)