#ifndef BASE_TREE_H
#define BASE_TREE_H

#include "base_node.h"

struct s_base_tree
{
    struct s_base_node* root[ALPHABET_SIZE];
};

typedef struct s_base_tree s_base_tree, t_base_tree, *p_base_tree;

p_base_tree createEmptyBaseTree();
p_base_node insertBaseTree(p_base_tree t, char*);
p_base_node isBaseInTree(p_base_tree t, const char* chaine);
void rechercheFormeBase(p_base_tree Verb, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom, const char* chaine);

#endif //BASE_TREE_H
