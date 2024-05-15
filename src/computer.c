#include "computer.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "config.h"

int offset = 0;

// TODO: Get better random num && add smart place
int moveComputer(char spaces[]) {
  time_t t;
  srand((unsigned)time(&t));
  int num = rand() % 8;

  if (spaces[num + offset] != '-') ++offset;

  if (num >= 8 || offset >= 8) {
    offset -= 8;
    return num + 1 + offset;
  }

  return num + 1 + offset;
}