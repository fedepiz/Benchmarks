#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <malloc.h>
#include <math.h>
float squareAdd(float x, float y){
  return x + (y * y);
}
float id(float x){
  { return x; }
}
void liftKernel(float* v__10, float* v__16){ 
{
  /* Static local memory */
  /* Typed Value memory */
  float v__11;
  /* Private Memory */
  float v_tmp_18 = 0.0f;
  v__11 = v_tmp_18;
  /* reduce_par */
  #pragma omp parallel for reduction (+:v__11)
  for (int v_i_8 = 0;v_i_8<100000;v_i_8 = (1 + v_i_8)){
    v__11 = squareAdd(v__11, v__10[v_i_8]);
  }
  /* end reduce_par */
  /* map_seq */
  /* iteration count is exactly 1, no loop emitted */
  {
    int v_i_9 = 0;
    v__16[v_i_9] = id(v__11);
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
//code for parameter p24
float *p24 = malloc(sizeof(float) * 100000);
//geerating array of type float
for(unsigned long i1 = 0; i1 < 100000; i1++){
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p24[(i1 * 100000/100000)]));
}
//main invocation
float *output = malloc(sizeof(float) * 1);
struct timeval startTime;
gettimeofday(&startTime, NULL);
liftKernel( p24, output);
struct timeval endTime;gettimeofday(&endTime, NULL);
float totalTime = ((endTime.tv_sec * 1e6 + endTime.tv_usec) - (startTime.tv_sec * 1e6 + startTime.tv_usec))/1000;
printf("\n");
printf("Elapsed time = %f\n",totalTime);
}