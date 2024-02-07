#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// debugging
// src: https://stackoverflow.com/a/1644898
// function debug_print() must take at least TWO arguments
#define DEBUG 0
#define debug_print(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while (0)


//int hayHoja(int*, int, int, int, int, int);
int hayHoja(int[300][300], int, int, int, int);
int buscarHojas(int[300][300], int, int, int, int, int);

int main(){

	int y, x;
	scanf("%d %d", &y, &x);
	getchar();

	int pasto[300][300];

	for( int i = 0; i < y; i++){
		for( int j = 0; j < x; j++){
			char x = getchar();
//			x es 120 y o es 111
			if(x == 'x'){
				debug_print("es x\n", 0);
				pasto[i][j] = -1;
			} else {
				debug_print("es o\n", 0);
				pasto[i][j] = 0;
			}

			getchar();
			//printf("char is %c ", x);
		}
		//printf("\n");
		//getchar();
	}

	//printf("WTFFFF\n");

	for( int i = 0; i < y; i++){
		for( int j = 0; j < x; j++){
			debug_print("%d ", pasto[i][j]);
		}
		debug_print("\n", 0);
		//getchar();
	}

	int numPila = 0;



	for( int i = 0; i < y; i++){
		for( int j = 0; j < x; j++){
			// es x
			if( pasto[i][j] == -1 ){
				debug_print("MASTER hoja (%d, %d)!!\n", j, i);


//	for( int k = 0; i < y; i++){
//		for( int z = 0; j < x; j++){
//			debug_print("%c ", pasto[k][z]);
//		}
//		debug_print("\n");
//		//getchar();
//	}
					
				numPila++;
				pasto[i][j] = numPila;
				debug_print("MASTER hoja (%d, %d) Pila: %d\n", j, i, pasto[i][j] );
				// x es ancho de pasto total
				// y es largo de pasto total
				// j es posicion x de una hoja
				// i es posicion y de una hoja
				//

				
				
				/*
				if( hayHoja(pasto, x, y, j + 1, i) ){
					debug_print("hoja derecha\n", 0);
					pasto[i][j+1] = numPila;
					buscarHojas(pasto, x, y, j+1, i, numPila);
				}
				if( hayHoja(pasto, x, y, j, i + 1) ){
					debug_print("hoja abajo\n", 0);
					pasto[i+1][j] = numPila;
					buscarHojas(pasto, x, y, j, i+1, numPila);
				}
				*/

				buscarHojas(pasto, x, y, j, i, numPila);
				
			}
			//printf("%d ", pasto[i][j]);
		}
		//printf("\n");
		//getchar();
	}

	//Pilas:
	printf("%d\n", numPila);
	//printf("x es %d y o es %d\n", 'x', 'o');

	return 0;
}


int hayHoja(int pasto[300][300], int width, int height, int x, int y){
		debug_print("afojifja %d\n", pasto[y][x]);
		debug_print("width is %d\n", width);
		debug_print("height is %d\n", height);
	if( x < width && x >= 0 && y < height && y >= 0){
		debug_print("IIIIIafojifja %d\n", pasto[y][x]);
		if (pasto[y][x] == -1){
			return 1;
		} else{
			return 0;
		}
	}
	return 0;
}

// solo puede escanear a su derecha o abajo
// cada vez que encuentre una hoja adyacnete derecha o abajo
// debera modificar el valor a su numPila
int buscarHojas(int pasto[300][300], int width, int height, int x, int y, int numPila){
	// sabemos que x, y ya es hoja
	
	debug_print("@(%d, %d)\n", x, y);

	for( int i = 0; i < y; i++){
		for( int j = 0; j < x; j++){
			debug_print("%d ", pasto[i][j]);
		}
		debug_print("\n", 0);
		//getchar();
	}

	
	int derecha = hayHoja(pasto, width, height, x+1, y);
	int abajo = hayHoja(pasto, width, height, x, y+1);
	
	if( derecha ){
		pasto[y][x+1] = numPila;
		buscarHojas(pasto, width, height, x+1, y, numPila);
	}
	if( abajo ){
		pasto[y+1][x] = numPila;
		buscarHojas(pasto, width, height, x, y+1, numPila);
	}

	if( abajo == derecha && abajo == 0 ){
		return 0;
	}

	return 0;

}
