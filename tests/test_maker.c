#include <stdio.h>
#include <stdlib.h>


int main(){
	FILE *f = fopen("test1.txt", "w");
	if (f == NULL){
	    printf("Error opening file!\n");
	}

	fprintf(f,"lslslsls\alslsls");
}
