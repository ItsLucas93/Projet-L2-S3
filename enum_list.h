#ifndef PROJET_ENUM_LIST_H
#define PROJET_ENUM_LIST_H

#include "enum_node.h"

struct s_enum_list
{
    struct s_enum_node *head;
    struct s_enum_node *tail;
};

typedef struct s_enum_list t_enum_list, *p_enum_list;

t_enum_list createEmptyEnumQueue();

#endif //PROJET_ENUM_LIST_H
