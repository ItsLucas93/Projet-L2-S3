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

struct s_cell
{
    int value;
    struct s_cell *next;
};

typedef struct s_cell t_cell, *p_cell;

struct s_char_node
{
    char value;
    p_cell n_node;

};

typedef struct s_char_node t_char_node, *p_char_node;

// Pour node_c prototype

p_char_node createCharNode(char val)
{
    p_char_node nouv;

    nouv = (p_char_node )malloc(sizeof(t_char_node));
    nouv->value = val;
    nouv->n_node->value=NULL;
    nouv->n_node->next=NULL;
    return nouv;
}
