#include <thread>
#include <string>

#include <realvnc/realvnc.h>
using namespace TinyProcessLib;
std::string get_cmd() { 
    std::string cmd = "/usr/bin/vncviewer";
    cmd += " 113.198.230.10:32752";
    cmd += " -FullScreen=1";
    cmd += " -HideCloseAlert=1";
    cmd += " -Scaling=Fit";
    cmd += " -Quality=Low";
    cmd += " -SecurityNotificationTimeout=0";
    return cmd;
}

realvnc::realvnc() { 
    this->process = nullptr;
}
bool realvnc::start() {
    if (this->process != nullptr) { 
        return false;
    }
    std::string cmd = get_cmd();

    this->process = std::make_shared<TinyProcessLib::Process>(cmd);
    return true;
}

bool realvnc::stop() {
    if (this->process == nullptr) { 
        return false;
    }
    this->process->kill(true);
    this->process = nullptr;
    return true;
}
bool realvnc::is_run() const {
    return this->process != nullptr;
}


// $true@chacha@chacha#
// $false@chacha@chacha#
