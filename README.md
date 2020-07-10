[![Run on Repl.it](https://repl.it/badge/github/progsis-espol/progsis-c-plantilla)](https://repl.it/github/progsis-espol/progsis-c-plantilla)
# Implementanción de wc en c

## Descripción
Este programa contiene código ejemplo de uso de lo siguiente:
* Documentación de un repositorio usando *README.md*
* Uso de un *Makefile* para compilar varios archivos
* Uso de *.gitignore*
* Parsing de opciones y argumentos usando *getopt*
* Uso de *fscan*

## Uso del programa
El programa tiene el siguiente funcionamiento:
```
$ ./wc -h
 ./wc [-i] [-e] [arg 1] [arg 2] ... [arg n]
 ./wc -h
Opciones:
 -h			Ayuda, muestra este mensaje
 -l			Muestra conteo de líneas
 -w			Muestra conteo de palabras
 -m			Muestra conteo de caracteres

```

Ejemplos de ejecución:
Ejemplo usando todos el parámetro -w para contar palabras
```
$ ./wc -w hola.txt
6 hola.txt
```
Otro ejemplo de ejecución, usando -l para contar las líneas:
```
./wc -l hola.txt
6 hola.txt

```
Otro ejemplo de ejecución, usando el parámetro l,m, w  para más de un archivo:
```
./wc -lmw hola.txt foo.txt
2 6 43 hola.txt
4 15 72 foo.txt
6 21 115 total

```

## Ejemplos de código en el programa
El archivo [input.h](input.h) muestra un ejemplo de documentación de una función:
```
int contar_palabras(FILE *archivo){
	int nw = -1;
	char texto[MAXWORD];
	while (fscanf(archivo, "%s", texto)==1){
		nw +=1;
	}
	if (nw == -1){
		return nw;
	}
	return nw+=1;
}
```
## Compilación
Para compilar el programa:
```
$ make
```
Para compilar facilitando la depuración con gdb:
```
$ make debug
```
Para compilar habilitando la herramienta AddressSanitizer, facilita la depuración en tiempo de ejecución:
```
$ make sanitize
```
