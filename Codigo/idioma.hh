/** @file Idioma.hh
    @brief Especificación de la clase Idioma.
*/

#ifndef IDIOM_HH
#define IDIOM_HH

#include "frecuencia.hh"
#include "treecode.hh"

#ifndef NO_DIAGRAM
#include <string>
#endif

/** @class Idioma
    @brief Representa un idioma
    
    Dispone de todas las propiedades relacionadas con un idioma, que son su tabla de frecuencias, el código de todas sus palabras y el treecode que le corresponde. Se introducen las clases <em>Frecuencia</em> y <em>Treecode</em>.
*/


class Idioma{

private:

 /** @brief Identificador de un idioma. */
 string nombre;
 /** @brief Tabla de frecuencias de un idioma. */
 Frecuencia f;
 /** @brief Treecode de un idioma. */
 Treecode tree;


public:
    
    //Constructoras:
    
    /** @brief Creadora por defecto.
    
    Se ejecuta automáticamente al declarar un conjunto de idiomas.
    \pre <em>cierto</em>
    \post El resultado es un idioma no inicializado.
    */
    Idioma();
    
    /** @brief Creadora de un idioma con propiedades.
    \pre El parámetro implícito está inicializado.
    \post El resultado es un idioma con propiedades.
    */
    void llena(const string& s);
    
    
    //Destructora:
    
    /** @brief Destructora por defecto.
    
    Elimina automáticamente el objecto local al salir de un ámbito de visibilidad.
    \pre <em>cierto</em>
    \post El objeto local deja de existir.
    */
    ~Idioma();
    
    
    //Modificadoras:
    
    /** @brief Decodifica un código según un idioma.
    \pre El parámetro implícito está inicializado.
    \post Devuelve el codigo decodificado.
    */
    void decodifica_idioma(string& s);

    /** @brief Codifica una palabra.
    \pre El parámetro implícito está inicializado.
    \post Devuelve la palabra codificada.
    */
    void codifica_idioma(string& s);
    
    /** @brief Crea el treecode de un idioma.
    \pre El parámetro implícito está inicializado.
    \post El resultado es el treecode de un idioma.
    */
    void completa_treecode();
    
    /** @brief Recalcula la tabla de frecuencias de un idioma.
    \pre El parámetro implícito está inicializado.
    \post El resultado es la tabla de frecuencias de un idioma.
    */
    void recalcula_frecuencia();
    
    //Consultoras:
    
    /** @brief Consulta los códigos deseados de un idioma.
    \pre El parámetro implícito está inicializado.
    \post Escribe los código del idioma deseado.
    */
    void codi_idioma(string& s);
    
    /** @brief Consulta el treecode de un idioma.
    \pre El parámetro implícito está inicializado.
    \post Escribe los treecodes del idioma deseado (en inorden y preorden) por pantalla.
    */
    void tree_idioma();
    
    /** @brief Consulta la tabla de frecuencias de una palabra concreta o de todas.
    \pre El parámetro implícito está inicializado.
    \post Devuelve la frecuencia que corresponde a la palabra deseada
    */
    void frec_idioma();
    
};
#endif
