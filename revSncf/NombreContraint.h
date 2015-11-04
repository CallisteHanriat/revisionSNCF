/* 
 * File:   NombreContraint.h
 * Author: loft-2015-asus
 *
 * Created on 4 novembre 2015, 20:34
 */

#ifndef NOMBRECONTRAINT_H
#define	NOMBRECONTRAINT_H
#include <iostream>
using namespace std;

/**
 * Classe qui contiendra un noubre contraint entre un min et un max
 */
template <class T>
class NombreContraint {
public:
    NombreContraint(T valeur = 0, T min = 0, T max = 1000);
    void setVal(T val);
    T getVal() const;
    T getMax() const;
    T getMin() const;
    void saisir(std::istream & cin = std::cin);
    void afficher(std::ostream & cout = std::cout) const;
    operator T();
private:
    T m_min;
    T m_max;
    T m_val;
};

template <class T>
std::ostream &operator<<(std::ostream & flux, const NombreContraint<T> &n) {
    n.afficher(flux);
    return flux;
}

template <class T>
std::istream & operator>>(std::istream & flux, NombreContraint<T> &n) {
    n.saisir(flux);
    return flux;
}

#include "NombreContraint.cpp"
#endif	/* NOMBRECONTRAINT_H */

