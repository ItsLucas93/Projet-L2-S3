#ifndef PROJET_FILE_MANAGER_H
#define PROJET_FILE_MANAGER_H

#define PATH "../dictionnaire/dico_10_lignes.txt"

#include "base_tree.h"

void create_typed_tree(p_base_tree tree_verb, p_base_tree tree_adj, p_base_tree tree_adv, p_base_tree tree_nom);
int compare_type(const char *, const char *);
void clear_tab_char(char* mot);
void clear_tab_type_char(char* mot);
void insertFlechieList(p_base_node pn, char* chaine, sub_type sous_type);

#endif //PROJET_FILE_MANAGER_H
