#include <iostream>
#include <argument/parser.h>
#include <serial/serial.h>
#include <realvnc/realvnc.h>
#include <happyhttp/server.h>

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
    spdlog::info("  - vnc ip : {}", op.vnc_ip);
    spdlog::info("  - api : {}", op.api_ip);
    spdlog::info("  - vnc port : {}", op.vnc_port);
    spdlog::info("  - api port : {}", op.api_port);

    realvnc vnc = realvnc(op.vnc_ip, op.vnc_port);
    vnc.stop();
    
    cloud_server cs;
    bool network_connection = false;

    if (true) { 
        cs.start(op.api_ip, op.api_port, [&network_connection](std::string recv) { 
            if (recv == "{\"flag\":true}") { 
                network_connection = true;
            }else { 
                
                network_connection = false;
            }
            spdlog::info("network connection : {}", network_connection);
        }, 10);
    }
      
    spdlog::info("Serial Port 관련 처리");
    serial ser;

    ser.event()->user_access = [&vnc, &network_connection](user_access data) { 
        spdlog::info("{}, {}, {}", data.failure, data.user_name, data.user_id);
        // true && 실행중 X
        if (data.failure && !vnc.is_run() && network_connection) { 
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
