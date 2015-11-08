/* 
 * File:   Billet.cpp
 * Author: loft-2015-asus
 * 
 * Created on 7 novembre 2015, 15:11
 */


#include "Billet.h"

//constructor
/**
 * 
 * @param unTrajet le trajet 
 * @param unTarif le tarif
 * @param cl le client
 */
Billet::Billet(Trajet &unTrajet, Tarif &unTarif, Client &cl)
: trajet(unTrajet), tarif(unTarif), Produit(cl) {
}

const Tarif& Billet::getTarif() const {

    return tarif;

}

const Trajet& Billet::getTrajet() const {

    return trajet;

}


void Billet::afficher(ostream &cout) const {
    Produit::afficher(cout);
    cout << "Trajet : \n" << getTrajet() << endl;
    cout << "Tarif : \n" << getTarif() << endl;
    cout << "Prix : " << getPrix() << "€\n";
}

float Billet::getPrix() const {
    return getTarif().getPrixAuKm() * getTrajet().getDistance();
}

std::ostream& operator<<(std::ostream& flux, const Billet & b) {
    b.afficher(flux);
    return flux;
}



