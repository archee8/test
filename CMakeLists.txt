cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(rfid_test)
# Find Gazebo
find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS} include)
link_directories(${GAZEBO_LIBRARY_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")

# Build our plugin
add_library(rfid_test SHARED src/WirelessReceiverPlugin.cc)
target_link_libraries(rfid_test ${GAZEBO_LIBRARIES})
add_library(rfid_test1 SHARED src/WirelessTransmitterPlugin.cc)
target_link_libraries(rfid_test1 ${GAZEBO_LIBRARIES})
add_library(rfid_test2 SHARED src/WirelessTransceiverPlugin.cc)
target_link_libraries(rfid_test2 ${GAZEBO_LIBRARIES})
