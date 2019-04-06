#include "WirelessTransceiverPlugin.hh"
#include "gazebo/transport/Publisher.hh"


using namespace gazebo;
GZ_REGISTER_SENSOR_PLUGIN(WirelessTransceiverPlugin)

/////////////////////////////////////////////////
WirelessTransceiverPlugin::WirelessTransceiverPlugin() : SensorPlugin()
{
}

/////////////////////////////////////////////////
WirelessTransceiverPlugin::~WirelessTransceiverPlugin()
{
}

/////////////////////////////////////////////////
void WirelessTransceiverPlugin::Load(sensors::SensorPtr _sensor, sdf::ElementPtr /*_sdf*/)
{
  // Get the parent sensor.
  this->parentSensor =
    std::dynamic_pointer_cast<sensors::WirelessTransceiver>(_sensor);

  // Make sure the parent sensor is valid.
  if (!this->parentSensor)
  {
    gzerr << "WirelessPlugin requires a WirelessTR.\n";
    return;
  }

  // Connect to the sensor update event.
  this->updateConnection = this->parentSensor->ConnectUpdated(
      std::bind(&WirelessTransceiverPlugin::OnUpdate, this));

  // Make sure the parent sensor is active.
  this->parentSensor->SetActive(true);

    std::cout << "wirelress tranceiver active";
}

/////////////////////////////////////////////////
void WirelessTransceiverPlugin::OnUpdate()
{
     
     transport::PublisherPtr pub;
     std::cout << "trans wireless signal";
     double power = 0.0;
     pub = this->parentSensor->GetPublisherPtr();
     std::cout << power << " \n";

}
