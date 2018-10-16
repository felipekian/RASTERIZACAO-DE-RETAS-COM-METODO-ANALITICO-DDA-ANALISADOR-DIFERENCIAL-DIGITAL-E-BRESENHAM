#include <stdio.h>

#define BORDA 1
#define TAM_MATRIX 30

void pause(){
	getchar();
}


void bresenham_line(int matrix[TAM_MATRIX][TAM_MATRIX], int x0,int y0, int x1, int y1){

	int delta_x = abs(x0-x1);
	int delta_y = abs(y0-y1);
	
	int parametro = 2*delta_y-delta_x;
	int parametro2 = 2*delta_y;
	int xy2 = 2*(delta_y-delta_x);
	int xf,x,y;

	if(x0 > x1){
		x = x1;
		y = y1;
		xf = x0;

		matrix[x][y] = BORDA;
	
	
	}else{
		x = x0;
		y = y0;
		xf = x1;

		matrix[x][y] = BORDA;

	}


	while(x < xf){
			x = x+1;

			if(parametro < 0){
				parametro = parametro + parametro2;
			
			}else{
				y = y+1;
				parametro = parametro + xy2;

			}

			matrix[x][y] = BORDA;	
			
		}

}

void imprimeMatrix(int matrix[TAM_MATRIX][TAM_MATRIX]){
	int i,j;
	for(i=0 ; i<TAM_MATRIX ; i++){
		for(j=0 ; j<TAM_MATRIX ; j++){
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
	pause();
}

int main(){

	int matrix[TAM_MATRIX][TAM_MATRIX]={0}, x1, y1, x2, y2;

	printf("\t\tAlgoritmo Bresenham semiretas\nOBS: tamanho da matrix %dx%d\n\n",TAM_MATRIX,TAM_MATRIX);
	printf("Informe o valor de x1 e y1:\n>> ");
	scanf("%d %d", &x1,&y1);
	printf("Informe o valor de x2 e y2:\n>> ");
	scanf("%d %d", &x2,&y2);

	bresenham_line(matrix, x1,y1,x2,y2);
	imprimeMatrix (matrix);

	return 0;
}
