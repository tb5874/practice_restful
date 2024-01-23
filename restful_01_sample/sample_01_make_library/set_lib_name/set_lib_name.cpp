#include <set_lib_name.hpp>

void empty_lib(void) {
    try {
        printf("Hello world !!!\n");
    }
    catch (std::exception e) {
        printf("Exception : %s\n", e.what());
    }
    catch (...) {
        printf("Exception : unknown exception.\n");
    }

    return;
}