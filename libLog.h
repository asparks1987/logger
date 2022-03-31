#ifndef LIBLOG_H
#define LIBLOG_H
#include <string>
#include <fstream>
#include <time.h>

#ifndef SSTR
#define SSTR( x ) static_cast< std::ostringstream & >(std::ostringstream()<<std::dec<<x).str()
#endif //SSTR

#ifndef ENDLINE
#define ENDLINE char(13)<<char(10)
#endif // ENDLINE

enum  typelog
{
    DEBUG,
    INFO,
    WARN,
    ERROR
};

struct structlog
{
    bool headers = false;
    typelog level = ERROR;
    std::string OutputFile="Default.log";
};
extern structlog LOGCFG;

class LOG
{   

public:
    LOG(std::string FileName);
    LOG(typelog type);

   template<class T>
    LOG &operator<<(const T &msg)
    {
        if(msglevel >= LOGCFG.level)
        {
            File.open(LOGCFG.OutputFile,std::ofstream::app);
            File << msg;
            File.close();
        }
        return *this;
    }
    ~LOG();
private:
    typelog msglevel = DEBUG;
    inline std::string getLabel(typelog type);
    std::string errorcode ="";
    bool newLog=false;
    const std::string currentDateTime();
    std::ofstream File;
};


#endif // LIBLOG_H
