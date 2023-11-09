#ifndef MAIN_HAPPY_HTTP_SERVER_H
#define MAIN_HAPPY_HTTP_SERVER_H

#include <functional>
#include <thread>
#include <string>

class cloud_server { 
private:
    bool run = false;
    std::thread loop;
    int duration;

public:
    int get_duration() const;

    bool start(std::string ip, int port, std::function<void(std::string)> callback, int duration);
    bool close();

    bool is_run() const;
};


#endif // MAIN_HAPPY_HTTP_SERVER_H