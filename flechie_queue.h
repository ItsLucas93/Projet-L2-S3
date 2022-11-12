#ifndef FLECHIE_QUEUE_H
#define FLECHIE_QUEUE_H

#include "enum_list.h"

struct s_flechie_queue
{
	s_flechie_node head*;
}

typedef struct s_flechie_queue t_flechie_queue *p_flechie_queue;

#endif //FLECHIE_QUEUE