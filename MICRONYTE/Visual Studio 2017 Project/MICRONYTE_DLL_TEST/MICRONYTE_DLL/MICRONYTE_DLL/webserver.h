/*
   webserver.h
*/

#include <string>
#include <map>

class Socket;

class webserver {
  public:
    struct http_request {
    
      http_request() : authentication_given_(false) {}
    
      Socket*                            s_;
      std::string                        method_;
      std::string                        path_;
      std::map<std::string, std::string> params_;

      std::string                        accept_;
      std::string                        accept_language_;
      std::string                        accept_encoding_;
      std::string                        user_agent_;
    
      /* status_: used to transmit server's error status, such as
         o  202 OK
         o  404 Not Found 
         and so on */
      std::string                        status_;
    
      /* auth_realm_: allows to set the basic realm for an authentication,
         no need to additionally set status_ if set */
      std::string                        auth_realm_;
    
      std::string                        answer_;
    
      /*   authentication_given_ is true when the user has entered a username and password.
           These can then be read from username_ and password_ */
      bool authentication_given_;
      std::string username_;
      std::string password_;
    };

    typedef   void (*request_func) (http_request*);
    webserver(unsigned int port_to_listen, request_func);


  private:
    static unsigned __stdcall Request(void*);
    static request_func request_func_;
};
