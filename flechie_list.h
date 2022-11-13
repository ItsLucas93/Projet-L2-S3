#ifndef FLECHIE_LIST_H
#define FLECHIE_LIST_H

#include "enum_list.h"
#include "flechie_node.h"

struct s_flechie_list
{
	struct s_flechie_node* head;
};

typedef struct s_flechie_list s_flechie_list, t_flechie_list, *p_flechie_list;

#endif //FLECHIE_LIST_H