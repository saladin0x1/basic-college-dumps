#include <stdio.h>
#include <stdlib.h>

// Define a node structure for a linked list
struct node {
    int value;           // Data of the node
    struct node *next;   // Pointer to the next node in the list
};

struct node *tete;  // Head pointer of the linked list

// Function prototypes
void init();
int testVide();
void AjouterPr(int element);
void AjouterDr(int element);
void afficher();
void libererMemoire();

int main() {
    // Initialize the linked list
    init();

    int option, element;
    while (1) {
        //system("clear");
        // Display menu options
        printf("Veuillez Choisir une Option:\n 1) Ajouter Une nouvelle cellule en tete de la liste. \n 2) Ajouter des cellules a la fin de la liste \n 3) Afficher La liste \n => ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                system("clear");
                // Add a new node at the beginning of the list
                printf("Saisir l'element a ajouter au premier de la liste: ");
                scanf("%d", &element);
                AjouterPr(element);
                break;
            case 2:
                system("clear");
                // Add a new node at the end of the list
                printf("Saisir l'element a ajouter a la fin de la liste: ");
                scanf("%d", &element);
                AjouterDr(element);
                break;
            case 3:
                // Display the linked list
                afficher();
                break;
            default:
                printf("Option invalide.\n");
        }
    }

    return 0;
}

// Initialize the linked list
void init() {
    tete = NULL;
}

// Check if the linked list is empty
int testVide() {
    if (tete == NULL) {
        printf("la liste est vide. \n");
        return 1;
    }
    return 0;
}

// Add a new node at the beginning of the list
void AjouterPr(int element) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = element;
    newNode->next = tete;
    tete = newNode;
}

// Add a new node at the end of the list
void AjouterDr(int element) {
    struct node *newNode, *tmp;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = element;
    newNode->next = NULL;
    tmp = tete;
    if (tmp == NULL) {
        tete = newNode;
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = newNode;
    }
    printf("element inséré\n");
}

// Display the linked list
void afficher() {
    if (testVide())
        return;

    struct node *current = tete;
    while (current != NULL) {
        //system("clear");
        printf("%d->", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Free the memory allocated for the linked list
void libererMemoire() {
    struct node *current = tete;
    struct node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
