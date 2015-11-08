/* 
 * File:   Produit.cpp
 * Author: loft-2015-asus
 * 
 * Created on 8 novembre 2015, 10:01
 */
#include "Produit.h"

//constructor

Produit::Produit(Client &cl)
: client(cl) , prix(1.0){
}

Client &Produit::getClient() const {
    return this->client;
}

/**
 * 
 * @param p le produit à ajouter
 * @do ajoute un produit dans le vecteur de produit.
 */
void Produit::ajouter(Produit *p) {
    produits.push_back(p);
}

void Produit::afficher(ostream &cout) const {
    cout << getClient();
}
std::ostream& operator<<(std::ostream& flux, const Produit & p) {
    p.afficher(flux);
    return flux;
}



