/** @file Treecode.hh
    @brief Especificación de la clase Treecode.
*/
#ifndef TREE_HH
#define TREE_HH

#include "frecuencia.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <string>
#include <map>
#include <list>
#include <algorithm>
#endif

class Treecode{
/** @class Treecode
    @brief Representa el treecode de un idioma.
    
    Dispone de un arbol binario con pares en cada nodo de palabras y su correspondiente frecuencia y de una tabla con el códgio correspondiente a cada palabra.
*/

private:
 
 /** @brief Arbol binario con los pares palabra-frecuencia de un idioma. */
 BinTree<pair<string,int> > t;
 /** @brief Tabla de códigos de un idioma. */
 map<string,string> c;

/** @brief Función de immersión para imprimir el treecode de un idioma en inorden.
    */
    void i_inorden(const BinTree<pair<string,int>>& tre);
    
    /** @brief Función de immersión para decodificar una palabra según un idioma.
    */
    void i_decodif(const string& s, string& p, int pos, int& last, bool& correcte, const BinTree<pair<string,int>>& tree);
    
    /** @brief Función de immersión para imprimir el treecode de un idioma en preorden.
    */
    void i_preorden(const BinTree<pair<string,int>>& tre);
    
    /** @brief Completa la tabla de códigos de un idioma.
    */
    void completa_codi(const BinTree<pair<string,int>>& tree, string& s);

public:
    //Creadora:
    
    /** @brief Creadora por defecto.
    
    Se ejecuta automáticamente al declarar un treecode.
    \pre <em>cierto</em>
    \post El resultado es un treecode no inicializado.
    */
    Treecode();
    
    
    //Destructora:
    
    /** @brief Destructora por defecto.
    
    Elimina automáticamente el objecto local al salir de un ámbito de visibilidad.
    \pre <em>cierto</em>
    \post El objeto local deja de existir.
    */
    ~Treecode();
    
    
    //Modificadora:
    
    /** @brief Completa un treecode según las frecuencias de cada palabra del idioma.
    \pre El parámetro implícito está inicializado.
    \post El resultado es un treecode completo.
    */
    void completa_tree(Frecuencia& f);
    
    
    //Acción:
    
    /** @brief Decodifica la palabra deseada.
    \pre El parámetro implícito está inicializado.
    \post El resultado es la palabra codificada según el idioma.
    */
    void codif(string& s);
    
    /** @brief Decodifica la palabra deseada.
    \pre El parámetro implícito está inicializado.
    \post El resultado es la palabra decodificada según el idioma.
    */
    void decodif(string& s);
    
    
    //Escritura:
    
    /** @brief Escribe en pantalla el treecode recorrido en preorden.
    \pre El parámetro implícito está inicializado.
    \post El resultado es el treecode correspondiente escrito en pantalla.
    */
    void imprime_preorden();
    
    /** @brief Escribe en pantalla el treecode recorrido en inorden.
    \pre El parámetro implícito está inicializado.
    \post El resultado es el treecode correspondiente escrito en pantalla.
    */
    void imprime_inorden();
    
    /** @brief Escribe en pantalla la tabla de códigos de un idioma.
    \pre El parámetro implícito está inicializado.
    \post El resultado es la tabla de codigos de un idioma escrita por pantalla.
    */
    void imprime_codi(string& s);
    
};
#endif
