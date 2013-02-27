/* MODULO VALIDACION */
int validacion(int argc, char *argv[], char Nombre_entrada[100], char Nombre_salida[100]);
/* 
FUNCION ENCARGADA DE QUE LOS ARGUMENTOS DE ENTRADA DE MAIN ESTEN CORRECTOS
Regresa los valores:
0 ERROR.
1 MENU.
2 -i (ENTRADA) -o (SALIDA)
3 -i (ENTRADA) -o (SALIDA) -ow
*/

/* MODULO ENTRADA/SALIDA */
void Entrada_Salida(char *argv[], char *Entrada, char *Salida);
/* Funcion encargada de validar de que la extension de los archivos sean 
correctos. */
