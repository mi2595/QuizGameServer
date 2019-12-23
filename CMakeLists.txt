cmake_minimum_required(VERSION 3.15)
project(QuizGameServer C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS -pthread)
add_executable(QuizGameServer main.c utilitySocket.c utilitySocket.h utilityThread.c utilityThread.h server.c server.h)