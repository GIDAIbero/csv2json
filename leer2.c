#include "leer2.h"

int Leer_y_guardar (char Nombre_entrada[100], char matriz[100][100], int *renglones) {
	FILE *Archivo;
	int i=0;
	Archivo=fopen(Nombre_entrada, "rt");
	if(Archivo!=NULL) {
		while(fgets(matriz[i], 100, Archivo)!=NULL) {
			i++;
			*renglones=*renglones+1;
		}
		fclose(Archivo);
		return 1;
	}
	return 0;
}

void Desplegar(char matriz[100][100], int renglones) {
	int i=0;
	printf("Desplegando el contenido de la matriz\n\n");
	for(i=0; i<renglones; i++) {
		printf("%s",matriz[i]);
	}
	printf("\nFin de la matriz\n");
}

void Validar_y_meter(char matriz[100][100], int renglones, int *error) {
	int i, comas=0, j, quo;
	*error=0;
	for(i=0; i<=renglones; i++) {
		if (i==0){
			if (matriz[i][0]==',') {
				*error=*error+1;
				printf("Error en la línea %d.-> La primera línea debe ser un tema con el formato Tema,,\n", i+1);
			}
		}
		if(matriz[i][0]!=',') {
			if (matriz[i][0]==',' || matriz[i][0]=='\n' || matriz[i][0]=='\0') {
				*error=*error+1;
				printf("Error en la línea %d.-> El primer caracter de la línea no es valido\n", i+1);
			}
			if (matriz[i][strlen(matriz[i]-2)] == '\0' || matriz[i][strlen(matriz[i]-2)] == '\n'){
				if (matriz[i][strlen(matriz[i])-3]!=',' && matriz[i][strlen(matriz[i])-4]!=',') {
					*error=*error+1;
					printf("Error en la línea %d.-> Los temas deben tener al final dos comas\n", i+1);
				}
			} else {
				if (matriz[i][strlen(matriz[i])-2]!=',' && matriz[i][strlen(matriz[i])-3]!=',') {
					*error=*error+1;
					printf("Error en la línea %d.-> Los temas deben tener al final dos comas\n", i+1);
				}
			}
			if (matriz[i][strlen(matriz[i])-1]!='\n') {
				*error=*error+1;
				printf("Error en la línea %d.-> Los temas deben tener al final dos comas\n", i+1);
			}
			for(j=0; j<strlen(matriz[i]); j++) {
				if(matriz[i][j]==',')
					comas++;
			}
			if(comas!=2) {
				*error=*error+1;
				printf("Error en la línea %d.-> Los temas solo pueden tener dos comas. Formato: tema,,\n", i+1);
			}
			if(matriz[i][j]=='\n' && j!=strlen(matriz[i])&&j!=strlen(matriz[i]-1)) {
				*error=*error+1;
				printf("Error en la línea %d.\n", i+1);
			}
			if(matriz[i+1][0]!=',') {
				*error=*error+1;
				printf("Error en la línea %d.->No puede haber un tema sin titulos y subtitulos\n", i+1);
			}
		} else {
			while(matriz[i][0]==',') {
				comas=0;
				quo = 0;
				for(j=0; j<strlen(matriz[i]); j++) {
					if (matriz[i][j] == '"') {
						if (quo == 0)
							quo = 1;
						else 
							quo = 0;
					}
					if (matriz[i][j]==',' && quo == 0)
						comas++;
				}
				if(comas>2) {
					*error=*error+1;
					printf("Error en la línea %d.->No puede haber más de dos comas. Formato: ,título, subtitulo\n", i+1);
				}
				i++;
			}
		}
	}
	if (*error!=0) {
		printf("ERROR, el archivo no esta en el formato correcto.\n");
	}	
}

