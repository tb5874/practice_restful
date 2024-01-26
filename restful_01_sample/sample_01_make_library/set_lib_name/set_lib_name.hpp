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

#include <cpprest/http_listener.h>
#include <cpprest/http_client.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////

#define CATCH_MACRO \
catch (std::exception& e) {\
    printf("Func : %s() : Exception : %s\n", ((std::string)__func__).c_str(), e.what());\
}\
catch (...) {\
    printf("Func : %s() : Exception : unknown exception\n", ((std::string)__func__).c_str());\
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

class restful_core
{
    public:
        restful_core();
        ~restful_core();

    public:
        // listener = server = s
        void restful_s_open(std::string get_addr);
        void restful_s_close(void);
        void restful_s_setup(void);
        void restful_s_get(void);
        void restful_s_post(void);
        void restful_s_put(void);
        void restful_s_delete(void);
        utility::string_t restful_s_func01(void);
        utility::string_t restful_s_func02(void);
        web::http::experimental::listener::http_listener* restful_s; 
        web::http::experimental::listener::http_listener_config restful_s_cfg;
        std::string restful_s_addr;

    public:
        // listener = client = c
        void restful_c_open(std::string get_addr);
        void restful_c_close(void);
        void restful_c_setup(void);
        void restful_c_get(void);
        void restful_c_post(void);
        void restful_c_put(void);
        void restful_c_delete(void);
        web::http::client::http_client* restful_c;
        web::http::client::http_client_config restful_c_cfg;
        std::string restful_c_addr;

};

//////////////////////////////////////////////////////////////////////////////////////////////////////
