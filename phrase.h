#ifndef UNTITLED_PHRASE_H
#define UNTITLED_PHRASE_H

#include "base_tree.h"

void create_sentence_1(p_base_tree Ver, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom);
void create_sentence_2(p_base_tree Ver, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom);
void create_sentence_3(p_base_tree Ver, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom);

void create_word_verb(p_base_tree Verb, sub_type temps, sub_type nombre, sub_type pluriel);
void create_word_genre(p_base_tree tree, sub_type nombre, sub_type pluriel);
void create_word_adv(p_base_tree tree);

#endif //UNTITLED_PHRASE_H
