//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// [ notice ]
// 
// indent :  4 space
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <exception>
#include <iostream>
#include <string>

//////////////////////////////////////////////////////////////////////////////////////////////////////

#define CATCH_MACRO \
catch (std::exception& e) {\
    printf("Func : %s() : Exception : %s\n", ((std::string)__func__).c_str(), e.what());\
}\
catch (...) {\
    printf("Func : %s() : Exception : unknown exception\n", ((std::string)__func__).c_str());\
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

class restful_sc
{
    public:
        restful_sc();
        ~restful_sc();

    public:
        void restful_s_open(std::string get_addr);
        void restful_c_open(std::string get_addr);

    public:
        void* p_core;

};

//////////////////////////////////////////////////////////////////////////////////////////////////////