#include <stdio.h>
#include <math.h>

#define TAM_MATRIX 30
#define BORDA 1

void pause(){
	getchar();
	getchar();
}

void imprimeMatrix(int matrix[TAM_MATRIX][TAM_MATRIX]){
	int i , j;

	for(i=0 ; i<TAM_MATRIX ; i++){
		for(j=0 ; j<TAM_MATRIX ; j++){
			if(matrix[i][j]== 1){
				printf(".");
			}else{
				printf(" ");
			}			
		}
		printf("\n");
	}	
}

void algoritmo_dda(int matrix[TAM_MATRIX][TAM_MATRIX], int x1, int y1, int x2, int y2){
	
	int abs_x = x2-x1;
	abs_x = abs(abs_x); //pega o valor abs do delta x

	int abs_y = y2-y1;
	abs_y = abs(abs_y); //pega o valor abs do delta y

	double incremento=0, totalIncrementos=0;

	int x , y;

	if(abs_x > abs_y){
		incremento = (double) (y2-y1) / (x2-x1);
		y = y1;

		printf("INCREMETO = %f\n", incremento);

		for(x=x1 ; x<=x2 ; x++){
			matrix[x][y] = BORDA;
			totalIncrementos = totalIncrementos + incremento;
			y = round(totalIncrementos);
		}
	}else{

		incremento = (double) (x2-x1) / (y2-y1);
		x = x1;
		//printf("INCREMETO = %f\n", incremento);

		for(y=y1 ; y<=y2 ; y++){
			matrix[x][y] = BORDA;
			totalIncrementos = totalIncrementos + incremento;
			x = round(totalIncrementos);
		}
	}

}

int main(){
	
	while(1){
		int matrix[TAM_MATRIX][TAM_MATRIX]={0}, x1,y1,x2,y2;
	
		printf("\tAlgoritmo DDA\n\nOBS: tamanho da matrix %dx%d\n\n",TAM_MATRIX,TAM_MATRIX);
	
		printf("Informe o valor de x1 e y1.\n>> ");
		scanf("%d %d",&x1,&y1);
		printf("Informe o valor de x2 e y2.\n>> ");
		scanf("%d %d",&x2,&y2);
		printf("\n");
	
		algoritmo_dda(matrix,x1,y1,x2,y2);
		imprimeMatrix(matrix);
	
		pause();
		system("cls");
	}
	
	return 0;
}
