#include <stdio.h>
#include <math.h>

void lire(float *A, int d, char nom);
void afficher(float *A, int d);
float produit(float *A, float *B, int d);
void somme(float *A, float *B, int d);
void scalaire(float *A, int d, float k);
void distance(float *A, float *B, int d);

void lire(float *A, int d, char nom) {
    for (int i = 0; i < d; i++) {
        printf("%c[%d] = ", nom, i);
        scanf("%f", &A[i]);}}
void afficher(float *A, int d) {
    for (int i = 0; i < d; i++) {
        printf("%.2f ", A[i]);}
    printf("\n");}
float produit(float *A, float *B, int d) {
    float s = 0;
    for (int i = 0; i < d; i++) {
        s += A[i] * B[i];
    }return s;}
void somme(float *A, float *B, int d) {
    for (int i = 0; i < d; i++) {
        A[i] += B[i];}}
void scalaire(float *A, int d, float k) {
    for (int i = 0; i < d; i++) {
        A[i] *= k;}}
void distance(float *A, float *B, int d) {
    float s = 0;
    for (int i = 0; i < d; i++) {
        s += pow(A[i] - B[i], 2);}
    printf("Distance = %.2f\n", sqrt(s)); }
int main() {
    int choix, d, lu = 0;
    float k;
    do {
        printf("Entrer la dimension du vecteur: ");
        scanf("%d", &d);
    } while (d <= 0);

    float A[d], B[d];

    do {
        printf("\n------ MENU ------\n");
        printf("1- Lecture A\n");
        printf("2- Affichage\n");
        printf("3- Somme A+B\n");
        printf("4- Produit scalaire\n");
        printf("5- Multiplication par un scalaire\n");
        printf("6- Distance\n");
        printf("7- Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("Vecteur A:\n");
                lire(A, d, 'A');
                printf("Vecteur B:\n");
                lire(B, d, 'B');
                lu = 1;
                break;
            case 2:
                if (!lu) { printf("Veuillez lire les vecteurs.\n"); break; }
                printf("A: "); afficher(A, d);
                printf("B: "); afficher(B, d);
                break;
            case 3:
                if (!lu) { printf("Veuillez lire les vecteurs.\n"); break; }
                somme(A, B, d);
                printf("A + B = ");
                afficher(A, d);
                break;
            case 4:
                if (!lu) { printf("Veuillez lire les vecteurs.\n"); break; }
                printf("Produit scalaire = %.2f\n", produit(A, B, d));
                break;
            case 5:
                if (!lu) { printf("Veuillez lire le vecteur A.\n"); break; }
                printf("Donner k: ");
                scanf("%f", &k);
                scalaire(A, d, k);
                afficher(A, d);
                break;
            case 6:
                if (!lu) { printf("Veuillez lire les vecteurs.\n"); break; }
                distance(A, B, d);
                break;
            case 7:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide.\n"); } } while (choix != 7);
                return 0;}
