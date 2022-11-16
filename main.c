#include <stdlib.h>
#include <stdio.h>

#include "file_manager.h"
#include "base_tree.h"

void bienvenue();
void menu_principal();

int main(void)
{

    // Initialisation des arbres
    t_base_tree verb, adj, adv, nom;
    verb = createEmptyBaseTree();
    adj = createEmptyBaseTree();
    adv = createEmptyBaseTree();
    nom = createEmptyBaseTree();
    create_typed_tree(&verb, &adj, &adv, &nom);


    /*
    bienvenue();
    menu_principal();

    printf("\n-+-+-+-+-+-+-+-+-+\n"
           "Sortie du programme.\n"
           "-+-+-+-+-+-+-+-+-+\n");
    */

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
    printf("\033[0;34mG̲é̲n̲é̲r̲a̲t̲e̲u̲r̲ d̲e̲ p̲h̲r̲a̲s̲e̲s̲\n");
    printf("\033[0m"); // Reset color
}

void menu_principal()
/*
 * Fonction: menu_principal
 * -----------------
 * Menu principal, l'utilisateur à trois choix possible
 */
{
    int choix = -1;
    do
    {
        printf("\033[1mMenu principal. \033[2;34mChoisissez votre menu : \033[0m\n"
               "1 - Modèle n°1 : nom - adjectif - verbe - nom\n"
               "2 - Modèle n°2 : nom - 'qui' - verbe - verbe - nom - adjectif\n"
               "3 - Modèle n°3 : (Modèle personnalisé)\n"
               "4 - Rechercher un mot parmi les formes fléchies\n"
               "5 - Quitter le programme.\n");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
            {
                // Appel de la génération 1
                break;
            }
            case 2:
            {
                // Appel de la génération 2
                break;
            }
            case 3:
            {
                // Appel de la génération 3
                break;
            }
            case 4:
            {
                // Appel de la recherche de mot
                break;
            }
            case 5:
            {
                break;
            }
            default: printf("\033[1;31mChoix non valide. Veuillez réessayez à nouveau.\033[0m\n");
        }
    } while (choix != 5);
}