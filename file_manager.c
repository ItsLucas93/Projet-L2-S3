#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#include "file_manager.h"

void createTypedTrees(p_base_tree tree_nom, p_base_tree tree_adj, p_base_tree tree_adv, p_base_tree tree_verb)
/*
 * Fonction: createTypedTrees
 * -----------------
 * Génère les arbres depuis le fichier dictionnaire.
 * Prends en charge seulement les dictionnaires sans accents.
 * Le chemin est défini par la variable PATH.
 *
 * À chaque ligne, la forme de base, la forme fléchie, les sous_type sont stockés dans des variables char[]
 * Pour chaque arbre:
 *  Dans un premier temps, on injecte les formes de base
 *  Dans un deuxième temps, on injecte les formes fléchies
 *  Dans un troisième temps, on injecte les sous_types associés aux formes fléchies (sauf pour les adverbes, car tous de même type)
 * Ensuite on nettoie les variables char[]
 *
 * tree_nom: p_base_tree
 * tree_adj: p_base_tree
 * tree_adv: p_base_tree
 * tree_verb: p_base_tree
 * forme_base: char
 * type: char
 * forme_flechie: char
 */
{
    const char *filename = PATH;
    FILE *input_file = fopen(filename, "r");

    struct stat sb;
    if (stat(filename, &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    int nbligne = 0;
    for (char c = getc(input_file); c != EOF; c = getc(input_file)) {
        if (c == '\n') {
            nbligne++;
        }
    }
    printf("Nombres de mots : %d\n", nbligne);
    fclose(input_file);

    input_file = fopen(filename, "r");

    char forme_base[ALPHABET_SIZE];
    char type[100];
    char forme_flechie[ALPHABET_SIZE];

    int i = 0;
    while ( i < nbligne) {

        // printf("%d %d\n",i,nbligne);
        fscanf(input_file, "%s\t%s\t%s", forme_flechie, forme_base, type);

        // printf("%s \n", forme_base);
        if (compareType(type, "Ver:"))
        {
            p_base_node ptr_last_node_base = insertBaseTree(tree_verb, forme_base);
            p_flechie_node ptr_flechie_node = insertFlechieList(ptr_last_node_base, forme_flechie);
            addTypeToFlechieList(ptr_flechie_node, type);
        }
        else if (compareType(type, "Adj:"))
        {
            p_base_node ptr_last_node_base = insertBaseTree(tree_adj, forme_base);
            p_flechie_node ptr_flechie_node = insertFlechieList(ptr_last_node_base, forme_flechie);
            addTypeToFlechieList(ptr_flechie_node, type);
        }
        else if (compareType(type, "Adv")) {
            p_base_node ptr_last_node_base = insertBaseTree(tree_adv, forme_base);
            insertFlechieList(ptr_last_node_base, forme_flechie);
        }
        else if (compareType(type, "Nom:")) {
            p_base_node ptr_last_node_base = insertBaseTree(tree_nom, forme_base);
            p_flechie_node ptr_flechie_node = insertFlechieList(ptr_last_node_base, forme_flechie);
            addTypeToFlechieList(ptr_flechie_node, type);
        }
        clearTabChar(forme_base);
        clearTabTypedChar(type);
        clearTabChar(forme_flechie);
        i++;
    }
    fclose(input_file);
}
p_flechie_node insertFlechieList(p_base_node pn, char* chaine)
/*
 * Fonction: insertFlechieList
 * -----------------
 * Insère les formes fléchies dans la liste des formes fléchies (ne comprends pas les sous_types)
 *
 * pn: p_base_node
 * temp: p_base_node
 * t: p_flechie_list
 * chaine: char*
 */
{
    p_flechie_list t = pn->flechie_list;
    if (t->head == NULL)
    {
        t->head = createFlechieNode();
        strcpy(t->head->value, chaine);
        pn->nb_forme_flechie++;
        p_flechie_node ptr_node = t->head;
        return ptr_node;
    }

    p_flechie_node temp = t->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = createFlechieNode();
    strcpy(temp->next->value, chaine);
    pn->nb_forme_flechie++;
    return temp->next;
}

void clearTabChar(char* mot)
/*
 * Fonction: clearTabChar
 * -----------------
 * Nettoie le tableau de char
 *
 * mot: char*
 */
{
    for (int i = 0; i < ALPHABET_SIZE ; i++)
    {
        mot[i] = '\0';
    }
}

void clearTabTypedChar(char* mot)
/*
 * Fonction: clearTabTypedChar
 * -----------------
 * Nettoie le tableau de type
 *
 * mot: char*
 */
{
    for (int i = 0; i < 99 ; i++)
    {
        mot[i] = '\0';
    }
}

int compareType(const char* type, const char* type_ligne)
/*
 * Fonction: compareType
 * -----------------
 * Compare les deux chaînes de caractère pour voir si les types correspondent
 * Retourne 0 si faux, sinon 1 si vrai
 *
 * type: const char*
 * type_ligne: const char*
 */
{
    for (int i = 0; i < strlen(type_ligne); i++)
    {
        if (type[i] != type_ligne[i]) return 0;
    }
    return 1;
}

