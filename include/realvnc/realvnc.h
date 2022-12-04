#ifndef MAIN_ARGUMENT_OPTION_H
#define MAIN_ARGUMENT_OPTION_H

#include <process.hpp>

class realvnc { 
private:
    bool run;
    TinyProcessLib::Process* process;
    
public:
    bool start();
    bool stop();

    bool is_run() const;
};


#endif // MAIN_ARGUMENT_OPTION_H