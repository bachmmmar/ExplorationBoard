cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(CMAKE_CXX_STANDARD 11)
set(PROJECT_NAME exploration_board)

set(${PROJECT_NAME}_BOARD uno)
# set(ARDUINO_CPU)
project(${PROJECT_NAME})



file(GLOB ${PROJECT_NAME}_SRCS  "src/*.cpp")
message(${${PROJECT_NAME}_SRCS})
#set(${PROJECT_NAME}_SRCS "src/coded_rotary_switch.cpp" )
#list(APPEND ALL_SRCS ${${PROJECT_NAME}_SRCS})
#set(_SOURCES ${${PROJECT_NAME}_SRCS})

# Define additional source and header files or default arduino sketch files
#set(${PROJECT_NAME}_SRCS)

#file(GLOB_RECURSE ${PROJECT_NAME}_HDRS src/*.h)

set(${PROJECT_NAME}_HDRS User_Setup.h)
include_directories(./src)
#set(_HEADERS ${${PROJECT_NAME}_HDRS})
#message(${${PROJECT_NAME}_HDRS} )

### Add project directories into the build
#add_subdirectory(src)


### Additional static libraries to include in the target.
# set(${PROJECT_NAME}_LIBS)

### Main sketch file
set(${PROJECT_NAME}_SKETCH exploration_board.ino)


### Additional settings to add non-standard or your own Arduino libraries.
# For this example (libs will contain additional arduino libraries)
# An Arduino library my_lib will contain files in libs/my_lib/: my_lib.h, my_lib.cpp + any other cpp files
# link_directories(${CMAKE_CURRENT_SOURCE_DIR}/)

# For nested library sources replace ${LIB_NAME} with library name for each library
# set(_RECURSE true)

#### Additional settings for programmer. From programmers.txt
set(${PROJECT_NAME}_PROGRAMMER arduinoasisp)
set(${PROJECT_NAME}_PORT /dev/cu.usbmodem1443101)
# set(uno.upload.speed 9600)

## Verbose build process
# set(${PROJECT_NAME}_AFLAGS -v)


get_cmake_property(_variableNames VARIABLES)
#list (SORT _variableNames)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()

message(${PROJECT_SOURCE_DIR})
generate_arduino_firmware(${PROJECT_NAME})
