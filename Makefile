output: main.o motorController.o
	g++ -Wall main.o motorController.so -o slp 
	#-lwiringPi -pthread -lrt -lcrypt

motorController.so: motorController.o
	g++ -l motorController.so -lwiringPi -pthread -lrt -lcrypt

main.o: main.cpp
	g++ -c main.cpp

motorController.o: motorController.cpp motorController.h
	g++ -shared -c motorController.cpp -lwiringPi -pthread -lrt -lcrypt -o motorController.so

clean: 
	rm *.o slp 
