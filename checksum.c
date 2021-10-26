#include <stdio.h>

unsigned char i; //indice
unsigned char tam; //tamaño de la tramma
int csum; //guarda el valor del checksum

int Checksum(unsigned char trama[], unsigned char tam); //función para obtener checksum
int verifica(unsigned char trama[], unsigned char tam); //función que verifica el checksum

int main(){
	/*tramas a probar*/
	unsigned char trama[] = {0X45, 0X00, 0X01, 0Xe2, 0Xd7, 0Xdb, 0X40, 0X00, 0X80, 0X06, 0X00, 0X00, 0Xc0, 0Xa8, 0X01, 0X43, 0X94, 0Xcc, 0X3a, 0Xdd};
	//unsigned char trama[] = {0X45, 0X00, 0X01, 0X9c, 0Xd7, 0Xde, 0X40, 0X00, 0X80, 0X06, 0X88, 0X9d, 0Xc0, 0Xa8, 0X01, 0X43, 0X94, 0Xcc, 0X3a, 0Xdd};
	//unsigned char trama[] = {0X45, 0X00, 0X01, 0Xe2, 0Xd7, 0Xdb, 0X40, 0X00, 0X80, 0X06, 0X8f, 0Xa5, 0Xc0, 0Xa8, 0X01, 0X43, 0X94, 0Xcc, 0X3a, 0Xdd};

	tam = (sizeof trama / sizeof trama[0]); 

	printf("\nTrama a analizar:\n");
	for(i = 0; i < tam; i++){
		printf("%x ", trama[i]);
	}

	if((trama[10] && trama[11]) == 0){
		printf("\n\nChecksum por default: 0000\n");
		printf("\nChecksum construido: %x\n\n", Checksum(trama, tam));
	}else{
		if(verifica(trama, tam)==1){
			printf("\n\nEl checksum por default %x%x es correcto.\n\n", trama[10], trama[11]);
		}else{
			printf("\n\nEl checksum por default %x%x es incorrecto.\n", trama[10], trama[11]);

			trama[10] = 0X00;
			trama[11] = 0X00;
			printf("\nChecksum correcto: %x\n\n", Checksum(trama, tam));
		}
	}
	return 0;
}

int Checksum(unsigned char trama[], unsigned char tam){
	csum = 0;
	/*Realiza la suma de los datos*/
	for(i = 0; i < tam; i=i+2){
		csum = csum + ((trama[i]<<8)|trama[i+1]);
	}
	/*Realiza el complemento de la suma obtenida*/
	csum = 0XFFFF ^ ((csum & 0XFFFF) + (csum>>16)); 

	return csum; //retorna el valor del checksum
}

int verifica(unsigned char trama[], unsigned char tam){
	csum = 0;
	
	/*Suma los datos del array*/
	for(i = 0; i < tam; i=i+2){
      csum = csum + ((trama[i]<<8)|trama[i+1]);
   	}
	
	/*Realiza el complemento de la suma obtenida*/
	csum = 0XFFFF ^ ((csum & 0XFFFF) + (csum>>16)); 

	/*
	*csum = 0 el checksum es correcto retorna 1
	*csum diferente de 0 el checksum es incorrecto, retorna 0
	*/
	if (csum == 0){
		return 1;
	}else{
		return 0;
	}
}
