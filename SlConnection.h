#pragma once
#include <cstdio>
#include <curl/curl.h>

class SlConnection{
	private: 
		char *url = "ipinfo.io";
		CURL *curl;

	public:
		SlConnection(char*);
		void getIp();


	private:
		void setupUrl(char*);
		void initHttpRequest(bool);

};
