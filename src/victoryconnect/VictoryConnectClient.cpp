#include "VictoryConnectClient.h"

VictoryConnectClient::VictoryConnectClient()
{
	tcpClient = new TCPClient();

}


bool VictoryConnectClient::Connect(string host)
{
    do
    {   

        Logger::Info("VictoryConnectClient", "Connect", "Connecting to server at: " + host);
        

        if (tcpClient->setup("pi4056.local", 5800))
        {
			Logger::Success("VictoryConnectClient", "Connect", "Connected to server!");
           // tcpClient->Send("0 0 id victory_cv");
			Logger::Info("VictoryConnectClient", "Connect", "Sent ID Packet.");
            connected = true;
            //thread tcpRecTread(VictoryConnectClient::recv_loop,tcpClient);
            //tcpRecTread.detach();
            return true;
        }
        else
        {
			Logger::Error("VictoryConnectClient", "Connect", "Failed to connect. Retrying in 3s");
            connected = false;

          //  sleep(3.0);
        }
    } while (connected == false);
}


bool VictoryConnectClient::SendPacket(int type, string topic, string value){
	if (connected) {
		return tcpClient->Send("0 " + to_string(type) + " " + topic + " {" + value + "}");
	}
	else {
		return false;
	}
    
}

void VictoryConnectClient::recv_loop(TCPClient *client)
{


    while (1)
    {

        string rec = client->receive();
        if (rec != "")
        {
            //cout << "Server Response:" << rec << endl;
            client->Send("0 0 heartbeat no_data");
        }
        sleep(0.1);
    }
}
