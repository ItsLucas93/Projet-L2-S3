#include <string.h>
#include <stdlib.h>

#include "base_tree.h"
#include <stdio.h>

t_base_tree createEmptyBaseTree()
{
	t_base_tree t;
    printf("%d", t.root[0]->value);
    for (int i = 0 ; i < ALPHABET_SIZE ; i++)
    {
        t.root[i] = NULL;
    }
	return t;
}

p_base_node insertBaseTree(p_base_tree t, char* val)
{
    // ascii a 97 to 122
    unsigned long lenght_word = strlen(val);

    if (lenght_word) {
        t->root[((int) val[0] - 97)] = createBaseNode();
        t->root[((int) val[0] - 97)]->value = val[0];

        p_base_node temp = t->root[((int) val[0] - 97)];
        // lenght_word - 1 pour ne pas prendre en compte le \0
        for (unsigned long i = 0; i < lenght_word - 1; i++)
        {
            int idx = ((int) val[i + 1] - 97);
            temp->fils[idx] = createBaseNode();
            temp = temp->fils[idx];
            temp->value = val[idx];
        }

        return temp;
    }
    return NULL;
}