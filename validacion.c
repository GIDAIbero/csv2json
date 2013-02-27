#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"abrearchivo.h"

int validacion(int argc, char *argv[], char Nombre_entrada[100],char Nombre_salida[100]);
void Despliega_error();
void Despliega_menu(char Nombre_entrada[100],char Nombre_salida[100]);
void Entrada_Salida(char *argv[], char *Entrada, char *Salida);
void Menu_Entrada_Salida(char *Entrada, char *Salida);

/* int validacion(int argc, char *argv[], char Nombre_entrada[15]) */
/* { */
/*   if(argc>=2||argc<=6) */
/*     { */
/*       if(argc==2 && strcmp(argv[1],"-menu")==0) */
/* 	return 1; */
/*       else */
/* 	if(argc==5 && strcmp(argv[1],"-i")==0 && strcmp(argv[3],"-o")==0) */
/* 	  { */
/* 	    strcpy(Nombre_entrada, argv[2]); */
/* 	    return 2; */
/* 	  } */
/* 	else */
/* 	  if(argc==6 && strcmp(argv[5],"-ow")==0) */
/* 	    return 3; */
/* 	  else */
/* 	    { */
/* 	      printf("ERROR DE SINTAXIS: Sintaxis correcta:\n"); */
/* 	      printf("                            $CSV2JSON -menu\n"); */
/* 	      printf("                            $CSV2JSON -i entrada -o salida\n"); */
/* 	      printf("                            $CSV2JSON -i entrada -o salida -ow\n\n"); */
/* 	    } */
/*       return 0; */
/*     } */
/* } */

void Despliega_menu (char Nombre_entrada[100],char Nombre_salida[100])
{
  char ow[10];
  int i=0;
  do
    {
      system("clear");
      printf("*******MENU********\n\n");
      printf("Dame el nombre del archivo de entrada (.csv): ");
      scanf("%s", Nombre_entrada);
      printf("Dame el nombre del archivo de salida (.json): ");
      scanf("%s", Nombre_salida);
      printf("¿Deseas omitir el mensaje de sobreescritura si el archivo de salida ya exitse?: ");
      scanf("%s", ow);
      if(strcasecmp(ow, "no")==0)
	{
	  i=3;
	  //printf("entra a no\n");
	}
      if (strcasecmp(ow, "si")==0)
	{
	  i=1;
	  //printf("entra a si \n");
	}
      if(strcasecmp(ow, "renombrar")==0)
	i=2;
      //printf("sale de si\n");
      //printf("%d\n", i);
      if(i==0)
	{
	  printf("ERROR, opción no válida.\n");
	  printf("Opciones válidas: si, no, renombrar\n");
	}
    }
  while (i!=1 && i!=3);
  Menu_Entrada_Salida(Nombre_entrada, Nombre_salida);
  if(i==3)
    if(Archivo_NULL(Nombre_salida)==0)
      {
	printf("Ese archivo ya existe.\n");
	exit(0);
      }
  //printf("sale del while\n");
}

int validacion(int argc, char *argv[], char Nombre_entrada[100], char Nombre_salida[100])
{
  int i=0;
  if (argc<2||argc>6)
    Despliega_error();
  else
    {
      if (argc==2)
	{
	  if (strcmp(argv[1], "-menu")==0)
	    {
	      Despliega_menu(Nombre_entrada, Nombre_salida);
	      i++;
	    }
	  else
	    Despliega_error();
	}
      if (argc==3 || argc==4)
	Despliega_error();
      if(argc==5)
	{
	  if (strcmp(argv[1],"-i")==0)
	    {
	      if (strcmp(argv[3], "-o")==0)
		{
		  i++;
		  Entrada_Salida(argv, Nombre_entrada, Nombre_salida);
		}
	    }
	  else
	    Despliega_error();
	}
      if(argc==6)
	{
	  if (strcmp(argv[1],"-i")==0)
	    {
	      if (strcmp(argv[3], "-o")==0)
		{
		  if(strcmp(argv[5], "-ow")==0)
		    {
		      i++;
		      Entrada_Salida(argv, Nombre_entrada, Nombre_salida);
		    }
		  else
		    Despliega_error();
		}
	      else
		Despliega_error();
	    }
	  else
	    Despliega_error();
	}
    }
  return i;
}

void Despliega_error()
{
  printf("ERROR DE SINTAXIS: Sintaxis correcta:\n");
  printf("                            $CSV2JSON -menu\n");
  printf("                            $CSV2JSON -i entrada -o salida\n");
  printf("                            $CSV2JSON -i entrada -o salida -ow\n\n");
}

void Entrada_Salida(char *argv[], char *Entrada, char *Salida)
{
  int a;
  strcpy(Entrada, argv[2]);
  strcpy(Salida, argv[4]);
  //printf("%s & %s\n", Entrada, Salida);
  //Entrada
  for(a=0; Entrada[a]!='.' && Entrada[a]!='\0'; a++)
    {}
  if(Entrada[a]=='.')
    if(strcmp(&Entrada[a], ".csv")!=0)
      strcpy(&Entrada[a],".csv");
  if(Entrada[a]!='.')
    strcat(Entrada,".csv");
  //Salida
  for(a=0; Salida[a]!='.' && Salida[a]!='\0'; a++)
    {}
  if(Salida[a]=='.')
    if(strcmp(&Salida[a], ".json")!=0)
      strcpy(&Salida[a],".json");
  if(Salida[a]!='.')
    strcat(Salida,".json");
  //printf("%s & %s\n", Entrada, Salida);
}

void Menu_Entrada_Salida(char *Entrada, char *Salida)
{
  int a;
  //printf("%s & %s\n", Entrada, Salida);
  //Entrada
  for(a=0; Entrada[a]!='.' && Entrada[a]!='\0'; a++)
    {}
  if(Entrada[a]=='.')
    if(strcmp(&Entrada[a], ".csv")!=0)
      strcpy(&Entrada[a],".csv");
  if(Entrada[a]!='.')
    strcat(Entrada,".csv");
  //Salida
  for(a=0; Salida[a]!='.' && Salida[a]!='\0'; a++)
    {}
  if(Salida[a]=='.')
    if(strcmp(&Salida[a], ".json")!=0)
      strcpy(&Salida[a],".json");
  if(Salida[a]!='.')
    strcat(Salida,".json");
  //printf("%s & %s\n", Entrada, Salida);
}
