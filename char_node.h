#ifndef UNTITLED_CHAR_NODE_H
#define UNTITLED_CHAR_NODE_H

// Sous-type des formes fléchis

// Masculin Féminin / Singulier Pluriel / 1e 2e 3e personne / Participe Passé Participe Présent / Indicatif Présent Passé simple Imparfait
typedef enum
{
    Mas, Fem, SG, PL, P1, P2, P3, PPas, PPres, IPres, IPSim, IImp, IFut
}sub_type;

struct s_char_node
{
    char value;
    struct s_char_node   *left, *right; // à modifier
    sub_type forme_flechie; // t_enum_node à implémenter
    // int depth;
};

typedef struct s_char_node t_char_node, *p_char_node;

/***
 * @brief
 * @param
 * @return
 */
p_char_node createCharNode(char);

#endif //UNTITLED_CHAR_NODE_H