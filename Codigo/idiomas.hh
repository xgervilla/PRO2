/** @file Idiomas.hh
    @brief Especificación de la clase Idiomas.
*/

#ifndef IDIOMS_HH
#define IDIOMS_HH

#include "idioma.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#endif


class Idiomas{
/** @class Idiomas
    @brief Representa el conjunto de idiomas.
    
    Dispone de todos los idiomas identificados con su abecedario.
*/
    
private:

 /** @brief Estructura con todos los idiomas. */
 map<string, Idioma> m;
    
public:
    //Creadora:
    
    /** @brief Creadora por defecto.
    
    Se ejecuta automáticamente al declarar un conjunto de idiomas.
    \pre <em>cierto</em>
    \post El resultado es un conjunto de idiomas no inicializado.
    */
    Idiomas();
    
    //Destructora:
    
    /** @brief Destructora por defecto.
    
    Elimina automáticamente el objecto local al salir de un ámbito de visibilidad.
    \pre <em>cierto</em>
    \post El objeto local deja de existir.
    */
    ~Idiomas();
    
    //Entrada:
    
    /** @brief Hace la lectura inicial de un conjunto de idiomas.
    \pre El parámetro implícito está inicializado.
    \post El parámetro implícito pasa a contener los idiomas que entran por el puerto de escritura.
    */
    void leer();
    
    //Modificadoras:
    
    /** @brief Añade un idioma al conjunto de idiomas
    \pre El parámetro implícito está inicializado.
    \post El parámetro implícito pasa a contener sus idiomas originales mas el idioma añadido
    */
    void modifica(string& s);
    
    /** @brief Decodifica un código según un idioma.
    \pre El parámetro implícito está inicializado.
    \post Escribe el código decodificado según el idioma
    */
    void decodif_idiomas(string& s);

    /** @brief Codifica una palabra según un idioma.
    \pre El parámetro implícito está inicializado.
    \post Escribe la palabra codificada según el idioma.
    */
    void codif_idiomas(string& s);
    
    //Consultoras:
    
    /** @brief Consulta los códigos de un idioma
    \pre El parámetro implícito está inicializado.
    \post Escribe los código del idioma deseado.
    */
    void codig_idiomas(string& s);
    
    /** @brief Consulta el treecode de un idioma
    \pre El parámetro implícito está inicializado.
    \post Escribe los treecodes del idioma deseado (en inorden y preorden)
    */
    void treec_idiomas(string& s);
    
    /** @brief Consulta la tabla de frecuencias de una palabra concreta o de todas.
    \pre El parámetro implícito está inicializado
    \post Escribe la frecuencia que corresponde a la palabra deseada del idioma correspondiente.
    */
    void frecu_idiomas(string& s);
    
};
#endif
