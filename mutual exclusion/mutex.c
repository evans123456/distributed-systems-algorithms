//p15/36969/2016

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>




#define K        5  // number to loop
#define SLEEP    1000000  // max. length of random sleep, 1000000 = 1 s

volatile int inCS = 0, flag1 = 0, flag2 = 0;




void *process1(void* arg) {
  int i;
  for (i=0; i<K; i++) {

    // not the critical section
    random_sleep();
    
    // wait section
    printf("1: Wait (%d)\n", i);
    while (flag2 == 1) {  }
    random_sleep();
    flag1 = 1;
    
    // critical section    
    inCS++;
    printf("1: Critical Section (%d)\n", i);
    if (inCS > 1) printf("Mutual exclusion violated!\n");
    random_sleep();
    inCS--;
    
    // exit section
    flag1 = 0;
  }
  pthread_exit(NULL);  
}



void *process2(void* arg) {
  int i;
  for (i=0; i<K; i++) {

    // not the critical section section
    random_sleep();
    
    // wait 
    printf("\t\t2: Wait (%d)\n", i);
    while (flag1 == 1)  { }
    random_sleep();
    flag2 = 1;    
    
    // critical section
    inCS++;
    printf("\t\t2: Critical Section (%d)\n", i);
    if (inCS > 1) printf("Mutual exclusion violated!\n");
    random_sleep();
    inCS--;

    // exit section
    flag2 = 0;    
  }
  pthread_exit(NULL);  
}

void random_sleep() { 
// used to increase the probability of different interleavings 
  usleep(rand() % SLEEP);  
}





int main(int argc, char *argv[]) {
  pthread_t p1, p2;
  
  srand(time(NULL));

  pthread_create(&p1, NULL, process1, NULL);
  pthread_create(&p2, NULL, process2, NULL);

  pthread_exit(NULL);
}