#include <iostream>
#include <argument/parser.h>
#include <serial/serial.h>
#include <realvnc/realvnc.h>

#include <spdlog/spdlog.h>

using namespace std;

int main(int argc, char** argv) { 
    auto opr = parser(argc, argv);
    if (!get<0>(opr)) { 
        cout << "\n완전한 입력이 되지 못하였습니다.\n";
        return 0;
    }
    auto op = get<1>(opr);

    spdlog::info("Argument 파싱 후 정상적으로 동작하였습니다.");
    spdlog::info("  - baudrate : {}", op.baudrate);
    spdlog::info("  - com : {}", op.com);

    realvnc vnc;
    vnc.stop();
      
    spdlog::info("Serial Port 관련 처리");
    serial ser;

    ser.event()->user_access = [&vnc](user_access data) { 
        spdlog::info("{}, {}, {}", data.failure, data.user_name, data.user_id);
        // true && 실행중 X
        if (data.failure && !vnc.is_run()) { 
            vnc.start();
        }// false && 실행중 O
        else if (!data.failure && vnc.is_run()) { 
            vnc.stop();
        }
    };
    ser.event()->raw = [](string data) { 
        spdlog::info("RAW : {}", data);
    };
    ser.event()->error = []() { 
        spdlog::info("ERROR Not Receive");
    };
    
    spdlog::info("  - Callback event initialize");
    ser.open(op.baudrate, op.com);
    spdlog::info("open success");

    ser.write("i am chacha and wow !!! text");
    // s
    while (true) { 
        ser.read();
    }

    ser.close();
    return 0;
}
