#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ISBN{
	int prefijo_internacional;
	int grupo_registro;
	int prefijo_editor;
	int identificador_titulo;
	int digito_control;
};

void carga_ISBN(FILE *archivo);

main(){
	
	FILE *datos = fopen("VentaLibros.txt", "a+");
	
	
}
