#ifndef BASE_TREE_H
#define BASE_TREE_H

#include "base_node.h"

struct s_base_tree
{
    p_base_node root;
};

typedef struct s_base_tree t_base_tree, *p_base_tree;

t_base_tree createEmptyBaseTree();

#endif //BASE_TREE_H
