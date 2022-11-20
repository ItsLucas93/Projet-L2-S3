#ifndef PROJET_ENUM_NODE_H
#define PROJET_ENUM_NODE_H

// Sous-type des formes fléchis
enum sub_type
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

    // (Invariant pluriel/Invariant genre - ADJ/NOM)
    InvPL,InvGen,
    
    //Adverbe
    // Adv, <- useless, pas de formes fléchies dans les adverbes puisque invariable

    // NULL
    null,

};

typedef enum sub_type sub_type;

struct s_enum_node
{
    sub_type value;
    struct s_enum_node *next;
};

typedef struct s_enum_node s_enum_node, t_enum_node, *p_enum_node;


p_enum_node createEnumNode();

sub_type charToEnum(const char* type);
char* enumToChar(sub_type sous_type);

int compareChar(const char* mot1, const char* mot2);


#endif //PROJET_ENUM_NODE_H