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

char* isVerbFlechieInList(p_flechie_node pn, sub_type temps, sub_type nombre, sub_type pluriel);
char* isGenreFlechieInList(p_flechie_node pn, sub_type nombre, sub_type pluriel);
void add_type_to_list_type(p_flechie_node, const char*);

#endif //FLECHIE_LIST_H