#pragma once
#include <cstdio>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
class SlConnection{
	private: 
		char *url = "ipinfo.io";
		CURL *curl;

	public:
		SlConnection(char*);
		void getIp();
		void setupUrl(char*);
		void initHttpRequest(bool);
		void setupParameters(char*);

};
