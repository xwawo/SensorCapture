#include "../../../Documents/SpeedDreams/src/modules/sensors/mindwave/mindwave.cpp"
#include "../../../Documents/SpeedDreams/src/modules/sensors/arduinoFing/arduinoFing.cpp"
#include <thread>
#include <iostream>
#include <conio.h>

int main()
{
    mindwave mw; // Create an instance of the mindwave class
    arduinoFing ar;

    std::thread mindwaveThread([&]() {
        mw.Start();
        });

    std::thread arduinoThread([&]() {
        ar.start();
        });

    // Wait for 'k' key press to stop both threads
    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 'k') {
                mw.Stop();
                ar.stop();
                std::cout << "Capture stopped " << std::endl;
                break;
            }
        }

    }

    // Join the threads to ensure they finish properly before exiting
    mindwaveThread.join();
    arduinoThread.join();

    return 0;
}

