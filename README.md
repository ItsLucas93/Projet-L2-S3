# Générateur-automatique-de-phrases
PRJ-TI301 - Générateur automatique de phrases

## Description du projet
L’objectif de ce projet est de créer un programme qui génère automatiquement des phrases.
Le programme comporte 4 types de mots : **Nom**, **Adjectif**, **Adverbe** et **Verbe**.
Les mots comportent aussi des sous-types grammaticaux (*Masculin*, *Féminin*, *Singulier*, *Pluriel*, …).

Ces données sont conservées dans le fichier `./dictionnaire/dictionnaire_non_accentue.txt`.
(*Le projet n'utilise pas de dictionnaire avec accents.*)

Le projet comprend plusieurs structures : `t_base_tree` `t_base_node` `t_flechie_tree` `t_flechie_node` `t_enum_list` `t_enum_node`

### Exemple structure dans le fichier dictionnaire
|  Forme Fléchie  | Forme de base |  Types et sous-types  |
|:---------------:|:-------------:|:---------------------:|
|  stabilisames	  |  stabiliser	  | **Ver :** IPSim+PL+P1 |
|  stabilisant	   | stabilisant	  |   **Adj :** Mas+SG    |
|  stabilisant	   | stabilisant	  |    **Nom:** Mas+SG    |
|  stabilisant	   |  stabiliser	  |     **Ver:** PPre     |
| stabilisassent	 |  stabiliser	  |  **Ver:** SImp+PL+P3  |

### Exemple de structure d'arbre : verbe avoir

```
                  [root@]
                     |
                     |
                     v
          [a]---[b]--+- …
           |
           v
 [@]---[b]-+-- … -[v]-…
   |    |          |
   v    v          |
 [NULL][NULL]      |
                   |
                   v
         [o]--…----+---…
          |        |
          |        v
          |      [NULL]
          |
          |
 [i]--…---+---…
  |       |
  |       v
  |     [NULL]
  |
--+--…---[r]    
  |       |
  |       |
  v       v
[NULL]  [NULL] 
```

### Exemple de structure du nœud base_node 'r' à la fin du parcours : 'a' - 'v' - 'o' - 'i' - 'r'

| char value | s_base_node* node->fils[27] | int nb_forme_flechie | s_flechie_list* flechie_list     |
|------------|-----------------------------|----------------------|----------------------------------|
| r          | @ -> [NULL] [NULL] … [NULL] | 44                   | @ -> a -> ai -> aie -> … -> NULL |

### Exemple de structure de nœud flechie_node du nœud 'r'

| s_flechie_node* next        | char* value | t_enum_list *sub_type_list    |
|-----------------------------|-------------|-------------------------------|
| @ -> ai -> aie -> … -> NULL | a           | @ -> IPre -> SG -> P3 -> NULL |


### Exemple de structure de nœud enum_node

| struct s_enum_node *next; | sub_type value; |
|---------------------------|----------------|
| @ -> SG -> P3 -> NULL     | IPre           |

    
### Fonctionnalités proposées

1. Génération de phrase selon modèle 1 : Nom – Adjectif – Verbe – Nom
2. Génération de phrase selon modèle 2 : Nom – ‘qui’ – Verbe – Verbe – Nom – Adjectif
3. Génération de phrase selon modèle 3 : Adverbe - ',' - Nom - Adjectif - Verbe
4. Recherche de forme de base
5. Génération aléatoire de forme de base
6. ~~Recherche de forme fléchie~~ (fonctionnalité pas encore implémentée)
 
# Exécuter le programme

À notre connaissance, __le programme ne s'exécute que sur Windows__.
Vous pouvez lancer le programme dans l'[IDE CLion](https://www.jetbrains.com/fr-fr/clion/IDE) et/ou par le compilateur [MinGW](https://www.mingw-w64.org/)

