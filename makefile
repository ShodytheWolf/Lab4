all: pltaforma

DATAS = dtCategoria.o dtPartidaIndividual.o dtPartidaMultijugador.o enumSuscripcion.o enumPago.o dtVideoJuego.o dtJugador.o

plataforma: main.o 
	@$(GXX) -o $@ main.o

main.o: main.cpp Fabrica.o IControlador.o
	@$(GXX) -c main.cpp Fabrica.o IControlador.o

Fabrica.o: Fabrica.cpp Controlador.o #seguir con el controlador.o
	@$(GXX) -c Fabrica/Fabrica.cpp Controlador.o

IControlador: IControlador.cpp $(DATAS)
	@$(GXX) -c IControlador/IControlador.cpp $(DATAS)

dtCategoria.o: dtCategoria.cpp
	@$(GXX) -c Datatypes/dtCategoria.cpp

dtJugador.o: dtJugador.cpp	
	@$(GXX) -c Datatypes/dtJugador.cpp

dtPartidaIndividual.o: dtPartidaIndividual.cpp dtPartida.o 
	@$(GXX) -c Datatypes/dtPartidaIndividual.cpp dtPartida.o

dtPartidaMultijugador.o: Datatypes/dtPartidaMultijugador.cpp dtPartida.o
	@$(GXX) -c $^

dtPartida.o: dtPartida.cpp
	@$(GXX) -c Datatypes/dtPartida.cpp

enumSuscripcion.o: enumSuscripcion.cpp
	@$(GXX) -c Enumeration/enumSuscripcion.cpp

enumPago.o: enumPago.cpp
	@$(GXX) -c Enumeration/enumPago.cpp

dtVideoJuego.o: dtVideoJuego.cpp	
	@$(GXX) -c Datatypes/dtVideoJuego.cpp



clear:
	rm -f plataforma *.o *.out

