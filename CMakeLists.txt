cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(xsens_driver)

set(CMAKE_BUILD_TYPE Release CACHE STRING "build type")
cmake_policy(SET CMP0057 NEW)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

link_directories(lib/xspublic/xscontroller lib/xspublic/xscommon lib/xspublic/xstypes)
add_executable(example main.cpp)
target_include_directories(example PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lib/xspublic>
  $<INSTALL_INTERFACE:include>)

target_link_libraries(example xscommon xscontroller xstypes pthread dl)


# include_directories(${PROJECT_SOURCE_DIR}/xspublic)
# link_directories(${PROJECT_SOURCE_DIR}/xspublic/xscommon)
# link_directories(${PROJECT_SOURCE_DIR}/xspublic/xscontroller)
# link_directories(${PROJECT_SOURCE_DIR}/xspublic/xstypes)
# include_directories(${PROJECT_SOURCE_DIR}/xscontroller)
# include_directories(${PROJECT_SOURCE_DIR}/xstypes)
# include(ExternalProject)
# ExternalProject_Add(xspublic
#   SOURCE_DIR ${PROJECT_SOURCE_DIR}/xspublic
#   INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/install
#   CONFIGURE_COMMAND ""
#   BUILD_COMMAND ${CMAKE_COMMAND} -E env
#     HOST_CC=
#     CC=${CMAKE_C_COMPILER}
#     make -C <SOURCE_DIR>
#     BUILD_IN_SOURCE TRUE
#     # INSTALL COMMAND make DESTDIR=<INSTALL_DIR> install
#     INSTALL_COMMAND "" 
# )

# add_executable(example ${PROJECT_SOURCE_DIR}/examples/example_mti_receive_data.cpp)
