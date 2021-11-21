#ifndef GOLFFUNC_H_
#define GOLFFUNC_H_

#include <iostream>

const size_t array_len = 10;


// Function prototypes using in programm

void eat_line();

size_t read_golf_results(int _golf_results[], size_t size);

double mean_of_results(int _golf_results[], size_t size);

void print_results(int _golf_results[], size_t size, double mean);


#endif
