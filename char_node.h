#ifndef UNTITLED_CHAR_NODE_H
#define UNTITLED_CHAR_NODE_H

struct s_char_node
{
    char value;
    struct s_char_node   *left, *right; // à modifier
    sub_type forme_flechie; // t_enum_node à implémenter
    // int depth;
};

typedef struct s_char_node t_char_node, *p_char_node;

p_char_node createCharNode(char);
*/
#endif //UNTITLED_CHAR_NODE_H