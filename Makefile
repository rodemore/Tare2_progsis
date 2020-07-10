DEPS = funciones.h

wc: main.o funciones.o
	gcc -o wc main.o  funciones.o $(DFLAGS)

main.o: main.c  $(DEPS)
	gcc -c main.c $(DFLAGS)

funciones.o: funciones.c $(DEPS)
	gcc -c funciones.c $(DFLAGS)


# Compila usando la opción -g para facilitar la depuración con gdb.
.PHONY: debug
debug: DFLAGS = -g
debug: clean wc

# Compila habilitando la herramienta AddressSanitizer para
# facilitar la depuración en tiempo de ejecución.
.PHONY: sanitize
sanitize: DFLAGS = -fsanitize=address,undefined
sanitize: clean wc

.PHONY: clean
clean:
	rm -rf wc *.o

.PHONY: run
run: wc
	./wc hola mundo
