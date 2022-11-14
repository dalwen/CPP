cmake_minimum_required(VERSION 3.0.0)
project(PlayGround VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCES main.cpp FollowPointer.cpp)
add_executable(PlayGround ${SOURCES} )
target_include_directories(PlayGround PRIVATE headerdir/)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
