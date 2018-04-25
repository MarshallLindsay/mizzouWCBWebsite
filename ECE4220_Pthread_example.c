#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>


#define NUM_THREADS 8

void *PrintHello(void *threadid){
  long my_tid;
  my_tid = (long)threadid;
  printf("Hello World! It's me, thread #%ld!\n", my_tid);
}

int main(int argc, char* argv[]){
  pthread_t threads[NUM_THREADS];

  long t;

  //fork

  for(t = 0; t < NUM_THREADS; t++){
    printf("In main: creating thread %ld\n", t);
    pthread_create($threads[t], NULL, PrintHello, (void*)t);
  }

  //join

  for(t = 0; t < NUM_THREADS; t++){
    printf("In main: joining thread %ld", t);
    pthread_join(threads[t], NULL);
  }
}
