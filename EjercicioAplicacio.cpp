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

void carga_ISBN(FILE *archivo, ISBN isbn){
	int contador = 13;
	printf("Ingrese el prefijo internacional (3 digitos): ");
	scanf("%d", isbn.prefijo_internacional);
	contador-=isbn.prefijo_internacional;
	if(isbn.prefijo_internacional == 978 || isbn.prefijo_internacional == 979){
		printf("Ingrese el identificador de grupo (1 a 5 digitos, %d digitos restantes): ", contador);
		scanf("%d", isbn.grupo_registro);
		contador-=isbn.grupo_registro;
		if(isbn.grupo_registro > 0 && isbn.grupo_registro < 6){
			printf("Ingrese el prefijo de editor (1 a 7 digitos, %d digitos restantes)", contador);
		}
	}
	
}





