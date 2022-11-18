#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#include "file_manager.h"

void create_typed_tree(p_base_tree tree_nom, p_base_tree tree_adj, p_base_tree tree_adv, p_base_tree tree_verb) {
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
    printf("Nombres de mots : %d\n", nbligne);
    fclose(input_file);

    input_file = fopen(filename, "r");


    char forme_base[ALPHABET_SIZE];
    char type[100];
    char forme_flechie[ALPHABET_SIZE];

    int i = 0;
    while ( i < nbligne) {

        printf("%d %d\n",i,nbligne);
        fscanf(input_file, "%s\t%s\t%s", forme_flechie, forme_base, type);

        printf("%s \n", forme_base);
        if (compare_type(type, "Ver:"))
        {
            p_base_node ptr_last_node_base = insertBaseTree(tree_verb, forme_base);
            p_flechie_node ptr_flechie_node = insertFlechieList(ptr_last_node_base, forme_flechie);
            add_type_to_list_type(ptr_flechie_node, type);
        }
        else if (compare_type(type, "Adj:"))
        {
            p_base_node ptr_last_node_base = insertBaseTree(tree_adj, forme_base);
            p_flechie_node ptr_flechie_node = insertFlechieList(ptr_last_node_base, forme_flechie);
            add_type_to_list_type(ptr_flechie_node, type);
        }
        else if (compare_type(type, "Adv")) {
            insertBaseTree(tree_adv, forme_base);
        }
        else if (compare_type(type, "Nom:")) {
            p_base_node ptr_last_node_base = insertBaseTree(tree_nom, forme_base);
            p_flechie_node ptr_flechie_node = insertFlechieList(ptr_last_node_base, forme_flechie);
            add_type_to_list_type(ptr_flechie_node, type);
        }
        clear_tab_char(forme_base);
        clear_tab_type_char(type);
        clear_tab_char(forme_flechie);
        i++;
    }

}
p_flechie_node insertFlechieList(p_base_node pn, char* chaine)
{
    p_flechie_list t = pn->flechie_list;
    if (t->head == NULL)
    {
        t->head = createFlechieNode();
        strcpy(t->head->value, chaine);
        pn->nb_forme_flechie++;
        p_flechie_node ptr_node = t->head;
        return ptr_node;
    }

    p_flechie_node temp = t->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = createFlechieNode();
    strcpy(temp->next->value, chaine);
    pn->nb_forme_flechie++;
    return temp->next;
}

void insertEnumList(p_flechie_node pn, char* chaine)
{
    p_enum_list t = pn->sub_type_list;
    if (t->head == NULL)
    {
        t->head = createEnumNode();
    }
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

int compare_type(const char *type, const char *type_ligne) {
    for (int i = 0; i < strlen(type_ligne); i++) {
        if (type[i] != type_ligne[i]) {
            return 0;
        }
    }
    return 1;
}

