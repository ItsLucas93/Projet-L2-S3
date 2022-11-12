#ifndef PROJET_ENUM_LIST_H
#define PROJET_ENUM_LIST_H

#include "enum_node.h"

struct s_enum_list
{
    s_enum_node *head;
    s_enum_node *tail;
};

typedef struct s_enum_list t_enum_list *p_enum_list;

#endif //PROJET_ENUM_LIST_H
