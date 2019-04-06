#include "WirelessTransmitterPlugin.hh"

using namespace gazebo;
GZ_REGISTER_SENSOR_PLUGIN(WirelessTransmitterPlugin)

/////////////////////////////////////////////////
WirelessTransmitterPlugin::WirelessTransmitterPlugin() : SensorPlugin()
{
}

/////////////////////////////////////////////////
WirelessTransmitterPlugin::~WirelessTransmitterPlugin()
{
}

/////////////////////////////////////////////////
void WirelessTransmitterPlugin::Load(sensors::SensorPtr _sensor, sdf::ElementPtr /*_sdf*/)
{
  // Get the parent sensor.
  this->parentSensor =
    std::dynamic_pointer_cast<sensors::WirelessTransmitter>(_sensor);

  // Make sure the parent sensor is valid.
  if (!this->parentSensor)
  {
    gzerr << "WirelessPlugin requires a WirelessTR.\n";
    return;
  }

  // Connect to the sensor update event.
  this->updateConnection = this->parentSensor->ConnectUpdated(
      std::bind(&WirelessTransmitterPlugin::OnUpdate, this));

  // Make sure the parent sensor is active.
  this->parentSensor->SetActive(true);

    std::cout << "wirelress tra active";
}

/////////////////////////////////////////////////
void WirelessTransmitterPlugin::OnUpdate()
{
     std::cout << "trans wireless signal";
     std::string power = "";
     power = this->parentSensor->GetName();
     std::cout << power << " \n";

}
