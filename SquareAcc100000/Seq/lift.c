#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <malloc.h>
#include <math.h>
float square(float x){
  return x*x;
}
float add(float x, float y){
  { return x+y; }
}
float id(float x){
  { return x; }
}
void liftKernel(float* v__12, float* v__15, float* v__19){ 
{
  /* Static local memory */
  /* Typed Value memory */
  float v__13;
  /* Private Memory */
  float v_tmp_21 = 0.0f;
  v__13 = v_tmp_21;
  /* omp_map */
  #pragma omp parallel for
  for (int v_i_9 = 0;v_i_9<100000;v_i_9 = (1 + v_i_9)){
    v__15[v_i_9] = square(v__12[v_i_9]);
  }
  /* end omp_map */
  /* reduce_seq */
  for (int v_i_10 = 0;v_i_10<100000;v_i_10 = (1 + v_i_10)){
    v__13 = add(v__13, v__15[v_i_10]);
  }
  /* end reduce_seq */
  /* map_seq */
  /* iteration count is exactly 1, no loop emitted */
  {
    int v_i_11 = 0;
    v__19[v_i_11] = id(v__13);
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
//code for parameter p247
float *p247 = malloc(sizeof(float) * 100000);
//geerating array of type float
for(unsigned long i1 = 0; i1 < 100000; i1++){
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p247[(i1 * 100000/100000)]));
}
//Code for intermediate parameters
float *v__15 = malloc(sizeof(float) * 100000);
//main invocation
float *output = malloc(sizeof(float) * 1);
struct timeval startTime;
gettimeofday(&startTime, NULL);
liftKernel( p247, v__15, output);
struct timeval endTime;gettimeofday(&endTime, NULL);
float totalTime = ((endTime.tv_sec * 1e6 + endTime.tv_usec) - (startTime.tv_sec * 1e6 + startTime.tv_usec))/1000;
printf("\n");
printf("Elapsed time = %f\n",totalTime);
}