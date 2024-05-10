#include "computer.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "config.h"

// TODO: Get better random num && add smart place
int moveComputer() {
  time_t t;
  srand((unsigned)time(&t));
  int num = rand() % 9;

  return num + 1;
}