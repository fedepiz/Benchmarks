#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <malloc.h>
#include <math.h>
#ifndef Tuple_float_float_DEFINED
#define Tuple_float_float_DEFINED
typedef struct {
  float _0;
  float _1;
} Tuple_float_float;
#endif

float mult(float l, float r){
  { return l * r; }
}
float add(float x, float y){
  { return x+y; }
}
float id(float x){
  { return x; }
}
void liftKernel(float* v__9, float* v__10, float* v__15, float* v__19){
{
  /* Static local memory */
  /* Typed Value memory */
  float v__11;
  /* Private Memory */
  float v_tmp_24 = 0.0f;
  v__11 = v_tmp_24;
  /* map_seq */
  for (int v_i_6 = 0;v_i_6<100000;v_i_6 = (1 + v_i_6)){
    v__15[v_i_6] = mult(v__9[v_i_6], v__10[v_i_6]);
  }
  /* end map_seq */
  /* reduce_seq */
  for (int v_i_7 = 0;v_i_7<100000;v_i_7 = (1 + v_i_7)){
    v__11 = add(v__11, v__15[v_i_7]);
  }
  /* end reduce_seq */
  /* map_seq */
  /* iteration count is exactly 1, no loop emitted */
  {
    int v_i_8 = 0;
    v__19[v_i_8] = id(v__11);
  }
  /* end map_seq */
}}


//Auto-generated runtime harness
int main(int argc, char** argv) {
int arrCount;
char* inputData = strtok(argv[1],"@");
//code for parameter p73
float *p73 = malloc(sizeof(float) * 100000);
//geerating array of type float
for(unsigned long i1 = 0; i1 < 100000; i1++){
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p73[(i1 * 100000/100000)]));
}
//code for parameter p153
float *p153 = malloc(sizeof(float) * 100000);
//geerating array of type float
for(unsigned long i3 = 0; i3 < 100000; i3++){
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p153[(i3 * 100000/100000)]));
}
//Code for intermediate parameters
float *v__15 = malloc(sizeof(float) * 100000);
//main invocation
float *output = malloc(sizeof(float) * 1);
struct timeval startTime;
gettimeofday(&startTime, NULL);
for(int i = 0; i < 10; i++) {
liftKernel( p73, p153, v__15, output);
}
struct timeval endTime;gettimeofday(&endTime, NULL);
float totalTime = ((endTime.tv_sec * 1e6 + endTime.tv_usec) - (startTime.tv_sec * 1e6 + startTime.tv_usec))/1000;
printf("\n");
printf("Elapsed time = %f\n",totalTime);
}
