#include <string.h>
#include <stdlib.h>
#include "base_tree.h"
#include "base_node.h"
#include <stdio.h>
#include <time.h>


p_base_tree createEmptyBaseTree()
{
    p_base_tree t=(p_base_tree)malloc(sizeof(t_base_tree));
    for (int i = 0 ; i < ALPHABET_SIZE ; i++)
    {
        t->root[i] = NULL;

    }
    return t;
}

p_base_node insertBaseTree(p_base_tree t, char* val)
{
    // ascii a 97 to 122
    unsigned long lenght_word = strlen(val);

    if (lenght_word) {

        if (t->root[((int) val[0] - 97)] == NULL){
            t->root[((int) val[0] - 97)] = createBaseNode();
        }
        t->root[((int) val[0] - 97)]->value = val[0];

        p_base_node temp = t->root[((int) val[0] - 97)];
        // lenght_word - 1 pour ne pas prendre en compte le \0
        for (unsigned long i = 1; i < lenght_word; i++)
        {
            int idx = ((int) val[i] - 97);
            if (temp->fils[idx] == NULL)
            {
                temp->fils[idx] = createBaseNode();
                temp = temp->fils[idx];
                temp->value = val[i];
            }
            else
            {
                temp = temp->fils[idx];
            }
        }

        return temp;
    }
    return NULL;
}



/*
p_flechie_node extraire_random_flechie(t_base_tree categorie){
    srand(time(NULL));
    int letter=rand()%26; //aléatoirement l'abre commençant par une lettre
    p_base_node node=categorie.root;//on va dans le premier noeud de l'arbre
    int suite=1;
    int i;
    while(node->nb_forme_flechie==0 || suite==1){ //tanque je n'atteint pas une forme fléchie et qu'il existe une suite
        suite=0;
        i=rand()%26;
        while(node->fils[i]!=NULL){ //je vais dans un fils aléatoirement
            i=rand()%26;
        }
        node=node->fils[i]; // je vais dans le fils

        int est_vide=1; //je regarde si il possède des fils
        for(int j=0;j<26;j++){
            if(node->fils[j]!=NULL){
                est_vide=0;
            }
        }
        if(node->nb_forme_flechie!=0 && est_vide==0){// si oui on tire àléatoirement une pièce pour savoir si on continue ou si on s'arrête
            suite=rand()%2;
        }
    }

    return node->flechie_list.head; //on renvoie les formes fléchies
}

char* extraire_random_base(t_base_tree categorie[]){
    char base[12];
    int c=0;
    srand(time(NULL));
    int letter=rand()%26;   //aléatoirement l'abre commençant par une lettre
    p_base_node node=categorie[letter].root;   //on va dans le premier noeud de l'arbre
    int suite=1;
    while(node->nb_forme_flechie==0 || suite==1){//tanque je n'atteint pas une forme fléchie et qu'il existe une suite
        suite=0;
        int i=rand()%26;
        while(node->fils[i]!=NULL){  //je vais dans un fils aléatoirement
            rand()%25;
        }
        base[c]=node->value; //je stocke le char dans la forme de base
        node=node->fils[i];  // je vais dans le fils
        c++;                // je passe au caractère suivant

        int est_vide=1;  //je regarde si il possède des fils
        for(int j=0;j<26;j++){
            if(node->fils[j]!=NULL){
                est_vide=0;
            }
        }
        if(node->nb_forme_flechie>0 && est_vide==0){// si oui on tire àléatoirement une pièce pour savoir si on continue ou si on s'arrête
            suite=rand()%2;
        }
    }
    return base; //je renvoie la forme de base
}
*/