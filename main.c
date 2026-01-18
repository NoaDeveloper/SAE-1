#include <stdio.h>
#include <string.h>

// --- CONSTANTES (On réserve la taille max des placards) ---
#define MAX_ELEVES 50
#define MAX_MATIERES 10
#define MAX_NOTES 20
#define TAILLE_TXT 50

// Fonction pour nettoyer le clavier après avoir tapé un nombre
// (Sinon le programme valide la question suivante tout seul)
void viderBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

// Fonction pratique pour enlever le "Entrée" à la fin d'un texte
void nettoyerTexte(char *texte)
{
    texte[strcspn(texte, "\n")] = 0;
}

float calculerMoyenneMatiere(int id_eleve, int id_matiere, float notes[MAX_ELEVES][MAX_MATIERES][MAX_NOTES], int nb_evals)
{
    float somme = 0;
    if (nb_evals <= 0)
        return 0; // Sécurité pour éviter la division par zéro

    for (int n = 0; n < nb_evals; n++)
    {
        somme += notes[id_eleve][id_matiere][n];
    }
    return somme / nb_evals;
}

float calculerMoyenneGenerale(int id_eleve, float moyennes_par_matiere[MAX_ELEVES][MAX_MATIERES], int nb_matieres)
{
    float somme = 0;
    if (nb_matieres <= 0)
        return 0;

    for (int m = 0; m < nb_matieres; m++)
    {
        somme += moyennes_par_matiere[id_eleve][m];
    }
    return somme / nb_matieres;
}

int main()
{
    // --- 1. DÉCLARATION DES TABLEAUX (Le travail de tes potes + tes ajouts) ---

    char noms_eleves[MAX_ELEVES][TAILLE_TXT];     // Liste des noms
    char noms_matieres[MAX_MATIERES][TAILLE_TXT]; // Liste des matières
    int nb_evals_par_matiere[MAX_MATIERES];       // Combien de notes par matière ?

    // Le tableau 3D imposé par le sujet : [Qui ?] [Quelle matière ?] [Quelle note ?] [cite: 82, 157]
    float notes[MAX_ELEVES][MAX_MATIERES][MAX_NOTES];

    // Tes tableaux pour stocker les résultats et gérer le tri [cite: 165]
    float moyennes_matiere_eleve[MAX_ELEVES][MAX_MATIERES];
    float moyennes_generales[MAX_ELEVES];
    int ordre_tri[MAX_ELEVES]; // Tableau d'indices pour le classement

    int nb_eleves = 0;
    int nb_matieres = 0;

    printf("=== GESTIONNAIRE DE NOTES (SAE 1.01) ===\n\n");

    // --- 2. CONFIGURATION DES MATIÈRES (Code original de tes potes) ---

    printf("Combien de matieres y a-t-il (max %d) ? : ", MAX_MATIERES);
    scanf("%d", &nb_matieres);
    viderBuffer();

    printf("\n--- Etape 1 : Noms des matieres ---\n");
    for (int m = 0; m < nb_matieres; m++)
    {
        printf("Matiere %d : ", m + 1);
        fgets(noms_matieres[m], TAILLE_TXT, stdin);
        nettoyerTexte(noms_matieres[m]);

        printf("  -> Combien de notes en '%s' ? : ", noms_matieres[m]);
        scanf("%d", &nb_evals_par_matiere[m]);
        viderBuffer();
    }

    // --- 3. SAISIE DES ÉLÈVES ET DES NOTES + TES CALCULS ---

    printf("\n--- Etape 2 : Saisie des notes ---\n");
    printf("Combien d'eleves (max %d) ? : ", MAX_ELEVES);
    scanf("%d", &nb_eleves);
    viderBuffer();

    for (int i = 0; i < nb_eleves; i++)
    {
        ordre_tri[i] = i; // On prépare l'indice pour le tri
        printf("\n>> Eleve %d/%d\n", i + 1, nb_eleves);
        printf("Nom de l'eleve : ");
        fgets(noms_eleves[i], TAILLE_TXT, stdin);
        nettoyerTexte(noms_eleves[i]);

        for (int m = 0; m < nb_matieres; m++)
        {
            printf("   Notes de %s (%d notes attendues) :\n", noms_matieres[m], nb_evals_par_matiere[m]);

            for (int n = 0; n < nb_evals_par_matiere[m]; n++)
            {
                printf("     Note %d : ", n + 1);
                scanf("%f", &notes[i][m][n]);
            }
            moyennes_matiere_eleve[i][m] = calculerMoyenneMatiere(i, m, notes, nb_evals_par_matiere[m]);
        }
        moyennes_generales[i] = calculerMoyenneGenerale(i, moyennes_matiere_eleve, nb_matieres);
        viderBuffer();
    }

    // --- 4. TRI DES ÉTUDIANTS (Ta fonctionnalité supplémentaire) [cite: 165] ---
    // Algorithme de tri à bulles pour classer par moyenne décroissante
    for (int i = 0; i < nb_eleves - 1; i++)
    {
        for (int j = 0; j < nb_eleves - i - 1; j++)
        {
            if (moyennes_generales[ordre_tri[j]] < moyennes_generales[ordre_tri[j + 1]])
            {
                int temp = ordre_tri[j];
                ordre_tri[j] = ordre_tri[j + 1];
                ordre_tri[j + 1] = temp;
            }
        }
    }

    // --- 5. AFFICHAGE FINAL (Bulletin complet et classement) [cite: 164, 165] ---

    printf("\n\n=== CLASSEMENT FINAL DES ETUDIANTS ===\n");
    for (int i = 0; i < nb_eleves; i++)
    {
        int idx = ordre_tri[i];
        printf("%d. %s | MOYENNE GENERALE : %.2f / 20\n", i + 1, noms_eleves[idx], moyennes_generales[idx]);

        printf("   Details par matiere :\n");
        for (int m = 0; m < nb_matieres; m++)
        {
            printf("   - %-15s : %.2f / 20\n", noms_matieres[m], moyennes_matiere_eleve[idx][m]);
        }
        printf("--------------------------------------------\n");
    }

    return 0;
}