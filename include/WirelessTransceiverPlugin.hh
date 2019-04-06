#ifndef _GAZEBO_WIRELESS_TRANSCEIVER_PLUGIN_HH_
#define _GAZEBO_WIRELESS_TRANSCEIVER_PLUGIN_HH_

#include <string>
#include <string>
#include <ignition/math/Pose3.hh>

#include "gazebo/transport/TransportTypes.hh"
#include "gazebo/physics/PhysicsTypes.hh"
#include "gazebo/sensors/Sensor.hh"
#include "gazebo/util/system.hh"
#include "gazebo/gazebo.hh"
#include "gazebo/sensors/sensors.hh"


namespace gazebo
{
  /// \brief Plugin for a wireless receiver sensor.
  class WirelessTransceiverPlugin : public SensorPlugin
  {
    /// \brief Constructor.
    public: WirelessTransceiverPlugin();

    /// \brief Destructor.
    public: virtual ~WirelessTransceiverPlugin();

    /// \brief Load the sensor plugin.
    /// \param[in] _sensor Pointer to the sensor that loaded this plugin.
    /// \param[in] _sdf SDF element that describes the plugin.
    public: virtual void Load(sensors::SensorPtr _sensor, sdf::ElementPtr _sdf);

    /// \brief Callback that receives the wireless receiver sensor's update signal.
    private: virtual void OnUpdate();

    /// \brief Pointer to the contact sensor
      private: transport::PublisherPtr pub;

    private: sensors::WirelessTransceiverPtr parentSensor;

    /// \brief Connection that maintains a link between the contact sensor's
    /// updated signal and the OnUpdate callback.
    private: event::ConnectionPtr updateConnection;
  };
}
#endif
