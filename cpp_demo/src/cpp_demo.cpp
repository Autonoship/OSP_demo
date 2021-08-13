#include "cpp_demo.hpp"

#include <iostream>
#include <string>

void load_scenario(
    cosim::execution& execution,
    const cosim::filesystem::path& scenarioPath,
    cosim::time_point startTime)
{
    auto s = std::make_shared<cosim::scenario_manager>();
    execution.add_manipulator(s);
    s->load_scenario(scenarioPath, startTime);
}

int main() {
  std::cout << "Successfully included the cosim library!" << std::endl;
  
  // load config
  std::cout << "Loading OSP config ......" << std::endl;
  const std::string path = "/home/chuanhui/research/autonoship/Open_Simulation_Platform/my_demo/OspSystemStructure.xml";
  const auto uriResolver = cosim::default_model_uri_resolver();
  const cosim::osp_config config = cosim::load_osp_config(path, *uriResolver);

  std::cout << "start time: " << cosim::to_double_time_point(config.start_time) << std::endl;
  std::cout << "Successfully loaded OSP config!" << std::endl;
  
  // execute simulation
  // cosim::algorithm algo;
  cosim::execution exe(config.start_time, std::make_shared<cosim::fixed_step_algorithm>(config.step_size));
  cosim::entity_index_maps index_maps = cosim::inject_system_structure(exe, config.system_structure, config.initial_values);
  std::cout << "Successfully created execution!" << std::endl;
  
  // add observer
  // cosim::file_observer observer("/home/chuanhui/research/autonoship/Open_Simulation_Platform/my_demo/log");
  // cosim::simulator_index target_simulator_index = index_maps.simulators.at("ship_dynamics");
  exe.add_observer(std::make_shared<cosim::file_observer>("/home/chuanhui/research/autonoship/Open_Simulation_Platform/my_demo/log"));
  std::cout << "Successfully added file observer!" << std::endl;
  
  
  // load scenario
  load_scenario(exe, "/home/chuanhui/research/autonoship/Open_Simulation_Platform/my_demo/scenarios/autopilot_test_scenario.json", cosim::to_time_point(0.0));
  exe.simulate_until(cosim::to_time_point(1200.0)).get();
  
  return 0;
}
