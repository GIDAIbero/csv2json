#include "Insertar.h"

void Pasar_cadenas(char matriz[100][100], int renglones, int error, ptrtema *Inicio, char tema[100], char titulo[100], char subtitulo[100], ptrsubtema *ultimo_subtema, int *posicion_comas) {
	int i, j, k=0, l, m, quo = 0;

	*posicion_comas=0;
	if(error==0) {
		for(i=0; i<renglones-1; i++) {
			if(matriz[i][0]!=',') {
				k=0;
				for(j=0; matriz[i][j]!=',' ; j++) {
					tema[k]=matriz[i][j];
					k++;
				}
				tema[k]='\0';
				k=0;
				Insertar_tema(Inicio, tema);
			}
			if(matriz[i][0]==',') {
				k=0;
				quo = 0;
				for(j=1; matriz[i][j]!='\n' && matriz[i][j]!='\0'; j++) {
					if (matriz[i][j] == '"') {
						if (quo == 0) {
							quo = 1;
						} else {
							quo = 0;
						}
					}
					if(matriz[i][j]==',' && quo == 0) {
						*posicion_comas=j;
					}
				}
				if(*posicion_comas!=0) {
					for(l=1; l<*posicion_comas; l++) {
						if (matriz[i][l] != '"') {
							titulo[k]=matriz[i][l];
							k++;
						}
					}	  
					titulo[k]='\0';
					k=0;
					for(m=*posicion_comas+1; matriz[i][m]!='\n' && matriz[i][m]!='\0'; m++) {
						subtitulo[k]=matriz[i][m];
						k++;
					}
					subtitulo[k-1]='\0';
					Insertar_subtema(*Inicio, titulo, subtitulo, ultimo_subtema, *posicion_comas);
				}
				if(*posicion_comas==0) {
					k=0;
					for(l=1; matriz[i][l]!='\n' && matriz[i][l]!='\0'; l++) {
						titulo[k]=matriz[i][l];
						k++;
					}	  
					titulo[k]='\0';
					Insertar_subtema(*Inicio, titulo, subtitulo, ultimo_subtema, *posicion_comas);
				}
			}
		}
	}
}

void Insertar_tema(ptrtema *Inicio, char tema[100]) {
	ptrtema Ultimo=(*Inicio), Nuevo; 
	if(*Inicio==NULL) {
		*Inicio=(ptrtema)malloc(sizeof(tema));
		strcpy((*Inicio)->tema, tema);
		(*Inicio)->Next_tema=NULL;
		(*Inicio)->Next_subtema=NULL;
	} else {
		while(Ultimo->Next_tema!=NULL) {
			Ultimo=Ultimo->Next_tema;
		}
		Nuevo=(ptrtema)malloc(sizeof(ttema));
		Nuevo->Next_tema=NULL;
		Nuevo->Next_subtema=NULL;
		strcpy(Nuevo->tema, tema);
		Ultimo->Next_tema=Nuevo;
	}
}

void Insertar_subtema (ptrtema Inicio, char titulo[100], char subtitulo[100], ptrsubtema *ultimo_subtema, int posicion_comas) {
	ptrtema ultimo_tema=Inicio;
	ptrsubtema Nuevo;
	if(Inicio->Next_tema==NULL) {
		if(Inicio->Next_subtema==NULL) {
			Nuevo=(ptrsubtema)malloc(sizeof(tsubtema));
			strcpy(Nuevo->titulo, titulo);
			if(posicion_comas!=0) {
				strcpy(Nuevo->subtitulo, subtitulo);
			}
			Nuevo->Next_subtema=NULL;
			Inicio->Next_subtema=Nuevo;
			(*ultimo_subtema)=Nuevo;
			Inicio->Next_tema=NULL;
		} else {
			if((*ultimo_subtema)->Next_subtema==NULL) {
			}
			while ((*ultimo_subtema)->Next_subtema!=NULL) {
				(*ultimo_subtema)=(*ultimo_subtema)->Next_subtema;
			}
			Nuevo=(ptrsubtema)malloc(sizeof(tsubtema));
			strcpy(Nuevo->titulo, titulo);
			if(posicion_comas!=0) {
				strcpy(Nuevo->subtitulo, subtitulo);
			}
			Nuevo->Next_subtema=NULL;
			(*ultimo_subtema)->Next_subtema=Nuevo;
		}
	} else {
		while(ultimo_tema->Next_tema!=NULL) {
			ultimo_tema=ultimo_tema->Next_tema;
		}
		if(ultimo_tema->Next_subtema==NULL) {
			Nuevo=(ptrsubtema)malloc(sizeof(tsubtema));
			strcpy(Nuevo->titulo, titulo);
			if(posicion_comas!=0) {
				strcpy(Nuevo->subtitulo, subtitulo);
			}
			Nuevo->Next_subtema=NULL;
			(*ultimo_subtema)=Nuevo;
			ultimo_tema->Next_subtema=Nuevo;
		} else {
			while((*ultimo_subtema)->Next_subtema!=NULL) {
				(*ultimo_subtema)=(*ultimo_subtema)->Next_subtema;
			}
			Nuevo=(ptrsubtema)malloc(sizeof(tsubtema));
			strcpy(Nuevo->titulo, titulo);
			if(posicion_comas!=0) {
				strcpy(Nuevo->subtitulo, subtitulo);
			}
			Nuevo->Next_subtema=NULL;
			(*ultimo_subtema)->Next_subtema=Nuevo;
		}
	}
}

void Destruye(ptrtema Inicio) {
	ptrsubtema Inicio_subtema, ultimo_sub;
	ptrtema ultimo_tema, Destroy;
	if(Inicio->Next_tema==NULL) {
		ultimo_tema=Inicio;
		Inicio_subtema=ultimo_tema->Next_subtema;
		ultimo_sub=Inicio_subtema;
		while(ultimo_tema->Next_subtema!=NULL) {
			ultimo_sub=ultimo_sub->Next_subtema;
			Inicio_subtema->Next_subtema=NULL;
			free(Inicio_subtema);
			ultimo_tema->Next_subtema=ultimo_sub;
			Inicio_subtema=ultimo_sub;
		}
		free(ultimo_tema);
	} else {
		while(Inicio->Next_tema!=NULL) {
			ultimo_tema=Inicio->Next_tema;
			Destroy=ultimo_tema->Next_tema;
			Inicio_subtema=ultimo_tema->Next_subtema;
			ultimo_sub=Inicio_subtema;
			while(ultimo_tema->Next_subtema!=NULL) {
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

void Muestra(ptrtema Inicio, char Nombre_salida[100], int posicion_comas) {
	ptrtema Mostrar=Inicio;
	ptrsubtema ultimo;
	FILE *Archivo;
	Archivo=fopen(Nombre_salida, "wt");
	if(Inicio==NULL) {
		printf("La lista esta vacia\n");
	} else {
		fprintf(Archivo, "\133\n");
		printf("\133\n");
		if((Inicio->Next_tema)==NULL) {
			fprintf(Archivo, "   \133");
			fprintf(Archivo, "\"%s\"\n", Inicio->tema);
			fprintf(Archivo, "],\n");
			printf("   \133");
			printf("\"%s\"\n", Inicio->tema);
			printf("],\n");
		} else {
			fprintf(Archivo, "   \133");
			printf("   \133");
			while(Mostrar->Next_tema!=NULL) {
				fprintf(Archivo, "\"%s\",", Mostrar->tema);
				printf("\"%s\",", Mostrar->tema);
				Mostrar=Mostrar->Next_tema;
			}
			fprintf(Archivo, "\"%s\"", Mostrar->tema);
			fprintf(Archivo, "],\n");
			printf("\"%s\"", Mostrar->tema);
			printf("],\n");
		}
		Mostrar=Inicio;
		fprintf(Archivo, "   \133\n");
		printf("   \133\n");
		while (Mostrar->Next_tema!=NULL) {
			fprintf(Archivo, "      \133");
			printf("      \133");
			ultimo=Mostrar->Next_subtema;
			while(ultimo->Next_subtema!=NULL) {
				if((*ultimo->titulo)!='\n' && (*ultimo->titulo)!=' ' && (*ultimo->titulo)!='\0') {
					fprintf(Archivo, "\"%s\",", ultimo->titulo);
					printf("\"%s\",", ultimo->titulo);
				}
				ultimo=ultimo->Next_subtema;
			}
			if((*ultimo->titulo)!='\n' && (*ultimo->titulo)!=' ' && (*ultimo->titulo)!='\0') {
				fprintf(Archivo, "\"%s\"", ultimo->titulo);
				printf("\"%s\"", ultimo->titulo);
			}
			Mostrar=Mostrar->Next_tema;
			fprintf(Archivo, "]");
			printf("]");
			if(Mostrar->Next_subtema!=NULL){
				fprintf(Archivo, ",\n");
				printf(",\n");
			}
		}
		fprintf(Archivo, "      \133");
		printf("      \133");
		ultimo=Mostrar->Next_subtema;
		while(ultimo->Next_subtema!=NULL) {
			if((*ultimo->titulo)!='\n' && (*ultimo->titulo)!=' ' && (*ultimo->titulo)!='\0') {
				fprintf(Archivo, "\"%s\",", ultimo->titulo);
				printf("\"%s\",", ultimo->titulo);
			}
			ultimo=ultimo->Next_subtema;
		}
		fprintf(Archivo, "\"%s\"", ultimo->titulo);
		fprintf(Archivo, "]\n");
		fprintf(Archivo, "   ]\n");
      	printf("\"%s\"", ultimo->titulo);
		printf("]\n");
		printf("   ]\n");
      	if (posicion_comas!=0) {
			fprintf(Archivo, "   ,\133\n");
			printf("   ,\133\n");
			Mostrar=Inicio;
			while (Mostrar->Next_tema!=NULL) {
				fprintf(Archivo, "      \133");
				printf("      \133");
				ultimo=Mostrar->Next_subtema;
				while(ultimo->Next_subtema!=NULL) {
					if((*ultimo->subtitulo)!='\n' && (*ultimo->subtitulo)!=' ' && (*ultimo->subtitulo)!='\0') {
						fprintf(Archivo, "\"%s\",", ultimo->subtitulo);
						printf("\"%s\",", ultimo->subtitulo);
					}
					ultimo=ultimo->Next_subtema;
				}
				if((*ultimo->subtitulo)!='\n' && (*ultimo->subtitulo)!=' ' && (*ultimo->subtitulo)!='\0') {
					fprintf(Archivo, "\"%s\"", ultimo->subtitulo);
					printf("\"%s\"", ultimo->subtitulo);
				}
				fprintf(Archivo, "]");
				printf("]");
				Mostrar=Mostrar->Next_tema;
				fprintf(Archivo, ",\n");
				printf(",\n");
			}
			ultimo=Mostrar->Next_subtema;
			fprintf(Archivo, "      \133");
			printf("      \133");
			while(ultimo->Next_subtema!=NULL) {
				if((*ultimo->subtitulo)!='\n' && (*ultimo->subtitulo)!=' ' && (*ultimo->subtitulo)!='\0') {
					fprintf(Archivo, "\"%s\",", ultimo->subtitulo);
					printf("\"%s\",", ultimo->subtitulo);
				}
				ultimo=ultimo->Next_subtema;
			}
			if((*ultimo->subtitulo)!='\n' && (*ultimo->subtitulo)!=' ' && (*ultimo->subtitulo)!='\0') {
				fprintf(Archivo, "\"%s\"", ultimo->subtitulo);
				printf("\"%s\"", ultimo->subtitulo);
			}
			fprintf(Archivo, "]\n");
			fprintf(Archivo, "   ]\n");
			printf("]\n");
			printf("   ]\n");
		}
		fprintf(Archivo, "]\n");
		printf("]\n");
	}
	fclose(Archivo);
}

void imprimeLaCadena(ptrtema Inicio) {
	if (Inicio!=NULL){
		puts(Inicio->tema);
    	imprimeLaCadena(Inicio->Next_tema);
	}
}

void imprimeLosSubtemas(ptrsubtema Inicio) {
	if (Inicio!=NULL) {
		puts(Inicio->titulo);
		puts(Inicio->subtitulo);
		imprimeLosSubtemas(Inicio->Next_subtema);
	}
}
