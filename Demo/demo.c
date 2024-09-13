/***************************************************
Filename: demo.c
Author: MIDN Ian Coffey (m261194)
demo for C
***************************************************/

// Import Libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  double x, y;
  printf("command: ");
  while(scanf(" dist (%lf,%lf)",&x,&y) == 2) {
    printf("%lf\n",(x*x + y*y));
    printf("command: ");
  }
  printf("bye.\n");
  return 0;
}