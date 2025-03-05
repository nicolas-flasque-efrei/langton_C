# ordre et chaos

Nous allons étudier, grâce à une petite simulation informatique, un système régi par des règles extrêmement simples, mais qui montre des comportements complexes difficilement explicables.

## Règles du système

### Univers de la simulation

Cette simulation se déroule dans une grille carrée *N*x*N*. Cette grille possède la propriété que ses bords sont connectés : le bord droit est connecté au bord gauche, le bord bas est connecté au bord haut.

Cette grille est ainsi subdivisée en *N*x*N* cases.

Chaque case est repérée par deux coordonnées *x* et *y*. La case de coordonnées (0, 0) est située en haut à gauche de la grille. La coordonnée *x* augmente vers la droite, la coordonnée *y* augmente vers le bas.

Chaque case ne peut comporter que deux valeurs, associées à des 'couleurs' : NOIR et BLANC.

Dans son état initial, la grille ne contient que des cases 'NOIR'.

### Règles d'évolution

Au sein de cet univers, on va insérer un agent, qui va être susceptible de modifier l'état des cases de la grille.

Cet agent est localisé, à l'origine, dans une case quelconque de la grille, avec ses propres coordonnées *x_a* et *y_a*.

Cet agent possède également une orientation (la 'direction' vers laquelle il regarde), parmi HAUT, BAS, DROITE et GAUCHE.

Les règles utilisées par cet agent sont les suivantes :

> S'il se trouve sur une case **'NOIR'** :
>    - il fait un quart de tour vers sa gauche
>    - il change la couleur de cette case en **'BLANC'**
>    - il se déplace d'une case dans la direction vers laquelle il regarde

> S'il se trouve sur une case **'BLANC'** :
>    - il fait un quart de tour vers sa droite
>    - il change la couleur de cette case en **'NOIR'**
>    - il se déplace d'une case dans la direction vers laquelle il regarde

Il suffit alors de répéter ces règles d'évolution un 'certain nombre' de fois pour voir apparaître des comportements complexes.

## Elements pour l'implémentation

grille : la grille est représentée par un tableau dynamique 2D stockant des entiers : 0 pour NOIR, 1 pour BLANC
*option* utiliser un type énuméré pour les couleurs 

on utilisera une structure de données (struct ) nommée **t_map** pour regrouper : la taille de la grille, le tableau dynamique 2D

fonctions à écrire :

t_map create_map(int dimension); qui crée la grille en utilisant des allocations dynamiques, et qui initialise chaque case de la grille en 'NOIR'

coordonnées de l'agent : l'agent est représenté par ses coordonnées *x* et *y*, ainsi que par son orientation :
on peut utiliser une valeur de type *int* pour représenter cette orientation :
par exemple : 0 pour HAUT, 1 pour DROITE, 2 pour BAS, 3 pour GAUCHE
*option* utiliser un type énuméré pour les orientations

les liens entre coordonnées et orientations sont les suivants :
A partir des coordonnées *(x,y)* et de l'orientation de l'agent, on peut calculer les coordonnées de la case vers laquelle l'agent regarde :
>  HAUT : (x, y-1)
> 
>  DROITE : (x+1, y)
> 
>  BAS : (x, y+1)
> 
>  GAUCHE : (x-1, y)

on utilisera une structure de données (struct), nommée **t_coord** pour regrouper ces coordonnées et l'orientation de l'agent

fonctions à écrire :

t_coord create_coord(int x, int y, int orientation); qui crée l'agent avec ses coordonnées et son orientation initiales
t_coord turn_left(t_coord agent ); qui met à jour l'orientation de l'agent en faisant un quart de tour vers la gauche
t_coord turn_right(t_coord agent ); qui met à jour l'orientation de l'agent en faisant un quart de tour vers la droite

fonctions concernant la grille et l'agent :

t_coord up(t_coord agent, t_map grille); qui met à jour la position de l'agent en le déplaçant vers le haut :
Attention : quand on déplace l'agent vers le haut, on diminue sa coordonnée y de 1. Pour connecter les bords haut et bas de la grille, il faudra bien gérer cette coordonnée *y* dans la fonction

t_coord down(t_coord agent, t_map grille); qui met à jour la position de l'agent en le déplaçant vers le bas
Attention : quand on déplace l'agent vers le bas, on augmente sa coordonnée y de 1. Pour connecter les bords haut et bas de la grille, il faudra bien gérer cette coordonnée *y* dans la fonction

t_coord left(t_coord agent, t_map grille); qui met à jour la position de l'agent en le déplaçant vers la gauche
Attention : quand on déplace l'agent vers la gauche, on diminue sa coordonnée x de 1. Pour connecter les bords gauche et droit de la grille, il faudra bien gérer cette coordonnée *x* dans la fonction

t_coord right(t_coord agent, t_map grille); qui met à jour la position de l'agent en le déplaçant vers la droite
Attention : quand on déplace l'agent vers la droite, on augmente sa coordonnée x de 1. Pour connecter les bords gauche et droit de la grille, il faudra bien gérer cette coordonnée *x* dans la fonction

t_coord forward(t_coord agent, t_map grille); qui met à jour la position de l'agent en le faisant avancer d'une case dans la direction vers laquelle il regarde : en fonction de son orientation, il faut utiliser les fonctions up(), down(), left() et right()
int get_map_value(t_coord agent, t_map grille); qui renvoie la 'couleur' (valeur 0 ou 1) de la case vers laquelle l'agent regarde
void toggle_value(t_coord agent, t_map grille); qui inverse la 'couleur' de la case sur laquelle l'agent est situé



