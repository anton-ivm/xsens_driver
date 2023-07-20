cmake_minimum_required (VERSION 3.18 FATAL_ERROR)
project(xspublic LANGUAGES CXX C)


set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_C_FLAGS "-W -Wall -fPIC -include xstypes/xsens_compat.h -include xscontroller/xscontrollerconfig.h -DHAVE_JOURNALLER")
set(CMAKE_CXX_FLAGS "-W -Wall -std=c++11 -fPIC -include xscommon/xscommon_config.h -include xstypes/xsens_compat.h -include xscontroller/xscontrollerconfig.h -DHAVE_JOURNALLER")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

include_directories(xspublic)


# xstypes
file(GLOB_RECURSE SRC xspublic/xstypes/*.c)
add_library(xstypesc ${SRC})
set_target_properties(xstypesc PROPERTIES LINKER_LANGUAGE C)

file(GLOB_RECURSE SRC xspublic/xstypes/*.cpp)
add_library(xstypes ${SRC})
target_link_libraries(xstypes xstypesc)

# xscommon
file(GLOB_RECURSE SRC xspublic/xscommon/*.c)
add_library(xbus ${SRC})
set_target_properties(xbus PROPERTIES LINKER_LANGUAGE C)

file(GLOB_RECURSE SRC xspublic/xscommon/*.cpp)
add_library(xscommon ${SRC})
target_link_libraries(xscommon xbus xstypes)

# xscontroller
file(GLOB_RECURSE SRC xspublic/xscontroller/*.c)
add_library(xsdevicestate ${SRC})
set_target_properties(xsdevicestate PROPERTIES LINKER_LANGUAGE C)

file(GLOB_RECURSE SRC xspublic/xscontroller/*.cpp)
add_library(xscontroller ${SRC})
target_link_libraries(xscontroller xsdevicestate xscommon)

# example
add_executable(example example_mti_receive_data.cpp)
target_link_libraries(example xscommon xscontroller xstypes)
