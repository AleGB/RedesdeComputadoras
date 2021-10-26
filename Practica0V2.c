#include <stdio.h>
 
int main(){
	char resp;
	do{ 
	    unsigned char IP[4];
	    char cadena[15];
	    printf("\nIngresa una direccion ip\n");

		scanf("%i.%i.%i.%i",&IP[0],&IP[1],&IP[2],&IP[3]);
	    
	    if((IP[0]&128)==0){
	    	printf("\nClase: A\n");
	  		printf("Mascara de red: 255.0.0.0\n ");
		}else if((IP[0]&192)==128){
			printf("\nClase: B\n");
			printf("Mascara de red: 255.255.0.0\n");
		}else if((IP[0]&224)==192){
			printf("\nClase: C\n");
			printf("Mascara de red: 255.255.255.0\n");
		}else if((IP[0]&240)==224){
			printf("\nClase: D\n");
			printf("Mascara de red: none\n");
		}else if((IP[0]&240)==240){
			printf("\nClase: E\n");
			printf("Mascara de red: none\n");
		}
		
		printf("\nDeseas ingresar otra Direccion IP? s/n \n");
		fflush( stdin );
		scanf("%c",&resp);	
	}while(resp!='n');
	return 0;
}
/*10000000
01111111
00000000

11000000
10111111
10000000

11100000
11011111
11000000

11110000
11101111
11100000

11110000
11111111
11110000*/
