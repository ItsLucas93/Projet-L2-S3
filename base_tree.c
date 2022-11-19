#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "base_tree.h"
#include "base_node.h"

p_base_tree createEmptyBaseTree()
/*
 * Fonction: createEmptyBaseTree
 * -----------------
 * Crée l'arbre des formes de bases et renvoie un pointeur sur le premier étage de cet arbre
 * Etage de taille ALPHABET_SIZE (26 + 1, 1 pour rentrer les caractères spéciaux : ' et -)
 *
 * t: p_base_tree
 */
{
    p_base_tree t = (p_base_tree) malloc (sizeof(t_base_tree));

    for (int i = 0 ; i < ALPHABET_SIZE ; i++)
    {
        t->root[i] = NULL;

    }
    return t;
}

p_base_node insertBaseTree(p_base_tree t, char* mot)
/*
 * Fonction: insertBaseTree
 * -----------------
 * Injecte dans l'arbre le mot
 * L'indice est associé à la lettre (a = 0; b = 1 ; ... ; z = 25 ; '- = 26);
 * L'entrée des mots provient du fichier dictionnaire non accentué, qui ont des caractères minuscules
 *
 * Pré-condition : Si le mot est vide (lenght_word == 0), renvoie un pointeur NULL
 * Première étape : Positionnement au premier étage (crée un t_base_node si n'existe pas)
 * Deuxième étape : Construit avec le reste des lettres les nodes suivants
 * Fin : Retourne un pointeur vers le dernier node
 *
 * t: p_base_tree
 * mot: char*
 * idx: int
 * temp: p_base_node
 */
{
    unsigned long lenght_word = strlen(mot);

    if (lenght_word) {

        // On gère les indices par le code ASCII (en sachant que les entrés du fichier son des lettres minuscules)
        int idx = (int) mot[0] - 97;

        // Si le node n'est pas occupé par une lettre (donc est NULL), on crée le node
        if (t->root[idx] == NULL)
        {
            t->root[idx] = createBaseNode();
            t->root[idx]->value = mot[0];
        }

        p_base_node temp = t->root[idx];

        for (unsigned long i = 1; i < lenght_word; i++)
        {
            idx = 0;

            // Traitement de cas des deux caractères spéciaux ' et -
            if (mot[i] == '-' || mot[i] == '\'') idx = 26;
            else idx = ((int) mot[i] - 97);

            // Si le node n'est pas occupé par une lettre (donc est NULL), on crée le node
            if (temp->fils[idx] == NULL)
            {
                temp->fils[idx] = createBaseNode();
                temp = temp->fils[idx];
                temp->value = mot[i];
            }
            // Sinon on va dans le node pusqu'il existe déjà
            else
            {
                temp = temp->fils[idx];
            }
        }

        // On retourne un pointeur vers le dernier node pour traiter la partie des formes fléchies
        return temp;
    }

    // On retourne NULL si la chaîne de caractère est vide
    return NULL;
}

p_base_node isBaseInTree(p_base_tree t, const char* chaine)
/*
 * Fonction: isBaseInTree
 * -----------------
 * Vérifie si le mot de base est dans l'arbre.
 * L'indice est associé à la lettre (a = 0; b = 1 ; ... ; z = 25 ; '- = 26);
 * L'entrée des mots provient d'une entrée utilisateur, qui ont des caractères minuscules
 *
 * Pré-condition : Si le mot est vide (lenght_word == 0), renvoie un pointeur NULL
 * Un filtre de l'indice est faite en fonction si le caractère est majuscule ou miniscule à chaque étape
 * Si à la fin du parcours, on atteint un node avec un nb_forme_flechie != 0, alors on renvoie le pointeur sur ce node, sinon on renvoie un pointeur NULL
 *
 *
 * t: p_base_tree
 * chaine: const char*
 * idx: int
 * pn: p_base_node
 */
{
    if (strlen(chaine) == 0) return NULL;

    p_base_node pn = NULL;

    // Indexation selon le tableau
    // Positionnement sur le premier étage
    // Caractère majuscule
    int idx = 0;
    if ((int) chaine[0] >= 65 && (int) chaine[0] <= 90)
    {
        idx = (int) chaine[0] - 65;
        pn = t->root[idx];
    }
    // Caractères - et '
    else if (chaine[0] == '-' || chaine[0] == '\'')
    {
        idx = ALPHABET_SIZE - 1;
        pn = t->root[idx];
    }
    // Caractère minuscule
    else if ((int) chaine[0] >= 97 && (int) chaine[0] <= 122)
    {
        idx = (int) chaine[0] - 97;
        pn = t->root[idx];
    }
    // Caractère non répertorié - Sortie de Programme
    else
    {
        return NULL;
    }

    // Vérification
    if (pn == NULL) return NULL; // Pas de valeur sur la case du tableau

    // Parcours du tableau
    for (int i = 1; i < strlen(chaine); i++)
    {
        // Indexation selon le tableau
        // Caractère majuscule
        idx = 0;
        if ((int) chaine[i] >= 65 && (int) chaine[i] <= 90)
        {
            idx = (int) chaine[i] - 65;
            pn = pn->fils[idx];
        }
        // Caractères - et '
        else if (chaine[i] == '-' || chaine[i] == '\'')
        {
            idx = ALPHABET_SIZE - 1;
            pn = pn->fils[idx];
        }
        // Caractère minuscule
        else if ((int) chaine[i] >= 97 && (int) chaine[i] <= 122)
        {
            idx = (int) chaine[i] - 97;
            pn = pn->fils[idx];
        }
        // Caractère non répertorié - Sortie de Programme
        else
        {
            return NULL;
        }

        // Vérification
        if (pn == NULL) return NULL; // Pas de valeur sur la case du tableau
    }

    // Fin de la forme de base ? si pas de forme flechie, mot incomplet
    if (pn->nb_forme_flechie == 0) return NULL;

    return pn;
}

void rechercheFormeBase(p_base_tree Verb, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom, const char* chaine)
/*
 * Fonction: rechercheFormeBase
 * -----------------
 * Recherche dans l'arbre une forme de base saisie par l'utilisateur
 *
 * Parcours les 4 arbres et affiche les formes fléchies ainsi que leurs types
 *
 * Verb: p_base_tree
 * Adj: p_base_tree
 * Adv: p_base_tree
 * Nom: p_base_tree
 * chaine: const char*
 */
{
    if (strlen(chaine) == 0 || (strlen(chaine) > 25))
    {
        printf("Chaine incompatible (votre chaine est = 0 ou > à 25) !\n");
        return;
    }

    p_base_node pn = isBaseInTree(Nom, chaine);
    printf("-=-=-=-=-=-= Nom =-=-=-=-=-=-\n");
    if (pn == NULL)
    {
        printf("Forme de base non trouve.\n");
    }
    else
    {
        printf("%s trouve ! Type : Nom\n"
               "Forme(s) flechie(s) : \n", chaine);
        printFlechieList(pn->flechie_list);
    }
    
    pn = isBaseInTree(Adj, chaine);
    printf("-=-=-=-=-=-= Ajdectif =-=-=-=-=-=-\n");
    if (pn == NULL)
    {
        printf("Forme de base non trouve.\n");
    }
    else
    {
        printf("%s trouve ! Type : Adjectif\n"
               "Forme(s) flechie(s) : \n", chaine);
        printFlechieList(pn->flechie_list);
    }

    pn = isBaseInTree(Adv, chaine);
    printf("-=-=-=-=-=-= Adverbe =-=-=-=-=-=-\n");
    if (pn == NULL)
    {
        printf("Forme de base non trouve.\n");
    }
    else
    {
        printf("%s trouve ! Type : Adverbe\n"
               "Forme(s) flechie(s) : \n%s:Adverbe", chaine, chaine);
    }

    pn = isBaseInTree(Verb, chaine);
    printf("-=-=-=-=-=-= Verbe =-=-=-=-=-=-\n");
    if (pn == NULL)
    {
        printf("Forme de base non trouve.\n");
    }
    else
    {
        printf("%s trouve ! Type : Verbe\n"
               "Forme(s) flechie(s) : \n", chaine);
        printFlechieList(pn->flechie_list);
    }
    printf("-=-=-=-=-=-= Fin de la recherche =-=-=-=-=-=-\n");
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