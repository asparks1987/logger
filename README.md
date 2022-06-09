# logger
My simple logging script. I lost the project file and cant for the life of me remember where i gleaned the code from. 

to use the logger you can either call the constructor by its name LOG and use your object to log plain text to console, or you can call the constructor using a file name such as Log* myLogger = newLog("./newLog.txt); which will log to console as well as your file. The logger requires a simple configuration which should be done in your "Main" file. Simply call "structlog LOGCFG" and in any of your other files simple include log.h and call "extern structlog LOGCFG". All entities within can be changed via the "." operand. struclog myLog; myLog.Headers=true, myLog.loglevel=DEBUG;

Logging is as simple as myLogger(DEBUG)<<"this is logged to wherever i have configured it to";
