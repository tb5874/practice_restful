#include <for_dll.hpp>
#include <set_lib_name.hpp>

restful_sc::restful_sc() {

    try {

        p_core = new restful_core;

    }
    CATCH_MACRO

}

restful_sc::~restful_sc() {

    try {

        delete p_core;

    }
    CATCH_MACRO

}

void restful_sc::restful_s_open(std::string get_addr) {

    try {

        ((restful_core*)p_core)->restful_s_open(get_addr);

    }
    CATCH_MACRO

}

void restful_sc::restful_c_open(std::string get_addr) {

    try {

        ((restful_core*)p_core)->restful_c_open(get_addr);

    }
    CATCH_MACRO

}
