/**
 * @file Main.c
 * @author vishalK
 * @brief 
 * @version @ref VERSION
 * @date 2020-12-20
 * @bug No known bugs at the time of development
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include "Logger.h"

/**
 * @brief Printfunction to be registered with Logger
 * 
 * @param str String to be printed
 * @param len Len of the string to be printed
 * @note fwrite used for demonstartion, to be replaced with console write based on need 
 */
void UserPrint(const char* str,uint8_t len)
{
    fwrite(str, sizeof(char), len, stdout);
}

/**
 * @brief Function entry point, Initialization and logging of logger demonstrated
 * 
 * 
 * @return int 
 */
int main()
{
    /// Create Logger object 
    sLogger_t testLogger;

    /// Initialise logger with the log object created earlier @see LogInit
    LogInit(&testLogger , E_ALLLOG, UserPrint);

    /// Demonstration of logging unformatted string using @ref LogStr
    LogStr(&testLogger , E_ALLLOG ,"Unformatted string\n",sizeof("Unformatted string\n") );

    /// Demonstartion of formatted string logging @ref LogFStr
    LogFStr(&testLogger , E_ALLLOG, "%f\t %d\t %s \n",25.89,1200,"testing formatted strings") ;

    return 0;

}