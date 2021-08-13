# OSP_demo Installation Guide (Under construction)
This is a demo of running FMU based simulation with libcosim. If you are looking for the ROS-OSP simulation, please look at (under construction). For more information about OSP, please look at https://opensimulationplatform.com/. To run the demo, you just need to install the FMI_library and libcosim. However, it is recommended to install the command line tool (https://github.com/open-simulation-platform/cosim-cli) and the cosim demo web app (https://github.com/open-simulation-platform/cosim-demo-app).

## 1. Install FMI library
Install FMI Library according to https://github.com/modelon-community/fmi-library and https://jmodelica.org/fmil/FMILibrary-2.0.3-htmldoc/index.html, or try:

    cd 
    git clone https://github.com/modelon-community/fmi-library.git
    mkdir build-fmil; cd build-fmil
    cmake -DFMILIB_INSTALL_PREFIX=~/FMI_library ~/fmi-library
    make install test


## 2. Build libcosim
Build the libcosim according to https://github.com/open-simulation-platform/libcosim ("How to build" section). To modify the Conan profile, try to find it at _~/.conan/profiles_. For this demo, the FMU-Proxy is not included.

If failed with a "Werror" flag, turn off the Werror by:

    cmake .. -DLIBCOSIM_USING_CONAN=TRUE -DCMAKE_BUILD_TYPE=Debug -DLIBCOSIM_TREAT_WARNINGS_AS_ERRORS=OFF


## 3. Build the demo
After installing the FMI library and libcosim, the demo is ready for run. Make changes in the CMakeLists.txt to set the correct path to the libcosim and FMI library. Make changes to the src/cpp_demo.cpp to set the correct path to _OSP_simulation_demo_.
Build and run the demo by:
    
    cd cpp_demo
    mkdir build
    cd build 
    cmake ..
    cmake --build .
    ./cosim_demo

If the system failed to find GSL, install by:
    
    sudo apt-get install libmsgsl-dev


## 4. Install cosim command line tool
Install the cosim-cli according to https://github.com/open-simulation-platform/cosim-cli. If failed with a "Werror" flag, try removing the Werror compile option in the CMakeLists.txt. 
Before you run the cosim in a terminal, you also need to add the build directory to the system PATH.


## 5. Download cosim demo web app
Install the cosim demo web app according to https://github.com/open-simulation-platform/cosim-demo-app. After installation, you need to make the following files executable:

    chmod u+x run-linux
    chmod u+s bin/cosim-demo-app 

For practice, you can also download demo cases from https://github.com/open-simulation-platform/demo-cases/releases/tag/v0.6.0.
