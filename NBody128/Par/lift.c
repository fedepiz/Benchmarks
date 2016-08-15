#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <malloc.h>
#include <math.h>
#ifndef Tuple_float_float_float_float_DEFINED
#define Tuple_float_float_float_float_DEFINED
typedef struct {
  float _0;
  float _1;
  float _2;
  float _3;
} Tuple_float_float_float_float;
#endif

#ifndef Tuple_float_float_float_float_DEFINED
#define Tuple_float_float_float_float_DEFINED
typedef struct {
  float _0;
  float _1;
  float _2;
  float _3;
} Tuple_float_float_float_float;
#endif
#ifndef Tuple_float_float_float_float_DEFINED
#define Tuple_float_float_float_float_DEFINED
typedef struct {
  float _0;
  float _1;
  float _2;
  float _3;
} Tuple_float_float_float_float;
#endif
#ifndef Tuple_Tuple_float_float_float_float_Tuple_float_float_float_float_DEFINED
#define Tuple_Tuple_float_float_float_float_Tuple_float_float_float_float_DEFINED
typedef struct {
  Tuple_float_float_float_float _0;
  Tuple_float_float_float_float _1;
} Tuple_Tuple_float_float_float_float_Tuple_float_float_float_float;
#endif

Tuple_float_float_float_float calcAcc(Tuple_float_float_float_float p1, Tuple_float_float_float_float p2, float deltaT, float espSqr, Tuple_float_float_float_float acc){
  typedef Tuple_float_float_float_float Tuple;
  
  {
  Tuple_float_float_float_float r;
  r._0 = p1._0 - p2._0;
  r._1 = p1._1 - p2._1;
  r._2 = p1._2 - p2._2;
  float distSqr = r._0*r._0 + r._1*r._1 + r._2*r._2;
  float invDist = 1.0f / sqrt(distSqr + espSqr);
  float invDistCube = invDist * invDist * invDist;
  float s = invDistCube * p2._3;
  Tuple_float_float_float_float res;
  res._0 = acc._0 + s * r._0;
  res._1 = acc._1 + s * r._1;
  res._2 = acc._2 + s * r._2;
  return res;
}
 
}
Tuple_Tuple_float_float_float_float_Tuple_float_float_float_float update(Tuple_float_float_float_float pos, Tuple_float_float_float_float vel, float deltaT, Tuple_float_float_float_float acceleration){
  typedef Tuple_float_float_float_float Tuple0;
  
  typedef Tuple_Tuple_float_float_float_float_Tuple_float_float_float_float Tuple1;
  
  {
  Tuple_float_float_float_float newPos;
  newPos._0 = pos._0 + vel._0 * deltaT + 0.5f * acceleration._0 * deltaT * deltaT;
  newPos._1 = pos._1 + vel._1 * deltaT + 0.5f * acceleration._1 * deltaT * deltaT;
  newPos._2 = pos._2 + vel._2 * deltaT + 0.5f * acceleration._2 * deltaT * deltaT;
  newPos._3 = pos._3;
  Tuple_float_float_float_float newVel;
  newVel._0 = vel._0 + acceleration._0 * deltaT;
  newVel._1 = vel._1 + acceleration._1 * deltaT;
  newVel._2 = vel._2 + acceleration._2 * deltaT;
  newVel._3 = vel._3;
  Tuple_Tuple_float_float_float_float_Tuple_float_float_float_float t = {newPos, newVel};
  return t;
}
      
}
void liftKernel(Tuple_float_float_float_float* v__12, Tuple_float_float_float_float* v__13, float v__14, float v__15, Tuple_Tuple_float_float_float_float_Tuple_float_float_float_float* v__23){ 
{
  /* Static local memory */
  /* Typed Value memory */
  Tuple_float_float_float_float v__18;
  /* Private Memory */
  /* omp_map */
  #pragma omp parallel for private(v__18)
  for (int v_i_9 = 0;v_i_9<128;v_i_9 = (1 + v_i_9)){
    Tuple_float_float_float_float v_tmp_35 = (Tuple_float_float_float_float) { 0.0f, 0.0f, 0.0f, 0.0f };
    v__18 = v_tmp_35;
    /* reduce_seq */
    for (int v_i_10 = 0;v_i_10<128;v_i_10 = (1 + v_i_10)){
      v__18 = calcAcc(v__12[v_i_9], v__12[v_i_10], v__15, v__14, v__18);
    }
    /* end reduce_seq */
    /* map_seq */
    /* iteration count is exactly 1, no loop emitted */
    {
      int v_i_11 = 0;
      v__23[v_i_9] = update(v__12[v_i_9], v__13[v_i_9], v__15, v__18);
    }
    /* end map_seq */
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
//code for parameter p78
Tuple_float_float_float_float *p78 = malloc(sizeof(Tuple_float_float_float_float) * 128);
//geerating array of type Tuple_float_float_float_float
for(unsigned long i1 = 0; i1 < 128; i1++){
//reading tuple of t ype Tuple(float, float, float, float)
{
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p78[(i1 * 128/128)]._0));
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p78[(i1 * 128/128)]._1));
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p78[(i1 * 128/128)]._2));
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p78[(i1 * 128/128)]._3));

}
}
//code for parameter p101
Tuple_float_float_float_float *p101 = malloc(sizeof(Tuple_float_float_float_float) * 128);
//geerating array of type Tuple_float_float_float_float
for(unsigned long i3 = 0; i3 < 128; i3++){
//reading tuple of t ype Tuple(float, float, float, float)
{
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p101[(i3 * 128/128)]._0));
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p101[(i3 * 128/128)]._1));
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p101[(i3 * 128/128)]._2));
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p101[(i3 * 128/128)]._3));

}
}
//code for parameter p132
float p132;
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p132));
//code for parameter p241
float p241;
inputData = strtok(NULL, "_"); sscanf(inputData,"%f",&(p241));
//main invocation
Tuple_Tuple_float_float_float_float_Tuple_float_float_float_float *output = malloc(sizeof(Tuple_Tuple_float_float_float_float_Tuple_float_float_float_float) * 128 * 1);
struct timeval startTime;
gettimeofday(&startTime, NULL);
liftKernel( p78, p101, p132, p241, output);
struct timeval endTime;gettimeofday(&endTime, NULL);
float totalTime = ((endTime.tv_sec * 1e6 + endTime.tv_usec) - (startTime.tv_sec * 1e6 + startTime.tv_usec))/1000;
printf("\n");
printf("Elapsed time = %f\n",totalTime);
}