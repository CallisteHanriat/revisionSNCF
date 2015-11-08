#ifndef CONTENEUR_H
#define	CONTENEUR_H

#include <vector>
#include <iostream>


template <class TypeClass>

class Conteneur {
public:
    void ajouter(const TypeClass &t);
    void afficher(std::ostream &cout) const;
    const TypeClass& choisirElement(std::ostream &cout, std::istream &cin) const;
    static Conteneur* getInstance();
private:
    std::vector<const TypeClass*> contenu;
    static Conteneur<TypeClass>* instance;
protected :
    Conteneur();  
};

template <class TypeClass>
std::ostream & operator<<(std::ostream & flux, Conteneur<TypeClass> &t);

#include "Conteneur.cpp"
#endif	/* CONTENEUR_H */