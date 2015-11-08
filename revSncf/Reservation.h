/* 
 * File:   Reservation.h
 * Author: loft-2015-asus
 *
 * Created on 8 novembre 2015, 11:31
 */

#ifndef RESERVATION_H
#define	RESERVATION_H
#include "Produit.h"
using namespace std;

class Reservation : public Produit {
public:
    Reservation(Client &cl, float pr);
    float getPrix() const;
    void afficher(ostream &cout = cout) const;
private:
    float prix;
};

std::ostream& operator<<(std::ostream& flux, const Reservation & r);

#endif	/* RESERVATION_H */

