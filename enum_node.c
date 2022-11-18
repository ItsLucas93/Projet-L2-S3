#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "enum_list.h"

p_enum_node createEnumNode()
/*
 * Fonction: createEnumNode
 * -----------------
 * Crée un Node pour les sous_types des formes fléchies
 *
 * Initialise next à NULL
 *
 * pn: p_enum_node
 */
{
    p_enum_node nouv = (p_enum_node) malloc (sizeof(t_enum_list));
    nouv->next = NULL;

    return nouv;
}


sub_type charToEnum(char* type)
/*
 * Fonction: charToEnum
 * -----------------
 * Compare la chaîne de caractère et renvoie le sub_type
 */
{
    if (comparer_char(type, "Mas")) return Mas;
    else if (comparer_char(type, "Fem")) return Fem;
    else if (comparer_char(type, "SG")) return SG;
    else if (comparer_char(type, "PL")) return PL;
    else if (comparer_char(type, "InvPL")) return InvPL;
    else if (comparer_char(type, "InvGen")) return InvGen;

    else if (comparer_char(type, "P1")) return P1;
    else if (comparer_char(type, "P2")) return P2;
    else if (comparer_char(type, "P3")) return P3;

    else if (comparer_char(type,"Inf")) return Inf;
    else if (comparer_char(type,"PPas")) return PPas;
    else if (comparer_char(type,"PPre")) return PPre;
    else if (comparer_char(type,"IPre")) return IPre;
    else if (comparer_char(type,"IPSim")) return IPSim;
    else if (comparer_char(type,"IImp")) return IImp;
    else if (comparer_char(type,"IFut")) return IFut;
    else if (comparer_char(type,"SPre")) return SPre;
    else if (comparer_char(type,"SImp")) return SImp;
    else if (comparer_char(type,"CPre")) return CPre;
    else if (comparer_char(type,"ImPre")) return ImPre;
    else return null;
}


char* EnumToChar(sub_type sous_type)
/*
 * Fonction: EnumToType
 * -----------------
 * Compare le sub_type et renvoie sa chaîne de caractère
 */
{
    if (sous_type == Mas) return "Masculin";
    else if (sous_type == Fem) return "Féminin";
    else if (sous_type == SG) return "Singulier";
    else if (sous_type == PL) return "Pluriel";
    else if (sous_type == P1) return "1ère personne";
    else if (sous_type == P2) return "2e personne";
    else if (sous_type == P3) return "3e personne";

    else if (sous_type == Inf) return "Infinitif";
    else if (sous_type == PPas) return "Participe Passé";
    else if (sous_type == PPre) return "Participe Présent";
    else if (sous_type == IPre) return "Indicatif Présent";
    else if (sous_type == IPSim) return "Indicatif Passé Simple";
    else if (sous_type == IImp) return "Indicatif Imparfait";
    else if (sous_type == IFut) return "Indicatif Futur";
    else if (sous_type == SPre) return "Subjonctif Présent";
    else if (sous_type == SImp) return "Subjonctif Imparfait";
    else if (sous_type == CPre) return "Conditionnel Présent";
    else if (sous_type == Imp) return "Imp";
    else if (sous_type == ImPre) return "Impératif Présent";

    else if (sous_type == InvPL) return "InvPL";
    else if (sous_type == InvGen) return "InvGen";
    else return "null";
}


int comparer_char(const char* mot, const char* mot2)
/*
 * Fonction: comparer_char
 * -----------------
 * Compare les deux chaînes de caractère
 * Renvoie 0 si faux et 1 si vrai
 */
{
    if (strlen(mot) != strlen(mot2)) return 0;
    else
    {
        for(int i = 0 ; i < strlen(mot) ; i++)
        {
            if(mot[i] != mot2[i]) return 0;
        }
        return 1;
    }
}