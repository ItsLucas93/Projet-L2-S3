#include <stdlib.h>

#include "flechie_list.h"
#include "enum_list.h"

p_flechie_node createFlechieNode()
{
    p_flechie_node nouv = (p_flechie_node) malloc (sizeof (t_flechie_list));

    nouv->next = NULL;
    nouv->sub_type_list = createEmptyEnumQueue();

    return nouv;
}