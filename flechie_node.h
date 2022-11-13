#ifndef FLECHIE_NODE_H
#define FLECHIE_NODE_H

#define LENGHT_MAX 25 // anticonstitutionnellement

#include "enum_list.h"

struct s_flechie_node
{
	struct s_flechie_node* next;
	char value[LENGHT_MAX]; // mot sous forme fléchie
    t_enum_list sub_type_list;
};

typedef struct s_flechie_node t_flechie_node, *p_flechie_node;

p_flechie_node createFlechieNode();

#endif //FLECHIE_NODE_H