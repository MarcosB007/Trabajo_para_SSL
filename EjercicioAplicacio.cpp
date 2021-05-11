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

void carga_ISBN(FILE *archivo, ISBN isbn);
void mostrar(FILE *archivo, ISBN isbn);

main(){
	ISBN isbn;
	FILE *datos = fopen("VentaLibros.dat", "a+b");
	
	carga_ISBN(datos, isbn);
	mostrar(datos, isbn);
	
	system("pause");
	
	fclose(datos);
}

void carga_ISBN(FILE *archivo, ISBN isbn){
	int contador = 0;
	bool bandera = 0;
	do{
		printf("Ingrese el prefijo internacional (3 digitos): ");
		scanf("%d", &isbn.prefijo_internacional);
		contador += isbn.prefijo_internacional;
		if(isbn.prefijo_internacional == 978 || isbn.prefijo_internacional == 979){
			printf("Ingrese el identificador de grupo (1 a 5 digitos): ");
			scanf("%d", &isbn.grupo_registro);
			contador += isbn.grupo_registro;
			if(isbn.grupo_registro >= 0 && isbn.grupo_registro < 100000){
				printf("Ingrese el prefijo de editor (1 a 7 digitos)");
				scanf("%d", &isbn.prefijo_editor);
				contador += isbn.prefijo_editor;
				if(isbn.prefijo_editor >= 0 && isbn.prefijo_editor < 10000000 && contador > 0){
					printf("Ingrese el identificador de titulo (1 a 6 digitos)");
					scanf("%d", &isbn.identificador_titulo);
					contador += isbn.identificador_titulo;
					if(isbn.identificador_titulo >= 0 && isbn.identificador_titulo < 1000000 ){
						printf("Ingrese el digito de control (1 digito)");
						scanf("%d", &isbn.digito_control);
						contador += isbn.digito_control;
						if(isbn.digito_control >= 0 && isbn.digito_control < 10){
							if(contador > 999999999999 && contador < 10000000000000){
								
								fwrite(&isbn, sizeof(isbn), 1, archivo);
							}else{
								printf("ISBN no valido. Vuelva a intentar");
								bandera =1;
							}
									
						}
					}else bandera =1;
				}else bandera =1;
			}else bandera =1;
		}else bandera =1;
		
	}while(bandera == 1);
	
}

void mostrar(FILE *archivo, ISBN isbn){
    printf("ISBN: %d-%d-%d-%d-%d", isbn.prefijo_internacional, isbn.grupo_registro, isbn.prefijo_editor,
									isbn.identificador_titulo, isbn.digito_control);
	
}










