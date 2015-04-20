#include "ros/ros.h"
#include "flir_lepton_hardware_interface/flir_lepton_hardware_interface.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "flir_lepton_hardware_interface_node");
  FlirLeptonHardwareInterface flirLepron("/flir_lepton_hardware_interface");

  unsigned int rate;
  ros::NodeHandle("/flir_lepton_hardware_interface").param(
      "interface_rate", rate, 27);
  ros::Rate loop_rate(rate);

  while(ros::ok())
  {
    flirLepron.run();
    loop_rate.sleep();
  }

  return 0;
}
