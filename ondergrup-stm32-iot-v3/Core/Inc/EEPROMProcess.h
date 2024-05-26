/*
 * EEPROMProcess.h
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#ifndef INC_EEPROMPROCESS_H_
#define INC_EEPROMPROCESS_H_

#include <stdint.h>

class EEPROMProcess {
public:
    static EEPROMProcess& getInstance();

    void eepromKontrol();
    void firstSetup();
    void convertArrays(int state);

private:
    EEPROMProcess();
    EEPROMProcess(const EEPROMProcess&) = delete;
    EEPROMProcess& operator=(const EEPROMProcess&) = delete;
};

#endif /* INC_EEPROMPROCESS_H_ */

