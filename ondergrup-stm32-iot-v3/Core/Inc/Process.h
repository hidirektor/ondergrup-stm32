/*
 * Process.h
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#ifndef INC_PROCESS_H_
#define INC_PROCESS_H_

#include <cstdint>

class Process {
public:
    static Process& getInstance() {
        static Process instance;
        return instance;
    }

    // Disallow copy and assignment
    Process(const Process&) = delete;
    void operator=(const Process&) = delete;

    void lcdUpdate(uint8_t y);
    void bekle();
    void checkLCDBacklight();
    uint8_t buttonCheck();
    void checkBasincSalteri();
    void checkBasGonder();
    void checkKapiSecimleri();
    void checkAktifCalisma();
    void checkDemoModCalisma();
    void mainLoop();

private:
    Process() {}
};

#endif /* INC_PROCESS_H_ */
