//
// Created by Pascal Charpentier on 2024-09-13.
//

#include "pile.h"
#include "gtest/gtest.h"

TEST(Pile, constructeur_no_throw) {
    EXPECT_NO_THROW(Pile<int> p) ;
}

TEST(Pile, vide_cardinal_nul) {
    Pile<int> p ;
    EXPECT_EQ(0, p.size()) ;
}

TEST(Pile, vide_push_cardinal_1)  {
    Pile<int> p ;
    p.push(1) ;
    EXPECT_EQ(1, p.size()) ;
}

TEST(Pile, pile_vide_top_throw) {
    Pile<int> p ;
    EXPECT_THROW(p.top(), std::runtime_error) ;
}

TEST(Pile, pile_un_element_top_retourne_element) {
    Pile<int> p ;
    p.push(1) ;
    EXPECT_EQ(1, p.top()) ;
}

TEST(Pile, pile_vide_pop_throw) {
    Pile<int> p ;
    EXPECT_THROW(p.pop(), std::runtime_error) ;
}

TEST(Pile, pile_un_element_pop_enleve_element) {
    Pile<int> p ;
    p.push(1) ;
    p.pop() ;
    EXPECT_EQ(0, p.size()) ;
}

TEST(Pile, pile_vide_copie_vide) {
    Pile<int> p ;
    p.push(1) ;
    p.push(2) ;
    Pile<int> copie(p) ;
    EXPECT_EQ(2, copie.size()) ;
    EXPECT_EQ(2, copie.top()) ;
    copie.pop() ;
    EXPECT_EQ(1, copie.top()) ;
    copie.pop() ;
    EXPECT_EQ(0, copie.size()) ;
}
