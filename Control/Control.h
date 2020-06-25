#include <iostream>
#include "Connector.h"

namespace Control {

const char control_frame_character = '!';
const int movement_frame_size = 3;

struct movement_control{
    int right;
    int left;
};

struct manipulator_control{
    int axis_1;
    int axis_2;
    int axis_3;
};

class Controler{

public:

private:
    ET_Connection::Connector* connector;

public:
    Controler();
    Controler(ET_Connection::Connector* connector);

    ~Controler();

    void Control(char* data);

};

}
