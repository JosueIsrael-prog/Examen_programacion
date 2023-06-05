#include <stdio.h>

#define ALUMNOS 23
#define PROGRESOS 3

// Función para obtener el promedio de calificaciones de un alumno durante el semestre
float obtenerPromedioAlumno(float calificaciones[]) {
    float suma = 0.0;
    
    for (int i = 0; i < PROGRESOS; i++) {
        suma += calificaciones[i];
    }
    
    return suma / PROGRESOS;
}

// Función para obtener la nota promedio del grupo de estudiantes para cada progreso
void obtenerPromedioGrupo(float calificaciones[][PROGRESOS], float promediosGrupo[]) {
    for (int i = 0; i < PROGRESOS; i++) {
        float suma = 0.0;
        
        for (int j = 0; j < ALUMNOS; j++) {
            suma += calificaciones[j][i];
        }
        
        promediosGrupo[i] = suma / ALUMNOS;
    }
}

// Función para obtener el alumno que obtuvo el mayor promedio de calificación durante el semestre
int obtenerMejorAlumno(float promediosAlumnos[]) {
    int indiceMaximo = 0;
    
    for (int i = 1; i < ALUMNOS; i++) {
        if (promediosAlumnos[i] > promediosAlumnos[indiceMaximo]) {
            indiceMaximo = i;
        }
    }
    
    return indiceMaximo;
}

int main() {
    float calificaciones[ALUMNOS][PROGRESOS];
    float promediosAlumnos[ALUMNOS];
    float promediosGrupo[PROGRESOS];
    
    // Solicitar las calificaciones de cada alumno durante el semestre
    for (int i = 0; i < ALUMNOS; i++) {
        printf("Ingrese las calificaciones del alumno %d:\n", i+1);
        
        for (int j = 0; j < PROGRESOS; j++) {
            printf("Progreso %d: ", j+1);
            scanf("%f", &calificaciones[i][j]);
        }
        
        promediosAlumnos[i] = obtenerPromedioAlumno(calificaciones[i]);
        printf("Promedio del alumno %d: %.2f\n\n", i+1, promediosAlumnos[i]);
    }
    
    obtenerPromedioGrupo(calificaciones, promediosGrupo);
    
    printf("\n--- Resultados ---\n");
    
    // Imprimir la nota promedio del grupo de estudiantes para cada progreso
    for (int i = 0; i < PROGRESOS; i++) {
        printf("Promedio del grupo para el progreso %d: %.2f\n", i+1, promediosGrupo[i]);
    }
    
    // Obtener el alumno que obtuvo el mayor promedio de calificación durante el semestre
    int indiceMejorAlumno = obtenerMejorAlumno(promediosAlumnos);
    printf("\nEl alumno con el mayor promedio es el número %d.\n", indiceMejorAlumno+1);
    
    return 0;
}
