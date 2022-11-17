#ifndef FLECHIE_LIST_H
#define FLECHIE_LIST_H

#define ALPHABET_SIZE 26

#include "flechie_node.h"

struct s_flechie_list
{
	struct s_flechie_node* head;
};

typedef struct s_flechie_list s_flechie_list, t_flechie_list, *p_flechie_list;

p_flechie_list createEmptyFlechieList();
p_char_type lire_type(char* ligne);
void ajouter_type_Aux(char* categorie,char* type,p_flechie_list flechie);
void ajouter_type(char* categorie,p_flechie_list flechie,p_char_type type);

#endif //FLECHIE_LIST_H