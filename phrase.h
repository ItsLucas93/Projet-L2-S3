#ifndef UNTITLED_PHRASE_H
#define UNTITLED_PHRASE_H

#include "base_tree.h"

void createSentenceModel1(p_base_tree Ver, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom);
void createSentenceModel2(p_base_tree Ver, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom);
void createSentenceModel3(p_base_tree Ver, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom);

void createWordVerb(p_base_tree Verb, sub_type temps, sub_type nombre, sub_type pluriel);
void createWordGenre(p_base_tree tree, sub_type nombre, sub_type pluriel);
void createWordAdv(p_base_tree tree);

#endif //UNTITLED_PHRASE_H
