/* 
 * File:   BilletReduit.cpp
 * Author: loft-2015-asus
 * 
 * Created on 7 novembre 2015, 17:52
 */
#include "BilletReduit.h"

BilletReduit::BilletReduit(Trajet &unTrajet, Tarif &unTarif,Client &cl, Promotion &p)
: Billet(unTrajet, unTarif,cl), promotion(p) {
}

Promotion &BilletReduit::getPromotion() const {
    return this->promotion;
}

void BilletReduit::afficher(ostream& cout) const {
    cout << "Type : BilletReduit\n";
    cout << "Type de réduction : " << getPromotion().getLibelle() << endl;
    Billet::afficher();
}

float BilletReduit::getPrix() const {
    return getPromotion().calculerPrixReduit(Billet::getPrix());
}

std::ostream& operator<<(std::ostream& flux, const BilletReduit & b) {
    b.afficher(flux);
    return flux;
}

