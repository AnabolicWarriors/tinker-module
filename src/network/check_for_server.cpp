#include <happyhttp/server.h>
#include <happyhttp/network.hpp>
#include <spdlog/spdlog.h>

#include <unistd.h>

bool cloud_server::start(std::string ip, int port, std::function<void(std::string)> callback, int duration) { 
    if (this->run) { 
        return false;
    }
    this->duration = duration;
    this->run = true;

    loop = std::thread([&](std::string ip, int port, std::function<void(std::string)> callback) { 
        
        int dur = this->get_duration();

        while (this->run) { 
            {
                netowrk nwtp(ip, port);
                nwtp.request("/flag", "");
                nwtp.wait();
                auto data = nwtp.recv_body();
                spdlog::info("recv : {}", data);
                callback(data);
            }
            sleep(dur);
        }

    }, ip, port, callback);
    
    return true;
}

bool cloud_server::close() { 
    if (!this->run) { 
        return false;
    }

    this->run = false;
    return true;
}

bool cloud_server::is_run() const { 
    return this->run;
}

int cloud_server::get_duration() const { 
    return this->duration;
}