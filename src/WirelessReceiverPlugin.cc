#include "WirelessReceiverPlugin.hh"

using namespace gazebo;
GZ_REGISTER_SENSOR_PLUGIN(WirelessReceiverPlugin)

/////////////////////////////////////////////////
WirelessReceiverPlugin::WirelessReceiverPlugin() : SensorPlugin()
{
}

/////////////////////////////////////////////////
WirelessReceiverPlugin::~WirelessReceiverPlugin()
{
}

/////////////////////////////////////////////////
void WirelessReceiverPlugin::Load(sensors::SensorPtr _sensor, sdf::ElementPtr /*_sdf*/)
{
  // Get the parent sensor.
  this->parentSensor =
    std::dynamic_pointer_cast<sensors::WirelessReceiver>(_sensor);

  // Make sure the parent sensor is valid.
  if (!this->parentSensor)
  {
    gzerr << "WirelessReceiverPlugin requires a WirelessReceiver.\n";
    return;
  }

  // Connect to the sensor update event.
  this->updateConnection = this->parentSensor->ConnectUpdated(
      std::bind(&WirelessReceiverPlugin::OnUpdate, this));

  // Make sure the parent sensor is active.
  this->parentSensor->SetActive(true);

    std::cout << "wirelress receiver active";
}

/////////////////////////////////////////////////
void WirelessReceiverPlugin::OnUpdate()
{
     std::cout << "recieved wireless signal";
     double power = 0.0;
     power = this->parentSensor->GetSensitivity();
     std::cout << power << " \n";

}
