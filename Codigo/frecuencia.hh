/** @file Frecuencia.hh
    @brief Especificación de la clase Frecuencia.
*/

#ifndef FREC_HH
#define FREC_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#endif
using namespace std;

class Frecuencia{
/** @class Frecuencia
    @brief Representa la tabla de frecuencias de un idioma.
    
    Dispone de una tabla con la frecuencia correspondiente a cada palabra de un idioma. 
*/

private:
    
 /** @brief Estructura de la tabla de frecuencias de un idioma. */
 map<string,int> f;
 
 /** @brief Iterador para completar ciertas operaciones. */
 map<string,int>::iterator it;
    
public:
    //Creadora:
    
    /** @brief Creadora por defecto.
    
    Se ejecuta automáticamente al declarar un código.
    \pre <em>cierto</em>
    \post El resultado es una frecuencia no inicializada.
    */
    Frecuencia();
    
    //Destructora:
    
    /** @brief Destructora por defecto.
    
    Elimina automáticamente el objecto local al salir de un ámbito de visibilidad.
    \pre <em>cierto</em>
    \post El objeto local deja de existir.
    */
    ~Frecuencia();
    
    //Consultoras para operaciones en la clase treecode
    
    /** @brief Iterador de tabla de frecuencias que apunta al primer elemento.
    \pre El parámetro implícito está inicializado.
    \post Devuelve un iterador que apunta al primer elemento de la tabla de frecuencias.
    */
    map<string,int>::iterator inici();
    
    /** @brief Devuelve el elemento apuntado por un iterador.
    \pre El parámetro implícito está inicializado, el iterador apunta a una posición correcta.
    \post Devuelve el objeto de la tabla de frecuencias apuntado por el iterador.
    */
    pair<string,int> elem(map<string,int>::iterator it);
    
    /** @brief Indica si el iterador que entra no es válido.
    \pre El parámetro implícito está inicializado.
    \post Devuelve cierto si y solo si el iterador el iterador apunta a f.end().
    */
    bool acaba(map<string,int>::iterator it);
    
    /** @brief Aumenta el valor del iterador que entra.
    \pre El parámetro implícito está inicializado.
    \post Devuelve un iterador que apunta al siguiente elemento.
    */
    void aumenta(map<string,int>::iterator& it);
    
    //Modificadora:
    
    /** @brief Completa la tabla de frecuencias de un idioma.
    \pre El parámetro implícito está inicializado.
    \post El resultado es la tabla de frecuencias completa de un idioma.
    */
    void completa_frec();
    
    /** @brief Recalcula la tabla de frecuencias de un idioma.
    \pre El parámetro implícitoestá inicializado.
    \post El resultado es la tabla de frecuencias modificada.
    */
    void recalcula_frec();
    
    //Escritura:
    
    /** @brief Escribe en pantalla la frecuencia del idioma deseado.
    \pre El parámetro implícito está inicializado.
    \post El resultado es la frecuencia del idioma deseado escrita por pantalla.
    */
    void imprime_frec();
    
};
#endif

