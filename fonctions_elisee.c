#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int afficher_contenu_fichier() {
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
  
  // fermeture du fichier
  fclose(input_file);
  //libérer l'espace mémoire
  free(file_contents);
  return 0;
}

//Pour node_h prototype

struct s_flechie{
    struct s_flechie *next;
    char type;
    char tab[100];
};

typedef struct s_flechie t_flechie, *p_flechie;

struct s_cell
{
    int* value;
    struct s_cell *next;
};
typedef struct s_cell t_cell, *p_cell;



struct s_char_node
{
  char value;
  p_cell n_node;
  p_flechie f_flechie;
};
typedef struct s_char_node t_char_node;


// Pour node_c prototype

p_char_node createCharNode(char val)
{
  p_char_node nouv;
  nouv = (int*)malloc(sizeof(t_char_node));
  nouv->value = val;
  nouv->n_node=NULL;
  nouv->f_flechie=NULL;
  return nouv;
}

/* fonction qui prend un abre de caractère et ajoute uniquement la forme de base dans l'arbre, 
(À modifier ajouter un paramètre pour la forme fléchie et l'ajouter aux autres)
 exemple : parcourir l'arbre commençant par la lettre A, dans les adjectifs
*/

void ajouter_mot_n_node(p_char_node p_node,char mot[]) {
    p_char_node p1_node = p_node;//pointeur auxilliaire
    for (int i = 0; i < strlen(mot); i++) {
        if (p1_node != NULL) { // si le noeud est non vide

            if (p1_node->value == mot[i]) { // on cherche s'il existe une suite similaire
                int found = 0;
                p_cell p_next1 = p1_node->n_node;//pointeur auxilliaire
                while (p_next1 = !NULL && found == 0) {//on cherche dans tous les sous arbres
                    if (p_next1->value == mot[i]) {
                        p_next1 = p_next1->next;
                        found = 1;
                    }
                }
                if (found == 0) { // si il n'existe pas de sous arbres correspondant
                    p_char_node nouv = createCharNode(mot[i]);
                    p_cell p_next2 = p1_node->n_node;//pointeur auxilliaire
                    while (p_next2->next != NULL)//on va à la fin
                    {
                        p_next2->next;
                    }
                    p_cell new;          //on assigne une cellule à la fin de la liste
                    p_next2->next = new;
                    new->value = nouv;     // on lui donne le nouveau noeud
                    new->next = NULL;      // fin de la liste
                }
            } else// si le noeuds est vide on crée un nouveau noeuds
            {
                p_char_node nouv = createCharNode(mot[i]);

                p_cell new;
                p1_node = new;
                new->value = nouv;
                new->next = NULL;
            }
            p1_node = p1_node->n_node->next;
        } else {
            p_char_node nouv = createCharNode(mot[i]);
            p1_node = nouv;
        }
    }
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

    for (int i = 0; i < nbligne; i++) {
        fscanf(input_file, "%s\t%s\t%s", forme_flechie, forme_base, type);
        printf("%s\t%s\t%s\n", forme_flechie, forme_base, type);

    }

}




