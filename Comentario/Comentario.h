#ifndef COMENTARIO_H
#define COMENTARIO_H

#pragma once
#include <ctime>

class Comentario
{
public:
    Comentario();
    Comentario(int idNumerico, time_t horaEnvio, char* texto);
    ~Comentario();

    int getIdNumerico();
    void setIdNumerico(int idNumerico);

    time_t getHoraEnvio();
    void setHoraEnvio(time_t horaEnvio);

    char* getText();
    void setText(char* text); 

    void enviarComentarios(char* comentario);
    //set<dtComentario> listarComentariosExistentes();
    void enviarComentarios(int idNumerico, char* comentario);

private:
    int idNumerico;
    time_t horaEnvio;
    char* text;
};
#endif
