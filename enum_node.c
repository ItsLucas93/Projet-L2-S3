#include <stdlib.h>
#include <stddef.h>

#include "enum_list.h"

p_enum_node createEnumNode()
{
    p_enum_node nouv;

    nouv = (p_enum_node) malloc(sizeof(t_enum_list));
    nouv->next = NULL;

    return nouv;
}
