#include <stdio.h>
#include <stdlib.h>

#include "base_node.h"

p_base_node createBaseNode()
/*
 * Fonction: createBaseNode
 * -----------------
 * Crée un Node pour les formes de base
 *
 * Initialise l'étage à NULL
 * Initialise les valeurs à ' ' (vide, mais de tt façon sera affectée dans les autres fonctions)
 * Initialise une liste des formes fléchies vide
 * Initialise le nombre des formes fléchies à 0
 *
 * pn: p_base_node
 */
{
    p_base_node pn;

    pn = (p_base_node) malloc (sizeof(t_base_node));
    pn->value = ' ';
    pn->nb_forme_flechie = 0;
    pn->flechie_list = createEmptyFlechieList();

    for (int i = 0; i < ALPHABET_SIZE ; i++)
    {
        pn->fils[i] = NULL;
    }

    return pn;
}

