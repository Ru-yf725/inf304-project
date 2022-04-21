#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "environnement.h"
#include "interprete.h"
#include "programme.h"
#include "robot.h"
#include "terrain.h"
#include "type_pile.h"
#include "generation_terrains.h"
#include "observateur.h"

int main(int argc , char **argv){
    Environnement envt;
    etat_inter etat;
    resultat_inter resul;
    Programme prg;
    int nb_step;
    int nb_max_step;
    int ab,or;
    /*lecture de terrain et de programme*/
    FILE *f_ter = fopen(argv[1],"r");
    lire_terrain(f_ter,&(envt.t),&ab,&or);
    lire_programme(&prg,argv[2]);
    envt.obs=INIT;
    init_etat(&etat);
    init_robot(&(envt.r),ab,or,Est);
    resul=OK_ROBOT;
    
    nb_max_step=1000;
    for(nb_step=0;(nb_step < nb_max_step) && (resul == OK_ROBOT); nb_step++){
        resul=exec_pas(&prg,&envt,&etat);
        /*on obtient l'etat courant*/
        printf("l'etat courant est:%d\n",envt.obs);
        printf("resultat est:%d\n",resul);
        afficher_envt(&envt);
    }
    if(resultat_observateur(&envt)){
        printf("propriété est vrai\n");
    }
    else {
        printf("propriété est fausse\n");
    }
}