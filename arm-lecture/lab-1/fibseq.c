#include <stdio.h>

extern int fib(int x)
{
	if (x==0)
		return 0 ;
	if (x==1)
		return 1 ;

       return fib(x-1)+fib(x-2);   
}



int main(){
 
    int input, i;
 
    while(1){
 
        printf("The 0th number is 0, and the first number is 1\n");
        printf("ex : 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233 ...\n\n");
        printf("Please input an integer to show the last value of Fibonacci Sequence :\n");
        scanf("%d", &input);
        printf("\n");
 
        if(input<0)
            printf("\nInput cannot less than 0\n\n");

 
        else{
            for(i=0; i<=input; i++)
                printf("%d  ", fib(i));
        }
 
        printf("\n\n");
 
        system("PAUSE");
        
 
    }
 
    return 0;
 
}
