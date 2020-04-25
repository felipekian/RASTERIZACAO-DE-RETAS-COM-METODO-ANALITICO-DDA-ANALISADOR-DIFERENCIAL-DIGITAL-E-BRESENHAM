# RASTERIZACAO DE RETAS COM MÉTODO ANALÍTICO,DDA (ANALISADOR DIFERENCIAL DIGITAL) E BRESENHAM

## ALGORITMO MÉTODO ANALÍTICO

O algoritmo método analítico é um algoritmo usado para rasterização de semirretas onde dados dois pontos p1(x1,y1) e p2(x2,y2), ele rasteriza na escolha dos melhores pixel usado para isso como base a equação da reta que é dada por y=mx+b . onde m=(y2-y1)/(x2-x1), ou seja m=(delta_y/delta_x) e b=y1-mx1. Sabendo-se disso, basta substituir na fórmula da equação da reta para termos os pontos.

### PONTOS FORTES DO MÉTODO ANALÍTICO

O método analítico é um excelente algoritmo para rasterizar semirretas que fiquem no primeiro octante que vai de 0° a 45°. Pois para retas com inclinação abaixo de 45° fica muito satisfatório por exemplo os pontos p1(0,0) e p2(5,2) onde a reta não tem muita inclinação.

### PONTOS FRACOS DO MÉTODO ANALÍTICO

O método analítico quando utilizado para retas com mais de 45°, ou seja segundo octante, começa a ter falhas na reta ficando impraticável o uso do algoritmo, como no caso de teste usando os pontos p1(0,0) e p2(2,5), onde a reta tem muita inclinação e acontece falhas por conta dos arredondamentos de ponto flutuante.

### DESEMPENHO DO ALGORITMO MÉTODO ANALÍTICO

O algoritmo é pouco eficiente, pois usa muito ponto flutuante e arredondamentos que são operações complexas e custosas para o computador processar. Para desenhar uma reta pode ser uma boa opção, mas quando precisamos rasterizar centenas de linhas passa não ser interessante visto que em certos cenários existem centenas de linhas.

### PSEUDO CÓDIGO

```
Função metodoAnalitico recebe os pontos x1,y1,x2,y2:
  se x1 for igual a x2 faça
    para y de y1 ate y2
    setPixel(x1,y, cor)
  senão
    m = delta y / delta x
    b = y2-m*x2
    para x de x1 ate x2
      y = m*x+b
      setPixel(x,y,cor)
```


### CÓDIGO EM LINGUAGEM C
```
void metodoAnalitico(int matrix[TAM_MATRIX][TAM_MATRIX], int x1, int y1, int x2, int y2){
  int y;
  if(x1==x2){
    for(y=y1 ; y<=y2; y++)
    matrix[x1][y] = BORDA;
  }else{
    double m = (double) (y2-y1) / (x2-x1);
    double b = (double) y2-m*x2;
    int x;
    for(x=x1 ; x<=x2 ; x++){
      double k = (double) m*x+b;
      y = round(k);
      matrix[x][y] = BORDA;
    }
  }
}
```

