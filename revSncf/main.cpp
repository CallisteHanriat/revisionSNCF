/* 
 * File:   main.cpp
 * Author: loft-2015-asus
 *
 * Created on 4 novembre 2015, 20:27
 */

#include <cstdlib>
#include "NombreContraint.h"
#include "Trajet.h"
#include "Tarif.h"
#include "Client.h"
#include "Billet.h"
#include "Promotion.h"
#include "BilletReduit.h"
using namespace std;

void testNombreContraint() {
    cout << "Constructeur : \n";
    NombreContraint<int> n1(20);
    cout << "\nok.\n";    
    cout << "Test d'affichage du nombre contraint : \n";
    cout << n1 << endl;
    n1.afficher(cout);
    cout << "\nok.\n";
    cout << "Test de creation d'un nombre contraint trop grand : \n";
    try{
        NombreContraint<int> n2 (1001);
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    cout << "\nok.\n";
}

void testTrajet() {
    string va = "Paris";
    string vd = "Marseille";
    cout << "Constructeur : " << endl;
    Trajet t(vd, va, 650);
    cout << "ok.\n";
    cout <<  "Affichage : \n";
    cout << t;
    cout << "ok.\n";
    cout << "saisie : \n";
    cin >> t;
    cout << "ok.\n";
}

void testTarif() {
    string lib = "illico";
    float price = 0.2;
    cout << "Constructeur : " << endl;
    Tarif t (lib, price);
    cout << "ok.\n";
    cout << "Affichage : \n";
    cout << t << endl;
    cout << "Saisie :\n";
    cin >> t;
    cout << endl << t;
}

void testBillet() {
    string villeDep = "Paris";
    string villeAr = "Marseille";
    int distance = 550;
    string lib = "illico";
    float price = 0.2;
    
    cout << "Constructeurs : " << endl;
    Tarif tarif (lib, price);
    Trajet trajet(villeDep,villeAr, distance);
    cout << "ok.\n";
    cout << "Affichage du tarif: \n";
    cout << tarif << endl;
    cout << "Affichage du trajet : \n";
    cout << trajet << endl;
    
    cout << "Constructeur du billet : \n";
    Billet billet(trajet, tarif);
    cout << "ok.\n";
    cout << "Affichage du billet : " << endl;
    cout << billet << endl;
}


void testPromotion() {
    string lib = "illico_jeunes_mensuel";
    float tauxReduc = 0.75;
    cout << "Constructeur : \n";
    Promotion p(lib, tauxReduc);
    cout << "ok.\n";
    cout << "affichage de p : \n";
    cout << p;
    cout << "ok.\n";
    cout << "saisie de p : ";
    cin >> p;
    cout << "nouvel affichage de p : \n";
    cout << p;
}

void testBilletReduit() {
    string villeDep = "Paris";
    string villeAr = "Marseille";
    int distance = 550;
    string promoLib = "illico_jeunes_mensuel";
    float promo=0.75;
    string lib = "illico";
    float price = 0.2;
    
    Promotion promotion(promoLib, promo);
    cout << "Constructeurs : " << endl;
    Tarif tarif (lib, price);
    Trajet trajet(villeDep,villeAr, distance);
    cout << "ok.\n";
    cout << "Affichage du tarif: \n";
    cout << tarif << endl;
    cout << "Affichage du trajet : \n";
    cout << trajet << endl;
    
    cout << "Constructeur du billet : \n";
    Billet billet(trajet, tarif);
    cout << "ok.\n";
    cout << "Affichage du billet Reduit : " << endl;
    cout << billet << endl;
    
    cout << "AFFICHAGE DU BILLET REDUIT : " << endl;
    BilletReduit billetReduit(trajet, tarif, promotion);
    cout << billetReduit;
}

void testClient()  {
    string nm = "maxime";
    cout << "Constructeur : \n";
    Client c(nm);
    cout << "Affichage : \n";
    cout << c;
    cout << "\nsaisie : \n";
    cin >> c;
    cout << "Affichage : \n";
    cout << c;
}
/*
 * 
 */
int main(int argc, char** argv) {
    testClient();
    return EXIT_SUCCESS;
}

