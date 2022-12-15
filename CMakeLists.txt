cmake_minimum_required(VERSION 3.24)
project(FirstLanguage)

set(CMAKE_CXX_STANDARD 20)

add_executable(FirstLanguage main.cpp lexer.cpp lexer.h)
