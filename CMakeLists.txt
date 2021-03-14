cmake_minimum_required(VERSION 3.17)
project(Images_classification_IA)

set(CMAKE_CXX_STANDARD 14)

add_executable(Images_classification_IA main.cpp Sources/Input.cpp Sources/Bib/Input.h Tests/Point.cpp Tests/Point.h Sources/Iris.cpp Sources/Bib/Iris.h Sources/Image.cpp Sources/Bib/Image.h Sources/Service.cpp Sources/Bib/Service.h)