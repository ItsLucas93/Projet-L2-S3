#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "enum_list.h"

p_enum_list createEmptyEnumList()
/*
 * Fonction: createEmptyEnumList
 * -----------------
 * Crée une liste des sous_types des formes fléchies (Ex: SG / PL ...)
 * Tête initialsié à NULL
 *
 * p: p_enum_list
 */
{
    p_enum_list p = (p_enum_list) malloc (sizeof(t_enum_list));
    p->head = NULL;
    return p;
}

int isEnumInList(p_enum_list t, sub_type sous_type)
{
    p_enum_node temp = t->head;
    while (temp != NULL && temp->value != sous_type)
    {
        temp = temp->next;
    }
    if (temp != NULL && temp->value == sous_type) return 1;
    else return 0;
}

void printEnumList(p_enum_list p)
/*
 * Fonction: printEnumList
 * -----------------
 * Affiche les sous_types des formes fléchies
 *
 * p: p_enum_list
 * temp: p_enum_node
 */
{
    p_enum_node temp = p->head;

    while(temp != NULL)
    {
        printf("%s ", EnumToChar(temp->value));
        temp = temp->next;
    }
    printf(";\n");
}