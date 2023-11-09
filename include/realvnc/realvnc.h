#ifndef MAIN_REALVNC_REALVNC_H
#define MAIN_REALVNC_REALVNC_H

#include <memory>
#include <process.hpp>

class realvnc { 
private:
    std::shared_ptr<TinyProcessLib::Process> vnc_process;
    std::shared_ptr<TinyProcessLib::Process> dialog_process;
    std::string ip;
    int port;
    
public:
    realvnc(std::string ip, int port);
    bool start();
    bool stop();

    bool is_run() const;
};


#endif // MAIN_REALVNC_REALVNC_H