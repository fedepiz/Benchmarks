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
void liftKernel(float* v__20, float* v__21, float* v__26, float* v__30, float* v__31){ 
{
  /* Static local memory */
  /* Typed Value memory */
  float v__23;
  /* Private Memory */
  /* map_seq */
  for (int v_i_12 = 0;v_i_12<256;v_i_12 = (1 + v_i_12)){
    /* map_seq */
    for (int v_i_13 = 0;v_i_13<256;v_i_13 = (1 + v_i_13)){
      float v_tmp_40 = 0.0f;
      v__23 = v_tmp_40;
      /* map_seq */
      for (int v_i_14 = 0;v_i_14<256;v_i_14 = (1 + v_i_14)){
        v__26[(v_i_14 + (65536 * v_i_12) + (256 * v_i_13))] = mult(v__20[(v_i_14 + (256 * v_i_12))], v__21[(v_i_13 + (256 * v_i_14))]);
      }
      /* end map_seq */
      /* reduce_seq */
      for (int v_i_15 = 0;v_i_15<256;v_i_15 = (1 + v_i_15)){
        v__23 = add(v__23, v__26[(v_i_15 + (65536 * v_i_12) + (256 * v_i_13))]);
      }
      /* end reduce_seq */
      /* map_seq */
      /* iteration count is exactly 1, no loop emitted */
      {
        int v_i_16 = 0;
        v__30[(v_i_13 + (256 * v_i_12))] = id(v__23);
      }
      /* end map_seq */
    }
    /* end map_seq */
  }
  /* end map_seq */
  /* map_seq */
  for (int v_i_17 = 0;v_i_17<256;v_i_17 = (1 + v_i_17)){
    /* map_seq */
    for (int v_i_18 = 0;v_i_18<256;v_i_18 = (1 + v_i_18)){
      /* map_seq */
      /* iteration count is exactly 1, no loop emitted */
      {
        int v_i_19 = 0;
        v__31[(v_i_18 + (256 * v_i_17))] = id(v__30[(v_i_18 + (256 * v_i_17))]);
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
//code for parameter p242
float *p242 = malloc(sizeof(float) * 256 * 256);
//geerating array of type float
for(unsigned long i2 = 0; i2 < 256; i2++){
for(unsigned long i3 = 0; i3 < 256; i3++){
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p242[(i2 * 256 * 256/256) + (i3 * 256 * 256/256/256)]));
}
}
//code for parameter p27
float *p27 = malloc(sizeof(float) * 256 * 256);
//geerating array of type float
for(unsigned long i6 = 0; i6 < 256; i6++){
for(unsigned long i7 = 0; i7 < 256; i7++){
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p27[(i6 * 256 * 256/256) + (i7 * 256 * 256/256/256)]));
}
}
//Code for intermediate parameters
float *v__26 = malloc(sizeof(float) * 256 * 256 * 256);
float *v__30 = malloc(sizeof(float) * 256 * 256 * 1);
//main invocation
float *output = malloc(sizeof(float) * 256 * 256 * 1);
struct timeval startTime;
gettimeofday(&startTime, NULL);
liftKernel( p242, p27, v__26, v__30, output);
struct timeval endTime;gettimeofday(&endTime, NULL);
float totalTime = ((endTime.tv_sec * 1e6 + endTime.tv_usec) - (startTime.tv_sec * 1e6 + startTime.tv_usec))/1000;
printf("\n");
printf("Elapsed time = %f\n",totalTime);
}