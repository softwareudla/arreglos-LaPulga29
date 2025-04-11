#include <stdio.h>
#include <string.h>
int main() {
    int estudiantes = 5, materias = 3, aprobados = 0, len = 0, val1;
    float calificaciones[5][3], suma = 0;
    char ests_nombres[5][30];
    char mats_nombres[3][30] = {"Mate", "Costos", "Progra"};

    for (int cont1 = 0; cont1 < 5; cont1++)
    {
        printf("Nombre del estudiante %d: ", cont1 + 1);
        fflush(stdin);
        fgets(ests_nombres[cont1], 30, stdin);
        len = strlen(ests_nombres[cont1]) - 1;
        ests_nombres[cont1][len] = '\0';
    }
    for (int cont1 = 0; cont1 < estudiantes; cont1++) {
        for (int cont2 = 0; cont2 < materias; cont2++) {
            do {
                printf("Calificacion de %s en %s (0-10): ", ests_nombres[cont1], mats_nombres[cont2]);
                fflush(stdin);
                val1 = scanf("%f", &calificaciones[cont1][cont2]);
                if (val1 != 1)
                {
                    printf("No se permite ese valor.\n"); 
                }
                else if (calificaciones[cont1][cont2] < 0 || calificaciones[cont1][cont2] > 10)
                {
                    printf("No se permite ese valor.\n"); 
                }  
            } while (calificaciones[cont1][cont2] < 0 || calificaciones[cont1][cont2] > 10 || val1 != 1);
        }
    }
    printf("\n\t  -> PROMEDIOS POR ESTUDIANTES <-");
    printf("\nESTUDIANTE\t\t\t\tPROMEDIO\t\n");
    for (int cont1 = 0; cont1 < estudiantes; cont1++) {
        for (int cont2 = 0; cont2 < materias; cont2++)
            suma = suma + calificaciones[cont1][cont2];
        printf("%s \t\t\t\t  %.2f\t\t\t\n", ests_nombres[cont1], suma / 3);
        suma = 0; 
    }
    printf("\n\t   -> PROMEDIOS POR MATERIA <-"); 
    printf("\nMATERIA\t\t\t\t\tPROMEDIO\t\n");
    for (int cont2 = 0; cont2 < materias; cont2++) {
        for (int cont1 = 0; cont1 < estudiantes; cont1++)
            suma = suma + calificaciones[cont1][cont2];
        printf("%s \t\t\t\t\t  %.2f\t\t\t\n", mats_nombres[cont2], suma / 5);
        suma = 0; 
    }
    printf("\n\t -> NOTA MAS BAJA Y MAS ALTA POR ESTUDIANTE <- \t\n");
    printf("ESTUDIANTE\t\t\tMAYOR\t\t\tMENOR\n"); 
    for (int cont1 = 0; cont1 < estudiantes; cont1++) {
        float max = calificaciones[cont1][0], min = calificaciones[cont1][0];
        for (int cont2 = 1; cont2 < materias; cont2++) {
            if (calificaciones[cont1][cont2] > max) 
                max = calificaciones[cont1][cont2];
            if (calificaciones[cont1][cont2] < min) 
                min = calificaciones[cont1][cont2];
        }
        printf("%s\t\t\t%.2f\t\t\t%.2f\n", ests_nombres[cont1], max, min);
    }
    printf("\n\t -> NOTA MAS BAJA Y MAS ALTA POR MATERIA <- \t\n");
    printf("MATERIA\t\t\t\tMAYOR\t\t\tMENOR\n"); 
    for (int cont2 = 0; cont2 < materias; cont2++) {
        float max = calificaciones[0][cont2], min = calificaciones[0][cont2]; 
        for (int cont1 = 1; cont1 < estudiantes; cont1++) {
            if (calificaciones[cont1][cont2] > max) 
                max = calificaciones[cont1][cont2];
            if (calificaciones[cont1][cont2] < min) 
                min = calificaciones[cont1][cont2];
        }
        printf("%s\t\t\t\t%.2f\t\t\t%.2f\n", mats_nombres[cont2], max, min);
    }
    printf("\n\t  -> APROBADOS POR MATERIA <-\t");
    printf("\nMATERIA\t\t\t\t\tAPROBADOS\t\n");
    for (int cont2 = 0; cont2 < materias; cont2++) {
        for (int cont1 = 0; cont1 < estudiantes; cont1++) {
            if (calificaciones[cont1][cont2] >= 6)
                aprobados = aprobados + 1;
        }
        printf("%s\t\t\t\t\t   %d\n", mats_nombres[cont2], aprobados);
    }
    return 0;
}