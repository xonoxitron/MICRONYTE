#pragma once
#ifdef MICRONYTE_DLL_EXPORTS
#define MICRONYTE_DLL_API __declspec(dllexport) 
#else
#define MICRONYTE_DLL_API __declspec(dllimport) 
#endif
#include <string>
#include <vector>
using namespace std;
namespace MICRONYTE
{
	namespace SETTINGS
	{
		static int PORT = 8080;
		static string SERVER_NAME = "MICRONYTE | MICRO C++ HTTP REST WEB SERVER";
		static string CONTENT_TYPE = "text/html";
		static string CHARSET = "ISO-8859-1";
	}

	namespace TEMPLATE
	{
		struct ROUTE
		{
			string METHOD;
			string PATH;
			string RESPONSE;
		};
	}

	static vector<MICRONYTE::TEMPLATE::ROUTE> ROUTES;

	static class ACTION
	{
		public:
			static MICRONYTE_DLL_API void StartWebServer();
			static MICRONYTE_DLL_API void AddRoute(string METHOD, string PATH, string RESPONSE);
	};
}

