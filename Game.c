/*
typedef struct _playerInfo {
  int numberOfKPIpoints;
  int numberOfArcs;
  int numberOfPublications;
  int numberOfCampuses;
  int numberOfG08s;
  int numberOfIPs;
  int numberOfThD;
  int numberOfBPS;
  int numberOfB?;
  int numberOfMJ;
  int numberOfMTV;
  int numberOfM$;
} player;


typedef struct _game{
  int currentTurnValue;
  int currentPlayerTurn;
  int currentDiceValue;
  int isLegalAction;
  player players[NUM_UNIS];
  int currenthighestKPI;
}*/
#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

#define NUMBER_OF_DISCIPLINES 6
#define DEFAULT_RATE 3
#define REDUCED_RATE 2
#define STUDENTS_REQUIRED 3

struct _coordinates {
   int X;
   int Y;
   int previousX;
   int previousY;
};

//declaring a variable to store the information about the players
struct _player {
    int numberOfArcs;
    int numberOfKPIPoints;
    int numberOfPublications;
    int numberOfCampuses;
    int numberOfG08s;
    int numberOfIPs;

    //number of each student stored in indexes corresponding to their #defined discipline
    int numStudents [NUMBER_OF_DISCIPLINES];

    //number of retraining centres, index coresponds to their #defined disciplines
    int retrainCentres [NUMBER_OF_DISCIPLINES];


    //We will also have another method of storing the exchange rate
};

typedef struct _game {
    //variables to store information about game state
    int currentTurn;
    int isLegalAction;
    int currentTurnValue;
    int currentPlayerTurn;
    int currentDiceValue;
    int currenthighestKPI;
    int winner;
    int regionDisciplines[NUM_REGIONS];
    int campuses[11][6];

    //*Currently undecided but we will have a method
    //of storing all the arcs and vertices and any campuses
    //that are on them.

    //variables to store information about players
    struct _player playerA;
    struct _player playerB;
    struct _player playerC;
} game;


Game newGame (int discipline[], int dice[]) {
   Game new = malloc(sizeof(game));
   return new;
}

void disposeGame (Game g) {
   free(g);
   
}
void makeAction (Game g, action a) {
}

void throwDice (Game g, int diceScore) {
}

int getDiceValue (Game g, int regionID) {
   return 2;
}


int getMostARCs(Game g){
    int A = g->playerA.numberOfArcs;
    int B = g->playerB.numberOfArcs;
    int C = g->playerC.numberOfArcs; //obtaining relevant info from stack

    int winner = NO_ONE; //stores uni with highest no. Arcs
    int temp = 0; //temp variable for algorithm
    int numArcs [NUM_UNIS] = {A,B,C}; //creating array with uni info

    //bubble sort algorithm
    //traverses through array and checks if the next number is bigger than the previous
    //if not, swaps those two numbers
    //keeps doing this till all numbers are in ascending order
    while (numArcs [2] < numArcs[1] || numArcs [1] < numArcs[0]){
        if(numArcs [1] < numArcs[0]){
            temp = numArcs[1];
            numArcs[1] = numArcs[0];
            numArcs[0] = temp;
        }

        if(numArcs [2] < numArcs[1]){
            temp = numArcs[2];
            numArcs[2] = numArcs[1];
            numArcs[1] = temp;
        }
    }
    //array has now been sorted

    //checks which uni the last number belongs to
    if (numArcs[2] == A){
        winner = UNI_A;
    }

    else if (numArcs[2] == B){
        winner = UNI_B;
    }

    else if (numArcs[2] == C){
        winner = UNI_C;
    }

    return winner;
}

int getMostPublications (Game g){
    int A = g->playerA.numberOfPublications;
    int B = g->playerB.numberOfPublications;
    int C = g->playerC.numberOfPublications; //obtaining relevant info from stack

    int winner = NO_ONE; //stores uni with highest no. Arcs
    int temp = 0; //temp variable for algorithm
    int numArcs [NUM_UNIS] = {A,B,C}; //creating array with uni info

    //bubble sort algorithm
    //traverses through array and checks if the next number is bigger than the previous
    //if not, swaps those two numbers
    //keeps doing this till all numbers are in ascending order
    while (numArcs [2] < numArcs[1] || numArcs [1] < numArcs[0]){
        if(numArcs [1] < numArcs[0]){
            temp = numArcs[1];
            numArcs[1] = numArcs[0];
            numArcs[0] = temp;
        }

        if(numArcs [2] < numArcs[1]){
            temp = numArcs[2];
            numArcs[2] = numArcs[1];
            numArcs[1] = temp;
        }
    }
    //array has now been sorted

    //checks which uni the last number belongs to
    if (numArcs[2] == A){
        winner = UNI_A;
    }

    else if (numArcs[2] == B){
        winner = UNI_B;
    }

    else if (numArcs[2] == C){
        winner = UNI_C;
    }

    return winner;
}

int getKPIpoints (Game g, int player){
    int retVal = 0;

    //checking which player is being requested and obtaining appropriate info
    if (player == UNI_A){
        retVal = g->playerA.numberOfKPIPoints;

    }else if (player == UNI_B){
        retVal = g->playerB.numberOfKPIPoints;

    }else{
        retVal = g->playerC.numberOfKPIPoints;
    }

    return retVal;
}

int getARCs (Game g, int player){
    int retVal = 0;

    //checking which player is being requested and obtaining appropriate info
    if (player == UNI_A){
        retVal = g->playerA.numberOfArcs;

    }else if (player == UNI_B){
        retVal = g->playerB.numberOfArcs;

    }else{
        retVal = g->playerC.numberOfArcs;
    }

    return retVal;
}

int getGO8s (Game g, int player){
    int retVal = 0;

    //checking which player is being requested and obtaining appropriate info
    if (player == UNI_A){
        retVal = g->playerA.numberOfG08s;

    }else if (player == UNI_B){
        retVal = g->playerB.numberOfG08s;

    }else{
        retVal = g->playerC.numberOfG08s;
    }

    return retVal;
}

int getCampuses (Game g, int player){
    int retVal = 0;

    //checking which player is being requested and obtaining appropriate info
    if (player == UNI_A){
        retVal = g->playerA.numberOfCampuses;

    }else if (player == UNI_B){
        retVal = g->playerB.numberOfCampuses;

    }else{
        retVal = g->playerC.numberOfCampuses;
    }

    return retVal;
}

int getIPs (Game g, int player){
    int retVal = 0;

    //checking which player is being requested and obtaining appropriate info
    if (player == UNI_A){
        retVal = g->playerA.numberOfIPs;

    }else if (player == UNI_B){
        retVal = g->playerB.numberOfIPs;

    }else{
        retVal = g->playerC.numberOfIPs;
    }

    return retVal;
}

int getPublications (Game g, int player){
    int retVal = 0;

    //checking which player is being requested and obtaining appropriate info
    if (player == UNI_A){
        retVal = g->playerA.numberOfPublications;

    }else if (player == UNI_B){
        retVal = g->playerB.numberOfPublications;

    }else{
        retVal = g->playerC.numberOfPublications;
    }

    return retVal;
}

int getStudents (Game g, int player, int discipline){
    int retVal = 0;

    //checking which player is being requested
    //returning the appropriate value stored in the array in the struct
    if (player == UNI_A){
        retVal = g->playerA.numStudents[discipline];

    }else if (player == UNI_B){
        retVal = g->playerA.numStudents[discipline];

    }else{
        retVal = g->playerA.numStudents[discipline];
    }

    return retVal;
}

int getExchangeRate (Game g, int player,int disciplineFrom, int disciplineTo){
    int rate = 0;

    //checking which player is being requested
    //if value in training centre array is anything other than zero, this uni has a
    //retraining centre for that discipline therefore they get the reduced rate.
    if (player == UNI_A){
        if(g->playerA.retrainCentres[disciplineFrom] == 0){
            rate = DEFAULT_RATE;

        }else{
            rate = REDUCED_RATE;
        }


    }else if (player == UNI_B){
        if(g->playerB.retrainCentres[disciplineFrom] == 0){
            rate = DEFAULT_RATE;

        }else{
            rate = REDUCED_RATE;
        }

    }else{
        if(g->playerC.retrainCentres[disciplineFrom] == 0){
            rate = DEFAULT_RATE;

        }else{
            rate = REDUCED_RATE;
        }
    }

    return rate;

}

int getDiscipline (Game g, int regionID) {
   int studentsProduced = (*g).regionDisciplines[regionID-1];
   return studentsProduced;
}

int getTurnNumber (Game g) {
   int turnNumber = (*g).currentTurnValue;
   return turnNumber;
}

int getWhoseTurn (Game g) {
   int currentPlayer = (*g).currentPlayerTurn;
   return currentPlayer;
}

int getCampus(Game g, path pathToVertex) {
   
   int position = 0;
   int tempX = 0;
   int tempY = 0;

   struct _coordinates point;
   int adjacentPoints[3][2];
   int validPoints[2][2];

   /*
   struct coordinates adjacentPoint1;
   struct coordinates adjacentPoint2;
   struct coordinates adjacentPoint3;
   */

   
   point.X = 2;
   point.Y = 10;
   point.previousX = 2;
   point.previousY = 11;

   while (pathToVertex[position] != 0) {
      if (pathToVertex[position] == 'B') {
         tempX = point.X;
         tempY = point.Y;
         point.X = point.previousX;
         point.Y = point.previousY;
         point.previousX = tempX;
         point.previousY = tempY;
      } else {
         adjacentPoints[0][0] = point.X;
         adjacentPoints[0][1] = point.Y + 1;
         adjacentPoints[1][0] = point.X;
         adjacentPoints[1][1] = point.Y - 1;
         if (point.X % 2 == point.Y % 2) {
            adjacentPoints[2][0] = point.X + 1;
            adjacentPoints[2][1] = point.Y;
         } else {
            adjacentPoints[2][0] = point.X - 1;
            adjacentPoints[2][1] = point.Y;
         }
      }
         
         /*
         adjacentPoint1.X = point.X;
         adjacentPoint1.Y = point.Y + 1;
         adjacentPoint2.X = point.X;
         adjacentPoint2.Y = point.Y - 1;
         if (point.X % 2 == point.Y % 2) {
            adjacentPoint3.X = point.X + 1;
            adjacentPoint3.Y = point.Y;
         } else {
            adjacentPoint3.X = point.X - 1;
            adjacentPoint3.Y = point.Y;
         }
         */
         
         int adjacentCounter = 0;
         int validCounter = 0;
         
         while (adjacentCounter < 3) {
            if (adjacentPoints[adjacentCounter][0] != point.previousX && adjacentPoints[adjacentCounter][1] != point.previousY) {
               validPoints[validCounter][0] = adjacentPoints[adjacentCounter][0];
               validPoints[validCounter][1] = adjacentPoints[adjacentCounter][1];
               validCounter++;
            }
            adjacentCounter++;
         }
         
         int playerFacingX = point.X - point.previousX;
         int playerFacingY = point.Y - point.previousY;
         
         struct _coordinates left;
         struct _coordinates right;
         
         if (playerFacingX > 0) {
            if (validPoints[0][1] < validPoints[1][1]) {
               right.X = validPoints[0][0];
               right.Y = validPoints[0][1];
               left.X = validPoints[1][0];
               left.Y = validPoints[1][1];
            } else {
               left.X = validPoints[0][0];
               left.Y = validPoints[0][1];
               right.X = validPoints[1][0];
               right.Y = validPoints[1][1];
            }
         } else if (playerFacingX < 0) {
            if (validPoints[0][1] < validPoints[1][1]) {
               left.X = validPoints[0][0];
               left.Y = validPoints[0][1];
               right.X = validPoints[1][0];
               right.Y = validPoints[1][1];
            } else {
               right.X = validPoints[0][0];
               right.Y = validPoints[0][1];
               left.X = validPoints[1][0];
               left.Y = validPoints[1][1];
            }
         } else if (playerFacingY > 0) {
            if (validPoints[0][0] < validPoints[1][0]) {
               left.X = validPoints[0][0];
               left.Y = validPoints[0][1];
               right.X = validPoints[1][0];
               right.Y = validPoints[1][1];
            } else {
               right.X = validPoints[0][0];
               right.Y = validPoints[0][1];
               left.X = validPoints[1][0];
               left.Y = validPoints[1][1];
            }
         } else {
               if (validPoints[0][0] < validPoints[1][0]) {
               right.X = validPoints[0][0];
               right.Y = validPoints[0][1];
               left.X = validPoints[1][0];
               left.Y = validPoints[1][1];
            } else {
               left.X = validPoints[0][0];
               left.Y = validPoints[0][1];
               right.X = validPoints[1][0];
               right.Y = validPoints[1][1];
            }
         }
         
         point.previousX = point.X;
         point.previousY = point.Y;
         
         if (pathToVertex[position] == 'L') {
            point.X = left.X;
            point.Y = left.Y;
         } else {
            point.X = right.X;
            point.Y = right.Y;
         }
      position++;
   }
   
   int campusID = (*g).campuses[point.X][point.Y];
   return campusID;
   
}

int getARC(Game g, path pathToEdge) {

   return UNI_A;
}

int isLegalAction(Game g, action a){
  //we have to change LegalAction once we get our coord system down
  //cos we will then have to test with the coord cases.
  int LegalAction = FALSE;
  int student = STUDENT_BPS;

    if (a.actionCode == PASS){
      LegalAction = TRUE;
    } else if (a.actionCode == BUILD_CAMPUS){

      int legalcounter = 0;
      student = STUDENT_BPS;
      if ((*g).currentTurn == UNI_A){
        while (student <= STUDENT_MTV){ //start at STUDENT_BPS ends at STUDENT_MTV
        if (g->playerA.numStudents[student] >= 1){
          legalcounter++;
        } else {
          //return LegalAction;
        }
        student++; //checkstudent
        }
      } else if ((*g).currentTurn == UNI_B){
        while (student <= STUDENT_MTV){ //start at STUDENT_BPS ends at STUDENT_MTV
        if (g->playerA.numStudents[student] >= 1){
          legalcounter++;
        } else {
          //return LegalAction;
        }
        student++; //checkstudent
        }
      } else if ((*g).currentTurn == UNI_C){
        while (student <= STUDENT_MTV){ //start at STUDENT_BPS ends at STUDENT_MTV
        if (g->playerA.numStudents[student] >= 1){
          legalcounter++;
        } else {
          //return LegalAction;
        }
        student++; //checkstudent
        }
      }
      //CHECKS FOR LEGAL
      if(legalcounter == 4){ //WE MUST CHANGE THIS WHEN WE GET COORD SYSTEM DOWN
            LegalAction = TRUE;
      } else {
            LegalAction = FALSE;
      }

    } else if (a.actionCode == BUILD_GO8){ // BUILD G08

    } else if (a.actionCode == OBTAIN_ARC){ // OBTAIN ARC
      int legalcounter = 0;

      student = STUDENT_BPS;
      if ((*g).currentTurn == UNI_A){
        while (student <= STUDENT_BQN){
          if (g->playerA.numStudents[student] >= 1){
            legalcounter++;
          } else {

          }
        student++;
        }
      }
/*
      } else if ((*g).currentTurn == UNI_B){
        while (student <= STUDENT_BQN){
          if (g->playerB.numStudents[discipline] >= 1){
            legalcounter++;
          } else {

          }
          student++;
        }

      } else if ((*g).currentTurn == UNI_C){
        while (student <= STUDENT_BQN){
          if (g->playerC.numStudents[discipline] >= 1){
            legalcounter++;
          } else {

          }
          student++;
        }

      } else {

      }
*/
      if (legalcounter == 2){
        LegalAction = TRUE;
      } else {

      }
    } else if (a.actionCode == START_SPINOFF){
      int legalcounter = 0;

      student = STUDENT_MJ;
      //g->playerA.numStudents[student] >= 1
      if ((*g).currentTurn == UNI_A){
        while (student <= STUDENT_MMONEY){
          if (g->playerA.numStudents[student] >= 1){
            legalcounter++;
          } else {

          }
        student++;
        }
      } else if ((*g).currentTurn == UNI_B){
        while (student <= STUDENT_MMONEY){
          if (g->playerB.numStudents[student] >= 1){
            legalcounter++;
          } else {

          }
        student++;
        }
      } else if ((*g).currentTurn == UNI_C){
        while (student <= STUDENT_MMONEY){
          if (g->playerC.numStudents[student] >= 1){
            legalcounter++;
          } else {

          }
        student++;
        }
      }
      if (legalcounter == 3){
        LegalAction = TRUE;
      } else {
        LegalAction = FALSE;
      }



    } else if (a.actionCode == OBTAIN_IP_PATENT){
        LegalAction = FALSE;  
    } else if (a.actionCode == OBTAIN_PUBLICATION){
        LegalAction = FALSE;
    } else if (a.actionCode == RETRAIN_STUDENTS){
        if(g->currentPlayerTurn == UNI_A){        
            if(g->playerA.numStudents[a.disciplineFrom] <= STUDENTS_REQUIRED){
                LegalAction = FALSE;
            }
        }

        if(g->currentPlayerTurn == UNI_B){        
            if(g->playerB.numStudents[a.disciplineFrom] <= STUDENTS_REQUIRED){
                LegalAction = FALSE;
            }
        }

        if(g->currentPlayerTurn == UNI_C){        
            if(g->playerC.numStudents[a.disciplineFrom] <= STUDENTS_REQUIRED){
                LegalAction = FALSE;
            }
        }
    }
  return LegalAction;
  }
