#include <math.h>
#include <stdio.h>

// #define cordic_1K 0x26DD3B6A
// #define half_pi 0x6487ED51
#define scale_const 4194304.000000
#define cordic_const 1.646760
#define CORDIC_BIT 32

int angle [] = {0x0B400000, 0x06A429CC, 0x038251D0, 0x01C80044, 0x00E4E2A9, 0x00728DE5, 0x00394A86, 
  0x001CA5B5, 0x000E52E9, 0x00072976, 0x000394BB, 0x0001CA5D, 0x0000E52E, 0x00007297, 0x0000394B, 0x00001CA5, 
  0x00000E52, 0x00000729, 0x00000394, 0x000001CA, 0x000000E5, 0x00000072, 0x00000039, 0x0000001C, 0x0000000E, 
  0x00000007, 0x00000003, 0x00000001, };

void cordic_rotation(int *cosine, int *sine, int ty, int tx, int tz, int n) {
  int i, nx, ny, d;
  int x = (tx*scale_const), y = (ty*scale_const);
  for(i=0;i<n;i++){
      d = tz>>27;
      nx = x - (((y>>i) ^ d) - d);
      ny = y + (((x>>i) ^ d) - d);
      tz = tz - ((angle[i] ^ d) - d);
      x = nx;
      y = ny;
  }
  *cosine = x/cordic_const;
  *sine = y/cordic_const;
}

void cordic_vectoring(int tx, int ty, int *tz, int n){
  int i, nx, ny, d;
  int x = (tx*scale_const), y = (ty*scale_const);
  for(i=0;i<n;i++){
      d = y>>27;
      nx = x + (((y>>i) ^ d) - d);
      ny = y - (((x>>i) ^ d) - d);
      *tz = *tz + ((angle[i] ^ d) - d);
      x = nx;
      y = ny;
  }
}



int main(int argc, char **argv){
  double p, s;
  int cosine,sine, arctan;
  int x, y, z, i;
  x = 1;
  y = 1;
  z = 0;
  cordic_vectoring(x, y, &z, 28);
  printf("%f\n", z/scale_const);
  x = 1;
  y = 0;
  z = angle[0];
  cordic_rotation(&cosine, &sine, y, x, z, 28);
  printf("cosine: %f, sine: %f\n", cosine/scale_const, sine/scale_const);
  return 0;
}