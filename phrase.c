#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "phrase.h"

void create_sentence_1(p_base_tree Ver, p_base_tree Adj, p_base_tree Adv, p_base_tree Nom) {

    srand(time(NULL));

    int genre = rand() % (1);
    int nombre = rand() % (1);
    int determinant = rand() % (1);

    if (nombre == 0) {
        if (genre == 0) {
            if (determinant == 0) printf("le ");
            else printf("un ");
            for (int i = 0; i < 4; i++) {
                if (i == 0 || i == 3) create_word(Nom, Mas, SG);
                else if (i == 1) create_word(Ver, IPre, SG, P3);
                else if (i == 2) create_word(Adj, Mas, SG);
            }
        } else {
            if (determinant == 0) printf("la ");
            else printf("une ");
            for (int i = 0; i < 4; i++) {
                if (i == 0 || i == 3) create_word(Nom, Fem, SG);
                else if (i == 1) create_word(Ver, IPre, SG, P3);
                else if (i == 2) create_word(Adj, Fem, SG);
            }
        }
    } else {
        if (determinant == 0) printf("les ");
        else printf("des ");
        if (genre == 0) {
            for (int i = 0; i < 4; i++) {
                if (i == 0 || i == 3) create_word(Nom, Mas, PL);
                else if (i == 1) create_word(Ver, IPre, PL, P3);
                else if (i == 2) create_word(Adj, Mas, PL);
            }
        } else {
            for (int i = 0; i < 4; i++) {
                if (i == 0 || i == 3) create_word(Nom, Fem, PL);
                else if (i == 1) create_word(Ver, IPre, PL, P3);
                else if (i == 2) create_word(Adj, Fem, PL);
            }
        }
    }
}
