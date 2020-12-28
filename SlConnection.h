#pragma once
#include <cstdio>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <string>

using namespace nlohmann;

size_t toJsonCallBack(char *ptr, size_t size, size_t nmemb, std::string *userdata);

class SlConnection{
	private: 
		char *url = "ipinfo.io";
		CURL *curl;
		std::string reqData = std::string();
		json* responseToJson();

	public:
		SlConnection(char*);
		void getIp();
		void setupUrl(char*);
		void initHttpRequest(bool);
		void setupParameters(char*);

};
