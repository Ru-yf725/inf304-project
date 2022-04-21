#include <stdio.h>
#include <stdlib.h>
#include "environnement.h"
#include "interprete.h"
#include "programme.h"
#include "robot.h"
#include "terrain.h"
#include "type_pile.h"
#include "generation_terrains.h"



int main(int argc,char **argv){
    if(argc != 9){
        fprintf(stderr,"Utilisation demandée : curiosity-perf fichier_programme N L H d graine nb_step_max fichier_res\n");
        exit(1);
    }
    Programme prog;
    int N,L,H,nb_max_step,graine;
    float d;
    lire_programme(&prog, argv[1]);
    sscanf(argv[2], "%d", &N);
    sscanf(argv[3], "%d", &L);
    sscanf(argv[4], "%d", &H);
    sscanf(argv[5], "%f", &d);
    sscanf(argv[6], "%d", &graine);
    sscanf(argv[7], "%d", &nb_max_step);
    FILE* f_write = fopen(argv[8],"w");
    if(f_write == NULL){
        fprintf(stderr,"Erreur sur le dernier argument, cela doit etre un fichier valide\n");
        exit(2);
    }
    int nb_step;
    int num=0;
    etat_inter etat;
    resultat_inter resul;
    Environnement envt;
    float prop_reussi=0;
    int nb_bloque;
    float moyenne_pas=0;
    
    envt.t.hauteur=H;
    envt.t.largeur=L;
    fprintf(f_write,"%d\n",N);
    while(num<N){
        srand(graine*(num+1));
        initialiser(envt.t);/*chaque fois initialiser le terrian*/
        generation_aleatoire(&(envt.t),L,H,d);
        afficher_terrain(&(envt.t));printf("\n");
        if(existe_chemin_vers_sortie(envt.t)){
            init_etat(&etat);
            init_robot(&(envt.r),L/2,H/2,Est);
            resul=OK_ROBOT;
            for(nb_step=0;(nb_step<nb_max_step)&&(resul==OK_ROBOT);nb_step++){
                resul=exec_pas(&prog,&envt,&etat);
            }
            switch (resul)
            {
            case SORTIE_ROBOT:
                nb_bloque=nb_step;
                /*si le robot est sorti,nb de reussites sera augemente*/
                prop_reussi++;
                moyenne_pas+=nb_step;
                fprintf(f_write,"%d\n",nb_bloque);
                break;
            case OK_ROBOT:
                nb_bloque=-1;
                fprintf(f_write,"%d\n",nb_bloque);
                /* code */
                break;
            case ARRET_ROBOT:
                nb_bloque=-1;
                fprintf(f_write,"%d\n",nb_bloque);
                break;
            case PLOUF_ROBOT:
                nb_bloque=-2;
                fprintf(f_write,"%d\n",nb_bloque);
                break;
            case CRASH_ROBOT:
                nb_bloque=-3;
                fprintf(f_write,"%d\n",nb_bloque);
                break;

            default:
                break;
            }
        }
        else{
            nb_bloque=-1;
            fprintf(f_write,"%d\n",nb_bloque);
        }
        num++;

        
    }
    char *arg=argv[1];
    fprintf(f_write,"le pourcentage de reussite pour test %s: %f\n " ,arg,prop_reussi/(float)N);
    printf("voici le pourcentage de reussite pour test %s: %f\n " ,arg,prop_reussi/(float)N);
    fprintf(f_write,"voici le nombre de reussite pour test %s: %d\n ",arg,(int)prop_reussi);
    printf("le nombre de reussite pour test %s: %d\n " ,arg,(int)prop_reussi);
    fprintf(f_write,"voici le nombre d'obstacle pour test %s: %d\n ",arg,N-(int)prop_reussi);
    printf("le nombre d'obstacle pour test %s: %d\n " ,arg,N-(int)prop_reussi);
    fprintf(f_write,"voici nombre moyen de pas effectués pour test %s: %f\n ",arg,moyenne_pas/prop_reussi);
    printf("le nombre moyen de pas effectués pour test %s: %f\n ",arg,moyenne_pas/prop_reussi);


    return 0;
    
    
   
}