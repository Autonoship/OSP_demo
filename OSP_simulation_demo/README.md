# Simulation Description
This sample simulation contains a simple ship dynamic model and two controllers. These three models are built with MATLAB Simulink on a Ubuntu 20.04 machine, and are exported to FMUs.

## 1. Model description
The simulation has three models: ship dynamics, thrust controller, and rudder controller.
The ship dynamics is described as below:

    x1 = -x1/T+(K/T)*u1
    x2 = x1
    x3 = x5*cos⁡(x2)
    x4 = x5*sin⁡(x2)
    x5 = a*(u2-x5)

where:

    x1 = dphi/dt, the angular speed
    x2 = phi, the course of the ship
    x3 = x, the x coordinate
    x4 = y, the y coordinate
    x5 = v, the linear speed of the ship
    K = 0.1555
    T = 73.77
    u1 and u2 are the inputs

The ship dynamics is described in the _ShipWareDynamics.fmu_. The model has five outputs: x1 to x5, and two inputs: u1 and u2.

The thrust controller is a PID controller. The rudder controller is a nonlinear controller. For detailed information, one can look at the simulink models. 

## 2. Usage with command line tool
To run the simulation on OSP, one need to provide the _OspSystemStructure.xml_. In this file, the connection between FMUs are defined. An example is provided with this demo, and more information can be found at https://open-simulation-platform.github.io/libcosim/configuration.
One can also provide a scenario description file, which helps to better test the performance of the models. One can set input values at different time steps with a scenario file, and then analyze the output of the simulation accordingly. A sample scenario file _autopilot_test_scenario.json_ is provided with this demo, and more information can be found at https://open-simulation-platform.github.io/libcosim/scenario.
The simulation result can be logged to a csv file. If only part of the variables need to be logged, one can write a _LogConfig.xml_ to describe the required variables. An sample is provided, and more information can be found at https://open-simulation-platform.github.io/libcosim/logging.

With all these things ready, one can run the simulation with the command line tool: cosim. If you have not installed the cosim, please go back to the parent directory and look for instructions there.
A simple command example is: 
    
    cosim run OspSystemStructure.xml -b 0.0 -e 1200.0 --scenario scenarios/autopilot_test_scenario.json -v

The basic command is : cosim run OspSystemStructure.xml. The following conditions are added to the command to better describe the simulation:

    -b: begin time
    -e: end time
    --scenario: the path to the scenario description file
    -v: verbose

For more information, please look at the help documentation:

    cosim --help
    cosim run --help

## 3. Usage with demo web app
OSP has provided a cosim demo web app which can run OSP simulations and display the results. For installation guide, please go back to the parent directory. After installation, one can run the _cosim-demo-app_ file to start the simulation. Illustrations can be found at https://open-simulation-platform.github.io/cosim-demo-app/cosim-demo-app. One can use this app to run the simulation and plot the outputs. One can also set the real-time-factor of the simulation and look at the variables at real-time.

## 4. Usage with demo code
This demo also provided a code version usage of libcosim, which can be found at _cpp_demo_ directory. After building, one can run the compiled program by following the instruction in the parent directory: 

    cd cpp_demo/build 
    ./cosim_demo
   
