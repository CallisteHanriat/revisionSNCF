/* 
 * File:   main.cpp
 * Author: loft-2015-asus
 *
 * Created on 4 novembre 2015, 20:27
 */

#include <cstdlib>
#include "NombreContraint.h"

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
/*
 * 
 */
int main(int argc, char** argv) {
    testNombreContraint();
    return EXIT_SUCCESS;
}

