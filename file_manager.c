#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#include "file_manager.h"


void clear_tab_char(char* mot)
{
    for (int i = 0; i < ALPHABET_SIZE ; i++)
    {
        mot[i] = '\0';
    }
}

void clear_tab_type_char(char* mot)
{
    for (int i = 0; i < 99 ; i++)
    {
        mot[i] = '\0';
    }
}

int compare_type(char* type, char* type_ligne){
    for(int i=0;i<4;i++){
        if(type[i]!=type_ligne[i]){
            return 0;
        }
    }
    return 1;
}


void create_typed_tree(p_base_tree tree_verb, p_base_tree tree_adj, p_base_tree tree_adv, p_base_tree tree_nom) {
    const char *filename = PATH;
    FILE *input_file = fopen(filename, "r");

    struct stat sb;
    if (stat(filename, &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    int nbligne = 0;
    for (char c = getc(input_file); c != EOF; c = getc(input_file)) {
        if (c == '\n') {
            nbligne++;
        }
    }
    printf("%d\n", nbligne);
    fclose(input_file);

    input_file = fopen(filename, "r");


    char forme_base[ALPHABET_SIZE];
    char type[100];
    char forme_flechie[ALPHABET_SIZE];

    int i = 0;
    while ( i < nbligne) {

        printf("%d %d\n",i,nbligne);
        fscanf(input_file, "%s\t%s\t%s", forme_flechie, forme_base, type);

        printf("%s", forme_base);
        if (compare_type(type, "Ver:"))
        {

            insertBaseTree(tree_verb, forme_base);

        }
        else if (compare_type(type, "Adj:"))
        {
            insertBaseTree(tree_adj, forme_base);
        }
        else if (compare_type(type, "Adv:")) {
            insertBaseTree(tree_adv, forme_base);
        }
        else if (compare_type(type, "Nom:")) {
            insertBaseTree(tree_nom, forme_base);
        }
        clear_tab_char(forme_base);
        clear_tab_type_char(type);
        clear_tab_char(forme_flechie);
        i++;
    }

}


