gcc lift.c -o a.out -std=c99 -fopenmp -O3 -ftree-vectorize -lm
./a.out