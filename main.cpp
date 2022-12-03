#include <iostream>
#include <serialib.h>
#include <argument/parser.h>


using namespace std;

int main(int argc, char** argv) { 
    auto opr = parser(argc, argv);
    if (!get<0>(opr)) { 
        cout << "\n완전한 입력이 되지 못하였습니다.\n";
        return 0;
    }

    auto op = get<1>(opr);

    serialib serial;
    
    // Connection to serial port
    char errorOpening = serial.openDevice(op.com.c_str(), op.baudrate);

    // If connection fails, return the error code otherwise, display a success message
    if (errorOpening!=1) return errorOpening;


    // Display ASCII characters (from 32 to 128)
    serial.writeString("i am chacha i love you!");

    // Close the serial device
    serial.closeDevice();

    cout << "done";
    return 0;
}
