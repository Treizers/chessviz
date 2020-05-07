#include "header.h"
#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

int NumberBoard1 = 0, NumberBoard2 = 0;
int LetterBoard1 = 0, LetterBoard2 = 0;
int BoundMin = 0, BoundMax = 9;
int Qualifier;

void move(char turn[], char pole[][9]) {
  if (strlen(turn) == 5) {
    Qualifier = 0;
    if (Check(turn, pole, Qualifier)) {
      movePawn(pole);
    }
  } else {
    Qualifier = 1;
    if (Check(turn, pole, Qualifier)) {
      moveFigure(turn, pole);
    }
  }
}

void movePawn(char pole[][9]) {
  if (pole[NumberBoard1 - 1][LetterBoard1] == 'p') {
    pole[NumberBoard1 - 1][LetterBoard1] = ' ';
    pole[NumberBoard2 - 1][LetterBoard2] = 'p';
  } else if (pole[NumberBoard1 - 1][LetterBoard1] == 'P') {
    pole[NumberBoard1 - 1][LetterBoard1] = ' ';
    pole[NumberBoard2 - 1][LetterBoard2] = 'P';
  } else
    cout << "Entry incorrect, you tried to go not a pawn" << endl << endl;
}

void moveFigure(char turn[], char pole[][9]) {
  if (pole[NumberBoard1 - 1][LetterBoard1] == turn[0]) {
    pole[NumberBoard1 - 1][LetterBoard1] = ' ';
    pole[NumberBoard2 - 1][LetterBoard2] = turn[0];
  } else
    cout << "Entry incorrect, you tried to go not by figures from the back row"
         << endl
         << endl;
}

bool Check(char turn[], char pole[][9], int Qualifier) {
  string s = " ";
  switch (turn[0 + Qualifier]) {
  case 'a':
    LetterBoard1 = 1;
    break;
  case 'b':
    LetterBoard1 = 2;
    break;
  case 'c':
    LetterBoard1 = 3;
    break;
  case 'd':
    LetterBoard1 = 4;
    break;
  case 'e':
    LetterBoard1 = 5;
    break;
  case 'f':
    LetterBoard1 = 6;
    break;
  case 'g':
    LetterBoard1 = 7;
    break;
  case 'h':
    LetterBoard1 = 8;
    break;
  }

  switch (turn[3 + Qualifier]) {
  case 'a':
    LetterBoard2 = 1;
    break;
  case 'b':
    LetterBoard2 = 2;
    break;
  case 'c':
    LetterBoard2 = 3;
    break;
  case 'd':
    LetterBoard2 = 4;
    break;
  case 'e':
    LetterBoard2 = 5;
    break;
  case 'f':
    LetterBoard2 = 6;
    break;
  case 'g':
    LetterBoard2 = 7;
    break;
  case 'h':
    LetterBoard2 = 8;
    break;
  }
  s[0] = turn[1 + Qualifier];
  NumberBoard1 = atoi(s.c_str());

  s[0] = turn[4 + Qualifier];
  NumberBoard2 = atoi(s.c_str());

  if (NumberBoard1 <= BoundMin || NumberBoard1 >= BoundMax ||
      LetterBoard1 <= BoundMin || LetterBoard1 >= BoundMax ||
      NumberBoard2 <= BoundMin || NumberBoard2 >= BoundMax ||
      LetterBoard2 <= BoundMin || LetterBoard2 >= BoundMax) {
    cout << "Entry incorrect, out of bounds" << endl << endl;
    return false;
  }
  return true;
}
