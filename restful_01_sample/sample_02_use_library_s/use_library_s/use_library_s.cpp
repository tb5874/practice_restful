#include <use_library_s.hpp>

int main(void) {
    try {

        restful_sc* restful_test = new restful_sc;

        while (true) {

            fprintf(stdout, "%s", "*** Input server address for open ***\n");
            fprintf(stdout, "%s", "default : http://127.0.0.1:9090\n");
            fprintf(stdout, "%s", ">>> ");
            fflush(stdout);

            char get_char[1024] = "";
            std::fgets(get_char, 1024, stdin);

            std::string get_string = "";
            get_string += get_char;
            get_string.erase(get_string.size() - 1, 2); // for delete "\n"

            if (get_string != "") {
                //restful_test->restful_s_open("http://127.0.0.1:9090");
                restful_test->restful_s_open(get_string);

                while (true) {
                    fflush(stdout);
                    char get_exit[1024] = "";
                    std::fgets(get_exit, 1024, stdin);
                    get_string = "";
                    get_string += get_exit;
                    get_string.erase(get_string.size() - 1, 2); // for delete "\n"
                    if (get_string == "exit") {
                        break;
                    }
                    else {
                        //
                    }
                }
                break;
            }
            else if (get_string == "") {
                //
            }
            else if (get_string == "exit") {
                break;
            }
            else {
                //
            }

        }

        delete restful_test;

    }
    CATCH_MACRO

    return 0;
}
