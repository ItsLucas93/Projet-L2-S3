#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "phrase.h"

void create_sentence_1(t_base_tree Nom[], t_base_tree Adj[],t_base_tree Verbe[],t_base_tree Adv[])
{
    srand(time(NULL));
    int genre=rand() % (1);
    int nombre=rand() % (1);
    int deter= rand() % (1);
    if (nombre==0) {
        if (genre == 0) {
            if (deter == 0) printf("le ");
            else printf("un ");
            for (int i = 0; i < 4; i++) {
                if (i == 0 || i == 3) {
                    create_word(&Nom, Mas, SG);
                }
                if (i == 1) {
                    create_word(&Verbe, IPre, SG, P3);
                }
                if (i == 2) {
                    create_word(&Adj, Mas, SG);
                }
            }
        } else {
            if (deter == 0) printf("la ");
            else printf("une ");
            for (int i = 0; i < 4; i++) {
                if (i == 0 || i == 3) {
                    create_word(&Nom, Fem, SG);
                }
                if (i == 1) {
                    create_word(&Verbe, IPre, SG, P3);
                }
                if (i == 2) {
                    create_word(&Adj, Fem, SG);
                }
            }
        }
    }
    else
        {
        if (deter==0) printf("les ");
        else printf("des ");
        if (genre==0)
        {
            for (int i=0; i<4;i++)
            {
                if (i==0 || i==3)
                {
                    create_word(&Nom, Mas, PL);
                }
                if (i==1)
                {
                    create_word(&Verbe, IPre, PL, P3);
                }
                if (i==2)
                {
                    create_word(&Adj, Mas, PL);
                }
            }
        }
        else{
            for (int i=0; i<4;i++)
            {
                if (i==0 || i==3)
                {
                    create_word(&Nom, Fem, PL);
                }
                if (i==1)
                {
                    create_word(&Verbe, IPre, PL, P3);
                }
                if (i==2)
                {
                    create_word(&Adj, Fem, PL);
                }
            }
        }
    }
}