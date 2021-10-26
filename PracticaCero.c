#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	char resp;

	do{
		char dirIP[15] = ""; //declaracion de la cadena para la IP
    	char aux[3] = "";
    	int i = 0;
    	int pByte = 0;
    	clock_t tiempo_inicio, tiempo_final;
		double segundos;
		
    	printf("Ingresa tu Direccion IP\n");
    	scanf("%s", dirIP); //lee la cadena con la IP que ingresa el usuario
    
    	tiempo_inicio = clock();
		//recorremos la cadena hasta encontrar el caracter '.' y extraer el Byte en decimal
  		while(dirIP[i] != '.'){
  			aux[i] = dirIP[i];//variable auxiliar para extraer la cadena del primer Byte
  			i++;
		}
		
  		printf("\nClase y mascara de red correspondiente:\n");
  		pByte = atoi(aux);//conversion de string a entero para manejar el Byte como decimal
  		
		//conjunto de ifs para clasificar la IP y mostrar su mascara segun el rango al que corresponde  	
  		if(pByte >= 0 && pByte <= 127){
  			printf("Clase: A\n");
  			printf("Mascara de red: 255.0.0.0\n ");
		} else if(pByte >= 128 && pByte <= 191){
			printf("Clase: B\n");
			printf("Mascara de red: 255.255.0.0\n");			
		} else if(pByte >= 192 && pByte <= 223){
			printf("Clase: C\n");
			printf("Mascara de red: 255.255.255.0\n");
		} else if(pByte >= 224 && pByte <= 239){
			printf("Clase: D\n");
			printf("Mascara de red: none\n");
		}else if(pByte >= 240 && pByte <= 255){
			printf("Clase: E\n");
			printf("Mascara de red: none\n");
		}
		tiempo_final = clock();

		segundos = (double)(tiempo_final - tiempo_inicio)*1000/ CLOCKS_PER_SEC;
  		printf("Tiempo de respuesta: %.16g milisegundos\n", segundos);
  		
		printf("\nDeseas ingresar otra Direccion IP? s/n \n");
		fflush( stdin );
		scanf("%c",&resp);
		
	}while(resp!='n');
	
}
