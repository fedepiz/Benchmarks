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
void liftKernel(float* v__23, float* v__24, float* v__29, float* v__33, float* v__34){ 
{
  /* Static local memory */
  /* Typed Value memory */
  float v__26;
  /* Private Memory */
  /* map_seq */
  for (int v_i_15 = 0;v_i_15<200;v_i_15 = (1 + v_i_15)){
    /* map_seq */
    for (int v_i_16 = 0;v_i_16<200;v_i_16 = (1 + v_i_16)){
      float v_tmp_43 = 0.0f;
      v__26 = v_tmp_43;
      /* map_seq */
      for (int v_i_17 = 0;v_i_17<200;v_i_17 = (1 + v_i_17)){
        v__29[(v_i_17 + (40000 * v_i_15) + (200 * v_i_16))] = mult(v__23[(v_i_17 + (200 * v_i_15))], v__24[(v_i_16 + (200 * v_i_17))]);
      }
      /* end map_seq */
      /* reduce_seq */
      for (int v_i_18 = 0;v_i_18<200;v_i_18 = (1 + v_i_18)){
        v__26 = add(v__26, v__29[(v_i_18 + (40000 * v_i_15) + (200 * v_i_16))]);
      }
      /* end reduce_seq */
      /* map_seq */
      /* iteration count is exactly 1, no loop emitted */
      {
        int v_i_19 = 0;
        v__33[(v_i_16 + (200 * v_i_15))] = id(v__26);
      }
      /* end map_seq */
    }
    /* end map_seq */
  }
  /* end map_seq */
  /* map_seq */
  for (int v_i_20 = 0;v_i_20<200;v_i_20 = (1 + v_i_20)){
    /* map_seq */
    for (int v_i_21 = 0;v_i_21<200;v_i_21 = (1 + v_i_21)){
      /* map_seq */
      /* iteration count is exactly 1, no loop emitted */
      {
        int v_i_22 = 0;
        v__34[(v_i_21 + (200 * v_i_20))] = id(v__33[(v_i_21 + (200 * v_i_20))]);
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
float *p242 = malloc(sizeof(float) * 200 * 200);
//geerating array of type float
for(unsigned long i2 = 0; i2 < 200; i2++){
for(unsigned long i3 = 0; i3 < 200; i3++){
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p242[(i2 * 200 * 200/200) + (i3 * 200 * 200/200/200)]));
}
}
//code for parameter p30
float *p30 = malloc(sizeof(float) * 200 * 200);
//geerating array of type float
for(unsigned long i6 = 0; i6 < 200; i6++){
for(unsigned long i7 = 0; i7 < 200; i7++){
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p30[(i6 * 200 * 200/200) + (i7 * 200 * 200/200/200)]));
}
}
//Code for intermediate parameters
float *v__29 = malloc(sizeof(float) * 200 * 200 * 200);
float *v__33 = malloc(sizeof(float) * 200 * 200 * 1);
//main invocation
float *output = malloc(sizeof(float) * 200 * 200 * 1);
struct timeval startTime;
gettimeofday(&startTime, NULL);
liftKernel( p242, p30, v__29, v__33, output);
struct timeval endTime;gettimeofday(&endTime, NULL);
float totalTime = ((endTime.tv_sec * 1e6 + endTime.tv_usec) - (startTime.tv_sec * 1e6 + startTime.tv_usec))/1000;
printf("\n");
printf("Elapsed time = %f\n",totalTime);
}