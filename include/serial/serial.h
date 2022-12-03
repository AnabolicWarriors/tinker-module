#ifndef MAIN_SERIAL_SERIAL_H
#define MAIN_SERIAL_SERIAL_H

#include <string>
#include <serialib.h>

#include "event_handler.h"

class serial { 
private:
    int baudrate;
    std::string com;
    serialib lib;
    event_handler handler;
public:
    char open(int baudrate, std::string com);
    void close();

    void read();
    int write(std::string);

    const event_handler* event() const;

};

#endif // MAIN_SERIAL_SERIAL_H