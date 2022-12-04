#include <iostream>
#include <argument/parser.h>
#include <serial/serial.h>
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

    spdlog::info("Serial Port 관련 처리");
    serial ser;
    ser.event()->user_access = [](user_access data) { 
        spdlog::info("{}, {}, {}", data.failure, data.user_name, data.user_id);
    };
    spdlog::info("  - Callback event initialize");
    ser.open(op.baudrate, op.com);
    spdlog::info("open success");

    // ser.write("i am chacha and wow !!! text");
    
    while (true) { 
        ser.read();
    }

    ser.close();
    return 0;
}
