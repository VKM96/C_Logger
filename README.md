C Logger                      {#mainpage}
============
    This is a simple lightweight logger for embedded systems with support for multiple log levels and formatted strings

**Code Structure**

1. Source files are present in @ref Src
2. Interface files are present in @ref inc
3. PLease refer doxygen generated HTML documentation in the Doc/html subfolder for implementation details
4. The function entry point is @ref Main.c

**Usage**

1. Initialization of the Logger is achieved through @ref LogInit in @ref Logger.h
2. At initialization the function for outputting to the console needs to be passed to @ref LogInit.
3. @ref UserPrint is to be implemented based on the platform, as an example @ref fwrite is used.
4. Messages will be logged based on the log level @ref eLoggingLevel_t


**Modification**

1. If longer messages are to logged change size of @ref LOG_DEBUG_BUF in @ref Logger.c
2. Additional log levels can be added to enum @ref eLoggingLevel_t
4. If formatted strings are needed in debug messages @ref FORMATTED_STRINGS_EN macro in @ref UsrConfig,h needs to be defined


**Permissions**

1. PLease refer to the LICENSE file 