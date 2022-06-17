#ifndef COMENTARIO_H
#define COMENTARIO_H

#pragma once
#include <ctime>
#include <iostream>
#include "../colecciones-genericas/interfaces/ICollectible.h"
#include "../colecciones-genericas/interfaces/ICollection.h"
#include "../colecciones-genericas/collections/List.h"


using namespace std;
class Comentario : public ICollectible
{
public:
    Comentario();
    Comentario(int idNumerico, time_t horaEnvio, string texto);
    ~Comentario();

    int getIdNumerico();
    void setIdNumerico(int idNumerico);

    time_t getHoraEnvio();
    void setHoraEnvio(time_t horaEnvio);

    string getText();
    void setText(string text); 

    void enviarComentarios(string comentario);
    //set<dtComentario> listarComentariosExistentes();
    void enviarComentarios(int idNumerico, char* comentario); 

private:
    int idNumerico; //key
    time_t horaEnvio;
    string text;
    ICollection* respuesta = new List();
};
#endif
