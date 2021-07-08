/** @file idioma.cc
    @brief Implementación de la clase <em>Idioma</em>.
*/

#include "idioma.hh"

Idioma::Idioma(){
    string nombre;
    Frecuencia f;
    Treecode tree;
}

Idioma::~Idioma(){}

void Idioma::llena(const string& s){
    nombre = s;
    f.completa_frec();
    tree.completa_tree(f);
}

void Idioma::completa_treecode(){
    tree.completa_tree(f);
}

void Idioma::decodifica_idioma(string& s){
    tree.decodif(s);
    cout << endl;
}

void Idioma::codifica_idioma(string& s){
    tree.codif(s);
    cout << endl;
}

void Idioma::recalcula_frecuencia(){
    f.recalcula_frec();
}

void Idioma::codi_idioma(string& s){
    tree.imprime_codi(s);
    cout << endl;
}

void Idioma::tree_idioma(){
    cout << "recorrido en preorden:" << endl;
    tree.imprime_preorden();
    cout << "recorrido en inorden:" << endl;
    tree.imprime_inorden();
    cout << endl;
}

void Idioma::frec_idioma(){
    f.imprime_frec();
    cout << endl;
}
