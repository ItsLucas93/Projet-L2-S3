#ifndef FLECHIE_LIST_H
#define FLECHIE_LIST_H

#include "flechie_node.h"

struct s_flechie_list
{
	struct s_flechie_node* head;
};

typedef struct s_flechie_list s_flechie_list, t_flechie_list, *p_flechie_list;

p_flechie_list createEmptyFlechieList();
int Is_type_list(p_enum_list liste,sub_type type);
int comparer_char(char* mot,char* mot2);
sub_type correspondant(char* type);
void add_type_to_list_type(p_flechie_node pn, const char* ligne);

#endif //FLECHIE_LIST_H