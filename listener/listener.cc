
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/gazebo_client.hh>
#include <iostream>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstddef>
#include <sstream>

using namespace std;
int num = 1;
string s(30, '\0');
ofstream fw;
ofstream fr;
void cb(ConstWirelessNodesPtr &_msg);
void get_data(string id);

int main(int _argc, char **_argv) {
    time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    strftime(&s[0], s.size(), "%Y-%m-%d_%H:%M:%S\n", std::localtime(&now));
    fw.open("/home/archee8/rfid_test/log/" + s + ".txt", ios::app);
    fw << "Found tags:\n";
    fw.close();
    gazebo::client::setup(_argc, _argv);

    // Create our node for communication
    gazebo::transport::NodePtr node(new gazebo::transport::Node());
    node->Init();
    // Listen to Gazebo world_stats topic
    gazebo::transport::SubscriberPtr sub = node->Subscribe(
            "/gazebo/default/RFIDSensor/link/wirelessReceiver/transceiver", cb);

//  gazebo::transport::SubscriberPtr sub = node->Subscribe("/gazebo/default/px4_rfid/RFIDSensor/link/wirelessReceiver/transceiver", cb);

    // Busy wait loop...replace with your own code as needed.
    while (true) {
        gazebo::common::Time::MSleep(10);

    }
    // Make sure to shut everything down.
    gazebo::client::shutdown();
}

void cb(ConstWirelessNodesPtr &_msg) {
    int numNodes = _msg->node_size();
    cout << numNodes << " tags count \n";
    string essid = "";
    double signal = 0;


    for (int i = 0; i < numNodes; i++) {

        gazebo::msgs::WirelessNode Node = _msg->node(i);
        essid = Node.essid();
        signal = Node.signal_level();
        get_data(essid);

    }


}
void get_data(string id) {
    fw.open("/home/archee8/rfid_test/log/" + s + ".txt", ios::app);
    fw << num << ") " << id << " \n";
    num++;
    fw.close();

}