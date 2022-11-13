#include <string.h>
#include "base_tree.h"

t_base_tree createEmptyTree()
{
	t_base_tree t;
	return t;
}

void insertBaseTree(p_base_tree t, char* val)
{
    // ascii a 97 to 122
    unsigned long lenght_word = strlen(val);
    p_base_node temp = t->root[((int)val[0] - 97)];
    for (unsigned long i = 0 ; i < lenght_word ; i++)
    {
        temp->value = val[i];
        temp->fils[i] = createBaseNode();
        temp = temp->fils[i];
    }
}