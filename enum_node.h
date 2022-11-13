#ifndef PROJET_ENUM_NODE_H
#define PROJET_ENUM_NODE_H

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

struct s_enum_node
{
    sub_type value;
    struct s_enum_node *next;
};

typedef struct s_enum_node t_enum_node, *p_enum_node;

p_enum_node createEnumNode(sub_type);

#endif //PROJET_ENUM_NODE_H
