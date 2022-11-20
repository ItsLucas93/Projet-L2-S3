#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include "file_manager.h"
#include "phrase.h"

void bienvenue();
void menu_principal(p_base_tree, p_base_tree, p_base_tree, p_base_tree);
void menu_recherche_de_mots(p_base_tree, p_base_tree, p_base_tree, p_base_tree);

int main()
{
    // Initialisation des arbres
    p_base_tree Nom = createEmptyBaseTree();
    p_base_tree Adj = createEmptyBaseTree();
    p_base_tree Adv = createEmptyBaseTree();
    p_base_tree Ver = createEmptyBaseTree();

    create_typed_tree(Nom, Adj, Adv, Ver);

    setbuf(stdout, 0);
    printf("Initialisation des arbres termine.\n");

    // Menu principal
    bienvenue();
    menu_principal(Nom, Adj, Adv, Ver);
    printf("\n-+-+-+-+-+-+-+-+-+\n"
          "Sortie du programme.\n"
          "-+-+-+-+-+-+-+-+-+\n");

    return 0;
}

void bienvenue()
/*
 * Fonction: bienvenue
 * -----------------
 * Juste un message de bienvenue
 * Underline générée par : https://fsymbols.com/generators/wide/
 */
{
    printf("\n\nGenerateur de phrase\n");
}

void menu_principal(p_base_tree Nom, p_base_tree Adj, p_base_tree Adv, p_base_tree Ver)
/*
 * Fonction: menu_principal
 * -----------------
 * Menu principal, l'utilisateur à trois choix possible
 */
{
    char choix = '-';
    do
    {
        setbuf(stdout, 0);
        printf("Menu principal. Choisissez votre menu :\n"
               "1 - Modele 1 : nom - adjectif - verbe - nom\n"
               "2 - Modele 2 : nom - 'qui' - verbe - verbe - nom - adjectif\n"
               "3 - Modele 3 : (Modele personnalise) adverbe - nom - adjectif - verbe\n"
               "4 - Menu de recherche de mots\n"
               "5 - Quitter le programme.\n");
        scanf(" %c", &choix);
        switch (choix) {
            case '1': {
                // Appel de la génération 1
                create_sentence_1(Ver, Adj, Adv, Nom);
                break;
            }
            case '2': {
                create_sentence_2(Ver, Adj, Adv, Nom);
                // Appel de la génération 2
                break;
            }
            case '3': {
                // Appel de la génération 3
                create_sentence_3(Ver, Adj, Adv, Nom);
                break;
            }
            case '4': {
                // Appel de la recherche de mot
                menu_recherche_de_mots(Nom, Adj, Adv, Ver);
                break;
            }
            case '5': {
                break;
            }
            default:
                printf("Choix non valide. Veuillez reessayez à nouveau.\n");
        }
    } while (choix != '5');
}

void menu_recherche_de_mots(p_base_tree Nom, p_base_tree Adj, p_base_tree Adv, p_base_tree Ver)
{
    char choix = '-';
    do
    {
        setbuf(stdout, 0);
        printf("Menu recherche de mots. Faites votre choix :\n"
               "1. Rechercher un mot parmi les formes de base\n"
               "2. Mot aleatoire parmi les formes de base\n"
               "3. Rechercher un mot parmi les formes flechies\n"
               "4 - Quitter le programme.\n");
        scanf(" %c", &choix);
        switch (choix) {
            case '1':
            {
                // Recherche forme de base
                /*
                char chaine_1[30];
                setbuf(stdout, 0);
                printf("Inserez un mot : ");
                scanf(" %s", chaine_1);
                rechercheFormeBase(Ver, Adj, Adv, Nom, chaine_1);
                */
                printf("// Implémentation en suspend par manque de temps\n");
                break;
            }
            case '2':
            {
                // Mot aléatoire parmi le formes de base
                char* test = extraire_random_base(Ver, Adj, Adv, Nom, 0);
                printf("\nMot aleatoire : %s\n", test);
                break;
            }
            case '3':
            {
                // Recherche
                char chaine_2[30];

                printf("Inserez un mot : ");
                scanf(" %s", chaine_2);
                rechercheFormeFlechie(Ver, Adj, Adv, Nom, chaine_2);
                break;
            }
            case '4':
            {
                // Appel de la recherche de mot
                break;
            }
            default: printf("Choix non valide. Veuillez reessayez à nouveau.\n");
        }
    } while (choix != '4');
}
