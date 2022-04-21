#include <stdio.h>
#include "observateur.h"
Etat initial(){
    return INIT;
}

Etat transition(Etat e,Alphabet s){
    switch (e)
    {
    case INIT:
        if(s==A){return ERREUR;}
        else if(s==G || s==D){
            return INIT;
        }
        else{return MESURE;}
        break;
    case MESURE:
        if(s==A || s==G || s==D){return INIT;}
        else{return MESURE;}
        break;
    case ERREUR:
        return ERREUR;
        break;
    default:
        break;
    }
}
int est_accepteur(Etat e){
    return e!=ERREUR;
}