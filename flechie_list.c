#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "flechie_list.h"
#include "base_node.h"

t_flechie_list createEmptyFlechieQueue()
{
    t_flechie_list t;
    t.head = NULL;
    return t;
}

void insertFlechieList(p_base_node pn, char* chaine, sub_type sous_type)
{
    p_flechie_list t = pn->flechie_list;
    if (t->head == NULL)
    {
        t->head = createFlechieNode();
        strcpy(t->head->value, chaine);
        insertSubType(t->head->sub_type_list, sous_type);
        pn->nb_forme_flechie++;
        return;
    }

    p_flechie_node temp = t->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = createFlechieNode();
    strcpy(temp->next->value, chaine);
    insertSubType(temp->next->sub_type_list, sous_type);
    pn->nb_forme_flechie++;
}

//Pour comparer des chaînes de caractère

int comparer_char(char* mot,char*mot2){

    if(strlen(mot)!=strlen(mot2)){
        return 0;
    }
    else{
        for(int i;i<strlen(mot);i++){
            if(mot[i]!=mot2[i]){
                return 0;
            }
        }
        return 1 ;
    }
}

//ajoute un type à une forme fléchie

void ajouter_type_Aux(char* categorie,char* type,p_flechie_list flechie) {
    p_flechie_node flechie1 = flechie->head; //pointeur auxiliaire
    while (flechie1->next != NULL) {
        flechie1 = flechie1->next;
    }

    p_enum_node node= (p_enum_node)malloc(sizeof(t_enum_node));
    node->next=NULL;
    p_enum_list list=(p_enum_list) malloc(sizeof(t_enum_list));
    list->head=node;
    flechie1->sub_type_list = list;


    if (comparer_char(categorie,"Adj") == 1 || comparer_char(categorie,"Nom") == 1) {
        if (comparer_char(type,"Mas") == 1) {
            node->value = Mas;
        }
        if (comparer_char(type,"Fem") == 1) {
            node->value = Fem;
        }
        if (comparer_char(type,"SG") == 1) {
            node->value = SG;
        }
        if (comparer_char(type,"PL") == 1) {
            node->value = PL;
        }
        if (comparer_char(type,"InvPL") == 1 ){
            node->value = InvPL;
        }

        if (comparer_char(type,"InvGen") == 1) {
            node->value=InvGen;
        }
    }

    if (comparer_char(categorie,"Ver") == 1) {
        if (comparer_char(type,"P1")) {
            node->value=P1;
        }
        if (comparer_char(type,"P2")) {

            node->value=P2;
        }
        if (comparer_char(type,"P3")) {
            node->value=P3;
        }
        if (comparer_char(type,"Inf")) {
            node->value=Inf;
        }
        if (comparer_char(type,"PPas")) {
            node->value=PPas;
        }
        if (comparer_char(type,"PPre")) {
            node->value=PPre;
        }
        if (comparer_char(type,"Ipre")) {
            node->value=IPre;
        }
        if (comparer_char(type,"IPSim")) {
            node->value=IPSim;
        }
        if (comparer_char(type,"IImp")) {

            node->value=IImp;
            flechie1->sub_type_list->head->value=IImp;
        }
        if (comparer_char(type,"IFut")) {

            node->value=IFut;
            flechie1->sub_type_list->head->value=IFut;
        }
        if (comparer_char(type,"SPre")) {

            node->value=SPre;
            flechie1->sub_type_list->head->value=SPre;
        }
        if (comparer_char(type,"SImp")) {

            node->value=SImp;
            flechie1->sub_type_list->head->value=SImp;
        }
        if (comparer_char(type,"CPre")) {

            node->value=CPre;
            flechie1->sub_type_list->head->value=CPre;
        }
        if (comparer_char(type,"ImPre")) {

            node->value=ImPre;
            flechie1->sub_type_list->head->value=ImPre;
        }
    }
    if (comparer_char(type,"Adv")) {

        node->value=Adv;
        flechie1->sub_type_list->head->value=Adv;
    }
}
