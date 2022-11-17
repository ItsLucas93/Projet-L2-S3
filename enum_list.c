#include <stddef.h>
#include <stdlib.h>

#include "enum_list.h"

p_enum_list createEmptyEnumList()
{
    p_enum_list p = (p_enum_list) malloc (sizeof(t_enum_list));
    p->head = NULL;
    return p;
}

int isFlechieInList(t_enum_list t, sub_type sous_type)
{
    p_enum_node temp = t.head;
    while (temp != NULL && temp->value != sous_type)
    {
        temp = temp->next;
    }
    if (temp != NULL && temp->value == sous_type) return 1;
    else return 0;
}

void insertSubType(t_enum_list* t, sub_type sous_type)
{
    if (t->head == NULL)
    {
        t->head = createEnumNode(sous_type);
        return;
    }

    p_enum_node temp = t->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = createEnumNode(sous_type);
}