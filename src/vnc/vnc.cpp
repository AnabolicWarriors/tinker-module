#include <thread>
#include <string>

#include <realvnc/realvnc.h>
using namespace TinyProcessLib;

std::string get_vnc_cmd() { 
    std::string cmd = "/usr/bin/vncviewer";
    cmd += " 113.198.230.10:32752";
    cmd += " -FullScreen=1";
    cmd += " -HideCloseAlert=1";
    cmd += " -Scaling=Fit";
    cmd += " -Quality=Low";
    cmd += " -SecurityNotificationTimeout=0";
    return cmd;
}

std::string get_error_cmd() { 
    std::string cmd = "/usr/bin/zenity";
    cmd += " --error";
    cmd += " --text=\"사용자 인식 및 로그인이 필요합니다.\"";
    cmd += " --title=\"사용자 미인식 오류\"";
    cmd += " --width=300 --height=100";
    return cmd;
}

realvnc::realvnc() { 
    this->vnc_process = nullptr;
    this->dialog_process = nullptr;
}
bool realvnc::start() {
    if (this->vnc_process != nullptr) { 
        return false;
    }
    auto cmd = get_vnc_cmd();

    if (dialog_process != nullptr){ 
        this->dialog_process->kill(true);
        this->dialog_process = nullptr;
    }

    this->vnc_process = std::make_shared<TinyProcessLib::Process>(cmd);
    
    return true;
}

bool realvnc::stop() {
    if (this->dialog_process != nullptr) { 
        return false;
    }
    auto cmd = get_error_cmd();
    if (vnc_process != nullptr) { 
        this->vnc_process->kill(true);
        this->vnc_process = nullptr;
    }
    
    this->dialog_process = std::make_shared<TinyProcessLib::Process>(cmd);
    return true;
}
bool realvnc::is_run() const {
    return this->vnc_process != nullptr;
}


// $true@chacha@chacha#
// $false@chacha@chacha#
