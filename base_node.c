#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "base_node.h"
#include "enum_node.h"

p_base_node createBaseNode(){
    p_base_node nouv;
    nouv = (p_base_node) malloc (sizeof(t_base_node));
    nouv->value = ' ';
    nouv->nb_forme_flechie = 0;
    nouv->flechie_list = createEmptyFlechieList();
    for (int i = 0; i < ALPHABET_SIZE ; i++)
    {
        nouv->fils[i] = NULL;
    }
    return nouv;
}






















/*
void ajouter_mot_n_node(p_char_node p_node,char mot[],p_flechie flechie) {
    p_char_node p1_node = p_node;//pointeur auxilliaire
    for (int i = 0; i < strlen(mot); i++) {
        if (p1_node != NULL) { // si le noeud est non vide

            if (p1_node->value == mot[i]) { // on cherche s'il existe un début de mot similaire
                int found = 0;
                p_cell p_next1 = p1_node->n_node;//pointeur auxilliaire
                while (p_next1 = !NULL && found == 0) {//on cherche dans tous les sous arbres
                    if (p_next1->value == mot[i]) {
                        found = 1;
                    }
                    p_next1 = p_next1->next;
                }
                if (found == 0) { // si il n'existe pas de sous arbres correspondant
                    p_char_node nouv = createCharNode(mot[i]);
                    p_cell p_next2 = p1_node->n_node;//pointeur auxilliaire
                    while (p_next2->next != NULL)//on va à la fin
                    {
                        p_next2=p_next2->next;
                    }
                    p_cell new;          //on assigne une cellule à la fin de la liste
                    p_next2->next = new;
                    new->value = nouv;     // on lui donne le nouveau noeud
                    new->next = NULL;      // fin de la liste
                    if(i==strlen(mot-1)){//si on est à la fin du mot
                        *(new->value);
                    }
                }
            } else// si le noeuds est vide on crée un nouveau noeuds qui contient un char node
            {
                p_char_node nouv = createCharNode(mot[i]);

                p_cell new;
                new->value=nouv;  // on lui donne le nouveau noeud
                p1_node->n_node = new; //on assigne la nouvelle cellue à la fin
                new->next = NULL;      // fin de la liste
            }
            p1_node = p1_node->n_node->next;
        } else {
            p_char_node nouv = createCharNode(mot[i]);
            p1_node = nouv;
        }
    }
}
*/

