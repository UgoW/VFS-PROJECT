#include "filesystem.h"

void display_menu() {
    printf("\n=== Menu ===\n");
    printf("1. Ajouter un fichier\n");
    printf("2. Supprimer un fichier\n");
    printf("3. Afficher les fichiers\n");
    printf("4. Quitter\n");
    printf("Choisissez une option : ");
}

void prompt_string(const char* message, char* buffer, size_t buffer_size) {
    printf("%s", message);
    fgets(buffer, buffer_size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int main() {
    FileSystem fs;
    init_file_system(&fs);

    char choix[3];
    char nom[50], chemin[100], contenu[100];
    int taille;
    char date[20];

    while (1) {
        display_menu();
        fgets(choix, sizeof(choix), stdin);

        switch (choix[0]) {
        case '1':
            printf("\n--- Ajouter un fichier ---\n");
            prompt_string("Nom : ", nom, sizeof(nom));
            prompt_string("Chemin : ", chemin, sizeof(chemin));
            prompt_string("Contenu : ", contenu, sizeof(contenu));
            printf("Taille (en octets) : ");
            scanf("%d", &taille);
            getchar();
            prompt_string("Date : ", date, sizeof(date));

            File new_file;
            init_file(&new_file, nom, chemin, contenu, taille, date);
            add_file(&fs, new_file);
            printf("Fichier ajouté avec succès.\n");
            break;

        case '2':
            printf("\n--- Supprimer un fichier ---\n");
            prompt_string("Nom du fichier à supprimer : ", nom, sizeof(nom));
            remove_file(&fs, nom);
            printf("Fichier supprimé (si trouvé).\n");
            break;

        case '3':
            printf("\n--- Liste des fichiers ---\n");
            print_file_system(&fs);
            break;

        case '4':
            printf("Libération des ressources...\n");
            free_file_system(&fs);
            printf("Au revoir !\n");
            return EXIT_SUCCESS;

        default:
            printf("Option invalide. Veuillez réessayer.\n");
            break;
        }
    }

    return EXIT_SUCCESS;
}
