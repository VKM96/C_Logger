/**
 * @file Logger.c
 * @author vishalK
 * @brief Logging initialization and Logging functions implemented here 
 * @date 2020-12-20
 * 
 */

#include <stdint.h>
#include "Logger.h"
#include "UsrConfig.h"

#ifdef FORMATTED_STRINGS_EN
#include <stdarg.h>
#include <stdio.h>
#endif

static const uint8_t LOG_DEBUG_BUF = 128 ; /**> Buffer size for logging, vary according to need*/

/**
 * @brief Initialization function for logger
 * 
 * @param pLogger @ref sLogger_t object pointer to initialize
 * @param logLevel Inital log level @ref eLoggingLevel_t
 * @param pfUsrPrint Appplication print function to be registered with logger @ref pfUserprint
 */
void LogInit(sLogger_t* pLogger,eLoggingLevel_t logLevel , pfUserprint pfUsrPrint )
{
    pLogger->LoggingLevel = logLevel;

    pLogger->pLogPrintFunc = pfUsrPrint;
}

/**
 * @brief Set the current log level
 * 
 * @param pLogger pLogger @ref sLogger_t object pointer to initialize
 * @param logLevel Inital log level @ref eLoggingLevel_t
 */
void LogSetLevel(sLogger_t* pLogger,eLoggingLevel_t logLevel)
{
  pLogger->LoggingLevel = logLevel ;
}

/**
 * @brief Function to log simple unformatted strings
 * 
 * @param pLogger pLogger @ref sLogger_t object pointer whose log member print function will be invoked
 * @param logLevel the log message will only be printed if the loglevel passed is above the current loglevel @ref eLoggingLevel_t
 * @param str unformatted string to be logged
 * @param len Length of string @ref str
 */
void LogStr(sLogger_t* pLogger,eLoggingLevel_t logLevel,const char* str,uint8_t len)
{
    uint8_t PresLogLevel = pLogger->LoggingLevel ;

    /// If log message level is higher than current log level, print message
    if(logLevel >= PresLogLevel)
    {
        pLogger->pLogPrintFunc(str,len);
    }

}

/**
 * @brief Function to log Formatted strings
 * 
 * @param pLogger pLogger pLogger @ref sLogger_t object pointer whose log member print function will be invoked
 * @param logLevel the log message will only be printed if the loglevel passed is above the current loglevel @ref eLoggingLevel_t
 * @param str unformatted string to be logged
 * @param format format of strint to print like %d %f etc
 * @param ... formatted strint to be logged
 * @note To use this function @ref FORMATTED_STRINGS_EN needs to be defined in @ref UsrConfig.h
 * @note example usage :LogFStr(pLogger,logLevel,"%d %f %c",int,float,char) ;
 */
void LogFStr(sLogger_t* pLogger,eLoggingLevel_t logLevel,const char* format,...)
{
    #ifdef FORMATTED_STRINGS_EN

    uint8_t PresLogLevel = pLogger->LoggingLevel ;
    uint8_t buf[LOG_DEBUG_BUF];
	uint8_t len_fstring;

    /// make variadic list of formatted string, fill up buf and pass to application level print function
    va_list vl;
    va_start(vl,format);
    len_fstring=vsnprintf((char *)buf,sizeof(buf),(const char *)format,vl);
    va_end(vl);

    /// If log message level is higher than current log level, print message
    if(logLevel >= PresLogLevel)
    {
        pLogger->pLogPrintFunc((const char*)buf,len_fstring);
    }

    #else

    LogStr( pLogger,logLevel,"fstrings disabled\n",sizeof("fstrings disabled\n") );

    #endif

}
