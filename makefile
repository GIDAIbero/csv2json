SHELL := /bin/bash
default: main.o validacion.o leer2.o Insertar.o abrearchivo.o Guardar.o
	gcc main.o validacion.o leer2.o Insertar.o abrearchivo.o Guardar.o -o CSV2JSON

main.o: main.c
	gcc main.c -c

validacion.o: validacion.c
	gcc validacion.c -c

leer2.o: leer2.c
	gcc leer2.c -c

Insertar.o: Insertar.c
	gcc Insertar.c -c

abrearchivo.o: abrearchivo.c
	gcc abrearchivo.c -c

Guardar.o: Guardar.c
	gcc Guardar.c -c
.PHONY: cleantemp
cleantemp:
	rm *.*~
.PHONY: clean
clean:
	bash scripts/clean.sh
