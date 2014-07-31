#include <math.h>
#include <stdio.h>

#define scale_const 4194304.000000
#define inv_scale_const 0.0000002384185791015625
#define cordic_const 1.646760
#define inv_cord_const 0.60725303019262066117709927372538

void cordic_rotation(int z) {

  int angle [] = {0x0B400000, 0x06A429CC, 0x038251D0, 0x01C80044, 0x00E4E2A9, 0x00728DE5, 0x00394A86, 
  0x001CA5B5, 0x000E52E9, 0x00072976, 0x000394BB, 0x0001CA5D, 0x0000E52E, 0x00007297, 0x0000394B, 0x00001CA5, 
  0x00000E52, 0x00000729, 0x00000394, 0x000001CA, 0x000000E5, 0x00000072, 0x00000039, 0x0000001C, 0x0000000E, 
  0x00000007, 0x00000003, 0x00000001,};

  int i, nx, ny, d;
  int x = (1<<22), y = 0;
  z = (z<<22);
  for(i=(i-i);i<28; i+=7){
    if(z<0){
        nx = x + (y >> i);
        ny = y - (x >> i);
        z += angle[i];
      } else {
        nx = x - (y >> i);
        ny = y + (x >> i);
        z -= angle[i];
      }
      x = nx;
      y = ny;

      if(z<0){
        nx = x + (y >> (i+1));
        ny = y - (x >> (i+1));
        z += angle[i+1];
      } else {
        nx = x - (y >> (i+1));
        ny = y + (x >> (i+1));
        z -= angle[i+1];
      }
      x = nx;
      y = ny;

      if(z<0){
        nx = x + (y >> (i+2));
        ny = y - (x >> (i+2));
        z += angle[i+2];
      } else {
        nx = x - (y >> (i+2));
        ny = y + (x >> (i+2));
        z -= angle[i+2];
      }
      x = nx;
      y = ny;

      if(z<0){
        nx = x + (y >> (i+3));
        ny = y - (x >> (i+3));
        z += angle[i+3];
      } else {
        nx = x - (y >> (i+3));
        ny = y + (x >> (i+3));
        z -= angle[i+3];
      }
      x = nx;
      y = ny;

      if(z<0){
        nx = x + (y >> (i+4));
        ny = y - (x >> (i+4));
        z += angle[i+4];
      } else {
        nx = x - (y >> (i+4));
        ny = y + (x >> (i+4));
        z -= angle[i+4];
      }
      x = nx;
      y = ny;

      if(z<0){
        nx = x + (y >> (i+5));
        ny = y - (x >> (i+5));
        z += angle[i+5];
      } else {
        nx = x - (y >> (i+5));
        ny = y + (x >> (i+5));
        z -= angle[i+5];
      }
      x = nx;
      y = ny;

      if(z<0){
        nx = x + (y >> (i+6));
        ny = y - (x >> (i+6));
        z += angle[i+6];
      } else {
        nx = x - (y >> (i+6));
        ny = y + (x >> (i+6));
        z -= angle[i+6];
      }
      x = nx;
      y = ny;
  }
  printf("Cosine: %lf Sine: %lf\n", (x*inv_scale_const*inv_cord_const), (y*inv_scale_const*inv_cord_const));
}


void cordic_vectoring(int x, int y){
  int i, nx, ny, d, z;
  int angle [] = {0x0B400000, 0x06A429CC, 0x038251D0, 0x01C80044, 0x00E4E2A9, 0x00728DE5, 0x00394A86, 
  0x001CA5B5, 0x000E52E9, 0x00072976, 0x000394BB, 0x0001CA5D, 0x0000E52E, 0x00007297, 0x0000394B, 0x00001CA5, 
  0x00000E52, 0x00000729, 0x00000394, 0x000001CA, 0x000000E5, 0x00000072, 0x00000039, 0x0000001C, 0x0000000E, 
  0x00000007, 0x00000003, 0x00000001,};
  x = (x<<22);
  y = (y<<22); 
  z = 0;
  for(i=(i-i);i<28;i+=7){
    if(y>=0){
      nx = x + (y >> i);
      ny = y - (x >> i);
      z += angle[i];
    } else {
      nx = x - (y >> i);
      ny = y + (x >> i);
      z -= angle[i];
    }
    x = nx;
    y = ny; 

    if(y>=0){
      nx = x + (y >> (i+1));
      ny = y - (x >> (i+1));
      z += angle[i+1];
    } else {
      nx = x - (y >> (i+1));
      ny = y + (x >> (i+1));
      z -= angle[i+1];
    }
    x = nx;
    y = ny; 

    if(y>=0){
      nx = x + (y >> (i+2));
      ny = y - (x >> (i+2));
      z += angle[i+2];
    } else {
      nx = x - (y >> (i+2));
      ny = y + (x >> (i+2));
      z -= angle[i+2];
    }
    x = nx;
    y = ny; 

    if(y>=0){
      nx = x + (y >> (i+3));
      ny = y - (x >> (i+3));
      z += angle[i];
    } else {
      nx = x - (y >> (i+3));
      ny = y + (x >> (i+3));
      z -= angle[i+3];
    }
    x = nx;
    y = ny; 

    if(y>=0){
      nx = x + (y >> (i+4));
      ny = y - (x >> (i+4));
      z += angle[i+4];
    } else {
      nx = x - (y >> (i+4));
      ny = y + (x >> (i+4));
      z -= angle[i+4];
    }
    x = nx;
    y = ny; 

    if(y>=0){
      nx = x + (y >> (i+5));
      ny = y - (x >> (i+5));
      z += angle[i+5];
    } else {
      nx = x - (y >> (i+5));
      ny = y + (x >> (i+5));
      z -= angle[i+5];
    }
    x = nx;
    y = ny; 

    if(y>=0){
      nx = x + (y >> (i+6));
      ny = y - (x >> (i+6));
      z += angle[i+6];
    } else {
      nx = x - (y >> (i+6));
      ny = y + (x >> (i+6));
      z -= angle[i+6];
    }
    x = nx;
    y = ny;   
  }
  printf("arctan: %lf\n", (z*inv_scale_const));
}




int main(int argc, char **argv){
  printf("Vectoring Mode: \n");
  int x, y, z, i;
  x = 1;
  y = 1;
  cordic_vectoring(x, y);
  x = 1;
  y = 2;
  cordic_vectoring(x, y);
  x = 5;
  y = 3;
  cordic_vectoring(x, y);
  printf("Rotational Mode: \n");
  z = 0;
  printf("Angle: 0 ");
  cordic_rotation(z);
  z = 30;
  printf("Angle: 30 ");
  cordic_rotation(z);
  z = 45;
  printf("Angle: 45 ");
  cordic_rotation(z);
  z = 60;
  printf("Angle: 60 ");
  cordic_rotation(z);
  z = 75;
  printf("Angle: 75 ");
  cordic_rotation(z);
  z = 90;
  printf("Angle: 90 ");
  cordic_rotation(z);
  return 0;
}