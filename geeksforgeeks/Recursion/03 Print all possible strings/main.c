#include <stdio.h>
#include <string.h>

/**
 * str: string entrada
 * buff:almacenamiento de palabra separada
 * i: posicion string
 * j:posicion buffer
 * n: largo string entrada
 */
void printString(char str[],char buff[],int i,int j,int n){
	//si termino de recorrer el string, cierro el buffer
	if(i==n){
		buff[j]='\0';
		printf("%s\n",buff);
		return;
	}
	buff[j] = str[i];
	printString(str,buff,i+1,j+1,n); //13-19 copia cada char en el buffer
	//añade un espacio en la posicion donde estaba la letra antes.
	buff[j] = ' ';
	//la letra remplazada por el espacio se agrega adelante.
	buff[j+1] = str[i];
	printString(str,buff,i+1,j+2,n);	
}

int main(){
	// string entrada
	char *str = "ABCD";
	//largo del string
	int n = strlen(str);
	//N caracteres + N-1 espacios + \0 = tamaño arreglo 2n
	char buff[2*n];
	buff[0] = str[0];
	printString(str,buff,1,1,n);
	return 0;
}
