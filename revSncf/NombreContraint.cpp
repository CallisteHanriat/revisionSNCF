/* 
 * File:   NombreContraint.cpp
 * Author: loft-2015-asus
 * 
 * Created on 4 novembre 2015, 20:34
 */


#ifdef NOMBRECONTRAINT_H

/**
 * Constructor
 * @param valeur valeur du nombre contraint
 * @param min borne minimal du nombre contraint
 * @param max borne maximal du nombre contraint
 */
template <class T>
NombreContraint<T>::NombreContraint(T valeur, T min, T max)
:  m_min(min), m_max(max) {
    if (valeur> max || valeur < min) {
        cout << "Erreur de saisie du nombre. ";
        throw "\nErreur. Impossible de créer le nombre contraint.\n";
    }
    setVal(valeur);
}

template<class T>
void NombreContraint<T>::setVal(T val) {
    this->m_val = val;
}

template<class T>
T NombreContraint<T>::getVal() const {
    return m_val;
}

template<class T>
T NombreContraint<T>::getMax() const {
    return m_max;
}

template<class T>
T NombreContraint<T>::getMin() const {
    return m_min;
}

template <class T>
void NombreContraint<T>::afficher(std::ostream & cout) const {
    cout << this->getMin() << " < " << this->getVal() << " < " << this->getMax();
}

template <class T>
void NombreContraint<T>::saisir(std::istream& cin) {
    std::cout << "entrez valeur du nombre val : ";
    std::cin >> this->m_val;
}

template <class T>
NombreContraint<T>::operator  T() {
    return this->getVal();
}


#endif