/**
 * @mainpage Practica de diseño modular: Gestión de un conjunto de idiomas.
 
En esta practica se construye un programa modular que ofrece un menú de opciones para gestionar un conjunto de idiomas. Se introducen las clases <em>Idiomas</em>, <em>Idioma</em>, <em>Frecuencia</em> y <em>Treecode</em>.

*/

/** @file program.cc
    @brief Programa principal para el ejercicio <em>Gestión de un conjunto de idiomas</em>.
*/

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif
#include "idiomas.hh"
using namespace std;

/** @brief Programa principal para la practica <em>Gestión de un conjunto de idiomas</em>
*/

int main(){
    string inst;
    Idiomas m;
    m.leer();
    while(cin >> inst and inst!= "fin"){
        string s;
        cin >> s;
        //idioma al que afecta la instrucción
        
        if(inst == "anadir/modificar") m.modifica(s);
        else if(inst == "codifica") m.codif_idiomas(s);
        else if(inst == "decodifica") m.decodif_idiomas(s);
        if(inst == "codigos") m.codig_idiomas(s);
        else if(inst == "tabla_frec") m.frecu_idiomas(s);
        else if(inst == "treecode") m.treec_idiomas(s);
    }
}
