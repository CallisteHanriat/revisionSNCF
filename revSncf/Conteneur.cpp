#ifdef CONTENEUR_H

#include <vector>
#include "NombreContraint.h"
#include "Conteneur.h"
using namespace std;

template <class TypeClass>
Conteneur<TypeClass>* Conteneur<TypeClass>::instance = nullptr;

template <class TypeClass>
Conteneur<TypeClass>::Conteneur() 
{
}

template <class TypeClass>
void Conteneur<TypeClass>::afficher(std::ostream& cout) const{
    for (auto elem : this->contenu){
        cout << *elem << "\n";
    }
}

template <class TypeClass>
void Conteneur<TypeClass>::ajouter(const TypeClass & t) {
    contenu.push_back(&t);
}


/**
 * 
 * @param cout pour les sorties
 * @param cin pour les entrées
 * @return un élement situé dans le conteneur en question. (ex : un trajet si 
 * c'est un conteneur de trajets)
 */
template <class TypeClass>
const TypeClass& Conteneur<TypeClass>::choisirElement(std::ostream& cout, std::istream& cin) const{
    NombreContraint<int> n(1,1,contenu.size());
    bool ok;
    do {
        try {
            afficher();
            cout << endl << "Votre choix : " ;
            n.saisir(cin);
            ok = true;
        } catch (const char * e) {
            cout << "choix entre 1 et " << contenu.size() << endl;
            ok == false;
        }
    } while (!ok);
    return *contenu[n.getVal()-1];
}

/**
 * 
 * @return le pointeur static du conteneur en question. Donc la bonne instance. 
 * Pas de duplication possible.
 */
template <class TypeClass>
Conteneur<TypeClass>* Conteneur<TypeClass>::getInstance() {
    if (instance == nullptr) {
        instance = new Conteneur<TypeClass>();
    }
    return instance;
}


template <class TypeClass>
std::ostream & operator<<(std::ostream & flux, Conteneur<TypeClass> &t) {
    t.afficher(flux);
    return flux;
}

#endif