#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "phrase.h"
#include "enum_node.h"

void create_sentence_1(p_base_tree Ver, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom) {

    srand(time(NULL));

    int genre = rand() % 2;
    int nombre = rand() % 2;
    int determinant = rand() % 2;

    if (nombre == 0) {
        if (genre == 0) {
            if (determinant == 0) printf("Le");
            else printf("Un");
            for (int i = 0; i < 4; i++) {
                srand(i);
                if (i == 0 || i == 3) create_word_genre(Nom, Mas, SG);
                else if (i == 2) create_word_verb(Ver, (rand() % 4) + 10, SG, P3);
                else if (i == 1) create_word_genre(Adj, Mas, SG);
            }
        } else {
            if (determinant == 0) printf("La");
            else printf("Une");
            for (int i = 0; i < 4; i++) {
                srand(i);
                if (i == 0 || i == 3) create_word_genre(Nom, Fem, SG);
                else if (i == 2) create_word_verb(Ver, (rand() % 4) + 10, SG, P3);
                else if (i == 1) create_word_genre(Adj, Fem, SG);
            }
        }
    } else {
        if (determinant == 0) printf("Les");
        else printf("Des");
        if (genre == 0) {
            for (int i = 0; i < 4; i++) {
                srand(i);
                if (i == 0 || i == 3) create_word_genre(Nom, Mas, PL);
                else if (i == 2) create_word_verb(Ver, (rand() % 4) + 10, PL, P3);
                else if (i == 1) create_word_genre(Adj, Mas, PL);
            }
        } else {
            for (int i = 0; i < 4; i++) {
                srand(i);
                if (i == 0 || i == 3) create_word_genre(Nom, Fem, PL);
                else if (i == 2) create_word_verb(Ver, (rand() % 4) + 10, PL, P3);
                else if (i == 1) create_word_genre(Adj, Fem, PL);
            }
        }
    }
    printf(".\n");
}

void create_sentence_2(p_base_tree Ver, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom) {
    srand(time(NULL));

    int genre = rand() % 2;
    int nombre = rand() % 2;
    int determinant = rand() % 2;

    if (nombre == 0) {
        if (genre == 0) {
            if (determinant == 0) printf("Le");
            else printf("Un");
            for (int i = 0; i < 6; i++) {
                srand(i);
                if (i == 0) create_word_genre(Nom, Mas, SG);
                if (i == 1) printf(" qui");
                else if (i == 2 || i == 3) create_word_verb(Ver, (rand() % 4) + 10, SG, P3);
                else if (i == 4)
                {
                    if (determinant == 0) printf(" le");
                    else printf(" un");
                    create_word_genre(Nom, Mas, SG);
                }
                else if (i == 5) create_word_genre(Adj, Mas, SG);
            }
        } else {
            if (determinant == 0) printf("La");
            else printf("Une");
            for (int i = 0; i < 6; i++) {
                srand(i);
                if (i == 0) create_word_genre(Nom, Fem, SG);
                if (i == 1) printf(" qui");
                else if (i == 2 || i == 3) create_word_verb(Ver, (rand() % 4) + 10, SG, P3);
                else if (i == 4)
                {
                    if (determinant == 0) printf(" la");
                    else printf(" une");
                    create_word_genre(Nom, Fem, SG);
                }
                else if (i == 5) create_word_genre(Adj, Fem, SG);
            }
        }
    } else {
        if (determinant == 0) printf("Les");
        else printf("Des");
        if (genre == 0) {
            for (int i = 0; i < 6; i++) {
                srand(i);
                if (i == 0) create_word_genre(Nom, Mas, PL);
                if (i == 1) printf(" qui");
                else if (i == 2 || i == 3) create_word_verb(Ver, (rand() % 4) + 10, PL, P3);
                else if (i == 4)
                {
                    if (determinant == 0) printf(" les");
                    else printf(" des");
                    create_word_genre(Nom, Mas, PL);
                }
                else if (i == 5) create_word_genre(Adj, Mas, PL);
            }
        } else {
            for (int i = 0; i < 6; i++) {
                srand(i);
                if (i == 0) create_word_genre(Nom, Fem, PL);
                if (i == 1) printf(" qui");
                else if (i == 2 || i == 3) create_word_verb(Ver, (rand() % 4) + 10, PL, P3);
                else if (i == 4)
                {
                    if (determinant == 0) printf(" les");
                    else printf(" des");
                    create_word_genre(Nom, Fem, PL);
                }
                else if (i == 5) create_word_genre(Adj, Fem, PL);
            }
        }
    }
    printf(".\n");
}

void create_sentence_3(p_base_tree Ver, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom) {
    // Adv , Nom Adj Verb
    srand(time(NULL));

    int genre = rand() % 2;
    int nombre = rand() % 2;
    int determinant = rand() % 2;

    if (nombre == 0) {
        if (genre == 0) {
            for (int i = 0; i < 6; i++) {
                srand(i);
                if (i == 0) create_word_adv(Adv);
                else if (i == 1) printf(", ");
                else if (i == 2)
                {
                    if (determinant == 0) printf("le");
                    else printf("un");
                    create_word_genre(Nom, Mas, SG);
                }
                else if (i == 3) create_word_genre(Adj, Mas, SG);
                else if (i == 4) create_word_verb(Ver, (rand() % 4) + 10, SG, P3);
            }
        } else {
            for (int i = 0; i < 6; i++) {
                srand(i);
                if (i == 0) create_word_adv(Adv);
                else if (i == 1) printf(", ");
                else if (i == 2)
                {
                    if (determinant == 0) printf("la");
                    else printf("une");
                    create_word_genre(Nom, Fem, SG);
                }
                else if (i == 3) create_word_genre(Adj, Fem, SG);
                else if (i == 4) create_word_verb(Ver, (rand() % 4) + 10, SG, P3);
            }
        }
    } else {
        if (genre == 0) {
            for (int i = 0; i < 6; i++) {
                srand(i);
                if (i == 0) create_word_adv(Adv);
                else if (i == 1) printf(", ");
                else if (i == 2)
                {
                    if (determinant == 0) printf("les");
                    else printf("des");
                    create_word_genre(Nom, Mas, PL);
                }
                else if (i == 3) create_word_genre(Adj, Mas, PL);
                else if (i == 4) create_word_verb(Ver, (rand() % 4) + 10, PL, P3);
            }
        } else {
            for (int i = 0; i < 6; i++) {
                srand(i);
                if (i == 0) create_word_adv(Adv);
                else if (i == 1) printf(", ");
                else if (i == 2)
                {
                    if (determinant == 0) printf("les");
                    else printf("des");
                    create_word_genre(Nom, Fem, PL);
                }
                else if (i == 3) create_word_genre(Adj, Fem, PL);
                else if (i == 4) create_word_verb(Ver, (rand() % 4) + 10, PL, P3);
            }
        }
    }
    printf(".\n");
}

void create_word_verb(p_base_tree Verb, sub_type temps, sub_type nombre, sub_type pluriel) {

    srand(time(NULL) + rand() % 1000);

    int letter = rand () % 26;   //aléatoirement l'abre commençant par une lettre
    p_base_node node = NULL;

    while (Verb->root[letter] == NULL) letter = rand() % 26;
    node = Verb->root[letter];

    int suite = 1;
    int i;

    while (node->nb_forme_flechie == 0 || suite == 1) {//tanque je n'atteint pas une forme fléchie et qu'il existe une suite

        suite = 0;

        i = rand() % 26;
        while (node->fils[i] == NULL) i = rand() % 26;
        node = node->fils[i];  // je vais dans le fils

        if (node->nb_forme_flechie > 0) {
            char* mot = isVerbFlechieInList(node->flechie_list->head, temps, nombre, pluriel);
            if (mot != NULL)
            {
                printf(" %s", mot);
                suite = 0;
            }
            else
            {
                letter = rand () % 26;
                while (Verb->root[letter] == NULL) letter = rand() % 26;
                node = Verb->root[letter];
                suite = 1;
            }
        }
    }
}

void create_word_genre(p_base_tree tree, sub_type genre, sub_type pluriel) {

    srand(time(NULL) + rand() % 1000);

    int letter = rand () % 26;   //aléatoirement l'abre commençant par une lettre
    p_base_node node = NULL;

    while (tree->root[letter] == NULL) letter = rand() % 26;
    node = tree->root[letter];

    int suite = 1;
    int i;

    while (node->nb_forme_flechie == 0 || suite == 1) {//tanque je n'atteint pas une forme fléchie et qu'il existe une suite

        suite = 0;

        i = rand() % 26;
        while (node->fils[i] == NULL) i = rand() % 26;
        node = node->fils[i];  // je vais dans le fils

        if (node->nb_forme_flechie > 0) {
            int random = rand() % 2;
            char* mot;
            if (random == 0) mot = isGenreFlechieInList(node->flechie_list->head, InvGen, pluriel);
            else mot = isGenreFlechieInList(node->flechie_list->head, genre, pluriel);
            if (mot != NULL)
            {
                printf(" %s", mot);
                suite = 0;
            }
            else
            {
                letter = rand () % 26;
                while (tree->root[letter] == NULL) letter = rand() % 26;
                node = tree->root[letter];
                suite = 1;
            }
        }
    }
}

void create_word_adv(p_base_tree tree)
{
    srand(time(NULL) + rand() % 1000);

    int letter = rand () % 26;   //aléatoirement l'abre commençant par une lettre
    p_base_node node = NULL;

    while (tree->root[letter] == NULL) letter = rand() % 26;
    node = tree->root[letter];

    int suite = 1;
    int i;

    while (node->nb_forme_flechie == 0 || suite == 1) {//tanque je n'atteint pas une forme fléchie et qu'il existe une suite

        suite = 0;

        i = rand() % 26;
        while (node->fils[i] == NULL) i = rand() % 26;
        node = node->fils[i];  // je vais dans le fils

        if (node->nb_forme_flechie > 0) {
            char mot[LENGHT_MAX];
            strcpy(mot, node->flechie_list->head->value);
            mot[0] = mot[0] - 32;
            printf("%s", mot);
        }
    }
}
