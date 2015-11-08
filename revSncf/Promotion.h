/* 
 * File:   Promotion.h
 * Author: loft-2015-asus
 *
 * Created on 7 novembre 2015, 17:31
 */

#ifndef PROMOTION_H
#define	PROMOTION_H
#include "NombreContraint.h"
using namespace std;

class Promotion {
public:

    Promotion(string &lib, float tauxReduc);
    string getLibelle() const;
    void setLibelle(string &libelle);
    NombreContraint<float> getTauxReduction() const;
    void setTauxReduction(float tauxReduction);


    float calculerPrixReduit(float prix) const;
    void saisir(istream &cin = cin);
    void afficher(ostream &cout = cout) const;
private:
    string libelle;
    static const float TAUXMIN;
    static const float TAUXMAX;
    NombreContraint<float> tauxReduction;

};

std::ostream& operator<<(std::ostream& flux, const Promotion & p);
std::istream& operator>>(std::istream& flux, Promotion & p);


#endif	/* PROMOTION_H */

