#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* void PideNombreArchivo(char *NombreArchivo); */
int Archivo_NULL(char *Nombre);

int Archivo_NULL(char *Nombre)
{
  FILE *Archivo;
  Archivo = fopen(Nombre,"rt"); 
  if (Archivo != NULL)
    {
      fclose(Archivo);
      return 0;
    }
  return 1;
}

/* void PideNombreArchivo(char *NombreArchivo) */
/* { */
/*   char Extension[6]=".csv"; */
/*   printf("Dame el nombre del archivo: "); */
/*   scanf("%s",NombreArchivo); */
/*   strcat(NombreArchivo,Extension); */
/* } */
