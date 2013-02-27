#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void GuardarComo(char *Nombre);
void Menu(int *Opcion);
void PresionaEnter();
void Limpia();

/* main() */
/* { */
/*   int Opcion; */
/*   char Nombre[50]; */
/*   FILE *MiArchivo; */
/*   GuardarComo(Nombre); */
/*   MiArchivo = fopen(Nombre, "rt"); */
/*   if(MiArchivo == NULL) */
/*     MiArchivo = fopen(Nombre,"wt"); */
/*   else */
/*     { */
/*       printf("Ya hay un archivo con el mismo nombre.\n"); */
/*       	  do */
/* 	    { */
/*       	      Menu(&Opcion); */
/* 	      switch(Opcion) */
/* 		{ */
/* 		case 1: */
/* 		  MiArchivo = fopen(Nombre,"wt"); */
/* 		  fclose(MiArchivo); */
/* 		  Opcion=3; */
/* 		  break; */
/* 		case 2: */
/* 		  GuardarComo(Nombre); */
/* 		  MiArchivo = fopen(Nombre,"wt"); */
/* 		  fclose(MiArchivo); */
/* 		  Opcion=3; */
/* 		  break; */
/* 		case 3: */
/* 		  break; */
/* 		default: */
/* 		  printf("Error: Opcion incorrecta.\n"); */
/* 		  printf("Intenta otra vez.\n"); */
/* 		  PresionaEnter(); */
/* 		} */
/* 	    } */
/* 	  while(Opcion != 3); */
/*     } */
/* } */

void Menu(int *Opcion)
{
  printf("El archivo ya existe.\n\n");
  printf("1. Reemplazar \n");
  printf("2. Renombrar \n");
  printf("3. Cancelar.\n\n");
  printf("Opcion --> ");
  scanf("%d",Opcion);
  if(*Opcion==3)
    exit(0);
}

void PresionaEnter()
{
  char Nada[20];
  printf("Presiona <Enter> para continuar.");
  gets(Nada);
}

void Limpia()
{
  char Nada[20];
  gets(Nada);
}
