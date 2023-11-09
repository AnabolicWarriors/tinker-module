#ifndef MAIN_ARGUMENT_OPTION_H
#define MAIN_ARGUMENT_OPTION_H

#include <string>

struct option
{
    std::string com;
    int baudrate;
    std::string vnc_ip;
    std::string api_ip;
    int vnc_port;
    int api_port;
};

#endif // MAIN_ARGUMENT_OPTION_H