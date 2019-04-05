cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(CMAKE_CXX_STANDARD 11)
set(PROJECT_NAME exploration_board)

set(${PROJECT_NAME}_BOARD uno)
# set(ARDUINO_CPU)
project(${PROJECT_NAME})


# Add all source files
file(GLOB_RECURSE ${PROJECT_NAME}_SRCS  "src/*.cpp")
list(APPEND ${PROJECT_NAME}_SRCS exploration_board.cpp)


#### Additional settings for programmer. From programmers.txt
set(${PROJECT_NAME}_PROGRAMMER arduinoasisp)
set(${PROJECT_NAME}_PORT /dev/cu.usbmodem1443101)
# set(uno.upload.speed 9600)

## Verbose build process
# set(${PROJECT_NAME}_AFLAGS -v)


message(${PROJECT_SOURCE_DIR})
generate_arduino_firmware(${PROJECT_NAME})
