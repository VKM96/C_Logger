/**
 * @file Logger.h
 * @author vishalK
 * @brief Logger interface file for @ref Logger.c
 * @date 2020-12-20
 * 
 */
#ifndef LOGGER_H
#define LOGGER_H

#include <stdint.h>
/**
 * @brief Function pointer to print function defined in the application layer
 * @note The application level print will have to match this signature and will be set in @ref LogInit
 * 
 */
typedef void (*pfUserprint)(const char* usr_string, uint8_t len);

/**
 * @brief Log levels
 * 
 */
typedef enum
{
    E_NOLOG = 0,    /**< No logging */
    E_HALLOG,       /**< HAL level logging */
    E_SYSTEMLOG,    /**< System level logging */
    E_APPLOG,       /**< Application level logging */
    E_ALLLOG        /**< Highest logging level*/
}eLoggingLevel_t;

/**
 * @brief Logger class with log level and function pointer to application level print
 * @see pfUserprint
 * @see LogInit
 * 
 */
typedef struct
{
    uint8_t LoggingLevel ;
    pfUserprint pLogPrintFunc ;

}sLogger_t;



void LogInit(sLogger_t* pLogger,eLoggingLevel_t logLevel , pfUserprint pfUsrPrint);

void LogSetLevel(sLogger_t* pLogger,eLoggingLevel_t logLevel);

void LogStr(sLogger_t* pLogger,eLoggingLevel_t logLevel,const char* str,uint8_t len);

void LogFStr(sLogger_t* pLogger,eLoggingLevel_t logLevel,const char* format,...);



#endif