/**
 * @file SerialLutti.h
 * @brief Handle Serial communication
 * @author Lucas Seiti Taba
 * @date 06 Mar 2020
 */

#include "Arduino.h"

enum serial_command = {
    { "ENTRY_OPEN" },
    { "ENTRY_STOP" },
    { "ENTRY_RESUME" },
    { "ENTRY_CLOSE" },
    { "EXIT_OPEN" },
    { "EXIT_STOP" },
    { "EXIT_RESUME" },
    { "EXIT_CLOSE"}
};

/**
 * @class SerialLutti
 * @brief Has definition of valid serial commands
 * @param baud_rate
 */
class SerialLutti
{
    public:

    SerialLutti(int baud_rate);
    ~SerialLutti();

    int isCommandValid(serial_command cmd);

    private:

    int baud_rate;

}