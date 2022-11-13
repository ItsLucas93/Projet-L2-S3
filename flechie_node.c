#include "flechie_queue.h"
#include "enum_list.h"

#include <stdlib.h>

p_flechie_node createFlechieNode()
{
    p_flechie_node nouv = (p_flechie_node) malloc (sizeof (t_flechie_queue));

    nouv->next = NULL;
    nouv->sub_type_list = createEmptyEnumQueue();

    return nouv;
}