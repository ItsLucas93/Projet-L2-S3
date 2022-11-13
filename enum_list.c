#include <stddef.h>

#include "enum_list.h"

t_enum_list createEmptyEnumQueue()
{
    t_enum_list t;
    t.head = t.tail = NULL;
    return t;
}