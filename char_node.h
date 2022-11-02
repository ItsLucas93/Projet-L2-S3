#ifndef UNTITLED_CHAR_NODE_H
#define UNTITLED_CHAR_NODE_H

// Sous-type des formes fléchis
typedef enum
{
    // Genre (Masculin / Féminin - ADJ/NOM)
    Mas, Fem,
    // Nombre (Singulier / Pluriel - ADJ/NOM/VER)
    SG, PL,
    // Personne (1e 2e 3e personne - VER)
    P1, P2, P3,

    // Verbe
    // (Infinitif)
    Inf,
    // (Participe passé / Participe Présent)
    PPas, PPre,
    // (Indicatif : Présent / Passé simple / Imparfait / Futur)
    IPre, IPSim, IImp, IFut,
    // (Subjonctif : Présent / Passé (??) / Imparfait / Plus que parfait (??)) |
    SPre, SImp,
    // (Conditionnel : Présent)
    CPre,
    // Impératif (Présent / Passé(x)) | Pas d'impératif passé
    Imp, ImPre,

    // Nom
    Inv,

    // Adjectif
    InvGen,
}sub_type;

/*
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