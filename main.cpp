#include <iostream>
#include <argument/parser.h>
#include <serial/serial.h>

using namespace std;

int main(int argc, char** argv) { 
    auto opr = parser(argc, argv);
    if (!get<0>(opr)) { 
        cout << "\n완전한 입력이 되지 못하였습니다.\n";
        return 0;
    }

    auto op = get<1>(opr);

    serial ser;

    ser.open(op.baudrate, op.com);

    ser.write("i am chacha and wow !!! text");
    ser.read();

    ser.close();
    return 0;
}
