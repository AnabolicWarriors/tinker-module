#include <iostream>
#include <serialib.h>

using namespace std;

int main(int argc, char** argv) { 
    serialib serial;
    

    // Connection to serial port
    char errorOpening = serial.openDevice("\\\\.\\COM4", 19200);

    // If connection fails, return the error code otherwise, display a success message
    if (errorOpening!=1) return errorOpening;
    printf ("Successful connection to %s\n","\\\\.\\COM4");


    // Display ASCII characters (from 32 to 128)
    serial.writeString("i am chacha i love you!");

    // Close the serial device
    serial.closeDevice();

    cout << "done";
    return 0;
}
