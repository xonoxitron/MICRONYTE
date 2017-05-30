// MICRONYTE_DLL_TEST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MICRONYTE_DLL.h"
#include <thread>
#include <vector>
#include <iostream>

int main()
{
	// DEVELOPER MARK

	cout << "   __  __ ___ ____ ____   ___  _   ___   _______ _____ "			<< endl;
	cout << "  |  \\\/  |_ _\/ ___|  _ \\ \/ _ \\| \\ | \\ \\ \/ |_   _| ____|" << endl;
	cout << "  | |\\\/| || | |   | |_) | | | |  \\| |\\ V \/  | | |  _|  "		<< endl;
	cout << "  | |  | || | |___|  _ <| |_| | |\\  | | |   | | | |___ "			<< endl;
	cout << "  |_|  |_|___\\____|_| \\_\\\\___\/|_| \\_| |_|   |_| |_____|"		<< endl;
	cout << "  Description: MICRO C++ HTTP REST WEB SERVER"						<< endl;
	cout << "  Version: 1.0"													<< endl;
	cout << "  Update: 29th May 2017"											<< endl;
	cout << "  Author: Matteo Pisani (matteo.pisani.91@gmail.com)"				<< endl;

	// SETUP WEB SERVER
	MICRONYTE::SETTINGS::PORT = 8080;
	MICRONYTE::SETTINGS::SERVER_NAME = "MICRONYTE | MICRO C++ HTTP REST WEB SERVER";
	MICRONYTE::SETTINGS::CONTENT_TYPE = "text/html";
	MICRONYTE::SETTINGS::CHARSET = "ISO-8859-1";

	// SETUP A ROUTE
	MICRONYTE::ACTION::AddRoute("GET","/hello/world", "hello world!");
	
	// START WEB SERVER
	std::thread t0(MICRONYTE::ACTION::StartWebServer);
	t0.join();
    return 0;
}

