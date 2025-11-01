cmake_minimum_required(VERSION 4.1.0)

project(_template VERSION 1.0.0.0 LANGUAGES C CXX)
include_directories("C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/ucrt")

add_executable(_template main.c)