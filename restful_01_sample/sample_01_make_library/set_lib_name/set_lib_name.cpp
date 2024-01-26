#include <set_lib_name.hpp>

restful_core::restful_core() {

    try {

        //

    }
    CATCH_MACRO

}

restful_core::~restful_core() {

    try {

        restful_s_close();
        restful_c_close();

    }
    CATCH_MACRO

}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void restful_core::restful_s_open(std::string get_addr) {

    try {

        restful_s_addr = get_addr;
        
        restful_s_cfg.set_timeout( utility::seconds(10) ); // server response wait seconds

        utility::string_t temp_addr;
        temp_addr.assign(restful_s_addr.begin(), restful_s_addr.end());
        restful_s = new web::http::experimental::listener::http_listener( temp_addr, restful_s_cfg );

        restful_s_setup();

        restful_s->open().wait();

    }
    CATCH_MACRO

    return;

}

void restful_core::restful_s_close(void) {

    try {

        restful_s->close();
        delete restful_s;
        restful_s = nullptr;

    }
    CATCH_MACRO

    return;

}

void restful_core::restful_s_setup(void) {

    try {

        restful_s_get();
        restful_s_post();
        restful_s_put();
        restful_s_delete();

    }
    CATCH_MACRO

    return;

}

void restful_core::restful_s_get(void) {

    try {

        web::http::experimental::listener::http_listener* s = restful_s;

        s->support(\
            web::http::methods::GET,\
            [this, s](web::http::http_request req) mutable\
            // lambda function : -->
            {
                utility::string_t temp_req[4] = { U(""), };

                temp_req[0].append(U("\n"));
                temp_req[0].append(U("******************* server to client respond *******************\n"));

                // get info from client request
                temp_req[1].append(U("get info from client : address : ")               + req.remote_address() + U("\n"));
                temp_req[1].append(U("get info from client : method : ")                + req.method() + U("\n"));
                temp_req[1].append(U("get info from client : request_uri : ")           + req.request_uri().to_string() + U("\n"));

                // server URI ( Uniform Resource Identifier )
                temp_req[1].append(U("server send info to client : URI : path : ")        + s->uri().path() + U("\n"));
                temp_req[1].append(U("server send info to client : URI : scheme : ")      + s->uri().scheme() + U("\n"));
                temp_req[1].append(U("server send info to client : URI : user_info : ")   + s->uri().user_info() + U("\n"));
                temp_req[1].append(U("server send info to client : URI : host : ")        + s->uri().host() + U("\n"));
                temp_req[1].append(U("server send info to client : URI : port : ")        + std::to_wstring(s->uri().port()) + U("\n"));
                temp_req[1].append(U("server send info to client : URI : query : ")       + s->uri().query() + U("\n"));
                temp_req[1].append(U("server send info to client : URI : fragment : ")    + s->uri().fragment() + U("\n"));

                // function call test
                temp_req[2].append(U("server call func : "));
                if (req.request_uri() == U("/KA_Shell")) {
                    temp_req[2].append( restful_s_func01() + U("\n") );
                }
                else if (req.request_uri() == U("/KA_Shell2")) {
                    temp_req[2].append( restful_s_func02() + U("\n") );
                }
                else {
                    temp_req[2] = U("");
                }

                temp_req[0] = temp_req[0] + temp_req[1] + temp_req[2];

                temp_req[0].append(U("******************* server to client respond *******************\n"));

                // server to client
                req.reply(web::http::status_codes::OK, temp_req[0]);

            }
            // lambda function : <--
        );

    }
    CATCH_MACRO

    return;

}

void restful_core::restful_s_post(void) {

    try {

        //

    }
    CATCH_MACRO

    return;

}

void restful_core::restful_s_put(void) {

    try {

        //

    }
    CATCH_MACRO

    return;

}

void restful_core::restful_s_delete(void) {

    try {

        //

    }
    CATCH_MACRO

    return;

}

utility::string_t restful_core::restful_s_func01(void) {

    try {

        //

    }
    CATCH_MACRO

    return U("restful_s_func01()");

}

utility::string_t restful_core::restful_s_func02(void) {

    try {

        //

    }
    CATCH_MACRO

    return U("restful_s_func02()");

}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void restful_core::restful_c_open(std::string get_addr) {

    try {

        restful_c_addr = get_addr;

        restful_c_cfg.set_timeout(utility::seconds(10)); // client response wait seconds

        utility::string_t temp_addr;
        temp_addr.assign(restful_c_addr.begin(), restful_c_addr.end());
        restful_c = new web::http::client::http_client(temp_addr, restful_c_cfg);

        restful_c_setup();

    }
    CATCH_MACRO

    return;

}

void restful_core::restful_c_close(void) {

    try {

        delete restful_c;
        restful_c = nullptr;

    }
    CATCH_MACRO

    return;

}

void restful_core::restful_c_setup(void) {

    try {

        restful_c_get();

    }
    CATCH_MACRO

    return;

}

void restful_core::restful_c_get(void) {
    try {

        web::http::client::http_client* c = restful_c;
        web::uri_builder builder( U("/KA_Shell") );
        c->request(\
            web::http::methods::GET, builder.to_string()).then\
                ([&builder](web::http::http_response resp) mutable\
                    // lambda function : -->
                    {
                        std::wcout << "******************* only cmd view *******************"   << std::endl;
                        std::wcout << "client to server request : request URI : "               << builder.to_string() << std::endl;
                        std::wcout << "client to server request : status_code : "               << resp.status_code() << std::endl;
                        std::wcout << "client to server request : reason_phrase : "             << resp.reason_phrase() << std::endl;
                        std::wcout << "client to server request : headers-content_length : "    << resp.headers().content_length() << std::endl;
                        std::wcout << "client to server request : headers-date : "              << resp.headers().date() << std::endl;
                        std::wcout << "client to server request : headers-content_type : "      << resp.headers().content_type() << std::endl;
                        std::wcout << "******************* only cmd view *******************"   << std::endl;

                        resp.extract_string(true).then\
                            ([](utility::string_t sBoby)\
                                // lambda function : -->
                                {
                                    std::wcout << sBoby << std::endl;
                                }
                                // lambda function : <--
                            ).wait();

                    }
                ).wait();
                // lambda function : <--

    }
    CATCH_MACRO

    return;

}

void restful_core::restful_c_post(void) {

    try {

        //

    }
    CATCH_MACRO

    return;

}

void restful_core::restful_c_put(void) {

    try {

        //

    }
    CATCH_MACRO

    return;

}

void restful_core::restful_c_delete(void) {

    try {

        //

    }
    CATCH_MACRO

    return;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////
