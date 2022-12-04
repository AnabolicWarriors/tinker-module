#include <thread>
#include <string>

#include <realvnc/realvnc.h>

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

bool realvnc::start() {
    if (this->run) { 
        return false;
    }
    this->run = true;

    this->process = &TinyProcessLib::Process(get_cmd().c_str());
    return true;
}

bool realvnc::stop() {
    if (!this->run) { 
        return false;
    }
    this->process->kill(true);
    this->process = nullptr;
}
bool realvnc::is_run() const {

}
