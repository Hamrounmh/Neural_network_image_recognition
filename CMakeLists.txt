cmake_minimum_required(VERSION 3.17)
project(Images_classification_IA)

set(CMAKE_CXX_STANDARD 14)

add_executable(Images_classification_IA main.cpp Sources/Inputs/Input.cpp Sources/Libraries/Input.h Sources/Inputs/Iris.cpp Sources/Libraries/Iris.h Sources/Inputs/Image.cpp Sources/Libraries/Image.h Sources/Services/Service.cpp Sources/Libraries/Service.h)