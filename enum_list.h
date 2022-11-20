#ifndef ENUM_LIST_H
#define ENUM_LIST_H

#include "enum_node.h"

struct s_enum_list
{
    struct s_enum_node *head;
};

typedef struct s_enum_list s_enum_list, t_enum_list, *p_enum_list;


p_enum_list createEmptyEnumList();
int isEnumInList(p_enum_list, sub_type);
void printEnumList(p_enum_list);

#endif //ENUM_LIST_H
