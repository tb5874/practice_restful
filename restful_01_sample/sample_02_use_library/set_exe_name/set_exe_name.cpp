#include <set_exe_name.hpp>

int main(void) {
    try {
        empty_lib();
    }
    catch (std::exception e) {
        printf("Exception : %s\n", e.what());
    }
    catch (...) {
        printf("Exception : unknown exception.\n");
    }

    return 0;
}
