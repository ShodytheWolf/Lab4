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

    int getidNumerico() const;
    void setidNumerico(int idNumerico);
    char* gettexto() const;
    void settexto(char* texto);
    time_t gettime() const;
    void settime(time_t horaEnvio);
private:
    int idNumerico;
    time_t horaEnvio;
    char* text;
};
#endif
