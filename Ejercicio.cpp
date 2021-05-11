#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char cadena[15];
void carga_ISBN(FILE *archivo);
bool valida_ISBN(cadena isbn);

main(){

	FILE *datos = fopen("VentaLibros.dat", "a+b");
	carga_ISBN(datos);
}

void carga_ISBN(FILE *archivo){
	cadena isbn;
	bool bandera = 0;
	do{
		printf("Ingrese el ISBN: ");
		_flushall();
		gets(isbn);

		if(strlen(isbn) == 13 ){
			if(valida_ISBN(isbn) ){
				printf("ISBN valido.");
				fwrite(&isbn, sizeof(isbn), 1, archivo);
				bandera = 1;
			}	
		}else{
			printf("ISBN ingresado no valido. Vuelva a intentar.\n");
		}
		
	}while(bandera == 0);
}

bool valida_ISBN(cadena isbn){

		if(isbn[0] == '9'){
			if(isbn[1] == '7'){
				if(isbn[2] == '8' || isbn[2] == '9'){
					return true;
				}
			}
		}
		else{
			return false;
		}
}






