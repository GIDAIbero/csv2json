#include <stdio.h>
#include <string.h>
#include "validacion.h"
#include "leer2.h"
#include "Insertar.h"
#include "Guardar.h"
#include "abrearchivo.h"

main(int argc, char *argv[])
{
  char Nombre_entrada[100], Nombre_salida[100], matriz[100][100], tema[100], titulo[100], subtitulo[100]; 
  int renglones=0, i, error, opcion=0, posicion_comas;
  ptrtema Inicio=NULL;
  ptrsubtema ultimo_subtema;
  if (validacion(argc, argv, Nombre_entrada, Nombre_salida)!=0)
    {
      //printf("%s\n", Nombre_entrada);
      if(Leer_y_guardar (Nombre_entrada, matriz, &renglones)==1)
	{
	  //printf("%d\n", renglones);
	  //printf("leer y guradar\n");
	  Validar_y_meter(matriz, renglones, &error);
	  //printf("valida y mete\n");
	  Pasar_cadenas(matriz, renglones, error, &Inicio, tema, titulo, subtitulo, &ultimo_subtema, &posicion_comas);
	  //printf("pasa cadenas\n");
	  //printf("%s\n", Nombre_salida);
	  if(argc!=6)
	    { 
	      while(Archivo_NULL(Nombre_salida)==0 && opcion!=1)
		{
		  //opcion=0;
		  //printf("entra a opcion 1");
		  Menu(&opcion);
		  if(opcion==2)
		    {
		      printf("Archivo de Salida: ");
		      scanf("%s",Nombre_salida);
		    } 
		  Limpia();
		  Menu_Entrada_Salida(&Nombre_entrada, &Nombre_salida);
		}
	      //printf("sale del while");
	    }
	  //printf("sale del while\n");
	  Muestra(Inicio, Nombre_salida, posicion_comas);
	  //printf("muestra\n");
	  Destruye(Inicio);
	  //printf("destruye\n");
	}
       if(Leer_y_guardar (Nombre_entrada, matriz, &renglones)==0)
	 printf("ERROR: Archivo de Entrada inexistente.\n");
    }
}
