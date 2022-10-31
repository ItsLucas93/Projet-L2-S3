#include <stdio.h>
#include <stdlib.h>
#include "char_node.h"

p_char_node createCharNode(char val)
{
    p_char_node nouv;

    nouv = (p_char_node )malloc(sizeof(t_char_node));
    nouv->value = val;
    nouv->left = nouv->right = NULL;

    return nouv;
}