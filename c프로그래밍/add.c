#include <stdio.h>

extern int global;

int add(int a, int b) { 
	return a + b + global;
}