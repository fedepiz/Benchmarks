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
void liftKernel(float* v__19, float* v__20, float* v__25, float* v__29, float* v__30){ 
{
  /* Static local memory */
  /* Typed Value memory */
  float v__22;
  /* Private Memory */
  /* omp_map */
  #pragma omp parallel for
  for (int v_i_11 = 0;v_i_11<800;v_i_11 = (1 + v_i_11)){
    /* omp_map */
    #pragma omp parallel for
    for (int v_i_12 = 0;v_i_12<800;v_i_12 = (1 + v_i_12)){
      float v_tmp_39 = 0.0f;
      v__22 = v_tmp_39;
      /* map_seq */
      for (int v_i_13 = 0;v_i_13<800;v_i_13 = (1 + v_i_13)){
        v__25[(v_i_13 + (640000 * v_i_11) + (800 * v_i_12))] = mult(v__19[(v_i_13 + (800 * v_i_11))], v__20[(v_i_12 + (800 * v_i_13))]);
      }
      /* end map_seq */
      /* reduce_seq */
      for (int v_i_14 = 0;v_i_14<800;v_i_14 = (1 + v_i_14)){
        v__22 = add(v__22, v__25[(v_i_14 + (640000 * v_i_11) + (800 * v_i_12))]);
      }
      /* end reduce_seq */
      /* map_seq */
      /* iteration count is exactly 1, no loop emitted */
      {
        int v_i_15 = 0;
        v__29[(v_i_12 + (800 * v_i_11))] = id(v__22);
      }
      /* end map_seq */
    }
    /* end omp_map */
  }
  /* end omp_map */
  /* map_seq */
  for (int v_i_16 = 0;v_i_16<800;v_i_16 = (1 + v_i_16)){
    /* map_seq */
    for (int v_i_17 = 0;v_i_17<800;v_i_17 = (1 + v_i_17)){
      /* map_seq */
      /* iteration count is exactly 1, no loop emitted */
      {
        int v_i_18 = 0;
        v__30[(v_i_17 + (800 * v_i_16))] = id(v__29[(v_i_17 + (800 * v_i_16))]);
      }
      /* end map_seq */
    }
    /* end map_seq */
  }
  /* end map_seq */
}}


//Auto-generated runtime harness

char *readFile() {
  FILE* f = fopen("data.txt", "rb");
  fseek(f, 0, SEEK_END);
  long length = ftell(f);
  fseek(f, 0, SEEK_SET);
  char* buffer = malloc(length);
  if(buffer) {
    fread(buffer, 1, length, f);
  }
  fclose(f);
  return buffer;
}
    int main(int argc, char** argv) {
int arrCount;
char* inputData = strtok(readFile(),"@");
//code for parameter p174
float *p174 = malloc(sizeof(float) * 800 * 800);
//geerating array of type float
for(unsigned long i2 = 0; i2 < 800; i2++){
for(unsigned long i3 = 0; i3 < 800; i3++){
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p174[(i2 * 800 * 800/800) + (i3 * 800 * 800/800/800)]));
}
}
//code for parameter p10
float *p10 = malloc(sizeof(float) * 800 * 800);
//geerating array of type float
for(unsigned long i6 = 0; i6 < 800; i6++){
for(unsigned long i7 = 0; i7 < 800; i7++){
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p10[(i6 * 800 * 800/800) + (i7 * 800 * 800/800/800)]));
}
}
//Code for intermediate parameters
float *v__25 = malloc(sizeof(float) * 800 * 800 * 800);
float *v__29 = malloc(sizeof(float) * 800 * 800 * 1);
//main invocation
float *output = malloc(sizeof(float) * 800 * 800 * 1);
struct timeval startTime;
gettimeofday(&startTime, NULL);
liftKernel( p174, p10, v__25, v__29, output);
struct timeval endTime;gettimeofday(&endTime, NULL);
float totalTime = ((endTime.tv_sec * 1e6 + endTime.tv_usec) - (startTime.tv_sec * 1e6 + startTime.tv_usec))/1000;
printf("\n");
printf("Elapsed time = %f\n",totalTime);
}