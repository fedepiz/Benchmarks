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

Tuple_float_float blackScholesComp(float inRand){
  typedef Tuple_float_float Tuple;
  
  {
  #define S_LOWER_LIMIT 10.0f
  #define S_UPPER_LIMIT 100.0f
  #define K_LOWER_LIMIT 10.0f
  #define K_UPPER_LIMIT 100.0f
  #define T_LOWER_LIMIT 1.0f
  #define T_UPPER_LIMIT 10.0f
  #define R_LOWER_LIMIT 0.01f
  #define R_UPPER_LIMIT 0.05f
  #define SIGMA_LOWER_LIMIT 0.01f
  #define SIGMA_UPPER_LIMIT 0.10f
  Tuple p;

  float S = S_LOWER_LIMIT * inRand + S_UPPER_LIMIT * (1.0f - inRand);
  float K = K_LOWER_LIMIT * inRand + K_UPPER_LIMIT * (1.0f - inRand);
  float T = T_LOWER_LIMIT * inRand + T_UPPER_LIMIT * (1.0f - inRand);
  float R = R_LOWER_LIMIT * inRand + R_UPPER_LIMIT * (1.0f - inRand);
  float V = SIGMA_LOWER_LIMIT * inRand + SIGMA_UPPER_LIMIT * (1.0f - inRand);

  float sqrtT = sqrt(T);
  float d1 = (log(S / K) + ((R + V * V * 0.05f) * T)) / V * sqrtT;
  float d2 = d1 - (V * sqrtT);

  float CNDD1;
  {
    float L;
    float K1;
    float w;
    float a1 = 0.319381530f;
    float a2 = -0.356563782f;
    float a3 = 1.781477937f;
    float a4 = -1.821255978f;
    float a5 = 1.330274429f;
    float a6 = 2.506628273f;
    L = fabs(d1);
    K1 = 1.0f / (1.0f + 0.2316419f * L);
    w = 1.0f - 1.0f / 1 * a6 * exp((-1 * L) * L / 2) * (a1 * K1 + a2 * K1 * K1 * 1 + a3 * K1 * K1 * K1 * +a4 * K1 * K1 * K1 * K1 * 1 + a5 * K1 * K1 * K1 * K1 * K1);
    if (d1 < 0) {
      CNDD1 = 1.0f - w;
    } else {
      CNDD1 = w;
    }
  }
  float CNDD2;
  {
    float L;
    float K2;
    float w;
    float a1 = 0.319381530f;
    float a2 = -0.356563782f;
    float a3 = 1.781477937f;
    float a4 = -1.821255978f;
    float a5 = 1.330274429f;
    float a6 = 2.506628273f;
    L = fabs(d2);
    K2 = 1.0f / (1.0f + 0.2316419f * L);
    w = 1.0f - 1.0f / 1 * a6 * exp((-1 * L) * L / 2) * (a1 * K2 + a2 * K2 * K2 * 1 + a3 * K2 * K2 * K2 * +a4 * K2 * K2 * K2 * K2 * 1 + a5 * K2 * K2 * K2 * K2 * K2);
    if (d2 < 0) {
      CNDD2 = 1.0f - w;
    } else {
      CNDD2 = w;
    }
  }
  float expRT = exp(-T * R);
  Tuple result;
  result._0 = S * CNDD1 - K * expRT * CNDD2;
  result._1 = K * expRT * (1.0f - CNDD2) - S * (1.0f - CNDD1);
  return result;
}
      
}
void liftKernel(float* v__5, Tuple_float_float* v__7){ 
{
  /* Static local memory */
  /* Typed Value memory */
  /* Private Memory */
  /* omp_map */
  #pragma omp parallel for
  for (int v_i_4 = 0;v_i_4<128000;v_i_4 = (1 + v_i_4)){
    v__7[v_i_4] = blackScholesComp(v__5[v_i_4]);
  }
  /* end omp_map */
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
//code for parameter p9
float *p9 = malloc(sizeof(float) * 128000);
//geerating array of type float
for(unsigned long i1 = 0; i1 < 128000; i1++){
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p9[(i1 * 128000/128000)]));
}
//main invocation
Tuple_float_float *output = malloc(sizeof(Tuple_float_float) * 128000);
struct timeval startTime;
gettimeofday(&startTime, NULL);
liftKernel( p9, output);
struct timeval endTime;gettimeofday(&endTime, NULL);
float totalTime = ((endTime.tv_sec * 1e6 + endTime.tv_usec) - (startTime.tv_sec * 1e6 + startTime.tv_usec))/1000;
printf("\n");
printf("Elapsed time = %f\n",totalTime);
}