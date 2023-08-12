#include<stdio.h>
#include<stdlib.h>  
#include<time.h>
#include<conio.h>

void llenar_matriz(char matriz[10][10]);
void colocar_o(char matriz[10][10]);
void mostrar_matriz(char matriz[10][10]);
void juego_matriz(char matriz[10][10]);
int verificar_o(char matriz[10][10]);
int main(){
    srand(time(NULL));
    char matriz[10][10];
    int i;
    int j;
    llenar_matriz(matriz);
    colocar_o(matriz);
    matriz[0][0] = '*';
    mostrar_matriz(matriz);
    juego_matriz(matriz);
    system("pause");
    return 0;
}
int verificar_o(char matriz[10][10]){
    int i;
    int j;
    int bandera = 0;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if(matriz[i][j] == 'O'){
                bandera++;
               }
            }
        }
        if(bandera == 0){
            return 1;
        }else{
            return 0;
        }
    }


void llenar_matriz(char matriz[10][10]){
    int i;
    int j;
    for(i = 0;i < 10; i++ ){
        for (j = 0; j < 10; j++){
            matriz[i][j] = 32;
        }
    }
}
void colocar_o(char matriz[10][10]){
      srand(time(NULL));
    int fila ;
    int columna ;
    int i;
    int j;
for(i = 0; i < 5; i++){
    fila = rand()%9 + 1;
    columna = rand()%9 + 1;
matriz[fila][columna] = 'O';
}
}

void mostrar_matriz(char matriz[10][10]){
    system("cls");
 int i;
 int j;
    for(i = 0;i < 10; i++ ){
        for (j = 0; j < 10; j++){
            printf("[%c]",matriz[i][j]);
        }
        printf("\n");
    }
}

void juego_matriz(char matriz[10][10]){
    char caracter;
    int i;
    int j;
    int wherefila = 0;
    int wherecolumna = 0;

    while(caracter = getch()){ 
// movimiento izquierda
if (caracter == 'a' || caracter == 'A'){
    for(i = 0;i < 10; i++ ){
        for (j = 0; j < 10; j++){
            if(matriz[i][j] == '*'){
                wherefila = i;
                wherecolumna = j;
                matriz[i][j] = 32;
                break;
            }
        }
    }
    if(wherecolumna == 0){
        matriz[wherefila][wherecolumna] = '*';
    }else{
    matriz[wherefila][wherecolumna - 1] = '*';
        }
    }
// movimiento derecha
    if (caracter == 'd' || caracter == 'D'){
    for(i = 0;i < 10; i++ ){
        for (j = 0; j < 10; j++){
            if(matriz[i][j] == '*'){
                wherefila = i;
                wherecolumna = j;
                matriz[i][j] = 32;
                break;
            }
        }
    }
    if(wherecolumna == 9){
        matriz[wherefila][wherecolumna] = '*';
    }else{ 
        matriz[wherefila][wherecolumna + 1] = '*';
    }
    
        }
    // movimiento arriba 
if (caracter == 'w' || caracter == 'W'){
    for(i = 0;i < 10; i++ ){
        for (j = 0; j < 10; j++){
            if(matriz[i][j] == '*'){
                wherefila = i;
                wherecolumna = j;
                matriz[i][j] = 32;
                break;
            }
        }
    }
    if(wherefila == 0){
        matriz[wherefila][wherecolumna] = '*';
    }else{
        matriz[wherefila - 1][wherecolumna] = '*';
    }
        }
        // movimiento abajo
        if (caracter == 's' || caracter == 'S'){
    for(i = 0;i < 10; i++ ){
        for (j = 0; j < 10; j++){
            if(matriz[i][j] == '*'){
                wherefila = i;
                wherecolumna = j;
                matriz[i][j] = 32;
                break;
            }
        }
    }
    if(wherefila == 9){
        matriz[wherefila][wherecolumna] = '*';
    }else{
        matriz[wherefila + 1][wherecolumna] = '*';
    }
        

}
    mostrar_matriz(matriz);
    int bandera;
    bandera = verificar_o(matriz);
    if (bandera == 1){
    printf("\n \n \t \t GANASTE MI LOCO!!!\n\n");
        break;
    }
}
}