#include "Guardar.h"

void Menu(int *Opcion) {
  printf("El archivo ya existe.\n\n");
  printf("1. Reemplazar \n");
  printf("2. Renombrar \n");
  printf("3. Cancelar.\n\n");
  printf("Opcion --> ");
  scanf("%d",Opcion);
  if(*Opcion==3)
    exit(0);
}

void PresionaEnter() {
  char Nada[20];
  printf("Presiona <Enter> para continuar.");
  gets(Nada);
}

void Limpia() {
  char Nada[20];
  gets(Nada);
}
