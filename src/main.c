#include <stdio.h>
#include <string.h>

#include "computer.h"
#include "config.h"
#include "game.h"

// TODO: Add scalable board size & refactor spaces array

int main() {
  char spaces[] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
  build(spaces);

  int placesLeft = 9;
  int player1Went = 0;

  while (placesLeft > 0) {
    int place = controller(spaces, player1Went);

    if (!(place == -1)) {
      spaces[place - 1] = character;
      build(spaces);

      int result = getOutcome(spaces);
      if (result > 0) {
        printOutcome(result);
        break;
      }

      placesLeft -= 1;
      player1Went = (player1Went == 0) ? 1 : 0;
    }
  }

  if (placesLeft == 0) {
    int result = getOutcome(spaces);
    printOutcome(result);
  }
  return 0;
}