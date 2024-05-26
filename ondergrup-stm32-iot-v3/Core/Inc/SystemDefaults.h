#ifndef INC_SYSTEMDEFAULTS_H_
#define INC_SYSTEMDEFAULTS_H_

#include <string>
#include <array>

class SystemDefaults {
public:
    static SystemDefaults& getInstance() {
        static SystemDefaults instance;
        return instance;
    }

    // Disallow copy and assignment
    SystemDefaults(const SystemDefaults&) = delete;
    void operator=(const SystemDefaults&) = delete;

    static constexpr int machineIDCharacterLimit = 12;
    static constexpr int wifiCharacterLimit = 20;
    static constexpr int lcdBacklightSure = 6; // Value multiplied by 10. Max 90 seconds support.

    const std::string demoWifiSSID = "ONDERLIFT_PERSONEL";
    const std::string demoWifiPass = "PersonelOt2022*-";

    const std::string demoWifiSSIDEv = "Turna";
    const std::string demoWifiPassEv = "!?azxx!?1962edib1962";

    const std::string MAIN_SERVER = "http://85.95.231.92";
    const int MAIN_SERVER_PORT = 3000;
    const std::string MAIN_SERVER_WITH_PORT = MAIN_SERVER + ":" + std::to_string(MAIN_SERVER_PORT);

    std::array<char, 250> bufferTX;

    int idStartPos = 50;
    int ssidStartPos = 62;
    int passStartPos = 83;

    const std::string emptyArray = "                ";
    const std::string idCharactersArray = "0123456789";
    const std::string charactersArray = " abcdefghijklmnopqrstuvwxyzABCDEFGHIİJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=<>?";

    std::array<int, 10> eepromVal = {38, 39, 40, 41, 42, 43, 44, 45, 46, 47};
    std::array<int, 10> eepromFull = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int indeksSayisi = eepromVal.size();
    int eepromHataBaslangic = 38;

    // Flags
    static constexpr uint32_t UPDATE_FLAG_ADDRESS = 0x08003C00;  // Update address
    static constexpr uint32_t APPLICATION_ADDRESS = 0x08004000;  // Main program
    static constexpr uint32_t NEW_FIRMWARE_ADDRESS = 0x08008000;  // New firmware

private:
    SystemDefaults() {}
};

#endif /* INC_SYSTEMDEFAULTS_H_ */
