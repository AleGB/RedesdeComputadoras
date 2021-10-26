#include <stdio.h>
#include <time.h>
int main(){
	char resp;
	do{ 
	    unsigned char IP[4];
	   
	    printf("\nIngresa una direccion ip\n");

		scanf("%u.%u.%u.%u",&IP[0],&IP[1],&IP[2],&IP[3]);
	    
		printf("\nClase y mascara de red correspondiente:");

	    if((IP[0]&128)){
	    	if((IP[0]&64)){
	    		if((IP[0]&32)){
	    			if((IP[0]&16)){
	    				printf("\nClase: E\n");
						printf("Mascara de red: none\n");
					}else{
						printf("\nClase: D\n");
						printf("Mascara de red: none\n");
					}	
				}else{
					printf("\nClase: C\n");
					printf("Mascara de red: 255.255.255.0\n");
				}
			}else{
				printf("\nClase: B\n");
				printf("Mascara de red: 255.255.0.0\n");
			}	
		}else{
			printf("\nClase: A\n");
	  		printf("Mascara de red: 255.0.0.0\n ");
		} 
		
		printf("\nDeseas ingresar otra Direccion IP? s/n \n");
		fflush( stdin );
		scanf("%c",&resp);	
	}while(resp!='n');
	return 0;
}
