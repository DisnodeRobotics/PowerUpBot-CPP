#pragma once
#include <iostream>
#include <string.h>
#include "../termcolor/termcolor.hpp"

using namespace std;
class Logger{


    public:

        
        static void Info(string className, string functionName, string toLog);
		static void Warning(string className, string functionName, string toLog);
		static void Error(string className, string functionName, string toLog);
		static void Success(string className, string functionName, string toLog);
};