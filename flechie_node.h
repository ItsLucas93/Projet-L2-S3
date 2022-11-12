#ifndef FLECHIE_NODE_H
#define FLECHIE_NODE_H

#define LENGHT_MAX 25 // anticonstitutionnellement

#include "enum_list.h"

struct s_flechie_node
{
	s_flechie_node* next;
	char value[LENGHT_MAX];
	s_enum_list* sous_type;
};

typedef struct s_flechie_node t_flechie_node *p_flechie_node;

#endif //FLECHIE_NODE_H