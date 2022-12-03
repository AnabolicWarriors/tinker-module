#include <serial/serial.h>

char serial::open(int baudrate, std::string com) { 
    this->com = com;
    this->baudrate = baudrate;

    return this->lib.openDevice(com.c_str(), baudrate);
}
void serial::close() { 
    this->lib.closeDevice();
}

void serial::read() { 
    char text[256];
    this->lib.readString(text, '#', 256);

    std::string data = text;
    std::cout << data << "\n";
}
int serial::write(std::string data) { 
    return this->lib.writeString(data.c_str());
}

const event_handler* serial::event() const { 
    return &this->handler;
}

