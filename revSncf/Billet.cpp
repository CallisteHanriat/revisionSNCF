/* 
 * File:   Billet.cpp
 * Author: loft-2015-asus
 * 
 * Created on 7 novembre 2015, 15:11
 */


#include "Billet.h"

//constructor

Billet::Billet(Trajet &unTrajet, Tarif &unTarif, Client &cl)
: trajet(unTrajet), tarif(unTarif), client(cl) {
}

const Tarif& Billet::getTarif() const {

    return tarif;

}

const Trajet& Billet::getTrajet() const {

    return trajet;

}

void Billet::setClient(Client& cl) {
    string nm = cl.getNom();
    client.setNom(nm);
}
Client & Billet::getClient() const {
    return this->client;
}

void Billet::afficher(ostream &cout) const {
    cout << "Trajet : \n" << getTrajet() << endl;
    cout << "Tarif : \n" << getTarif() << endl;
    cout << "Prix : " << getPrix() << "€\n";
    cout << getClient();
}

float Billet::getPrix() const {
    return getTarif().getPrixAuKm() * getTrajet().getDistance();
}

std::ostream& operator<<(std::ostream& flux, const Billet & b) {
    b.afficher(flux);
    return flux;
}



