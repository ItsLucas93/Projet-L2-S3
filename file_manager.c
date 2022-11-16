#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#include "file_manager.h"

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

    for (int i = 0; i < nbligne; i++) {
        fscanf(input_file, "%s\t%s\t%s", forme_flechie, forme_base, type);
        printf("%s\t%s\t%s\n", forme_flechie, forme_base, type);

        printf("%s\n", type);
        if (compare_type(type, "Ver:"))
        {
            printf("Injection : %s\n", forme_base);
            insertBaseTree(tree_verb, forme_base);
        }
        else if (compare_type(type, "Adj:"))
        {
            printf("Injection : %s\n", forme_base);
            insertBaseTree(tree_verb, forme_base);
        }
        else if (compare_type(type, "Adv:")) {
            printf("Injection : %s\n", forme_base);
            insertBaseTree(tree_verb, forme_base);
        }
        else if (compare_type(type, "Nom:")) {
            printf("Injection : %s\n", forme_base);
            insertBaseTree(tree_verb, forme_base);
        }

        clear_tab_char(forme_base);
        clear_tab_type_char(type);
        clear_tab_char(forme_flechie);
    }
}

int compare_type(const char* mot1, const char* mot2)
{
    for (int i = 0 ; i < 4 ; i++)
    {
        if (mot1[i] != mot2[i]) return 0;
    }
    return 1;
}

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
