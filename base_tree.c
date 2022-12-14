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


void rechercheFormeFlechie(p_base_tree Verb, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom, const char* chaine)
/*
 * Fonction: rechercheFormeFlechie
 * -----------------
 * /!\ Non implémenté par manque de temps
 * Recherche dans l'arbre une forme de base saisie par l'utilisateur
 *
 * Parcours les 4 arbres et pour rechercher la forme fléchie pas l'entrée utilisateur
 *
 * On coupe la chaine en deux et se positionne dans l'arbre
 * Puis on cherche dans l'arbre
 *
 * Verb: p_base_tree
 * Adj: p_base_tree
 * Adv: p_base_tree
 * Nom: p_base_tree
 * chaine: const char*
 */
{

    srand(time(NULL));

    int idx = (int) chaine[0] - 97;
    p_base_node pn = Verb->root[idx];

    for (int i = 1 ; i <= strlen(chaine) / 2 ; i++)
    {
        idx = (int) chaine[i] - 97;
        pn = pn->fils[idx];
    }

    p_base_node temp = pn;
    int suite = 1;
    while (suite != 0)
    {
        suite = 0;
        while(temp->nb_forme_flechie != 0)
        {
            idx = rand() % 26;
            while(temp->fils[idx] == NULL)
            {
                idx = rand() % 26;
            }
            temp = temp->fils[idx];
        }

        p_flechie_node temp_flechie_node = isFlechieCharInList(temp->flechie_list, chaine);
        if (temp_flechie_node != NULL)
        {
            setbuf(stdout, 0);
            printf("-=-=-=-=-=-= Forme Fléchie trouvé =-=-=-=-=-=-\n"
                   "%s : ", temp_flechie_node->value);
            printFlechieList(pn->flechie_list);
        }
        else suite = 1;
    }
}

char* extraireRandomBase(p_base_tree Verb, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom, int select_tree)
/*
 * Fonction: extraireRandomBase
 * -----------------
 * Extrait une forme de base au hasard
 *
 * Parcours l'un des 4 arbres au hasard
 *
 * On regarde aléatoirement un fils non-NULL et on rentre dedans.
 * On fait l'action précédente jusqu'à tomber sur un node qui possède des formes fléchies.
 * À ce moment-là, on randomise 1 chance sur 2 pour s'arrêter ou continuer.
 * Si on s'arrête, on retourne la chaine de caractère de la forme de base.
 *
 * Verb: p_base_tree
 * Adj: p_base_tree
 * Adv: p_base_tree
 * Nom: p_base_tree
 * select_tree: int (0 = aléatoire [Par défaut]; 1 = Verb ; 2 = Adj ; 3 = Adv : 4 = Nom)
 */
{
    char* base = (char*) malloc (ALPHABET_SIZE * sizeof(char));
    for (int z = 0; z < ALPHABET_SIZE ; z++) base[z] = '\0';

    int c = 0;

    srand(time(NULL));

    if (select_tree == 0)
    {
        do {
            select_tree = rand() % 5;
        } while (select_tree == 0);
    }

    int letter = rand () % 26;   //aléatoirement l'abre commençant par une lettre
    p_base_node node = NULL;

    switch (select_tree)  //on va dans le premier noeud de l'arbre
    {
        case 1:
        {
            while (Verb->root[letter] == NULL){
                letter = rand() % 26;
            }
            node = Verb->root[letter];
            break;
        }

        case 2:
        {
            while (Adj->root[letter] == NULL){
                letter = rand() % 26;
            }
            node = Adj->root[letter];
            break;
        }

        case 3:
        {
            while (Adv->root[letter] == NULL){
                letter = rand() % 26;
            }
            node = Adv->root[letter];
            break;
        }

        case 4:
        {
            while (Nom->root[letter] == NULL){
                letter = rand() % 26;
            }
            node = Nom->root[letter];
            break;
        }

        default:
        {
            while (Nom->root[letter] == NULL){
                letter = rand() % 26;
            }
            node = Nom->root[letter];
        }
    }

    int suite = 1;
    int i;

    while (node->nb_forme_flechie == 0 || suite == 1) {//tanque je n'atteint pas une forme fléchie et qu'il existe une suite
        suite = 0;

        i = rand() % 26;
        while (node->fils[i] == NULL) {  //je vais dans un fils aléatoirement
            i = rand() % 26;
        }
        base[c] = node->value; //je stocke le char dans la forme de base
        node = node->fils[i];  // je vais dans le fils
        c++;                // je passe au caractère suivant

        int est_vide = 1;  //je regarde si il possède des fils
        for (int j = 0; j < 26; j++) {
            if (node->fils[j] != NULL) {
                est_vide = 0;
            }
        }
        if (node->nb_forme_flechie > 0 && est_vide == 0) {// si oui on tire àléatoirement une pièce pour savoir si on continue ou si on s'arrête
            suite = rand() % 2;
        }
    }
    //la boucle s'arrête à l'avant dernière lettre et ne prends pas la dernière lettre, parce que dans le dernier noeud la forme fléchie est présente
    base[c] = node->value;

    base[c + 1] = '\0';
    return base; //je renvoie la forme de base
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 *
 */
/*
struct s_pile_char
{
    char value;
    struct  s_pile_char* next;
};
typedef struct s_pile_char s_pile_char,t_pile_char,*p_pile_char;

struct s_pile_node{
    p_base_node value;
    struct s_pile_node* next;
};
typedef  struct s_pile_node s_pile_node,t_pile_node,*p_pile_node;

int node_in_pile(p_pile_node pile,p_base_node node){
    p_pile_node pile1=pile;
    while(pile1!=NULL){
        if(pile1==node){
            return 1;
        }
        pile1=pile1->next;
    }
    return 0;
};

void empile_char(p_pile_char mot,char lettre){
    p_pile_char node;
    node=(p_pile_char)malloc(sizeof(t_pile_char));
    node->value=lettre;

    node->next=mot;
    mot=node;
}

char depile_char(p_pile_char pile){
    char val;
    if(pile->value==NULL){
        val=pile->value;
        pile=pile->next;
        free(pile);
    }
    else{
        val=' ';
    }
    return val;
}

void empile_node(p_pile_node pile,p_base_node node){
    p_pile_node temp;
    temp=(p_pile_node)malloc(sizeof(t_pile_node));
    temp->value=node;

    temp->next=pile;
    pile=temp;
}

p_base_node depile_node(p_pile_node pile){
    p_base_node val;
    if(pile->value!=NULL){
        val=pile->value;
        pile=pile->next;
        free(pile);
    }
    else{
        val=NULL;
    }
    return val;
}


int forme_flechie_in_list(p_flechie_list list, char* mot){
    p_flechie_node list1=list->head;
    while(list1!=NULL){
        if(compareChar(list1->value,mot)){
            return 1;
        }
        list1=list1->next;
    }
    return 0;
}

int fils_vide(p_base_node node){
    p_base_node temp=node;
    for(int i=0;i<26;i++){
        if(temp->fils[i]!=NULL){
            return 0;
        }
    }
    return 1;
}


void research_flechie_form(char* flechie,p_base_tree categorie){
    int idx=(int)flechie[0]-97;
    p_base_node node;
    node=categorie->root[idx]; // on prend l'arbre associé à la première lettre du mot

    p_pile_node search;// on définit la première pile qui sert à parcourir l'arbre
    search=(p_pile_node) malloc(sizeof(t_pile_node));
    search->next=NULL;
    search->value=node;

    p_pile_node un_search;// on définit la seconde pile qui sert à stocker les précedents noeuds parcouru
    un_search=(p_pile_node) malloc(sizeof(t_pile_node));
    un_search->value=NULL;
    un_search->next=NULL;

    p_pile_char mot;// on définit une pile qui sert à stocker la forme de base si on la trouve
    mot=(p_pile_char)malloc(sizeof(t_pile_char));
    mot->value=flechie[0];

    p_base_node temp;
    temp=search->value; //pointeur temporaire qui permet de prendre le premier élément de la première pile
    int found=0;
    int i;
    while(search->value!=NULL && found==0){
        i=0;
        while(i<26){ // si on est déjà passé par là
            if(node_in_pile(un_search,temp)){
                //si on est à la fin on dépile
                if(i==25){
                    empile_node(un_search,depile_node(search));
                    temp=search->value;
                    i=0;
                    depile_char(mot);
                }
                    //sinon on passe au suivant
                else{
                    i++;
                    temp=search->value->fils[i];
                }

            }
            else{ // si on y es pas encore passé
                if(temp->nb_forme_flechie>0){// si on atteint une forme fléchie
                    // si la forme est dedans les formes fléchies du noeuds
                    if(forme_flechie_in_list(temp->flechie_list,flechie)){
                        found=1;
                        break;
                    }
                        // si la forme fléchie n'est pas présent dans le noeud
                    else{
                        // si toute les fils sont nuls on dépile search dans un_search
                        if(fils_vide(temp)){
                            empile_node(un_search,depile_node(search));
                            temp=search->value;
                            i=0;
                            depile_char(mot);
                        }
                            //si il existe une suite on passe au prochain noeuds
                        else{
                            empile_node(un_search,temp);
                            empile_node(search,temp->fils[0]);
                            temp=search->value;
                            empile_char(mot,search->value->value);
                            i=0;

                        }
                    }
                }
                else{ // si on ne trouve pas de forme fléchie on continue de parcourir, en empile les états
                    empile_node(search,temp->fils[0]);
                    temp=search->value;
                    empile_char(mot,search->value->value);
                    i=0;

                }
            }
        }
    }

    if(found==1){
        printf("la forme_fléchie %s est présente dans cette catégorie",flechie);
    }
    else{
        printf("la forme fléchie %s n'est pas présente dans cette catégorie",flechie);
    }

    free(un_search);
    free(search);
    free(mot);

}*/