#ifndef MAIN_REALVNC_REALVNC_H
#define MAIN_REALVNC_REALVNC_H

#include <process.hpp>

class realvnc { 
private:
    TinyProcessLib::Process* process;
    
public:
    realvnc();
    bool start();
    bool stop();

    bool is_run() const;
};


#endif // MAIN_REALVNC_REALVNC_H