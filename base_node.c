#include <stdio.h>
#include <stdlib.h>

#include "base_tree.h"

p_base_node createBaseNode()
{
    p_base_node nouv;

    nouv = (p_base_node) malloc (sizeof(t_base_tree));
    nouv->value = ' ';
    nouv->nb_forme_flechie = 0;
    for (int i = 0; i < ALPHABET_SIZE ; i++)
    {
        nouv->fils[i] = NULL;
    }

    return nouv;
}