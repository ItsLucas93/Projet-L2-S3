#ifndef PROJET_FILE_MANAGER_H
#define PROJET_FILE_MANAGER_H

#define PATH "../dictionnaire/dictionnaire_non_accentue.txt"

#include "base_tree.h"

void createTypedTrees(p_base_tree tree_verb, p_base_tree tree_adj, p_base_tree tree_adv, p_base_tree tree_nom);
int compareType(const char *, const char *);
void clearTabChar(char* mot);
void clearTabTypedChar(char* mot);
p_flechie_node insertFlechieList(p_base_node pn, char* chaine);

#endif //PROJET_FILE_MANAGER_H
