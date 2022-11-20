#ifndef FLECHIE_NODE_H
#define FLECHIE_NODE_H

#define LENGHT_MAX 25 // anticonstitutionnellement est dans ce dictionnaire le mot le plus long

#include "enum_list.h"

struct s_flechie_node
{
	struct s_flechie_node* next; // node successeur
	char* value; // Mot sous forme fléchie
    t_enum_list *sub_type_list; // liste des sous_types
};

typedef struct s_flechie_node s_flechie_node, t_flechie_node, *p_flechie_node;

p_flechie_node createFlechieNode();

#endif //FLECHIE_NODE_H