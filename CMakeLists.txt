cmake_minimum_required(VERSION 2.8)

project(Eye_tracker_Client)
include_directories(${CMAKE_SOURCE_DIR}/Connector ${CMAKE_SOURCE_DIR}/Control ${CMAKE_SOURCE_DIR}/Telemetrics)
add_executable(${PROJECT_NAME} "main.cpp" "Connector/Connector.cpp" "Control/Control.cpp" "Telemetrics/Telemetrics.cpp")
