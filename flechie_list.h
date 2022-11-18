#ifndef FLECHIE_LIST_H
#define FLECHIE_LIST_H

#include "flechie_node.h"

struct s_flechie_list
{
	struct s_flechie_node* head;
};

typedef struct s_flechie_list s_flechie_list, t_flechie_list, *p_flechie_list;

p_flechie_list createEmptyFlechieList();
void printFlechieList(p_flechie_list p);

int Is_type_list(p_enum_list, sub_type);
void add_type_to_list_type(p_flechie_node, const char*);

#endif //FLECHIE_LIST_H