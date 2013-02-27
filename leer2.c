#include <stdio.h>
#include <string.h>

//void Leer_y_guardar (char Nombre_entrada[15], char matriz[100][100], int *renglones);
/* void Desplegar(char matriz[100][100], int renglones); */
/* void Validar_y_meter(char matriz[100][100], int renglones, int *error); */
/* void Pasar_cadenas(char matriz[100][100], int renglones, int error); */

/* main() */
/* { */
/*   char Nombre_entrada[15],  matriz[100][100]; */
/*   int renglones, i, error; */
/*   strcpy(Nombre_entrada, "Prueba.txt"); */
/*   Leer_y_guardar (Nombre_entrada, matriz, &renglones); */
/*   Validar_y_meter(matriz, renglones, &error); */
/*   Pasar_cadenas(matriz, renglones, error); */
/*   /\* Desplegar(matriz, renglones); *\/ */
/* } */

int Leer_y_guardar (char Nombre_entrada[100], char matriz[100][100], int *renglones)
{
  FILE *Archivo;
  int i=0;
  Archivo=fopen(Nombre_entrada, "rt");
  if(Archivo!=NULL)
    {
      while(fgets(matriz[i], 100, Archivo)!=NULL)
	{
	  // printf("El numero que regresa archivo %s",fgets(matriz[i], 100, Archivo));
	  i++;
	  *renglones=*renglones+1;
	}
      //printf("sale del while\n");
      fclose(Archivo);
      return 1;
    }
  return 0;
}

void Desplegar(char matriz[100][100], int renglones)
{
  int i=0;
  printf("Desplegando el contenido de la matriz\n\n");
  for(i=0; i<renglones; i++)
    printf("%s",matriz[i]);
  //puts(matriz[i]);
  printf("\nFin de la matriz\n");
}

void Validar_y_meter(char matriz[100][100], int renglones, int *error)
{
  int i, comas=0, j;
  *error=0;
  for(i=0; i<=renglones; i++)
    {
      if (i==0)
	if (matriz[i][0]==',')
	  {
	    *error=*error+1;
	    //printf("entra a validacion de la primera linea");
	    printf("Error en la línea %d.-> La primera línea debe ser un tema con el formato Tmea,,\n", i+1);
	  }
      if(matriz[i][0]!=',')
	{
	  if (matriz[i][0]==',' ||matriz[i][0]=='\n' ||matriz[i][0]=='\0')
	    {
	      //printf("entra al primer error\n");
	      *error=*error+1;
	      printf("Error en la línea %d.-> El primer caracter de la línea no es valido\n", i+1);
	    }
	  if (matriz[i][strlen(matriz[i])-2]!=','||matriz[i][strlen(matriz[i])-3]!=',')
	    {
	      //printf("entra al segunfo error\n");
	      *error=*error+1;
	      printf("Error en la línea %d.-> Los temas deben tener al final dos comas\n", i+1);
	    }
	  if (matriz[i][strlen(matriz[i])-1]!='\n')
	    {
	      //printf("entra al tercer error\n");
	      *error=*error+1;
	      printf("Error en la línea %d.-> Los temas deben tener al final dos comas\n", i+1);
	    }
	  for(j=0; j<strlen(matriz[i]); j++)
	    if(matriz[i][j]==',')
	      comas++;
	  if(comas!=2)
	    {
	      *error=*error+1;
	      //printf("entra al error de comas\n");
	      printf("Error en la línea %d.-> Los temas solo pueden tener dos comas. Formato: tema,,\n", i+1);
	    }
	  if(matriz[i][j]=='\n' && j!=strlen(matriz[i])&&j!=strlen(matriz[i]-1))
	    {
	      *error=*error+1;
	      //printf("entra al error de raro\n");
	      printf("Error en la línea %d.\n", i+1);
	    }
	  //printf("sale del penultimo if\n");
	  if(matriz[i+1][0]!=',')
	    {
	      *error=*error+1;
	      //printf("error, la linea de abajo no es un titulo\n");
	      printf("Error en la línea %d.->No puede haber un tema sin titulos y subtitulos\n", i+1);
	    }
	  //printf("%d\n", error);
	}
      else
	{
	  //printf("entra al else\n");
	  while(matriz[i][0]==',')
	    {
	      comas=0;
	      //printf("strlen=%d\n", (int)strlen(matriz[i]));
	      for(j=0; j<strlen(matriz[i]); j++)
		{
		  //printf("entra al for \n");
		  //printf("i=%d\n", i);
		  //printf("j=%d\n", j);
		  if (matriz[i][j]==',')
		    comas++;
		}
	      //printf("sale del for\n");
	      if(comas>2)
		{
		  //printf("error 2 de comas\n");
		  *error=*error+1;
		  printf("Error en la línea %d.->No puede haber más de dos comas. Formato: ,título, subtitulo\n", i+1);
		}
	      /*if(matriz[i][strlen(matriz[i])-1]!='\n')
		{
		  //printf("entra al cuarto error\n");
		  *error=*error+1;
		  printf("Error en la línea %d.\n", i+1);
		}  
	      if(matriz[i][j]=='\n' && j!=strlen(matriz[i])&&j!=strlen(matriz[i]-1))
		{
		  *error=*error+1;
		  //printf("entra al error de raro\n");
		  printf("Error en la línea %d.\n", i+1);
		  }*/
	      i++;
	    }
	}
      /* if(i==renglones) */
      /* 	if(matriz[i][0]!=',') */
      /* 	  { */
      /* 	    error++; */
      /* 	    printf("Error en la línea %d.\n", i+1); */
      /* 	  } */
      //printf("%d\n", error);
    }
  if (*error!=0)
     printf("ERROR, el archivo no esta en el formato correcto.\n");
}
  
