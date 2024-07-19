/*
 * IoTMenu.h
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#ifndef INC_IOTMENU_H_
#define INC_IOTMENU_H_

class IoTMenu {
public:
	static IoTMenu& getInstance();

    void printTemplate(int type, int page);
    int checkSlideVal(int state);
    void slideText(const char* text, int startPos, int startLine, int state);
    void printCredentials(int type);

private:
    IoTMenu() = default;
    IoTMenu(const IoTMenu&) = delete;
    IoTMenu& operator=(const IoTMenu&) = delete;
};

#endif /* INC_IOTMENU_H_ */
