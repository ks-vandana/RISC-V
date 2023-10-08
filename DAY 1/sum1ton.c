#include <stdio.h>

int main(){
	int i;
	int sum=0;
	int n=5;
	for(i=0;i<=n;++i){
		sum += i;
	}
	printf("sum of numbers from 1 to %d is %d \n",n,sum);
	return 0;
}