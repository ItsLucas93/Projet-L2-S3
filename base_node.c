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
    for (int i = 0; i < ALPHABET_SIZE ; i++)
    {
        nouv->fils[i] = NULL;
    }
    return nouv;
}



char* contenu_fichier() {

    //définir un pointeur sur le fichier
    const char* filename = "../dictionnaire_non_accentue.txt";
    FILE* input_file = fopen(filename,"r");
    //vérifier si il n'y pas d'erreur avec la taille du ficher
    struct stat sb;
    if(stat(filename, &sb)==-1){
        perror("stat");
        exit(EXIT_FAILURE);
    }
    //stocker le contenu du pointeur dans un  tableau de caractère alloué dynamiqument
    char* file_contents = malloc(sb.st_size);
    fread(file_contents,sb.st_size,1,input_file);










    //affichage du contenu du fichier
    printf("%s\n",file_contents);

    fclose(input_file);



    return file_contents;
}
int afficher_contenu_fichier() {
    //définir un pointeur sur le fichier
    const char *filename = "../dico_10_lignes.txt";
    FILE *input_file = fopen(filename, "r");

    //vérifier s'il n'y pas d'erreur avec la taille du fichier
    struct stat sb;
    if (stat(filename, &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    char c;
    int nbligne = 0;
    for (c = getc(input_file); c != EOF; c = getc(input_file)) {
        if (c == '\n') {
            nbligne++;
        }
    }
    printf("%d\n", nbligne);
    fclose(input_file);

    input_file = fopen(filename, "r");

    char forme_base[250];

    char type[100];
    char forme_flechie[250];
    char categorie[250];

    for (int i = 0; i < nbligne; i++) {
        fscanf(input_file, "%s\t%s\t%s :%s", forme_flechie, forme_base,categorie,type);
        printf("%s\t%s\t%s\n", forme_flechie, forme_base,categorie,type);


    }

}


int comparer_char(char* mot,char* mot2){

    if(strlen(mot)!=strlen(mot2)){
        return 0;
    }
    else{
        for(int i;i<strlen(mot);i++){
            if(mot[i]!=mot2[i]){
                return 0;
            }
        }
        return 1 ;
    }
}

void ajouter_type_Aux(char* categorie,char* type,p_flechie_list flechie) {
    p_flechie_node flechie1 = flechie->head;
    while (flechie1->next != NULL) {
        flechie1 = flechie1->next;
    }

    p_enum_node node= (p_enum_node)malloc(sizeof(t_enum_node));
    node->next=NULL;
    p_enum_list list=(p_enum_list) malloc(sizeof(t_enum_list));
    list->head=node;
    flechie1->sub_type_list=list;


    if (comparer_char(categorie,"Adj") == 1 || comparer_char(categorie,"Nom") == 1) {
        if (comparer_char(type,"Mas") == 1) {
            node->value = Mas;
        }
        if (comparer_char(type,"Fem") == 1) {
            node->value = Fem;
        }
        if (comparer_char(type,"SG") == 1) {
            node->value = SG;
        }
        if (comparer_char(type,"PL") == 1) {
            node->value = PL;
        }
        if (comparer_char(type,"InvPL") == 1 ){
            node->value = InvPL;
        }

        if (comparer_char(type,"InvGen") == 1) {
            node->value=InvGen;
        }
    }

    if (comparer_char(categorie,"Ver") == 1) {
        if (comparer_char(type,"P1")) {
            node->value=P1;
        }
        if (comparer_char(type,"P2")) {

            node->value=P2;
        }
        if (comparer_char(type,"P3")) {
            node->value=P3;
        }
        if (comparer_char(type,"Inf")) {
            node->value=Inf;
        }
        if (comparer_char(type,"PPas")) {
            node->value=PPas;
        }
        if (comparer_char(type,"PPre")) {
            node->value=PPre;
        }
        if (comparer_char(type,"Ipre")) {
            node->value=IPre;
        }
        if (comparer_char(type,"IPSim")) {
            node->value=IPSim;
        }
        if (comparer_char(type,"IImp")) {

            node->value=IImp;
            flechie1->sub_type_list->head->value=IImp;
        }
        if (comparer_char(type,"IFut")) {

            node->value=IFut;
            flechie1->sub_type_list->head->value=IFut;
        }
        if (comparer_char(type,"SPre")) {

            node->value=SPre;
            flechie1->sub_type_list->head->value=SPre;
        }
        if (comparer_char(type,"SImp")) {

            node->value=SImp;
            flechie1->sub_type_list->head->value=SImp;
        }
        if (comparer_char(type,"CPre")) {

            node->value=CPre;
            flechie1->sub_type_list->head->value=CPre;
        }
        if (comparer_char(type,"ImPre")) {

            node->value=ImPre;
            flechie1->sub_type_list->head->value=ImPre;
        }
    }
    if (comparer_char(type,"Adv")) {

        node->value=Adv;
        flechie1->sub_type_list->head->value=Adv;
    }
}

/*/////////////////////////////////*/


p_char_type create_list_type(){
    p_char_type  type_list;
    type_list = (p_char_type)malloc(sizeof(t_char_type));
    type_list->next=NULL;
    return type_list;
}

int Is_type_list(t_char_type liste,char* type){
    while(liste.next!=NULL){
        if(comparer_char(type,liste.type)==1){
            return 1;
        }
    }
    return 0;
}


char* lire_categorie(char* ligne){
    char categorie[6];
    int i=0;
    while(ligne[i]!=':'){//on saute la catégorie
        categorie[i]=ligne[i];
        i++;
    }
    categorie[i]='\0';

    return categorie;
}

p_char_type lire_type(char* ligne){
    p_char_type  type_list=create_list_type();
    p_char_type type_list1=type_list;
    char mot[6];
    char tout_type[20];
    char categorie[6];
    int i=0;
    while(ligne[i]!=':'){//on saute la catégorie
        categorie[i]=ligne[i];
        i++;
    }

    categorie[i]='\0';
    i++;
    int j=0;//je stocke le reste des types dans tout_type
    while(ligne[i]!='\0'){
        tout_type[j]=ligne[i];
        i++;
        j++;
    }
    i=0;

    while(tout_type[i]!='\0'){//Tant que la chaine n'est pas à la fin
        j=0;//car le mot reviens toujours à 0;
        while(tout_type[i]!='+' && tout_type[i]!='\0' && tout_type[i]!=':'){// Tant que le mot n'est pas finit et que la chaine n'est pas à la fin
            mot[j]=tout_type[i];//récupère le type
            mot[j+1]='\0';//ajoute le caractère de fin
        } //on stocke le type dans la liste
        if(Is_type_list(*type_list,mot)==0){// si le type n'est déjà dans la liste
            type_list1->type=mot;
            type_list1->next=create_list_type();
            type_list=type_list1->next;
        }
    }
    return type_list;
}


void ajouter_type(char* categorie,p_flechie_list flechie,p_char_type type){
    p_flechie_node flechie_node=flechie->head;
    while(type->next!=NULL) {
        ajouter_type_Aux(categorie,type->type, flechie);
    }
}



/*//////////////////////////////////////////////////////////////////////////////*/






















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

