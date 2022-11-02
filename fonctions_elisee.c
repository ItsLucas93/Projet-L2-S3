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
