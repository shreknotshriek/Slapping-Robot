#include <cstdio>
#include "motorController.h"
#include "SlConnection.h"

int main(){
    //MotorController *mc = new MotorController(0, 0.5f);
	SlConnection *con = new SlConnection("https://streamlabs.com/api/v1.0/authorize");
	//SlConnection *con = new SlConnection("https://pokeapi.co/api/v2/");
	con->getIp();
	return 1;
}
