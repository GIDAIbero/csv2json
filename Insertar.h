#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct def_subtema
{
  char titulo[100];
  char subtitulo[100];
  struct def_subtema *Next_subtema;
};
typedef struct def_subtema tsubtema;
typedef struct def_subtema *ptrsubtema;

struct def_tema
{
  char tema[100];
  struct def_tema *Next_tema;
  ptrsubtema Next_subtema;
};
typedef struct def_tema ttema;
typedef struct def_tema *ptrtema;
  
void Pasar_cadenas(char matriz[100][100], int renglones, int error, ptrtema *Inicio, char tema[100], char titulo[100], char subtitulo[100], ptrsubtema *ultimo_subtema, int *posicion_comas);
void Insertar_tema(ptrtema *Inicio, char tema[100]);
void Insertar_subtema (ptrtema Inicio, char titulo[100], char subtitulo[100], ptrsubtema *ultimo_subtema, int posicion_comas);void Destruye(ptrtema Inicio);
void Muestra(ptrtema Inicio, char Nombre_salida[100], int posicion_comas);
void imprimeLaCadena(ptrtema Inicio);
void imprimeLosSubtemas(ptrsubtema Inicio);