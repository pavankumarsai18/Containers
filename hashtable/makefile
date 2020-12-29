#Venkata Vadrevu
#COP4530
#vv18d
executables: proj5.o sproj5.o passserver.o
	g++ -lcrypt -o proj5.x proj5.o passserver.o
	g++ -lcrypt -o sproj5.x sproj5.o passserver.o

proj5.o: proj5.cpp passserver.h
	g++ -c -std=c++11 proj5.cpp

sproj5.o: sproj5.cpp passserver.h
	g++ -c -std=c++11 sproj5.cpp

passserver.o: passserver.cpp passserver.h
	g++ -c -std=c++11  passserver.cpp

clean:
	rm *.o
	rm *.x











