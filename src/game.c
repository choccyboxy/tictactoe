#include "game.h"

#include <stdio.h>
#include <string.h>

#include "computer.h"
#include "config.h"

void build(char place[]) {
  printf("Tic Tac Toe in the Terminal\n\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", place[0], place[1], place[2]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", place[3], place[4], place[5]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", place[6], place[7], place[8]);
  printf("     |     |     \n");
}

char character;
int controller(char spaces[], int player1Went) {
  char player[32];

  if (player1Went == 0) {
    strcpy(player, "Player 1");
    character = PLAYER_ONE_CHAR;
  } else {
    strcpy(player, "Player 2");
    character = PLAYER_TWO_CHAR;

#ifdef COMPUTER_ENABLED
    strcpy(player, "Computer");
#endif
  }

  int place;
  if (strcmp(player, "Computer") == 0) {
    place = moveComputer();
    printf("%s chose place %d\n", player, place);
  } else {
    printf("%s enter a number from 1-9: ", player);
    scanf("%d", &place);
  }

  if (place > 9 || place < 0) {
    printf("[ERROR]: Invalid place\n");
    return -1;
  };

  if (spaces[place - 1] != '-') {
    printf("[ERROR]: Place already taken\n");
    return -1;
  }

  return place;
}

int getOutcome(char spaces[]) {
  int result = 0;

  // Check for horizontal win
  for (int i = 0; i < 9; i += 3) {
    if (spaces[i] == spaces[i + 1] && spaces[i + 1] == spaces[i + 2]) {
      if (spaces[i] == PLAYER_ONE_CHAR)
        return 1;
      else if (spaces[i] == PLAYER_TWO_CHAR)
        return 2;
    }
  }

  // Check for vertical win
  for (int i = 0; i < 3; i++) {
    if (spaces[i] == spaces[i + 3] && spaces[i + 3] == spaces[i + 6]) {
      if (spaces[i] == PLAYER_ONE_CHAR)
        return 1;
      else if (spaces[i] == PLAYER_TWO_CHAR)
        return 2;
    }
  }

  // Check for diagonal win
  if (spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
    if (spaces[0] == PLAYER_ONE_CHAR)
      return 1;
    else if (spaces[0] == PLAYER_TWO_CHAR)
      return 2;
  }

  // Check for reverse diagonal win
  if (spaces[2] == spaces[4] && spaces[4] == spaces[6]) {
    if (spaces[2] == PLAYER_ONE_CHAR)
      return 1;
    else if (spaces[2] == PLAYER_TWO_CHAR)
      return 2;
  }

  return result;
}

void printOutcome(int result) {
  switch (result) {
    case 0:
      printf("[GAME]: Game resulted in a tie\n");
      break;

    case 1:
      printf("[GAME]: Player 1 won the game\n");
      break;

    case 2:
      printf("[GAME]: Player 2 won the game\n");
      break;

    default:
      printf("[ERROR]: Unknown game ending type\n");
      break;
  }
}