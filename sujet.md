# ordre et chaos

Nous allons �tudier, gr�ce � une petite simulation informatique, un syst�me r�gi par des r�gles extr�mement simples, mais qui montre des comportements complexes difficilement explicables.

## R�gles du syst�me

### Univers de la simulation

Cette simulation se d�roule dans une grille carr�e *N*x*N*. Cette grille poss�de la propri�t� que ses bords sont connect�s : le bord droit est connect� au bord gauche, le bord bas est connect� au bord haut.

Cette grille est ainsi subdivis�e en *N*x*N* cases.

Chaque case est rep�r�e par deux coordonn�es *x* et *y*. La case de coordonn�es (0, 0) est situ�e en haut � gauche de la grille. La coordonn�e *x* augmente vers la droite, la coordonn�e *y* augmente vers le bas.

Chaque case ne peut comporter que deux valeurs, associ�es � des 'couleurs' : NOIR et BLANC.

Dans son �tat initial, la grille ne contient que des cases 'NOIR'.

### R�gles d'�volution

Au sein de cet univers, on va ins�rer un agent, qui va �tre susceptible de modifier l'�tat des cases de la grille.

Cet agent est localis�, � l'origine, dans une case quelconque de la grille, avec ses propres coordonn�es *x_a* et *y_a*.

Cet agent poss�de �galement une orientation (la 'direction' vers laquelle il regarde), parmi HAUT, BAS, DROITE et GAUCHE.

Les r�gles utilis�es par cet agent sont les suivantes :

> S'il se trouve sur une case **'NOIR'** :
>    - il fait un quart de tour vers sa gauche
>    - il change la couleur de cette case en **'BLANC'**
>    - il se d�place d'une case dans la direction vers laquelle il regarde

> S'il se trouve sur une case **'BLANC'** :
>    - il fait un quart de tour vers sa droite
>    - il change la couleur de cette case en **'NOIR'**
>    - il se d�place d'une case dans la direction vers laquelle il regarde

Il suffit alors de r�p�ter ces r�gles d'�volution un 'certain nombre' de fois pour voir appara�tre des comportements complexes.

## Elements pour l'impl�mentation

grille : la grille est repr�sent�e par un tableau dynamique 2D stockant des entiers : 0 pour NOIR, 1 pour BLANC
*option* utiliser un type �num�r� pour les couleurs 

on utilisera une structure de donn�es (struct ) nomm�e **t_map** pour regrouper : la taille de la grille, le tableau dynamique 2D

fonctions � �crire :

t_map create_map(int dimension); qui cr�e la grille en utilisant des allocations dynamiques, et qui initialise chaque case de la grille en 'NOIR'

coordonn�es de l'agent : l'agent est repr�sent� par ses coordonn�es *x* et *y*, ainsi que par son orientation :
on peut utiliser une valeur de type *int* pour repr�senter cette orientation :
par exemple : 0 pour HAUT, 1 pour DROITE, 2 pour BAS, 3 pour GAUCHE
*option* utiliser un type �num�r� pour les orientations

les liens entre coordonn�es et orientations sont les suivants :
A partir des coordonn�es *(x,y)* et de l'orientation de l'agent, on peut calculer les coordonn�es de la case vers laquelle l'agent regarde :
>  HAUT : (x, y-1)
> 
>  DROITE : (x+1, y)
> 
>  BAS : (x, y+1)
> 
>  GAUCHE : (x-1, y)

on utilisera une structure de donn�es (struct), nomm�e **t_coord** pour regrouper ces coordonn�es et l'orientation de l'agent

fonctions � �crire :

t_coord create_coord(int x, int y, int orientation); qui cr�e l'agent avec ses coordonn�es et son orientation initiales
t_coord turn_left(t_coord agent ); qui met � jour l'orientation de l'agent en faisant un quart de tour vers la gauche
t_coord turn_right(t_coord agent ); qui met � jour l'orientation de l'agent en faisant un quart de tour vers la droite

fonctions concernant la grille et l'agent :

t_coord up(t_coord agent, t_map grille); qui met � jour la position de l'agent en le d�pla�ant vers le haut :
Attention : quand on d�place l'agent vers le haut, on diminue sa coordonn�e y de 1. Pour connecter les bords haut et bas de la grille, il faudra bien g�rer cette coordonn�e *y* dans la fonction

t_coord down(t_coord agent, t_map grille); qui met � jour la position de l'agent en le d�pla�ant vers le bas
Attention : quand on d�place l'agent vers le bas, on augmente sa coordonn�e y de 1. Pour connecter les bords haut et bas de la grille, il faudra bien g�rer cette coordonn�e *y* dans la fonction

t_coord left(t_coord agent, t_map grille); qui met � jour la position de l'agent en le d�pla�ant vers la gauche
Attention : quand on d�place l'agent vers la gauche, on diminue sa coordonn�e x de 1. Pour connecter les bords gauche et droit de la grille, il faudra bien g�rer cette coordonn�e *x* dans la fonction

t_coord right(t_coord agent, t_map grille); qui met � jour la position de l'agent en le d�pla�ant vers la droite
Attention : quand on d�place l'agent vers la droite, on augmente sa coordonn�e x de 1. Pour connecter les bords gauche et droit de la grille, il faudra bien g�rer cette coordonn�e *x* dans la fonction

t_coord forward(t_coord agent, t_map grille); qui met � jour la position de l'agent en le faisant avancer d'une case dans la direction vers laquelle il regarde : en fonction de son orientation, il faut utiliser les fonctions up(), down(), left() et right()
int get_map_value(t_coord agent, t_map grille); qui renvoie la 'couleur' (valeur 0 ou 1) de la case vers laquelle l'agent regarde
void toggle_value(t_coord agent, t_map grille); qui inverse la 'couleur' de la case sur laquelle l'agent est situ�



