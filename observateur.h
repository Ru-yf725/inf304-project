#ifndef _OBSERVATEUR_H_
#define _OBSERVATEUR_H_
/*initialiser l'ensembles d'etat et d'alphabet*/
typedef enum{ INIT,ERREUR,MESURE } Etat;
typedef enum{ A, G, D, M } Alphabet;

Etat initial();/*revoie l’état initial */
Etat transition(Etat e, Alphabet s);/*fonction de transition*/
/*revoie vrai si e est accepteur*/
int est_accepteur(Etat e);


#endif



