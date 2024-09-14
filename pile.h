//
// Created by Pascal Charpentier on 2024-09-13.
//

#ifndef PILE_PILE_H
#define PILE_PILE_H

#include <cstdlib>
#include <stdexcept>



template <typename T>
class Pile {

private:
    struct Cellule {
        T valeur ;
        Cellule* next ;
        explicit Cellule(const T& val) : valeur(val), next(nullptr) {} ;
    };

public:
    Pile() ;
    Pile(const Pile& source) ;
    ~Pile() ;

    void push(const T& valeur) ;
    void pop() ;
    const T& top() const ;
    size_t size() const ;


private:
    Cellule* head ;
    size_t cardinal ;
} ;

template <typename T>
Pile<T>::Pile() :  head(nullptr), cardinal(0) {

}

template<typename T>
void Pile<T>::push(const T &valeur) {

    auto n = new Cellule(valeur) ;
    n->next = head ;
    head = n ;
    ++ cardinal ;
}

template<typename T>
size_t Pile<T>::size() const {
    return cardinal ;
}

template<typename T>
const T &Pile<T>::top() const {
    if (cardinal == 0) throw std::runtime_error("top: pile vide") ;
    return head->valeur ;
}

template<typename T>
void Pile<T>::pop() {
    if (cardinal == 0) throw std::runtime_error("pop: pile vide") ;

    auto new_head = head->next ;
    delete head ;
    head = new_head ;
    -- cardinal ;
}

template<typename T>
Pile<T>::~Pile() {
    while (cardinal > 0) pop() ;
}

template<typename T>
Pile<T>::Pile(const Pile &source) :  head(nullptr), cardinal(0) {
    auto source_current = source.head ;
    Cellule* copy_prev = nullptr ;
    while (source_current != nullptr) {
        auto copy_current = new Cellule(source_current->valeur) ;
        if (head == nullptr) head = copy_current ;
        if (copy_prev != nullptr) copy_prev->next = copy_current ;
        source_current = source_current->next ;
        copy_prev = copy_current ;
        ++ cardinal ;
    }
}

#endif //PILE_PILE_H
