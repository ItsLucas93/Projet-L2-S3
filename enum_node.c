#include <stdlib.h>
#include <stddef.h>

#include "enum_list.h"

p_enum_node createEnumNode(sub_type val)
{
    p_enum_node nouv;

    nouv = (p_enum_node) malloc(sizeof(t_enum_list));
    nouv->value = val;
    nouv->next = NULL;

    return nouv;
}

p_char_type create_list_type(){
    p_char_type  type_list;
    type_list = (p_char_type)malloc(sizeof(t_char_type));
    type_list->next=NULL;
    return type_list;
}
