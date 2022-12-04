#ifndef MAIN_REALVNC_REALVNC_H
#define MAIN_REALVNC_REALVNC_H

#include <memory>
#include <process.hpp>

class realvnc { 
private:
    std::shared_ptr<TinyProcessLib::Process> process;
    
public:
    realvnc();
    bool start();
    bool stop();

    bool is_run() const;
};


#endif // MAIN_REALVNC_REALVNC_H