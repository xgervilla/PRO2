/** @file idiomas.cc
    @brief Implementación de la clase <em>Idiomas</em>.
*/

#include "idiomas.hh"

Idiomas::Idiomas(){
    map<string, Idioma> m;
}

Idiomas::~Idiomas(){}

void Idiomas::leer(){
    int n;
    cin >> n;
    for(int y = 0;y<n;++y){
        string s;
        cin >> s;
        Idioma i;
        i.llena(s);
        m.insert(make_pair(s,i));
    }
}

void Idiomas::modifica(string& s){
    if(m.find(s) == m.end()){
        Idioma i;
        i.llena(s);
        m.insert(make_pair(s,i));
        cout << "Anadido " << s << endl;
    }
    else{
        m[s].recalcula_frecuencia();
        m[s].completa_treecode();
        cout << "Modificado " << s << endl;
    }
    cout << endl;
}

void Idiomas::decodif_idiomas(string& s){
    string t;
    cin >> t;
    cout << "Decodifica en " << s << " el texto:" << endl;
    cout << t << endl;
    if(m.find(s) == m.end()) cout << "El idioma no existe" << endl << endl;
    else m[s].decodifica_idioma(t);
}

void Idiomas::codif_idiomas(string& s){
    string t;
    cin >> t;
    cout << "Codifica en " << s << " el texto:" << endl;
    cout << t << endl;
    if(m.find(s) == m.end()) cout << "El idioma no existe" << endl << endl;
    else m[s].codifica_idioma(t);
}

void Idiomas::codig_idiomas(string& s){
    string t;
    cin >> t;
    if(t!= "todos") cout << "Codigo de " << t << " en " << s << ':' << endl;
    else cout << "Codigos de " << s << ':' << endl;
    if(m.find(s) == m.end()){
        if(t == "todos") cout << "El idioma no existe" << endl << endl;
        else cout << "El idioma no existe o el caracter no esta en el idioma" << endl << endl;
    }
    else m[s].codi_idioma(t);
}

void Idiomas::treec_idiomas(string& s){
    cout << "Treecode de " << s << ':' << endl;
    if(m.find(s) == m.end()) cout << "El idioma no existe" << endl << endl;
    else m[s].tree_idioma();
}

void Idiomas::frecu_idiomas(string& s){
    cout << "Tabla de frecuencias de " << s << ':' << endl;
    if(m.find(s) == m.end()) cout << "El idioma no existe" << endl << endl;
    else m[s].frec_idioma();
}
