all: steam
GXX = g++

DATAS = dtCategoria.o dtPartidaIndividual.o dtPartidaMultijugador.o dtVideoJuego.o dtJugador.o
VJDEP= ICollection.o List.o IDictionary.o OrderedDictionary.o Categoria.o Suscripcion.o dtSuscripcion.o Estadistica.o Desarrollador.o
JGDEP= Usuario.o Videojuego.o dtPartidaIndividual.o dtPartidaMultijugador.o ICollection.o Individual.o Multijugador.o Registro.o
steam: main.o Fabrica.o IControlador.o Controlador.o Jugador.o Registro.o Contratacion.o Videojuego.o Categoria.o Desarrollador.o Usuario.o Anual.o Mensual.o Trimestral.o Vitalicia.o Suscripcion.o Estadistica.o Individual.o EnVivo.o Multijugador.o Partida.o Comentario.o dtCategoria.o dtJugador.o dtPartidaIndividual.o dtPartidaMultijugador.o dtPartida.o dtVideoJuego.o dtEstadistica.o dtSuscripcion.o String.o Integer.o OrderedDictionary.o OrderedDictionaryEntry.o List.o ListIterator.o ListNode.o IDictionary.o ICollection.o IIterator.o OrderedKey.o IKey.o ICollectible.o
	@$(GXX) -o $@ $^ 

main.o: main.cpp IControlador.o Fabrica.o 
	@$(GXX) -c $^

Fabrica.o: Fabrica/Fabrica.cpp IControlador.o Controlador.o  #1
	@$(GXX) -c $^

IControlador.o: IControlador/IControlador.cpp $(DATAS) #2
	@$(GXX) -c $^

Controlador.o: Controlador/Controlador.cpp Usuario.o Categoria.o Videojuego.o #3
	@$(GXX) -c $^

Jugador.o: Jugador/Jugador.cpp $(JGDEP) #4
	@$(GXX) -c $^

Registro.o: Registro/Registro.cpp dtVideoJuego.o Contratacion.o ICollectible.o ICollection.o List.o #5
	@$(GXX) -c $^

Contratacion.o: Contratacion/Contratacion.cpp Videojuego.o #6
	@$(GXX) -c $^

Videojuego.o: Videojuego/Videojuego.cpp dtVideoJuego.o $(VJDEP) #7
	@$(GXX) -c $^

Categoria.o: Categoria/Categoria.cpp String.o ICollectible.o dtCategoria.o #8
	@$(GXX) -c $^

Desarrollador.o: Desarrollador/Desarrollador.cpp Usuario.o #9
	@$(GXX) -c $^

Usuario.o: Usuario/Usuario.cpp ICollectible.o String.o #10
	@$(GXX) -c $^

Anual.o: Suscripcion/Anual.cpp Suscripcion.o
	@$(GXX) -c $^

Mensual.o: Suscripcion/Mensual.cpp Suscripcion.o
	@$(GXX) -c $^

Trimestral.o: Suscripcion/Trimestral.cpp Suscripcion.o
	@$(GXX) -c $^

Vitalicia.o: Suscripcion/Vitalicia.cpp Suscripcion.o
	@$(GXX) -c $^

Suscripcion.o: Suscripcion/Suscripcion.cpp ICollectible.o #11
	@$(GXX) -c $^

Estadistica.o: Estadistica/Estadistica.cpp ICollectible.o dtEstadistica.o String.o #12
	@$(GXX) -c $^

Individual.o: Individual/Individual.cpp Partida.o #13
	@$(GXX) -c $^

EnVivo.o: EnVivo/EnVivo.cpp Multijugador.o ICollection.o List.o Comentario.o #14
	@$(GXX) -c $^

Multijugador.o: Multijugador/Multijugador.cpp Partida.o #15
	@$(GXX) -c $^

Comentario.o: Comentario/Comentario.cpp ICollectible.o ICollection.o List.o #17
	@$(GXX) -c $^
	
Partida.o: Partida/Partida.cpp dtPartida.o ICollectible.o String.o Integer.o #16
	@$(GXX) -c $^


#Datatypes:

dtCategoria.o: Datatypes/dtCategoria.cpp
	@$(GXX) -c $^

dtJugador.o: Datatypes/dtJugador.cpp	
	@$(GXX) -c $^

dtPartidaIndividual.o: Datatypes/dtPartidaIndividual.cpp dtPartida.o 
	@$(GXX) -c $^

dtPartidaMultijugador.o: Datatypes/dtPartidaMultijugador.cpp dtPartida.o
	@$(GXX) -c $^

dtPartida.o: Datatypes/dtPartida.cpp
	@$(GXX) -c $^

dtVideoJuego.o: Datatypes/dtVideoJuego.cpp	
	@$(GXX) -c $^

dtEstadistica.o: Datatypes/dtEstadistica.cpp
	@$(GXX) -c $^

dtSuscripcion.o: Datatypes/dtSuscripcion.cpp
	@$(GXX) -c $^

#String key:

String.o: colecciones-genericas/String.cpp ICollectible.o OrderedKey.o	
	@$(GXX) -c $^

#Integer key:

Integer.o: colecciones-genericas/Integer.cpp ICollectible.o OrderedKey.o
	@$(GXX) -c $^


#Collecciones:

OrderedDictionary.o: colecciones-genericas/collections/OrderedDictionary.cpp OrderedDictionaryEntry.o ListNode.o IDictionary.o
	@$(GXX) -c $^

OrderedDictionaryEntry.o: colecciones-genericas/collections/OrderedDictionaryEntry.cpp OrderedKey.o ICollectible.o
	@$(GXX) -c $^

List.o: colecciones-genericas/collections/List.cpp ListNode.o
	@$(GXX) -c $^

ListIterator.o: colecciones-genericas/collections/ListIterator.cpp ListNode.o
	@$(GXX) -c $^

ListNode.o: colecciones-genericas/collections/ListNode.cpp ICollection.o
	@$(GXX) -c $^

#Interfaces de colleciones:

IDictionary.o: colecciones-genericas/interfaces/IDictionary.cpp IKey.o ICollectible.o IIterator.o
	@$(GXX) -c $^

ICollection.o: colecciones-genericas/interfaces/ICollection.cpp IIterator.o
	@$(GXX) -c $^

IIterator.o: colecciones-genericas/interfaces/IIterator.cpp ICollectible.o
	@$(GXX) -c $^

OrderedKey.o: colecciones-genericas/interfaces/OrderedKey.cpp IKey.o
	@$(GXX) -c $^

IKey.o: colecciones-genericas/interfaces/IKey.cpp
	@$(GXX) -c $^

ICollectible.o: colecciones-genericas/interfaces/ICollectible.cpp
	@$(GXX) -c $^


clear:
	rm -f steam *.o *.out

