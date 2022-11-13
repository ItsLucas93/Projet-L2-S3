#include <stddef.h>
#include <string.h>

#include "flechie_list.h"

t_flechie_list createEmptyFlechieQueue()
{
    t_flechie_list t;
    t.head = NULL;
    return t;
}

void insertFlechieList(t_flechie_list* t, char* chaine, sub_type sous_type)
{
    if (t->head == NULL)
    {
        t->head = createFlechieNode();
        strcpy(t->head->value, chaine);
        insertSubType(t->head->sub_type_list, sous_type);
    }

    p_flechie_node temp = t->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = createFlechieNode();
    strcpy(temp->next->value, chaine);
    insertSubType(temp->next->sub_type_list, sous_type);
}