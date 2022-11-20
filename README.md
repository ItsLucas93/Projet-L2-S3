# Générateur automatique de phrases
PRJ-TI301 - Générateur automatique de phrases

## Description du projet
L’objectif de ce projet est de créer un programme qui génère automatiquement des phrases.
Le programme comporte 4 types de mots : **Nom**, **Adjectif**, **Adverbe** et **Verbe**.
Les mots comportent aussi des sous-types grammaticaux (*Masculin*, *Féminin*, *Singulier*, *Pluriel*, …).

Ces données sont conservées dans le fichier [./dictionnaire/dictionnaire_non_accentue.txt](https://github.com/ItsLucas93/Projet-L2-S3/blob/main/dictionnaire/dictionnaire_non_accentue.txt).
(*Le projet n'utilise pas de dictionnaire avec accents.*)

Le projet comprend plusieurs structures : `t_base_tree` `t_base_node` `t_flechie_list` `t_flechie_node` `t_enum_list` `t_enum_node`

### Structure des fichiers

```
./
/── dictionnaire
│   ├── dico_10_lignes.txt
│   └── dictionnaire_non_accentue.txt
├── README.md
├── base_node.c
├── base_node.h
├── base_tree.c
├── base_tree.h
├── enum_list.c
├── enum_list.h
├── enum_node.c
├── enum_node.h
├── file_manager.c
├── file_manager.h
├── flechie_list.c
├── flechie_list.h
├── flechie_node.c
├── flechie_node.h
├── main.c
├── phrase.c
└── phrase.h
```

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
|---------------------------|-----------------|
| @ -> SG -> P3 -> NULL     | IPre            |

    
### Fonctionnalités proposées

1. Génération de phrase selon modèle 1 : Nom – Adjectif – Verbe – Nom
2. Génération de phrase selon modèle 2 : Nom – ‘qui’ – Verbe – Verbe – Nom – Adjectif
3. Génération de phrase selon modèle 3 : Adverbe - ',' - Nom - Adjectif - Verbe
4. Recherche de forme de base
5. Génération aléatoire de forme de base
6. ~~Recherche de forme fléchie~~ *(fonctionnalité pas encore implémentée)*
 
# Exécuter le programme

À notre connaissance, __le programme ne s'exécute que sur Windows__.
Vous pouvez lancer le programme dans l'[IDE CLion](https://www.jetbrains.com/fr-fr/clion/IDE), qui comprend un compilateur intégré.

Incluez tous les fichiers `*.c` dans la compilation.

Lorsque vous exécuterez le programme, les arbres seront construits durant les 5-10 premières secondes. Il vous sera ensuite proposé un menu avec les diverses fonctionnalités. Pour accéder aux fonctionnalités de **4 à 6** par exemple, depuis le menu principal, saisissez 4. Vous aurez ensuite la possibilité de revenir dans le menu principal.

# Auteurs du projet

Ce projet est proposé par [Nicolas Flasque](https://www.linkedin.com/in/nicolas-flasque-48b25610), coordinateur du Module TI301 - Algorithmique et structure de données 2 à l'[EFREI Paris](https://www.efrei.fr/).

Groupe de projet constitué de :

* KOCOGLU Lucas
* NOIROT-RATHAR Elisée
* PINEDE Luka
