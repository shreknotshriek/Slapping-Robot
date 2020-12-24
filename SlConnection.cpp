#include "SlConnection.h"

SlConnection::SlConnection(char *url){
	this->url = url;
	curl_global_init(CURL_GLOBAL_DEFAULT);
	this->curl = curl_easy_init();
}


void SlConnection::getIp(){
	if(this->curl){
		this->initHttpRequest(false);
		this->setupUrl(this->url);
		int res = curl_easy_perform(this->curl);
		printf("res: %f\n", res);
		curl_easy_reset(this->curl);
		curl_easy_cleanup(this->curl);
	}
}

void SlConnection::initHttpRequest(bool post){
	printf("setting up curl for https\n");
	curl_easy_setopt(this->curl, CURLOPT_SSL_VERIFYPEER, 0L);
	curl_easy_setopt(this->curl, CURLOPT_SSL_VERIFYHOST, 0L);

	curl_easy_setopt(this->curl, (post)? CURLOPT_POST : CURLOPT_HTTPGET, 1L);
}

void SlConnection::setupUrl(char *url){
	this->url = url;
	printf("url: %s\n", this->url);
	curl_easy_setopt(this->curl, CURLOPT_URL, url);
	
}
