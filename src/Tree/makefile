proj4.x: proj4_driver.o bet.o
	g++ -o proj4.x bet.o proj4_driver.o

bet.o: bet.cpp bet.h
    g++ -c -std=c++11 bet.cpp

proj4_driver.o: proj4_driver.cpp bet.h
	g++ -c -std=c++11 proj4_driver.cpp

clean:
	rm *.o *.x
