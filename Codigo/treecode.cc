/** @file treecode.cc
    @brief Implementación de la clase <em>Treecode</em>.
*/

#include "treecode.hh"

Treecode::Treecode(){
    BinTree<pair<string,int> > t;
    map<string,string> c;
}

Treecode::~Treecode(){}

bool cond(BinTree<pair<string,int>> a1, BinTree<pair<string,int>> a2){
    if(a1.value().second == a2.value().second) return a1.value().first < a2.value().first;
    return a1.value().second < a2.value().second;
}

void Treecode::completa_tree(Frecuencia& f){
    map<string,int>::iterator it = f.inici();
    list<BinTree<pair<string,int>> > l;
    while(not f.acaba(it)){
        pair<string,int> p = f.elem(it);
        BinTree<pair<string,int> > tree;
        tree = BinTree<pair<string,int>> (p);
        l.insert(l.begin(),tree);
        f.aumenta(it);
    }
    //lista con todos los pares string-frecuencia como nodos de árboles, ordenados según su frecuencia
    l.sort(cond);
    list<BinTree<pair<string,int>>>::iterator it2 = l.begin();
    while(l.size()>1){
        it2 = l.begin();
        BinTree<pair<string,int>> b1 = (*it2);
        it2 = l.erase(it2);
        BinTree<pair<string,int>> b2 = (*it2);
        it2 = l.erase(it2);
        pair<string,int> p;
        p.second = b1.value().second + b2.value().second;
        if(b1.value().first < b2.value().first) p.first = b1.value().first + b2.value().first;
        else p.first = b2.value().first + b1.value().first;
        BinTree<pair<string,int>> b (p,b1,b2);
        //unión de los dos subarboles de menor frecuencia
        while(it2!= l.end() and not cond(b,*it2)) ++it2;
        l.insert(it2,b);
    }
    t = *(l.begin());
    string s = "";
    c.clear();
    completa_codi(t,s);
}

void Treecode::completa_codi(const BinTree<pair<string,int>>& tree,string& s){
    if(not tree.empty()){
        if(tree.left().empty() and tree.right().empty()){
            pair<string,string> p;
            p.first = tree.value().first;
            p.second = s;
            c.insert(p);
            s.pop_back();
        }
        else{
            s += "0";
            completa_codi(tree.left(),s);
            s += "1";
            completa_codi(tree.right(),s);
            if(s.size()!=0) s.pop_back();
        }
    }
}

void Treecode::decodif(string& s){
    bool correcte = true;
    string p = "";
    int pos,last;
    pos = last = 0;
    if(s[pos] == '0') i_decodif(s,p,pos+1,last,correcte,t.left());
    else i_decodif(s,p,pos+1,last,correcte,t.right());
    if(correcte) cout << p << endl;
    else cout << "El texto no procede de una codificacion del idioma; ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar: " << last << endl;
}

void Treecode::i_decodif(const string& s, string& p, int pos, int& last, bool& correcte, const BinTree<pair<string,int>>& tree){
    if(not tree.empty()){
        if(tree.left().empty() and tree.right().empty()){
            string aux = tree.value().first;
            p+=aux;
            last = pos;
            if(s.length()!=pos) i_decodif(s,p,pos,last,correcte,t);
        }
        else{
            if(s.length() == pos) correcte = false;
            else{
                if(s[pos] == '1') i_decodif(s,p,pos+1,last,correcte,tree.right());
                else i_decodif(s,p,pos+1,last,correcte,tree.left());
            }   
        }
    }
}


void Treecode::codif(string& s){
    bool correcte = true;
    int i = 0;
    string out, aux;
    while(i<s.length() and correcte){
        if(s[i]>=0){
            aux = string(1,s[i]);
            ++i;
        }
        else{
            aux = string(s, i, 2);
            i+=2;
        }
        map<string,string>::iterator it = c.find(aux);
        if(it == c.end()) correcte = false;
        else{
            string cod = it->second;
            out+= cod;
        }
    }
    if(correcte) cout << out << endl;
    else cout << "El texto no pertenece al idioma; primer caracter que falla: " << aux << endl;
}

void Treecode::imprime_preorden(){
    i_preorden(t);
}

void Treecode::i_preorden(const BinTree<pair<string,int>>& tre){
    if(not tre.empty()){
        BinTree<pair<string,int>> ti, td;
        ti = tre.left();
        td = tre.right();
        cout << tre.value().first << ' ' << tre.value().second << endl;
        i_preorden(ti);
        i_preorden(td);
    }
}

void Treecode::imprime_inorden(){
    i_inorden(t);
}

void Treecode::i_inorden(const BinTree<pair<string,int>>& tre){
    if(not tre.empty()){
        BinTree<pair<string,int>> ti, td;
        ti = tre.left();
        td = tre.right();
        i_inorden(ti);
        cout << tre.value().first << ' ' << tre.value().second << endl;
        i_inorden(td);
    }
}

void Treecode::imprime_codi(string& s){
    map<string,string>::iterator it = c.begin();
    if(s == "todos"){
        while(it != c.end()){
            cout << it->first << ' ' << it->second << endl;
            ++it;
        }
    }
    else{
        it = c.find(s);
        if(it==c.end()) cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
        else cout << it->first << ' ' << it->second << endl;
    }
}
