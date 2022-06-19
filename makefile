all: plataforma

DATAS = dtCategoria.o dtPartidaIndividual.o dtPartidaMultijugador.o enumSuscripcion.o enumPago.o dtVideoJuego.o dtJugador.o

plataforma: main.o 
	$(GXX) -o $@ main.o

main.o: main.cpp Fabrica.o IControlador.o
	$(GXX) -c $^

Fabrica.o: Fabrica/Fabrica.cpp Controlador.o IControlador.o
	$(GXX) -c $^

IControlador.o: IControlador/IControlador.cpp $(DATAS)
	$(GXX) -c $^

#Datatypes:

dtCategoria.o: Datatypes/dtCategoria.cpp
	$(GXX) -c $^

dtJugador.o: Datatypes/dtJugador.cpp	
	$(GXX) -c $^

dtPartidaIndividual.o: Datatypes/dtPartidaIndividual.cpp dtPartida.o 
	$(GXX) -c $^

dtPartidaMultijugador.o: Datatypes/dtPartidaMultijugador.cpp dtPartida.o
	$(GXX) -c $^

dtPartida.o: Datatypes/dtPartida.cpp
	$(GXX) -c $^

dtVideoJuego.o: Datatypes/dtVideoJuego.cpp	
	$(GXX) -c $^

dtEstadistica.o: Datatypes/dtEstadistica.cpp
	$(GXX) -c $^

dtSuscripcion.o: Datatypes/dtSuscripcion.cpp
	$(GXX) -c $^

#Collecciones:

OrderedDictionary.o: colecciones-genericas/collections/OrderedDictionary.cpp OrderedDictionaryEntry.o ListNode.o IDictionary.o
	$(GXX) -c $^

OrderedDictionaryEntry.o: colecciones-genericas/collections/OrderedDictionaryEntry.cpp OrderedKey.o ICollectible.o
	$(GXX) -c $^

List.o: colecciones-genericas/collections/List.cpp ListNode.o
	$(GXX) -c $^

ListIterator.o: colecciones-genericas/collections/ListIterator.cpp ListNode.o
	$(GXX) -c $^

ListNode.o: colecciones-genericas/collections/ListNode.cpp ICollection.o
	$(GXX) -c $^

#Interfaces de colleciones:

IDictionary.o: colecciones-genericas/interfaces/IDictionary.cpp IKey.o ICollectible.o IIterator.o
	$(GXX) -c $^

ICollection.o: colecciones-genericas/interfaces/ICollection.cpp IIterator.o
	$(GXX) -c $^

IIterator.o: colecciones-genericas/interfaces/IIterator.cpp ICollectible.o
	$(GXX) -c $^

OrderedKey.o: colecciones-genericas/interfaces/OrderedKey.cpp IKey.o
	$(GXX) -c $^

IKey.o: colecciones-genericas/interfaces/IKey.cpp
	$(GXX) -c $^

ICollectible.o: colecciones-genericas/interfaces/ICollectible.cpp
	$(GXX) -c $^


clear:
	rm -f plataforma *.o *.out

