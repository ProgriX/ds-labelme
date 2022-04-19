#include <string>
#include <iostream>



#ifndef LOGGER_H
#define LOGGER_H

using namespace std;

class Logger
{
private:
    bool _isEnable;
    std::string _name;
public:
    Logger(std::string name, bool isEnable = true);
    ~Logger();

    void print(ostream& writeTo, std::string text);
    void printLog(std::string text);
    void printWarning(std::string text);
    void printError(std::string text);
    void forwardPrint(std::string text);
    void enable();
    void disable();
};

#endif // LOGGER_H