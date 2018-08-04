#include <stdio.h>

void printNumbers(int number,int contador){
	if(contador<=number){
		printf("%d ",contador);
		contador++;
		printNumbers(number,contador);
	}
}

int main(){
	int n = 20;
	printNumbers(n,1);
	return 0;
}
