#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Tarea
{
    int TareaID; // Numerado en ciclo iterativo
    char *Descripcion;
    int Duracion; // entre 10 – 100
} Tarea;

void Crear(int cant, Tarea ***tarea);
void Llenar(int cant, Tarea ***tarea);
void Pendientes(int cant, Tarea ***tarea);
void Realizadas(int cant, Tarea ***tarea);
void Verificar(int cant, Tarea ***tarea1, Tarea ***tarea2);
void BuscarTarea(int cant, Tarea ***tarea);

int main()
{
    int cant;
    Tarea **tareaP, **tareaR;
    srand(time(NULL));
    printf("Ingrese cantidad de tareas: ");
    scanf("%d", &cant);
    Crear(cant, &tareaP); // tareas pendientes
    Crear(cant, &tareaR); // tareas realizadas
    Llenar(cant, &tareaP);
    Pendientes(cant, &tareaP);
    Verificar(cant, &tareaP, &tareaR);
    Pendientes(cant, &tareaP);
    Realizadas(cant, &tareaR);
    BuscarTarea(cant,&tareaP);
    return 0;
}

void Crear(int cant, Tarea ***tarea)
{
    *tarea = (Tarea **)malloc(cant * sizeof(Tarea *));
    for (int i = 0; i < cant; i++)
    {
        (*tarea)[i] = NULL;
    }
}

void Llenar(int cant, Tarea ***tarea)
{
    char *buff = (char *)malloc(sizeof(char) * 100);
    for (int i = 0; i < cant; i++)
    {
        (*tarea)[i] = (Tarea *)malloc(sizeof(Tarea));
        (*tarea)[i]->TareaID = i;
        (*tarea)[i]->Duracion = (rand() % 90) + 10;
        fflush(stdin);
        printf("Descripcion tarea %d: ", (*tarea)[i]->TareaID);
        gets(buff);
        (*tarea)[i]->Descripcion = (char *)malloc(sizeof(char) * strlen(buff) + 1);
        strcpy((*tarea)[i]->Descripcion, buff);
    }
}

void Pendientes(int cant, Tarea ***tarea)
{
    printf("--------TAREAS PENDIENTES--------\n");
    for (int i = 0; i < cant; i++)
    {
        if ((*tarea)[i] != NULL)
        {
            printf("Tarea %d: %s - %d dias\n", (*tarea)[i]->TareaID, (*tarea)[i]->Descripcion, (*tarea)[i]->Duracion);
        }
    }
}

void Realizadas(int cant, Tarea ***tarea)
{
    printf("--------TAREAS REALIZADAS--------\n");
    for (int i = 0; i < cant; i++)
    {
        if ((*tarea)[i] != NULL)
        {
            printf("Tarea %d: %s - %d dias\n", (*tarea)[i]->TareaID, (*tarea)[i]->Descripcion, (*tarea)[i]->Duracion);
        }
    }
}

void Verificar(int cant, Tarea ***tarea1, Tarea ***tarea2)
{
    int opc;
    for (int i = 0; i < cant; i++)
    {
        printf("Se resolvio Tarea %d - Descripcion: %s?\t(Si = 1 No = 2)\n", (*tarea1)[i]->TareaID, (*tarea1)[i]->Descripcion);
        scanf("%d", &opc);
        if (opc == 1)
        {
            (*tarea2)[i] = (*tarea1)[i];
            (*tarea1)[i] = NULL;
        }
    }
}

void BuscarTarea(int cant, Tarea ***tarea)
{
    char *buff = (char *)malloc(sizeof(char) * 100);
    char *resultado;
    fflush(stdin);
    printf("Que tarea desea buscar?\n");
    gets(buff);
    for (int i = 0; i < cant; i++)
    {
        if ((*tarea)[i] != NULL)
        {
            resultado = strstr((*tarea)[i]->Descripcion, buff);
            if (resultado != NULL)
            {
                printf("Se encontro la tarea: %s\n", (*tarea)[i]->Descripcion);
            }
        }
    }
}