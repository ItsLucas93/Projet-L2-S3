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
    p_enum_node nouv = (p_enum_node) malloc (sizeof(t_enum_node));
    nouv->next = NULL;

    return nouv;
}


sub_type charToEnum(const char* type)
/*
 * Fonction: charToEnum
 * -----------------
 * Compare la chaîne de caractère et renvoie le sub_type
 *
 * type: char*
 */
{
    if (compareChar(type, "Mas")) return Mas;
    else if (compareChar(type, "Fem")) return Fem;
    else if (compareChar(type, "SG")) return SG;
    else if (compareChar(type, "PL")) return PL;
    else if (compareChar(type, "InvPL")) return InvPL;
    else if (compareChar(type, "InvGen")) return InvGen;

    else if (compareChar(type, "P1")) return P1;
    else if (compareChar(type, "P2")) return P2;
    else if (compareChar(type, "P3")) return P3;

    else if (compareChar(type,"Inf")) return Inf;
    else if (compareChar(type,"PPas")) return PPas;
    else if (compareChar(type,"PPre")) return PPre;
    else if (compareChar(type,"IPre")) return IPre;
    else if (compareChar(type,"IPSim")) return IPSim;
    else if (compareChar(type,"IImp")) return IImp;
    else if (compareChar(type,"IFut")) return IFut;
    else if (compareChar(type,"SPre")) return SPre;
    else if (compareChar(type,"SImp")) return SImp;
    else if (compareChar(type,"CPre")) return CPre;
    else if (compareChar(type,"ImPre")) return ImPre;
    else return null;
}


char* enumToChar(sub_type sous_type)
/*
 * Fonction: EnumToType
 * -----------------
 * Compare le sub_type et renvoie sa chaîne de caractère
 *
 * sous_type: sub_type
 */
{
    if (sous_type == Mas) return "Masculin";
    else if (sous_type == Fem) return "Feminin";
    else if (sous_type == SG) return "Singulier";
    else if (sous_type == PL) return "Pluriel";
    else if (sous_type == P1) return "1e personne";
    else if (sous_type == P2) return "2e personne";
    else if (sous_type == P3) return "3e personne";

    else if (sous_type == Inf) return "Infinitif";
    else if (sous_type == PPas) return "Participe Passe";
    else if (sous_type == PPre) return "Participe Present";
    else if (sous_type == IPre) return "Indicatif Present";
    else if (sous_type == IPSim) return "Indicatif Passe Simple";
    else if (sous_type == IImp) return "Indicatif Imparfait";
    else if (sous_type == IFut) return "Indicatif Futur";
    else if (sous_type == SPre) return "Subjonctif Present";
    else if (sous_type == SImp) return "Subjonctif Imparfait";
    else if (sous_type == CPre) return "Conditionnel Present";
    else if (sous_type == Imp) return "Imp";
    else if (sous_type == ImPre) return "Imperatif Present";

    else if (sous_type == InvPL) return "InvPL";
    else if (sous_type == InvGen) return "InvGen";
    else return "null";
}


int compareChar(const char* mot1, const char* mot2)
/*
 * Fonction: compareChar
 * -----------------
 * Compare les deux chaînes de caractère
 * Renvoie 0 si faux et 1 si vrai
 *
 * mot1: const char*
 * mot2: const char*
 */
{
    if (strlen(mot1) != strlen(mot2)) return 0;
    else
    {
        for(int i = 0 ; i < strlen(mot1) ; i++)
        {
            if(mot1[i] != mot2[i]) return 0;
        }
        return 1;
    }
}