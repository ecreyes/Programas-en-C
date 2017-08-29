#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[])
 {
	int i; 
	printf("\nArgumentos de la línea de órdenes\n\n"); 
	for(i=0; i<argc; i++){
		printf("El argumento %d es %s\n", i, argv[i]); 
	}
	sleep(7);
	printf("\n\nTerminación normal del programa.\n"); 

  return 0;
 }
