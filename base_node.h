#ifndef BASE_NODE
#define BASE_NODE

#define ALPHABET_SIZE 26

#include "flechie_queue.h"

struct s_base_node
{
    char value;
    struct s_base_node* fils[ALPHABET_SIZE];
    int nb_forme_flechie;
    struct s_flechie_queue* tab_flechie;
};

typedef struct s_base_node t_base_node, *p_base_node;

p_base_node createBaseNode();

#endif //BASE_NODE