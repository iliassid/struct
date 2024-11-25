#include <stdio.h>
#include <string.h>

#define MAX_TACHES 100


typedef struct {
    char titre[100];
    char description[200];
    char date_echeance[20];  
    char priorite[10];  
} Tache;


Tache taches[MAX_TACHES];
int nb_taches = 0;  


void afficherMenu() {
    printf("Menu de Gestion des Taches:\n");
    printf("1. Ajouter une tache\n");
    printf("2. Afficher toutes les taches\n");
    printf("3. Modifier une tache\n");
    printf("4. Supprimer une tache\n");
    printf("5. Filtrer les taches par priorite\n");
    printf("6. Quitter\n");
    printf("Entrez votre choix: ");
}


void ajouterTache() {
    if (nb_taches < MAX_TACHES) {
        printf("Entrez le titre de la tache: ");
        
        scanf("%99s", taches[nb_taches].titre);

        printf("Entrez la description de la tache: ");
        
        scanf("%199s", taches[nb_taches].description);

        printf("Entrez la date d'echeance (JJ/MM/AAAA): ");
        scanf("%19s", taches[nb_taches].date_echeance);

        printf("Entrez la priorité (High/Low): ");
        scanf("%9s", taches[nb_taches].priorite);

        nb_taches++;
        printf("Tâche ajoutée avec succes!\n");
    } else {
        printf("Le nombre maximum de taches a ete atteint.\n");
    }
}


void afficherTaches() {
    if (nb_taches == 0) {
        printf("Aucune tache a afficher.\n");
    } else {
        printf("Liste des taches:\n");
        for (int i = 0; i < nb_taches; i++) {
            printf("\nTache %d:\n", i + 1);
            printf("Titre: %s\n", taches[i].titre);
            printf("Description: %s\n", taches[i].description);
            printf("Date d'echeance: %s\n", taches[i].date_echeance);
            printf("Priorite: %s\n", taches[i].priorite);
        }
    }
}


void modifierTache() {
    int index;
    printf("Entrez l'indice de la tache à modifier (1-%d): ", nb_taches);
    scanf("%d", &index);

    if (index > 0 && index <= nb_taches) {
        index--;  
        printf("Modifications de la tache %d:\n", index + 1);

        printf("Entrez le nouveau titre: ");
        scanf("%99s", taches[index].titre);

        printf("Entrez la nouvelle description: ");
        scanf("%199s", taches[index].description);

        printf("Entrez la nouvelle date d'echeance (JJ/MM/AAAA): ");
        scanf("%19s", taches[index].date_echeance);

        printf("Entrez la nouvelle priorite (High/Low): ");
        scanf("%9s", taches[index].priorite);

        printf("Tache modifiée avec succès!\n");
    } else {
        printf("Tache introuvable!\n");
    }
}


void supprimerTache() {
    int index;
    printf("Entrez l'indice de la tache a supprimer (1-%d): ", nb_taches);
    scanf("%d", &index);

    if (index > 0 && index <= nb_taches) {
        index--;  
        for (int i = index; i < nb_taches - 1; i++) {
            taches[i] = taches[i + 1];
        }
        nb_taches--;
        printf("Tâche supprimee avec succes!\n");
    } else {
        printf("Tache introuvable!\n");
    }
}


void filtrerParPriorite() {
    char priorite[10];
    printf("Entrez la priorité à filtrer (High/Low): ");
    scanf("%9s", priorite);

    printf("Liste des tâches avec priorite %s:\n", priorite);
    int trouve = 0;
    for (int i = 0; i < nb_taches; i++) {
        if (strcmp(taches[i].priorite, priorite) == 0) {
            printf("\nTache %d:\n", i + 1);
            printf("Titre: %s\n", taches[i].titre);
            printf("Description: %s\n", taches[i].description);
            printf("Date d'echeance: %s\n", taches[i].date_echeance);
            printf("Priorite: %s\n", taches[i].priorite);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucune tache trouvee avec cette priorite.\n");
    }
}

int main() {
    int choix;

    do {
        afficherMenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterTache();
                break;
            case 2:
                afficherTaches();
                break;
            case 3:
                modifierTache();
                break;
            case 4:
                supprimerTache();
                break;
            case 5:
                filtrerParPriorite();
                break;
            case 6:
                printf("Merci d'avoir utilise l'application de gestion des taches!\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 6);

    return 0;
}

    