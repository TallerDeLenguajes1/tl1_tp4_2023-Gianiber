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

int BuscarTarea(int id, Tarea **tarea, int cant);

int main()
{
    srand(time(NULL));
    int cant, opc, i_realizado, busc;
    i_realizado = 0;
    printf("Ingrese cantidad de tareas: ");
    scanf("%d", &cant);
    Tarea **tarea = (Tarea **)malloc(sizeof(Tarea *) * cant);  // tareas pendientes
    Tarea **tarea2 = (Tarea **)malloc(sizeof(Tarea *) * cant); // tareas realizadas
    char *buff = (char *)malloc(sizeof(char) * 100);

    for (int i = 0; i < cant; i++)
    {
        tarea[i] = NULL;
        tarea2[i] = NULL;
    }

    for (int i = 0; i < cant; i++)
    {

        tarea[i] = (Tarea *)malloc(sizeof(Tarea));
        tarea[i]->TareaID = i;
        tarea[i]->Duracion = (rand() % 90) + 10;
        tarea[i]->Descripcion = (char *)malloc(sizeof(char) * 100);
        fflush(stdin);
        printf("Descripcion: ");
        gets(buff);
        strcpy(tarea[i]->Descripcion, buff);
    }

    for (int i = 0; i < cant; i++)
    {
        printf("Se resolvio TareaID: %d - Descripcion: %s?\t(Si = 1 No = 2)\n", tarea[i]->TareaID, tarea[i]->Descripcion);
        scanf("%d", &opc);
        if (opc == 1)
        {
            tarea2[i] = tarea[i];
            tarea[i] = NULL;
        }
    }
    printf("Tareas realizadas: \n");

    for (int i = 0; i < cant; i++)
    {
        if (tarea2[i] != NULL)
        {
            printf("Descripcion: %s\n", tarea2[i]->Descripcion);
            printf("Duracion: %d\n", tarea2[i]->Duracion);
        }
    }

    printf("Que tarea desea buscar? (ID)");
    scanf("%d", &busc);
    printf("%s", tarea[BuscarTarea(busc, tarea, cant)]->Descripcion);

    for (int i = 0; i < cant; i++)
    {
        if (tarea[i] != NULL)
        {
            free(tarea[i]->Descripcion);
            free(tarea[i]);
        }
    }

    for (int i = 0; i < cant; i++)
    {
        if (tarea2[i] != NULL)
        {
            free(tarea2[i]->Descripcion);
            free(tarea2[i]);
        }
    }
    free(tarea);
    free(tarea2);
    free(buff);

    return 0;
}

int BuscarTarea(int id, Tarea **tarea, int cant)
{
    Tarea **aux;
    aux = tarea;
    for (int i = 0; i < cant; i++)
    {
        if (id == aux[i]->TareaID)
        {
            return aux[i]->TareaID;
        }
    }
}