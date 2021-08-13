cmake_minimum_required(VERSION 3.9)
project("cpp_demo_cosim" VERSION "0.0.1")

set(CMAKE_CXX_STANDARD 17)

# path to libcolib 
set(COLIB_INCLUDE_DIR ~/libcosim/include)
set(COLIB_LIBRARY ~/libcosim/build/output/debug/lib)

# path to FMI library 
set(FMILibrary_INCLUDE_DIR ~/FMI_library/include)
set(FMILibrary_LIBRARY ~/FMI_library/lib)

set(Boost_components date_time fiber log)
find_package(Boost REQUIRED COMPONENTS ${Boost_components})

set(CMAKE_PREFIX_PATH "${MS_GSL_INCLUDE_DIR}:${CMAKE_PREFIX_PATH}")
message("${CMAKE_PREFIX_PATH}")

add_executable(cosim_demo
    src/cpp_demo.cpp
)

target_include_directories(cosim_demo PUBLIC
    include
    ${COLIB_INCLUDE_DIR}
    ${FMILibrary_INCLUDE_DIR}
)

target_link_libraries(cosim_demo 
    PRIVATE
        ${COLIB_LIBRARY}/libcosim.so
        ${FMILibrary_LIBRARY}/libfmilib_shared.so
    PUBLIC
        Boost::boost
        Boost::date_time
        Boost::fiber
        Boost::log
        gsl
)

