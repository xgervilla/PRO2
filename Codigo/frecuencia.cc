/** @file frecuencia.cc
    @brief Implementación de la clase <em>Frecuencia</em>.
*/

#include "frecuencia.hh"

Frecuencia::Frecuencia(){
    map<string,int> f;
}

Frecuencia::~Frecuencia(){}

void Frecuencia::completa_frec(){
    int n;
    cin >> n;
    for(int i = 0; i<n; ++i){
        string s;
        int fr;
        cin >> s >> fr;
        f.insert(make_pair(s,fr));
    }
}

void Frecuencia::imprime_frec(){
    map<string,int>::iterator it = f.begin();
    while(it!=f.end()){
        cout << it->first << ' ' << it->second << endl;
        ++it;
    }
}

void Frecuencia::recalcula_frec(){
    Frecuencia f1;
    f1.completa_frec();
    map<string,int>::iterator it;
    map<string,int>::iterator it1 = f1.inici();
    while(not f1.acaba(it1)){
        pair<string,int> par = f1.elem(it1);
        string s = par.first;
        it = f.find(s);
        if(it == f.end()) f.insert(par);
        else it->second += par.second;
        f1.aumenta(it1);
    }
}

map<string,int>::iterator Frecuencia::inici(){
    it = f.begin();
    return it;
}

pair<string,int> Frecuencia::elem(map<string,int>::iterator it1){
    pair<string,int> p = *it1;
    return p;
}

bool Frecuencia::acaba(map<string,int>::iterator it1){
    return it1 == f.end();
}

void Frecuencia::aumenta(map<string,int>::iterator& it1){
    ++it1;
}
    
