#include <iostream>
#include "Control.h"
#include "Telemetrics.h"

using namespace std;

int main(int argc, char *argv[])
{
    int port = DEFAULT_PORT;
    ET_Connection::Connector* connector = new ET_Connection::Connector();
    if (argc < 2){
        std::cout<<"no port number provided, using default port 2020"<<std::endl;
    } else {
       port = atoi(argv[1]);
    }
    connector->connect_to_server(argv[2], port);
    Control::Controler* main_control_unit = new Control::Controler(connector);
    Telemetrics::Telemetry* telemetry = new Telemetrics::Telemetry(connector);
    char buffer[BUFFER_SIZE]; // TODO use Control Module data member
    while(1){
        //reading should be asynchronous
        int size = connector->receive_data(buffer);
        main_control_unit->Control(buffer);

        //TODO telemetry should be sent asynchornously
        telemetry->send_telemetry(10.0, 14.4);
    }
    return 0;
}
