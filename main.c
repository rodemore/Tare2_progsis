#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <getopt.h>

#include "funciones.h"

bool lflag = false; //Opción -l, contar lineas
bool mflag = false; //Opción -m, contar caracteres
bool wflag = false; // opcion -w, contar palabras


int main(int argc, char **argv){
	int opt, index;
	FILE *fptr;
	/* Este lazo recorre los argumentos buscando las
	opciones -e y -h... */
	while ((opt = getopt (argc, argv, "hlwm")) != -1){
		switch(opt)
		{
			case 'l':
				printf("contar lineas\n");
				lflag = true;
				break;
			case 'w':
				printf("contar palabras\n");
				wflag = true;
				break;
			case 'm':
				printf("contar caracteres\n");
				mflag = true;
				break;
			case 'h':
				print_help(argv[0]);
				return 0;
			case '?':
			default:
				fprintf(stderr, "uso: %s [-i] [-e] [arg 1] [arg 2] ... [arg n]\n", argv[0]);
				fprintf(stderr, "     %s -h\n", argv[0]);
				return -1;
		}
	}

	/* Aquí imprime argumentos que no son opción */
	for (index = optind; index < argc; index++) {
		printf("Abriendo %s...\n", argv[index]);
		fptr = fopen(argv[index], "r");

		if(fptr == NULL) {
			fprintf(stderr, "Error al intentar abrir %s\n", argv[index]);
			return 1;
		}
		else{
			if (lflag){
				int lines = contar_lineas(fptr);
				printf("%i ", lines);	
				
			}
			if (wflag){
				rewind(fptr);
				int words = contar_palabras(fptr);
				printf("%i ", words);	
			}
			if (wflag){
				rewind(fptr);
				int characters = contar_caracteres(fptr);
				printf("%i ", characters);	
			}
			printf("%s\n", argv[index]);
				
		}
	}

	if(argc == 1)
		print_help(argv[0]);
	}