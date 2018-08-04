#include <stdio.h>

void reverseDigits(int number){
	printf("%d",number%10);
	number = number/10;
	if(number>0){
		reverseDigits(number);
	}
}

int main(){
	int n = 102;
	reverseDigits(n);
	return 0;
}
