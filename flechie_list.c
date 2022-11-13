#include <stddef.h>
#include <string.h>

#include "flechie_list.h"
#include "base_node.h"

t_flechie_list createEmptyFlechieQueue()
{
    t_flechie_list t;
    t.head = NULL;
    return t;
}

void insertFlechieList(p_base_node pn, char* chaine, sub_type sous_type)
{
    p_flechie_list t = pn->flechie_list;
    if (t->head == NULL)
    {
        t->head = createFlechieNode();
        strcpy(t->head->value, chaine);
        insertSubType(t->head->sub_type_list, sous_type);
        pn->nb_forme_flechie++;
        return;
    }

    p_flechie_node temp = t->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = createFlechieNode();
    strcpy(temp->next->value, chaine);
    insertSubType(temp->next->sub_type_list, sous_type);
    pn->nb_forme_flechie++;
}