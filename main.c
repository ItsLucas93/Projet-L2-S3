#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include "file_manager.h"

int main(){
    p_base_tree Nom=createEmptyBaseTree();
    p_base_tree Adj=createEmptyBaseTree();
    p_base_tree Adv=createEmptyBaseTree();
    p_base_tree Ver=createEmptyBaseTree();

    create_typed_tree(Ver,Adj,Adv,Nom);

    p_enum_node pn = createEnumNode();
    pn->value = SG;

    char c[] = "stabilimetre\0";

    int idx = (int) c[0] - 97;
    printf("%d", idx);
    p_base_node temp = Nom->root[idx];

    for (int i = 0 ; i < strlen(c); i++)
    {
        printf("%c", temp->value);
        //printf("%d", (int) c[i + 1] - 97);d
        temp = temp->fils[(int)c[i+1] - 97];

    }




    return 0;
};


