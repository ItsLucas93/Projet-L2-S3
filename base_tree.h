#ifndef BASE_TREE_H
#define BASE_TREE_H

#include "base_node.h"

struct s_base_tree
{
    struct s_base_node* root[ALPHABET_SIZE];
};

typedef struct s_base_tree t_base_tree, *p_base_tree;

t_base_tree createEmptyBaseTree();
p_base_node insertBaseTree(p_base_tree t, char*);

#endif //BASE_TREE_H
