/* 
 * File:   Billet.cpp
 * Author: loft-2015-asus
 * 
 * Created on 7 novembre 2015, 15:11
 */


#include "Billet.h"

//constructor

Billet::Billet(Trajet &unTrajet, Tarif &unTarif) 
:trajet(unTrajet), tarif(unTarif)
{}

const Tarif& Billet::getTarif() const {

	return tarif;

}

const Trajet& Billet::getTrajet() const {

	return trajet;

}

void Billet::afficher(ostream &cout) const{
    cout << "Trajet : \n" << getTrajet() << endl;
    cout << "Tarif : \n" << getTarif()<< endl;
    cout << "Prix : " << getPrix() << "€";
}

float Billet::getPrix() const {
    return getTarif().getPrixAuKm()*getTrajet().getDistance();
}

std::ostream& operator<<(std::ostream& flux, const Billet & b) {
	b.afficher(flux);
	return flux;
}



