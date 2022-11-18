#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "flechie_list.h"
#include "base_node.h"

p_flechie_list createEmptyFlechieList()
{
    p_flechie_list p = (p_flechie_list) malloc (sizeof(t_flechie_list));
    p->head = NULL;
    return p;
}

//Pour comparer des chaînes de caractères

int comparer_char(char* mot,char*mot2){

    if(strlen(mot)!=strlen(mot2)){
        return 0;
    }
    else{
        for(int i = 0;i<strlen(mot);i++){
            if(mot[i]!=mot2[i]){
                return 0;
            }
        }
        return 1 ;
    }
}

//renvoie un type correspondant à sa chaîne de caractère
sub_type correspondant(char* type){
    sub_type sous_type = null;
    //Partie NOM et ADJ
    if (comparer_char(type,"Mas") == 1) {
        sous_type=Mas;
    }
    else if (comparer_char(type,"Fem") == 1) {
        sous_type=Fem;
    }
    else if (comparer_char(type,"SG") == 1) {
        sous_type=SG;
    }
    else if (comparer_char(type,"PL") == 1) {
        sous_type=PL;
    }
    else if (comparer_char(type,"InvPL") == 1 ) {
        sous_type=InvPL;
    }
    else if (comparer_char(type,"InvGen") == 1) {
        sous_type=InvPL;
    }

    //Partie VER
    else if (comparer_char(type,"P1") == 1) {
        sous_type=P1;
    }
    else if (comparer_char(type,"P2") == 1) {
        sous_type=P2;
    }
    else if (comparer_char(type,"P3") == 1) {
        sous_type=P3;
    }
    else if (comparer_char(type,"Inf") == 1) {
        sous_type=Inf;
    }
    else if (comparer_char(type,"PPas") == 1) {
        sous_type=PPas;
    }
    else if (comparer_char(type,"PPre") == 1) {
        sous_type=PPre;
    }
    else if (comparer_char(type,"IPre") == 1) {
        sous_type=IPre;
    }
    else if (comparer_char(type,"IPSim") == 1) {
        sous_type=IPSim;
    }
    else if (comparer_char(type,"IImp") == 1) {
        sous_type=IImp;
    }
    else if (comparer_char(type,"IFut") == 1) {
        sous_type=IFut;
    }
    else if (comparer_char(type,"SPre") == 1) {
        sous_type=SPre;
    }
    else if (comparer_char(type,"SImp") == 1) {
        sous_type=SImp;
       }
    else if (comparer_char(type,"CPre") == 1) {
        sous_type=CPre;
    }
    else if (comparer_char(type,"ImPre") == 1) {
        sous_type=ImPre;
    }
    /*
    //Partie Adv
    if (comparer_char(type,"Adv") == 1) {
        sous_type=Adv;
    }*/
    return sous_type;
}



//verifie si un type est déjà présent dans une liste de type de type t_enum_node
int Is_type_list(p_enum_list l,sub_type type){
    p_enum_node node = l->head;
    while(node != NULL){
        if(type == node->value){
            return 1;
        }
        node = node->next;
    }
    return 0;
}


//crée la liste de type de type p_char_type à partir de la ligne
void add_type_to_list_type(p_flechie_node pn, const char* ligne){
    pn->sub_type_list = createEmptyEnumList();
    p_enum_node type_node = NULL;

    char categorie[6];

    int i=0;
    //ligne est de type categorie:type1+type2...
    while(ligne[i]!=':'){//on saute la catégorie
        categorie[i]=ligne[i];
        i++;
    }

    categorie[i]='\0';
    i++;


    char tout_type[40];

    int j=0;//je stocke le reste des types dans tout_type
    while(ligne[i]!='\0'){
        tout_type[j]=ligne[i];
        i++;
        j++;
    }
    tout_type[j]='\0';

    char mot[8]; //nom

    i=0;

    while(tout_type[i]!='\0'){//Tant que la chaine n'est pas à la fin

        j=0;//car le mot reviens toujours à 0;
        while(tout_type[i]!='+' && tout_type[i]!='\0' && tout_type[i]!=':'){// Tant que le mot n'est pas finit et que la chaine n'est pas à la fin

            mot[j]=tout_type[i];//récupère le type
            mot[j+1]='\0';//ajoute le caractère de fin
            j++;
            i++;
        }

        sub_type sous_type = null;
        sous_type=correspondant(mot);

        if (pn->sub_type_list->head == NULL) {
            pn->sub_type_list->head = createEnumNode();
            type_node = pn->sub_type_list->head;
            type_node->value = sous_type;
        }

        //on stocke le type dans la liste
        else if ((!(Is_type_list(pn->sub_type_list,sous_type))) && sous_type != null){// si le type n'est pas déjà dans la liste on l'ajoute

            type_node->next = createEnumNode();
            type_node = type_node->next;
            type_node->value = sous_type;
        }

        if (i != '\0') i++;
        if (sous_type == null) break;
    }
}

