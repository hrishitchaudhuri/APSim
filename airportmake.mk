a.out: airportclient.o airportserver.o
	gcc airportclient.o airportserver.o
airportclient.o: airportclient.c airportserver.h
	gcc -c airportclient.c airportserver.h
airportserver.o: airportserver.c airportserver.h
	gcc -c airportserver.c airportserver.h