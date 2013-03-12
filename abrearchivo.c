#include "abrearchivo.h"

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