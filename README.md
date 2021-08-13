# OSP_demo Installation Guide (Under construction)
This is a demo of running FMU based simulation with libcosim. For more information about OSP, please look at https://opensimulationplatform.com/

## 1. Install FMI Library
nstall FMI Library according to https://github.com/modelon-community/fmi-library and https://jmodelica.org/fmil/FMILibrary-2.0.3-htmldoc/index.html, or try:

  cd 
  git clone https://github.com/modelon-community/fmi-library.git
  mkdir build-fmil; cd build-fmil
  cmake -DFMILIB_INSTALL_PREFIX=~/FMI_library ~/fmi-library
  make install test


## 2. Install libcosim


