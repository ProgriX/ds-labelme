#include "logger.h"

#include <chrono>
#include <iomanip>

const string colorYellow = "\e[33m";
const string colorGreen = "\e[32m";
const string colorRed = "\e[31m";
const string colorDefault = "\e[0m";

Logger::Logger(std::string name, bool isEnable)
{
    _isEnable = isEnable;
    _name = name;
}

Logger::~Logger()
{
    
}



void Logger::print(ostream &writeTo, std::string text){
    
    if(_isEnable){
        auto time_now = chrono::system_clock::now();

        time_t time_now_t = chrono::system_clock::to_time_t(time_now);
        time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
        
        writeTo << put_time(localtime(&time_now_t), "(%H:%M:%S %m.%d) ");
        writeTo << _name << ": ";
        writeTo << text << colorDefault << std::endl;
    }
}

void Logger::printLog(std::string text){
    print(cout, colorGreen + "LOG: " + text);
}

void Logger::printError(std::string text){
    print(cerr, colorRed + "ERROR: " + text);
}

void Logger::printWarning(std::string text){
    print(cerr, colorYellow + "WARNING: " + text);
}

void Logger::enable(){
    _isEnable = true;
}

void Logger::disable(){
    _isEnable = false;
}