#ifndef GENERATEUR_DE_PHRASE_BASE_NODE_H
#define GENERATEUR_DE_PHRASE_BASE_NODE_H

#define ALPHABET_SIZE 27 // 27e node pour les caractères spéciaux '-' '''

#include "flechie_list.h"

struct s_base_node
{
    char value;
    struct s_base_node* fils[ALPHABET_SIZE];
    int nb_forme_flechie;
    struct s_flechie_list* flechie_list;
};

typedef struct s_base_node s_base_node, t_base_node, *p_base_node;

p_base_node createBaseNode();

#endif //GENERATEUR_DE_PHRASE_BASE_NODE_H
