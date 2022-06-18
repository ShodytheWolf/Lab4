all: plataforma

DATAS = dtCategoria.o dtPartidaIndividual.o dtPartidaMultijugador.o enumSuscripcion.o enumPago.o dtVideoJuego.o dtJugador.o

plataforma: main.o 
	$(GXX) -o $@ main.o

main.o: main.cpp Fabrica.o IControlador.o
	$(GXX) -c main.cpp Fabrica.o IControlador.o

Fabrica.o: Fabrica/Fabrica.cpp Controlador.o #seguir con el controlador.o
	$(GXX) -c Fabrica/Fabrica.cpp Controlador.o

IControlador.o: IControlador/IControlador.cpp $(DATAS)
	$(GXX) -c IControlador/IControlador.cpp $(DATAS)

dtCategoria.o: Datatypes/dtCategoria.cpp
	$(GXX) -c Datatypes/dtCategoria.cpp

dtJugador.o: Datatypes/dtJugador.cpp	
	$(GXX) -c Datatypes/dtJugador.cpp

dtPartidaIndividual.o: Datatypes/dtPartidaIndividual.cpp dtPartida.o 
	$(GXX) -c Datatypes/dtPartidaIndividual.cpp dtPartida.o

dtPartidaMultijugador.o: Datatypes/dtPartidaMultijugador.cpp dtPartida.o
	$(GXX) -c $^

dtPartida.o: Datatypes/dtPartida.cpp
	$(GXX) -c Datatypes/dtPartida.cpp

enumSuscripcion.o: Enumeration/enumSuscripcion.h
	$(GXX) -c Enumeration/enumSuscripcion.h

enumPago.o: Enumeration/enumPago.h
	$(GXX) -c Enumeration/enumPago.h

dtVideoJuego.o: Datatypes/dtVideoJuego.cpp	
	$(GXX) -c Datatypes/dtVideoJuego.cpp

Controlador.o: Controlador/Controlador.cpp ICollection.o OrderedDictionary.o IDictionary.o
	$(GXX) -c $^

ICollection.o: colecciones-genericas/interfaces/ICollection.cpp IIterator.o
	$(GXX) -c $^

IIterator.o: colecciones-genericas/interfaces/IIterator.cpp ICollectible.o
	$(GXX) -c $^

ICollectible.o: colecciones-genericas/interfaces/ICollectible.cpp
	$(GXX) -c $^

OrderedDictionary.o: colecciones-genericas/collections/OrderedDictionary.cpp OrderedDictionaryEntry.o ListNode.o IDictionary.o
	$(GXX) -c $^

OrderedDictionaryEntry.o: colecciones-genericas/collections/OrderedDictionaryEntry.cpp OrderedKey.o ICollectible.o
	$(GXX) -c $^

OrderedKey.o: colecciones-genericas/interfaces/OrderedKey.cpp IKey.o
	$(GXX) -c $^

IKey.o: colecciones-genericas/interfaces/IKey.cpp
	$(GXX) -c $^

ListNode.o: colecciones-genericas/collections/ListNode.cpp ICollection.o
	$(GXX) -c $^

IDictionary.o: colecciones-genericas/interfaces/IDictionary.cpp IKey.o ICollectible.o IIterator.o
	$(GXX) -c $^


clear:
	rm -f plataforma *.o *.out

