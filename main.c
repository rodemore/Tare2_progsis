#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <getopt.h>

#include "funciones.h"

bool lflag = false; //Opción -l, contar lineas
bool mflag = false; //Opción -m, contar caracteres
bool wflag = false; // opcion -w, contar palabras
int files_n = 0;

int total_lines = 0;
int total_words = 0;
int total_characters = 0;

int main(int argc, char **argv){
	int opt, index;
	FILE *fptr;
	/* Este lazo recorre los argumentos buscando las
	opciones -e y -h... */
	while ((opt = getopt (argc, argv, "hlwm")) != -1){
		switch(opt)
		{
			case 'l':
				lflag = true;
				break;
			case 'w':
				wflag = true;
				break;
			case 'm':
				mflag = true;
				break;
			case 'h':
				print_help(argv[0]);
				return 0;
			case '?':
			default:
				fprintf(stderr, "uso:\n %s [-l] [-w] [-m] [-h] [arg 1] [arg 2] ... [arg n]\n", argv[0]);
				fprintf(stderr, "     %s -h\n", argv[0]);
				return -1;
		}
	}

	/* Aquí imprime argumentos que no son opción */
	for (index = optind; index < argc; index++) {
		fptr = fopen(argv[index], "r");
		
		if(fptr == NULL) {
			fprintf(stderr, "Error al intentar abrir %s\n", argv[index]);
			return 1;
		}
		
		else{
			files_n++;
			if (lflag){
				int lines = contar_lineas(fptr);
				printf("%i ", lines);
				total_lines += lines;	
				
			}
			if (wflag){
				rewind(fptr);
				int words = contar_palabras(fptr);
				printf("%i ", words);	
				total_words += words;
			}
			if (mflag){
				rewind(fptr);
				int characters = contar_caracteres(fptr);
				printf("%i ", characters);	
				total_characters += characters;
			}
			printf("%s\n", argv[index]);
			fclose(fptr);
		}
	}

	if (files_n>1) {
		if (total_lines>0){
			printf("%i ", total_lines);	
		}
		if (total_words>0){
			printf("%i ", total_words);	
		}
		if (total_characters>0){
			printf("%i ", total_characters);	
		}
		printf("total\n");
	}

	if(argc == 1)
		print_help(argv[0]);
	}


