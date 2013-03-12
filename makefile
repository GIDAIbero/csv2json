SHELL := /bin/bash
default: main.o validacion.o leer2.o Insertar.o abrearchivo.o Guardar.o
	gcc main.o validacion.o leer2.o Insertar.o abrearchivo.o Guardar.o -o CSV2JSON

main.o: main.c
	gcc -Wall main.c -c

validacion.o: validacion.c
	gcc -Wall validacion.c -c

leer2.o: leer2.c
	gcc -Wall leer2.c -c

Insertar.o: Insertar.c
	gcc -Wall Insertar.c -c

abrearchivo.o: abrearchivo.c
	gcc -Wall abrearchivo.c -c

Guardar.o: Guardar.c
	gcc -Wall Guardar.c -c
.PHONY: cleantemp
cleantemp:
	rm *.*~
.PHONY: clean
clean:
	bash scripts/clean.sh
