![](https://github.com/xonoxitron/MICRONYTE/blob/master/MICRONYTE.png?raw=true)

![](https://github.com/xonoxitron/MICRONYTE/blob/master/Screenshots/MICRONYTE.PNG?raw=true)

![](https://github.com/xonoxitron/MICRONYTE/blob/master/Screenshots/MICRONYTE TEST.PNG?raw=true)

 

CAPABILITIES
------------

-   Threaded

-   Easy

-   Customizable

 

USAGE
-----

Inside your .cpp source, include `MICRONYTE_DLL.h` and add the snippet above:

```
// SETUP WEB SERVER

MICRONYTE::SETTINGS::PORT = 8080;

MICRONYTE::SETTINGS::SERVER_NAME = "MICRONYTE \| MICRO C++ HTTP REST WEB
SERVER";

MICRONYTE::SETTINGS::CONTENT_TYPE = "text/html";

MICRONYTE::SETTINGS::CHARSET = "ISO-8859-1";

 

// SETUP A ROUTE

MICRONYTE::ACTION::AddRoute("GET","/hello/world", "hello world!");

	

// START WEB SERVER

std::thread t0(MICRONYTE::ACTION::StartWebServer);

t0.join();

 ```

 
