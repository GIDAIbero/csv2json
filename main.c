#include <stdio.h>
#include <string.h>
#include "validacion.h"
#include "leer2.h"
#include "Insertar.h"
#include "Guardar.h"
#include "abrearchivo.h"

int main(int argc, char *argv[]) {
	char *Nombre_entrada, *Nombre_salida, matriz[100][100], tema[100], titulo[100], subtitulo[100]; 
	Nombre_entrada = malloc(100*sizeof(char));
	Nombre_salida  = malloc(100*sizeof(char));
	int renglones=0, error, opcion=0, posicion_comas;
	ptrtema Inicio=NULL;
	ptrsubtema ultimo_subtema;
	if (validacion(argc, argv, Nombre_entrada, Nombre_salida)!=0) {
		if(Leer_y_guardar (Nombre_entrada, matriz, &renglones)==1) {
			Validar_y_meter(matriz, renglones, &error);
			Pasar_cadenas(matriz, renglones, error, &Inicio, tema, titulo, subtitulo, &ultimo_subtema, &posicion_comas);
			if(argc!=6) { 
				while(Archivo_NULL(Nombre_salida)==0 && opcion!=1) {
					Menu(&opcion);
					if(opcion==2) {
						printf("Archivo de Salida: ");
						scanf("%s",Nombre_salida);
					} 
					Limpia();
					Menu_Entrada_Salida(Nombre_entrada, Nombre_salida);
				}
			}
			Muestra(Inicio, Nombre_salida, posicion_comas);
			Destruye(Inicio);
		}
		if(Leer_y_guardar (Nombre_entrada, matriz, &renglones)==0)
			printf("ERROR: Archivo de Entrada inexistente.\n");
	}
	return 0;
}
