/* 
 * File:   Reservation.cpp
 * Author: loft-2015-asus
 * 
 * Created on 8 novembre 2015, 11:31
 */
#include "Reservation.h"




//constructor

Reservation::Reservation(Client &cl, float pr) 
:prix(pr), Produit(cl)
{
}

float Reservation::getPrix() const {
    return this->prix;
}

void Reservation::afficher(ostream &cout) const {
    Produit::afficher(cout);
    cout << "\nType : reservation"; 
    cout << "\nprix : " << getPrix();
}

std::ostream& operator<<(std::ostream& flux, const Reservation & r) {
    r.afficher(flux);
    return flux;
}

