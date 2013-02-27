#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Insertar.h"

void Destruye_subtema(ptrsubtema Inicio);
void imprimeLosSubtemas(ptrsubtema Inicio);
void imprimeLaCadena(ptrtema Inicio);

void Pasar_cadenas(char matriz[100][100], int renglones, int error, ptrtema *Inicio, char tema[100], char titulo[100], char subtitulo[100], ptrsubtema *ultimo_subtema, int *posicion_comas)
{
  int i, j, k=0, l, m;
  //char titulo[100], subtitulo[100];
  //printf("error=%d\n", error);
  *posicion_comas=0;
  if(error==0)
    {
      //printf("%d", renglones);
      for(i=0; i<renglones-1; i++)
	{
	  //printf("entra a primer for");
	  //imprimeLaCadena(*Inicio);
	  if(matriz[i][0]!=',')
	    {
	      k=0;
	      for(j=0; matriz[i][j]!=','; j++)
		{
		  tema[k]=matriz[i][j];
		  k++;
		}
	      tema[k]='\0';
	      k=0;
	      //puts(tema);
	      Insertar_tema(Inicio, tema);
	      //printf("inserta tema");
	    }
	  if(matriz[i][0]==',')
	    {
	      k=0;
	      for(j=1; matriz[i][j]!='\n'; j++)
		{
		  //printf("entra a for subtema");
		  if(matriz[i][j]==',') 
		    {
		      *posicion_comas=j;
		    }
		  //printf("pasa id de comas");
		  //printf("posicion comas= %d\n", posicion_comas);
		}
	      //printf("%d\n", *posicion_comas);
	      if(posicion_comas!=0)
		{
		  for(l=1; l<*posicion_comas; l++)
		    {
		      //printf("j=%d\n", j);
		      //printf("letra=%c\n", matriz[i][j]);
		      titulo[k]=matriz[i][l];
		      k++;
		    }	  
		  titulo[k]='\0';
		  //puts(titulo);
		  k=0;
		  for(m=*posicion_comas+1; matriz[i][m]!='\n'; m++)
		    {
		      //printf("j=%d\n", j);	    
		      subtitulo[k]=matriz[i][m];
		      k++;
		    }
		  subtitulo[k]='\0';
		  //puts(titulo);
		  //puts(subtitulo);
		  Insertar_subtema(*Inicio, titulo, subtitulo, ultimo_subtema, *posicion_comas);
		  //printf("Sali de insertar\n");
		}
	      if(*posicion_comas==0)
		{
		  k=0;
		  //printf("entra a else\n");
		  for(l=1; matriz[i][l]!='\n'; l++)
		    {
		      //printf("j=%d\n", j);
		      //printf("letra=%c\n", matriz[i][j]);
		      titulo[k]=matriz[i][l];
		      k++;
		    }	  
		  titulo[k]='\0';
		  Insertar_subtema(*Inicio, titulo, subtitulo, ultimo_subtema, *posicion_comas);
		  //printf("pasa insertar subtema\n");
		  //printf("%d\n", i);
		}
	    }
	}
      //printf("sale del for\n");
    }

}

void Insertar_tema(ptrtema *Inicio, char tema[100])
{
  ptrtema Ultimo=(*Inicio), Nuevo; 
  //printf("entra a insertar\n");
  if(*Inicio==NULL)
    {
      *Inicio=(ptrtema)malloc(sizeof(tema));
      strcpy((*Inicio)->tema, tema);
      //printf("%s\n", (*Inicio)->tema);
      (*Inicio)->Next_tema=NULL;
      (*Inicio)->Next_subtema=NULL;
    }
  else
    {
      //printf("entra a else\n");
      while(Ultimo->Next_tema!=NULL)
	{
	  //printf("entra a while\n");
	  Ultimo=Ultimo->Next_tema;
	}
      //printf("sale de while\n");
      Nuevo=(ptrtema)malloc(sizeof(ttema));
      Nuevo->Next_tema=NULL;
      Nuevo->Next_subtema=NULL;
      strcpy(Nuevo->tema, tema);
      //printf("%s\n", Nuevo->tema);
      Ultimo->Next_tema=Nuevo;
    }
}

void Insertar_subtema (ptrtema Inicio, char titulo[100], char subtitulo[100], ptrsubtema *ultimo_subtema, int posicion_comas)
{
  ptrtema ultimo_tema=Inicio;
  ptrsubtema Nuevo,*Inicio2;
  //printf("%d", posicion_comas);
  if(Inicio->Next_tema==NULL)
    {
      if(Inicio->Next_subtema==NULL)
	{
	  Nuevo=(ptrsubtema)malloc(sizeof(tsubtema));
	  strcpy(Nuevo->titulo, titulo);
	  if(posicion_comas!=0)
	    strcpy(Nuevo->subtitulo, subtitulo);
	  Nuevo->Next_subtema=NULL;
	  Inicio->Next_subtema=Nuevo;
	  (*ultimo_subtema)=Nuevo;
	  //puts(Nuevo->titulo);
	  //puts(Nuevo->subtitulo);
	  Inicio->Next_tema=NULL;
	}
      else
	{
	  if((*ultimo_subtema)->Next_subtema==NULL)
	    {
	      //printf("ultimo==NULL\n");
	    }
	  while ((*ultimo_subtema)->Next_subtema!=NULL)
	    {
	      (*ultimo_subtema)=(*ultimo_subtema)->Next_subtema;
	    }
	  Nuevo=(ptrsubtema)malloc(sizeof(tsubtema));
	  strcpy(Nuevo->titulo, titulo);
	  if(posicion_comas!=0)
	    strcpy(Nuevo->subtitulo, subtitulo);
	  Nuevo->Next_subtema=NULL;
	  (*ultimo_subtema)->Next_subtema=Nuevo;
	  //puts(Nuevo->titulo);
	  //puts(Nuevo->subtitulo);
	}
    }
  else
   {
     while(ultimo_tema->Next_tema!=NULL)
       ultimo_tema=ultimo_tema->Next_tema;
     if(ultimo_tema->Next_subtema==NULL)
       {
	 Nuevo=(ptrsubtema)malloc(sizeof(tsubtema));
	 strcpy(Nuevo->titulo, titulo);
	 if(posicion_comas!=0)
	   strcpy(Nuevo->subtitulo, subtitulo);
	 Nuevo->Next_subtema=NULL;
	 (*ultimo_subtema)=Nuevo;
	 ultimo_tema->Next_subtema=Nuevo;
	 //puts(Nuevo->titulo);
	 //puts(Nuevo->subtitulo);
       }
     else
       {
	 while((*ultimo_subtema)->Next_subtema!=NULL)
	   (*ultimo_subtema)=(*ultimo_subtema)->Next_subtema;
	 Nuevo=(ptrsubtema)malloc(sizeof(tsubtema));
	 strcpy(Nuevo->titulo, titulo);
	 if(posicion_comas!=0)
	   strcpy(Nuevo->subtitulo, subtitulo);
	 Nuevo->Next_subtema=NULL;
	 (*ultimo_subtema)->Next_subtema=Nuevo;
	 //puts(Nuevo->titulo);
	 //puts(Nuevo->subtitulo);
       }
   }
}


void Destruye(ptrtema Inicio)
{
  ptrsubtema Inicio_subtema, ultimo_sub;
  ptrtema ultimo_tema, Destroy;
  if(Inicio->Next_tema==NULL)
    {
      ultimo_tema=Inicio;
      Inicio_subtema=ultimo_tema->Next_subtema;
      ultimo_sub=Inicio_subtema;
      while(ultimo_tema->Next_subtema!=NULL)
	{
	  ultimo_sub=ultimo_sub->Next_subtema;
	  Inicio_subtema->Next_subtema=NULL;
	  free(Inicio_subtema);
	  ultimo_tema->Next_subtema=ultimo_sub;
	  Inicio_subtema=ultimo_sub;
	}
      //printf("sale del while\n");
      free(ultimo_tema);
    }
  else
    {
      while(Inicio->Next_tema!=NULL)
	{
	  ultimo_tema=Inicio->Next_tema;
	  Destroy=ultimo_tema->Next_tema;
	  Inicio_subtema=ultimo_tema->Next_subtema;
	  ultimo_sub=Inicio_subtema;
	  while(ultimo_tema->Next_subtema!=NULL)
	    {
	      ultimo_sub=ultimo_sub->Next_subtema;
	      Inicio_subtema->Next_subtema=NULL;
	      free(Inicio_subtema);
	      ultimo_tema->Next_subtema=ultimo_sub;
	      Inicio_subtema=ultimo_sub;
	    }
	  ultimo_tema->Next_tema=NULL;
	  Inicio->Next_tema=Destroy;
	  free(ultimo_tema);
	}
    }
}


void Muestra(ptrtema Inicio, char Nombre_salida[100], int posicion_comas)
{
  ptrtema Mostrar=Inicio;
  ptrsubtema ultimo;
  char nombre[100];
  FILE *Archivo;
  //printf("%s\n", Nombre_salida);
  //printf("entra a muestra\n");
  Archivo=fopen(Nombre_salida, "wt");
  if(Inicio==NULL)
    printf("La lista esta vacia\n");
  else
    {
      fprintf(Archivo, "[\n");
      if(Inicio->Next_tema==NULL)
	{
	  fprintf(Archivo, "   [");
	  //printf("Inicio=NULL");
	  fprintf(Archivo, "\"%s\"\n", Inicio->tema);
	  fprintf(Archivo, "],\n");
	}
      else
	{
	  fprintf(Archivo, "   [");
	  while(Mostrar->Next_tema!=NULL)
	    {
	      fprintf(Archivo, "\"%s\",", Mostrar->tema);
	      Mostrar=Mostrar->Next_tema;
	    }
	  fprintf(Archivo, "\"%s\"", Mostrar->tema);
	  fprintf(Archivo, "],\n");
	}
      Mostrar=Inicio;
      fprintf(Archivo, "   [\n");
      while (Mostrar->Next_tema!=NULL)
	{
	  fprintf(Archivo, "      [");
	  ultimo=Mostrar->Next_subtema;
	  while(ultimo->Next_subtema!=NULL)
	    {
	      if((*ultimo->titulo)!='\n' && (*ultimo->titulo)!=' ' && (*ultimo->titulo)!='\0')
		{
		  fprintf(Archivo, "\"%s\",", ultimo->titulo);
		}
	      ultimo=ultimo->Next_subtema;
	    }
	  if((*ultimo->titulo)!='\n' && (*ultimo->titulo)!=' ' && (*ultimo->titulo)!='\0')
	    fprintf(Archivo, "\"%s\"", ultimo->titulo);
	  Mostrar=Mostrar->Next_tema;
	  fprintf(Archivo, "]");
	  if(Mostrar->Next_subtema!=NULL)
	    fprintf(Archivo, ",\n");
	}
      fprintf(Archivo, "      [");
      ultimo=Mostrar->Next_subtema;
      while(ultimo->Next_subtema!=NULL)
	{
	  if((*ultimo->titulo)!='\n' && (*ultimo->titulo)!=' ' && (*ultimo->titulo)!='\0')
	    fprintf(Archivo, "\"%s\",", ultimo->titulo);
	  ultimo=ultimo->Next_subtema;
	}
      fprintf(Archivo, "\"%s\"", ultimo->titulo);
      fprintf(Archivo, "]\n");
      fprintf(Archivo, "   ]\n");
      //fprintf(Archivo, "   [\n");
      if(posicion_comas!=0)
	{
	  fprintf(Archivo, "   [\n");
	  Mostrar=Inicio;
	  while (Mostrar->Next_tema!=NULL)
	    {
	      fprintf(Archivo, "      [");
	      ultimo=Mostrar->Next_subtema;
	      while(ultimo->Next_subtema!=NULL)
		{
		  if((*ultimo->subtitulo)!='\n' && (*ultimo->subtitulo)!=' ' && (*ultimo->subtitulo)!='\0')
		     fprintf(Archivo, "\"%s\",", ultimo->subtitulo);
		  ultimo=ultimo->Next_subtema;
		}
	      if((*ultimo->subtitulo)!='\n' && (*ultimo->subtitulo)!=' ' && (*ultimo->subtitulo)!='\0')
		fprintf(Archivo, "\"%s\"", ultimo->subtitulo);
	      fprintf(Archivo, "]");
	      Mostrar=Mostrar->Next_tema;
	      fprintf(Archivo, ",\n");
	    }
	  ultimo=Mostrar->Next_subtema;
	  while(ultimo->Next_subtema!=NULL)
	    {
	      fprintf(Archivo, "      [");
	      if((*ultimo->subtitulo)!='\n' && (*ultimo->subtitulo)!=' ' && (*ultimo->subtitulo)!='\0')
		fprintf(Archivo, "\"%s\",", ultimo->subtitulo);
	      ultimo=ultimo->Next_subtema;
	    }
	  if((*ultimo->subtitulo)!='\n' && (*ultimo->subtitulo)!=' ' && (*ultimo->subtitulo)!='\0')
	    fprintf(Archivo, "\"%s\"", ultimo->subtitulo);
	  fprintf(Archivo, "]\n");
	  fprintf(Archivo, "   ]\n");
	}
      fprintf(Archivo, "]\n");
    }
  fclose(Archivo);
}

void imprimeLaCadena(ptrtema Inicio)
{
  if (Inicio!=NULL){
    puts(Inicio->tema);
    //imprimeLosSubtemas(*Inicio->Next_subtema);
    imprimeLaCadena(Inicio->Next_tema);
  }
}

void imprimeLosSubtemas(ptrsubtema Inicio)
{
  if (Inicio!=NULL)
    {
      puts(Inicio->titulo);
      puts(Inicio->subtitulo);
      imprimeLosSubtemas(Inicio->Next_subtema);
    }
}
