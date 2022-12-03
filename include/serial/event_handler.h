#ifndef MAIN_SERIAL_EVENT_H
#define MAIN_SERIAL_EVENT_H

#include <functional>
#include <string>

#include "event/user_access.h"

struct event_handler { 
    std::function<std::string()> raw;
    std::function<user_access()> user_access;
};

#endif // MAIN_SERIAL_EVENT_H