#include <stdio.h>
#include <stdlib.h>

#include "base_tree.h"

p_base_node createBaseNode(char val)
{
    p_base_node nouv;

    nouv = (p_base_node) malloc (sizeof(t_base_tree));
    nouv->value = val;
    nouv->nb_forme_flechie = 0;
    // tableau init en struct

    return nouv;
}