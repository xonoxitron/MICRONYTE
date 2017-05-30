#include "stdafx.h"
#include "webserver.h"
#include "socket.h"
#include <iostream>
#include "MICRONYTE_DLL.h"

using namespace std;

void MICRONYTE::ACTION::AddRoute(string _METHOD, string _PATH, string _RESPONSE)
{
	cout << "\n\tSTATUS: MICRONYTE::ACTION::AddRoute(string _METHOD, string _PATH, string _RESPONSE) Method Invoked";
	MICRONYTE::TEMPLATE::ROUTE ROUTE;
	ROUTE.METHOD = _METHOD;
	ROUTE.PATH = _PATH;
	ROUTE.RESPONSE = _RESPONSE;
	cout << "\n\tSTATUS: MICRONYTE::ROUTE::METHOD is \"" + _METHOD + "\"";
	cout << "\n\tSTATUS: MICRONYTE::ROUTE::PATH is \"" + _PATH + "\"";
	cout << "\n\tSTATUS: MICRONYTE::ROUTE::RESPONSE is \"" + _RESPONSE + "\"";
	MICRONYTE::ROUTES.push_back(ROUTE);
	cout << "\n\tSTATUS: MICRONYTE::ROUTE added to MICRONYTE::ROUTES vector";
}

void ROUTER(webserver::http_request* r) 
{
	for (auto ROUTE = MICRONYTE::ROUTES.begin(); ROUTE != MICRONYTE::ROUTES.end(); ++ROUTE)
	{
		if (r->method_ == ROUTE->METHOD && r->path_ == ROUTE->PATH)
		{
			Socket s = *(r->s_);
			r->answer_ = ROUTE->RESPONSE;
			cout << "\n\tSTATUS: MICRONYTE::WEB_SERVER answered to the incoming request with the response \"" + ROUTE->RESPONSE + "\"";
		}
		else
		{
			Socket s = *(r->s_);
			r->answer_ = "NOT ALLOWED";
			cout << "\n\tERROR: ROUTE::METHOD or ROUTE::PATH not matching with the current REQUEST";
		}
	}
}

void MICRONYTE::ACTION::StartWebServer()
{
	webserver(MICRONYTE::SETTINGS::PORT, ROUTER);
}