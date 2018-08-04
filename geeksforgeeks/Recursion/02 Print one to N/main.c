#include <stdio.h>

void printNumbers(int number,int contador){
	if(contador<=number){
		printf("%d ",contador);
		printNumbers(number,contador+1);
	}
}

int main(){
	int n = 20;
	printNumbers(n,1);
	return 0;
}
