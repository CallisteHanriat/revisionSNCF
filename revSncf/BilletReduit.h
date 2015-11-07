/* 
 * File:   BilletReduit.h
 * Author: loft-2015-asus
 *
 * Created on 7 novembre 2015, 17:52
 */

#ifndef BILLETREDUIT_H
#define	BILLETREDUIT_H
#include "Billet.h"
#include "Promotion.h"
class  BilletReduit : public Billet
{ 
public : 

	BilletReduit(Trajet &unTrajet, Tarif &unTarif, Promotion &p);
	Promotion &getPromotion() const;
        void afficher(ostream &cout = cout) const;
	float getPrix() const;
private :
	Promotion &promotion;

};

std::ostream& operator<<(std::ostream& flux, const BilletReduit & b);

#endif	/* BILLETREDUIT_H */

