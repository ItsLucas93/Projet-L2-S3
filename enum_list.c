#include <stddef.h>

#include "enum_list.h"

t_enum_list createEmptyEnumQueue()
{
    t_enum_list t;
    t.head = NULL;
    return t;
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