#include "SlConnection.h"

SlConnection::SlConnection(char *url){
	this->url = url;
	curl_global_init(CURL_GLOBAL_DEFAULT);
	this->curl = curl_easy_init();
}


void SlConnection::getIp(){
	if(this->curl){
		this->initHttpRequest(false);
		//this->setupUrl("ipinfo.io");
		this->setupUrl("https://pokeapi.co/api/v2/");
		int res = curl_easy_perform(this->curl);
		json j = this->responseToJson();
		std::cout << j.dump();
		std::string a = j["ability"];
		json b;
		b["allo"] = 420;
		printf("\nslot: %s\n", j["berry"]);
		printf("b: %d\n", b["allo"]);
		curl_easy_reset(this->curl);
		curl_easy_cleanup(this->curl);
	}
}

json SlConnection::responseToJson(){
	json j = json::parse(this->reqData);
	return j;
}

void SlConnection::initHttpRequest(bool post){
	curl_easy_setopt(this->curl, CURLOPT_SSL_VERIFYPEER, 0L);
	curl_easy_setopt(this->curl, CURLOPT_SSL_VERIFYHOST, 0L);
	curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION, toJsonCallBack);
	curl_easy_setopt(this->curl, CURLOPT_WRITEDATA, &(this->reqData));
	curl_easy_setopt(this->curl, (post)? CURLOPT_POST : CURLOPT_HTTPGET, 1L);
}

void SlConnection::setupUrl(char *url){
	this->url = url;
	printf("url: %s\n", this->url);
	curl_easy_setopt(this->curl, CURLOPT_URL, url);
	
}

void SlConnection::setupParameters(char *data){
	curl_easy_setopt(this->curl, CURLOPT_POSTFIELDS, data); 
}

size_t toJsonCallBack(char *ptr, size_t size, size_t nmemb, std::string *userData){
	printf("size: %d\nnmemb: %d\n", size, nmemb);
	userData->append(ptr, 0, nmemb);
	return size * nmemb;
}
