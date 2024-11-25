#include <stdio.h>
#include <string.h>
#define MAX_TACHE 100
typedef struct {
    char  titre[100];
    char  description[300];
    char date[100];
    char priorite[20];
}Taches;

Taches tache[MAX_TACHE];
int nb_taches = 0;

void tache_menu (){
    printf("Menu\n");
    printf("1.Ajouter une tache\n");
    printf("2.Afficher la list des taches\n");
    printf("3.Modifier une tache\n");
    printf("4.Supprimer une tache\n");
    printf("5.Filtrer les taches\n");
    printf("6.Quitte\n");
    printf("Entrer votre choix:\n");
}

void ajouterTache () {
    if (nb_taches<MAX_TACHE)
    {
        printf("Ajouter une tache:\n");
        printf("Entrer le titre de la tache:\n");
        scanf("%s", tache[nb_taches].titre);
        printf("Entrer la description:\n");
        scanf("%s", tache[nb_taches].description);
        printf("Entrer la date d'échéance:\n");
        scanf("%s", tache[nb_taches].date);
        printf("Entrer la priorité(High, Low)\n");
        scanf("%s", tache[nb_taches].priorite);
        nb_taches++;
        printf("Tâche ajoutée avec succès\n");
    }else{
        printf("Le nombre maximum de tâches a été atteint\n");
    }
}

void ListDesTaches(){
    if (nb_taches==0){
        printf("Aucune tâche à afficher.\n");
    }else{
        printf("La list des taches:");
        for (int i = 0; i < nb_taches; i++)
        {
            printf("taches numero :%d\n", i+1);
            printf("Le titre:%s\n", tache[i].titre);
            printf("La description:%s\n", tache[i].description);
            printf("La date d'echeance:%s\n", tache[i].date);
            printf("La priorité(High, Low):%s\n",tache[i].priorite);
        }
        
    } 

}
void modifierTache (){
    int index;
    printf("Entrez le numero de la tache a modifier (1-%d):",nb_taches);
    scanf("%d", &index);
    if (index > 0 && index <= nb_taches){
        index --;
        printf("Modifier la tache:\n", index+1);
        printf("entrer le nouveau titre:");
        scanf("%s", tache[index].titre);
        printf("Entrer le nouveau description:");
        scanf("%s", tache[index].description);
        printf("Entrer le nouveau date:");
        scanf("%s", tache[index].date);
        printf("Entrer la nouveau  la priorité(High, Low):");
        scanf("%s", tache[index].priorite);
        printf("Tâche modifiée avec succès!\n");
    }else{
        printf("tache intouvable\n");
    }
}