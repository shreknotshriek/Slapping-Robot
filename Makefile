output: main.o motorController.a SlConnection.so
	g++ -Wall main.o motorController.a SlConnection.so -pthread -lrt -lcurl -lcrypt -o slp

main.o: main.cpp
	g++ -c main.cpp

motorController.a: motorController.cpp motorController.h
	g++ -shared -c motorController.cpp -lwiringPi -pthread -lrt -lcrypt -o motorController.so
	ar rvs motorController.a motorController.so /usr/local/lib/libwiringPi.so

SlConnection.so: SlConnection.cpp SlConnection.h
	g++ -shared -c SlConnection.cpp -o SlConnection.so


clean: 
	rm *.o slp *.so *.a
