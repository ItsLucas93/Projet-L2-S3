#include "enum_node.h"
#include <stdlib.h>

p_enum_node createEnumNode(sub_type val)
{
    p_enum_node nouv;

    nouv = (p_enum_node) malloc(sizeof(t_enum_list));
    nouv->value = val;
    nouv->next = NULL;

    return nouv;
}