all: a.out

a.out: airportclient.o airportserver.o
	gcc airportclient.o airportserver.o
airportclient.o: simulator/airportclient.c simulator/airportserver.h
	gcc -c simulator/airportclient.c simulator/airportserver.h
airportserver.o: simulator/airportserver.c simulator/airportserver.h
	gcc -c simulator/airportserver.c simulator/airportserver.h

clean:
	rm a.out airportclient.o airportserver.o simulator/airportserver.h.gch
