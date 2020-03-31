#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *PrimeNum(void *args){
	int i,check;
	printf("Prime number from 2 to 1000000: ");
	for (i = 2; i <= 1000000; i++){
		check = 0;
		for (int j = 1 ; j < i; j++){
			if (i % j == 0 ) check++;
			if (check == 2) break;
		}
		if (check ==1) printf("%d ",i);
	}
}

void *FiboNum(void *args){
	int fibo1 = 1, fibo2 = 1, fibo3 = 0;
	printf("\nFibonaci number from 2 to 1000000: ");
	while (fibo3 <= 1000000){
		fibo3 = fibo1 + fibo2;
		fibo1 = fibo2;
		fibo2 = fibo3;
		printf("%d ",fibo3);
	}
}

int main(){
	pthread_t t1;
	pthread_t t2;
	pthread_create(&t1, NULL, PrimeNum, NULL);
	pthread_create(&t2, NULL, FiboNum, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
	
