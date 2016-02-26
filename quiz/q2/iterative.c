#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#define LOOP 20


static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec - t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}


char smallest_character(char str[], char c){
    int index=0;

    while(str[index] !='\0'){
    	if(str[index] > c)
    	   return str[index];
    	
    	index++	;
    }
    return str[0];
     
}



int main()
{
  char character[]="abcdefghijklmnopqrstuvwxyz";

  char input_character[]="rjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkho";

  struct timespec start, end;
    double cpu_time;
    clock_gettime(CLOCK_REALTIME, &start);
    for (int j = 0; j < LOOP; j++) {
        for(int i=0;i<sizeof(input_character);i++)
        	smallest_character(character,input_character[i]);
      }
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = (double) diff_in_second(start, end) / LOOP;

    FILE *fp;
    fp = fopen("time.dat", "a");
    assert(fp);

    fprintf(fp, "method\ttime\n");
    fprintf(fp, "iterative\t%.9lf\n", cpu_time);

    fclose(fp);

    printf("execution time : %lf sec\n", cpu_time);

    return 0;
}