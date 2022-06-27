#include <iostream>
#include "string.h"

using namespace std;

/**
 * @brief LUCAS DEVUELVE TRUE SI ENCUENTRA p EN l
 * 
 */
bool verificarEnLista(string** l, string p){
    int i = 0;
    while(l[i]){
        if(*l[i] == p)
            return true;
        i++;
    }
    return false;
}