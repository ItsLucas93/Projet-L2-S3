#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "phrase.h"
#include "enum_node.h"

void createSentenceModel1(p_base_tree Ver, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom)
/*
 * Fonction: createSentenceModel1
 * -----------------
 * Génère et affiche une phrase selon le modèle 1 :
 * Modèle : Nom – Adjectif – Verbe – Nom
 *
 * Le temps du verbe est choisi aléatoirement entre les temps de l'Indicatif simple
 * Le genre (Mas, Fem), le nombre (SG, PL) et le determinant (Un/Une/Des/Le/La/Les)
 *
 * Ver: p_base_tree
 * Adj: p_base_tree
 * Adv: p_base_tree
 * Nom: p_base_tree
 * genre: int
 * nombre: int
 * determinant: int
 */
{

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
                if (i == 0 || i == 3) createWordGenre(Nom, Mas, SG);
                else if (i == 2) createWordVerb(Ver, (rand() % 4) + 10, SG, P3);
                else if (i == 1) createWordGenre(Adj, Mas, SG);
            }
        } else {
            if (determinant == 0) printf("La");
            else printf("Une");
            for (int i = 0; i < 4; i++) {
                srand(i);
                if (i == 0 || i == 3) createWordGenre(Nom, Fem, SG);
                else if (i == 2) createWordVerb(Ver, (rand() % 4) + 10, SG, P3);
                else if (i == 1) createWordGenre(Adj, Fem, SG);
            }
        }
    } else {
        if (determinant == 0) printf("Les");
        else printf("Des");
        if (genre == 0) {
            for (int i = 0; i < 4; i++) {
                srand(i);
                if (i == 0 || i == 3) createWordGenre(Nom, Mas, PL);
                else if (i == 2) createWordVerb(Ver, (rand() % 4) + 10, PL, P3);
                else if (i == 1) createWordGenre(Adj, Mas, PL);
            }
        } else {
            for (int i = 0; i < 4; i++) {
                srand(i);
                if (i == 0 || i == 3) createWordGenre(Nom, Fem, PL);
                else if (i == 2) createWordVerb(Ver, (rand() % 4) + 10, PL, P3);
                else if (i == 1) createWordGenre(Adj, Fem, PL);
            }
        }
    }
    printf(".\n");
}

void createSentenceModel2(p_base_tree Ver, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom)
/*
 * Fonction: createSentenceModel2
 * -----------------
 * Génère et affiche une phrase selon le modèle 2 :
 * Modèle : Nom – ‘qui’ – Verbe – Verbe – Nom – Adjectif
 *
 * Le temps du verbe est choisi aléatoirement entre les temps de l'Indicatif simple
 * Le genre (Mas, Fem), le nombre (SG, PL) et le determinant (Un/Une/Des/Le/La/Les)
 *
 * Ver: p_base_tree
 * Adj: p_base_tree
 * Adv: p_base_tree
 * Nom: p_base_tree
 * genre: int
 * nombre: int
 * determinant: int
 */
 {
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
                if (i == 0) createWordGenre(Nom, Mas, SG);
                if (i == 1) printf(" qui");
                else if (i == 2 || i == 3) createWordVerb(Ver, (rand() % 4) + 10, SG, P3);
                else if (i == 4)
                {
                    if (determinant == 0) printf(" le");
                    else printf(" un");
                    createWordGenre(Nom, Mas, SG);
                }
                else if (i == 5) createWordGenre(Adj, Mas, SG);
            }
        } else {
            if (determinant == 0) printf("La");
            else printf("Une");
            for (int i = 0; i < 6; i++) {
                srand(i);
                if (i == 0) createWordGenre(Nom, Fem, SG);
                if (i == 1) printf(" qui");
                else if (i == 2 || i == 3) createWordVerb(Ver, (rand() % 4) + 10, SG, P3);
                else if (i == 4)
                {
                    if (determinant == 0) printf(" la");
                    else printf(" une");
                    createWordGenre(Nom, Fem, SG);
                }
                else if (i == 5) createWordGenre(Adj, Fem, SG);
            }
        }
    } else {
        if (determinant == 0) printf("Les");
        else printf("Des");
        if (genre == 0) {
            for (int i = 0; i < 6; i++) {
                srand(i);
                if (i == 0) createWordGenre(Nom, Mas, PL);
                if (i == 1) printf(" qui");
                else if (i == 2 || i == 3) createWordVerb(Ver, (rand() % 4) + 10, PL, P3);
                else if (i == 4)
                {
                    if (determinant == 0) printf(" les");
                    else printf(" des");
                    createWordGenre(Nom, Mas, PL);
                }
                else if (i == 5) createWordGenre(Adj, Mas, PL);
            }
        } else {
            for (int i = 0; i < 6; i++) {
                srand(i);
                if (i == 0) createWordGenre(Nom, Fem, PL);
                if (i == 1) printf(" qui");
                else if (i == 2 || i == 3) createWordVerb(Ver, (rand() % 4) + 10, PL, P3);
                else if (i == 4)
                {
                    if (determinant == 0) printf(" les");
                    else printf(" des");
                    createWordGenre(Nom, Fem, PL);
                }
                else if (i == 5) createWordGenre(Adj, Fem, PL);
            }
        }
    }
    printf(".\n");
}

void createSentenceModel3(p_base_tree Ver, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom)
/*
 * Fonction: createSentenceModel3
 * -----------------
 * Génère et affiche une phrase selon le modèle 2=3 :
 * Modèle : Nom – ‘qui’ – Verbe – Verbe – Nom – Adjectif
 *
 * Le temps du verbe est choisi aléatoirement entre les temps de l'Indicatif simple
 * Le genre (Mas, Fem), le nombre (SG, PL) et le determinant (Un/Une/Des/Le/La/Les)
 *
 * Ver: p_base_tree
 * Adj: p_base_tree
 * Adv: p_base_tree
 * Nom: p_base_tree
 * genre: int
 * nombre: int
 * determinant: int
 */
 {
    srand(time(NULL));

    int genre = rand() % 2;
    int nombre = rand() % 2;
    int determinant = rand() % 2;

    if (nombre == 0) {
        if (genre == 0) {
            for (int i = 0; i < 6; i++) {
                srand(i);
                if (i == 0) createWordAdv(Adv);
                else if (i == 1) printf(", ");
                else if (i == 2)
                {
                    if (determinant == 0) printf("le");
                    else printf("un");
                    createWordGenre(Nom, Mas, SG);
                }
                else if (i == 3) createWordGenre(Adj, Mas, SG);
                else if (i == 4) createWordVerb(Ver, (rand() % 4) + 10, SG, P3);
            }
        } else {
            for (int i = 0; i < 6; i++) {
                srand(i);
                if (i == 0) createWordAdv(Adv);
                else if (i == 1) printf(", ");
                else if (i == 2)
                {
                    if (determinant == 0) printf("la");
                    else printf("une");
                    createWordGenre(Nom, Fem, SG);
                }
                else if (i == 3) createWordGenre(Adj, Fem, SG);
                else if (i == 4) createWordVerb(Ver, (rand() % 4) + 10, SG, P3);
            }
        }
    } else {
        if (genre == 0) {
            for (int i = 0; i < 6; i++) {
                srand(i);
                if (i == 0) createWordAdv(Adv);
                else if (i == 1) printf(", ");
                else if (i == 2)
                {
                    if (determinant == 0) printf("les");
                    else printf("des");
                    createWordGenre(Nom, Mas, PL);
                }
                else if (i == 3) createWordGenre(Adj, Mas, PL);
                else if (i == 4) createWordVerb(Ver, (rand() % 4) + 10, PL, P3);
            }
        } else {
            for (int i = 0; i < 6; i++) {
                srand(i);
                if (i == 0) createWordAdv(Adv);
                else if (i == 1) printf(", ");
                else if (i == 2)
                {
                    if (determinant == 0) printf("les");
                    else printf("des");
                    createWordGenre(Nom, Fem, PL);
                }
                else if (i == 3) createWordGenre(Adj, Fem, PL);
                else if (i == 4) createWordVerb(Ver, (rand() % 4) + 10, PL, P3);
            }
        }
    }
    printf(".\n");
}

void createWordVerb(p_base_tree Verb, sub_type temps, sub_type nombre, sub_type pluriel)
/*
 * Fonction: createWordVerb
 * -----------------
 * On reprends le même principe de parcours aléatoire utilisé lors de la rechercheFormeBase()
 * Dès qu'il trouve une forme fléchie associée avec les sous_types en paramètre on affiche le mot
 *
 * Est pris en paramètre l'arbre verbe
 *
 * Ver: p_base_tree
 * temps: sub_type
 * nombre: sub_type
 * pluriel: sub_type
 * i: int
 * letter: int
 * node: p_base_node
 */
{

    srand(time(NULL) + rand() % 1000);

    // Choix aléatoire
    int letter = rand () % 26;
    p_base_node node = NULL;

    while (Verb->root[letter] == NULL) letter = rand() % 26;
    node = Verb->root[letter];

    int suite = 1;
    int i;

    // Est dans la boucle tant que pas de forme fléchie ou suite == 1
    while (node->nb_forme_flechie == 0 || suite == 1) {

        suite = 0;

        // Choix aléatoire
        i = rand() % 26;
        while (node->fils[i] == NULL) i = rand() % 26;
        node = node->fils[i];

        // Si présence de forme fléchie
        if (node->nb_forme_flechie > 0)
        {
            // Est-ce que les sous_types sont présents dans cette liste de forme fléchie ? Si non, mot = NULL
            char* mot = isVerbFlechieInList(node->flechie_list->head, temps, nombre, pluriel);

            // Si mot trouvé
            if (mot != NULL)
            {
                printf(" %s", mot);
                suite = 0;
            }
            // Sinon on repart dans la boucle à partir de la racine de l'arbre
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

void createWordGenre(p_base_tree tree, sub_type genre, sub_type pluriel)
/*
 * Fonction: createWordVerb
 * -----------------
 * On reprends le même principe de parcours aléatoire utilisé lors de la rechercheFormeBase()
 * Dès qu'il trouve une forme fléchie associée avec les sous_types en paramètre on affiche le mot

 * Prends en paramètre un arbre nom ou adjectif
 * Est utilisé le sous_type InvGen choisi aléatoirement par la variable random à la place de féminin masculin
 *
 * tree: p_base_tree
 * nombre: sub_type
 * pluriel: sub_type
 * i: int
 * letter: int
 * random: int
 * node: p_base_node
 */
{

    srand(time(NULL) + rand() % 1000);

    // Choix aléatoire
    int letter = rand () % 26;
    p_base_node node = NULL;

    while (tree->root[letter] == NULL) letter = rand() % 26;
    node = tree->root[letter];

    int suite = 1;
    int i;

    // Est dans la boucle tant que pas de forme fléchie ou suite == 1
    while (node->nb_forme_flechie == 0 || suite == 1) {

        suite = 0;

        // Choix aléatoire
        i = rand() % 26;
        while (node->fils[i] == NULL) i = rand() % 26;
        node = node->fils[i];

        if (node->nb_forme_flechie > 0)
        {
            // Choix aléatoire
            int random = rand() % 2;
            char* mot;

            // Est-ce que les sous_types sont présents dans cette liste de forme fléchie ? Si non, mot = NULL
            // On choisit aussi aléatoirement si on prend les formes en paramètre ou la forme InvGen
            if (random == 0) mot = isGenreFlechieInList(node->flechie_list->head, InvGen, pluriel);
            else mot = isGenreFlechieInList(node->flechie_list->head, genre, pluriel);

            // Si mot trouvé
            if (mot != NULL)
            {
                printf(" %s", mot);
                suite = 0;
            }
            // Sinon on repart dans la boucle à partir de la racine de l'arbre
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

void createWordAdv(p_base_tree tree)
/*
 * Fonction: createWordAdv
 * -----------------
 * On reprends le même principe de parcours aléatoire utilisé lors de la rechercheFormeBase()
 * Dès qu'il trouve une forme fléchie on affiche le mot
 *
 * Prends en paramètre un arbre adverbe
 * Toutes les formes fléchies sont de même sous_type, donc pas besoin de vérifier les sous_types
 *
 * tree: p_base_tree
 * i: int
 * letter: int
 * node: p_base_node
 */
{
    srand(time(NULL) + rand() % 1000);

    // Choix aléatoire
    int letter = rand () % 26;
    p_base_node node = NULL;

    while (tree->root[letter] == NULL) letter = rand() % 26;
    node = tree->root[letter];

    int i;

    // Est dans la boucle tant que pas de forme fléchie
    while (node->nb_forme_flechie == 0)
    {

        i = rand() % 26;
        while (node->fils[i] == NULL) i = rand() % 26;
        node = node->fils[i];  // je vais dans le fils

        // Si mot trouvé
        if (node->nb_forme_flechie > 0) {
            char mot[LENGHT_MAX];
            strcpy(mot, node->flechie_list->head->value);
            mot[0] = mot[0] - 32;
            printf("%s", mot);
        }
    }
}
