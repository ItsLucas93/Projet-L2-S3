#include <stdlib.h>

#include "flechie_list.h"
#include "enum_list.h"

p_flechie_node createFlechieNode()
/*
 * Fonction: createFlechieNode
 * -----------------
 * Crée un Node pour les formes fléchies
 * next initialisé à NULL
 * liste des sous_type reçoit un pointeur vers une liste de sous_type créée
 *
 * pn: p_enum_node
 */
{
    p_flechie_node nouv = (p_flechie_node) malloc (sizeof (t_flechie_node));

    nouv->next = NULL;
    nouv->sub_type_list = createEmptyEnumList();
    nouv->value = (char*) malloc (sizeof (char) * LENGHT_MAX);

    return nouv;
}