//Date : 08/05/2016
//Authors: Ramal Ratnayake, Anthony Vu, Justin Huynh & Edward Wu
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Game.h"


#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
                STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
                STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}

#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}



int main(int argc, char *argv[]) {
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    
    //test block 1
    Game g = newGame(disciplines, dice);
    assert(g != NULL);
    //testing inital state

    //testing the turn counter at the start
    assert (getWhoseTurn(g) == NO_ONE);
    
    //testing Campus locations
    char *test1 = "LRLRL";
    assert (getCampus(g, test1) == CAMPUS_C);
    char *test2 = "LRLRLRRLRL";
    assert (getCampus(g, test2) == CAMPUS_B);
    char *test3 = "LRRLRLRLRLR";
    assert (getCampus(g, test3) == CAMPUS_A);
    char *test4 = "RRLRL";    
    assert (getCampus(g, test4) == CAMPUS_B);
    char *test5 = "RRLRLLRLRL";
    assert (getCampus(g, test5) == CAMPUS_C);
    char *test6 = "L";
    assert (getCampus(g, test6) == VACANT_VERTEX);
    char *test7 = "R";
    assert (getCampus(g, test7) == VACANT_VERTEX);
    char *test8 = "LRL";
    assert (getCampus(g, test8) == VACANT_VERTEX);
    
    //testing ARC locations
    assert (getARC(g, test1) == VACANT_ARC);
    assert (getARC(g, test2) == VACANT_ARC);
    assert (getARC(g, test3) == VACANT_ARC);
    assert (getARC(g, test4) == VACANT_ARC);
    assert (getARC(g, test5) == VACANT_ARC);
    assert (getARC(g, test6) == VACANT_ARC);
    assert (getARC(g, test7) == VACANT_ARC);
    assert (getARC(g, test8) == VACANT_ARC);

    //testing KPI points
    assert (getKPIpoints (g, UNI_A) == 20);
    assert (getKPIpoints (g, UNI_B) == 20);
    assert (getKPIpoints (g, UNI_C) == 20); 

    //testing number of ARCs for each uni
    assert (getARCs (g, UNI_A) == 0);
    assert (getARCs (g, UNI_B) == 0);
    assert (getARCs (g, UNI_C) == 0);

    //trying stuff out
    //testing player turns through two cycles
    //during player B's turn, build 2 arcs & campus then test getCampus, KPI points, 
    //getArc and getArcs
    action test;
   
    throwDice(g,3);
    assert (getWhoseTurn(g) == UNI_A);

    throwDice(g,3);
    assert (getWhoseTurn(g) == UNI_B);
    //build first arc    
    test.actionCode = OBTAIN_ARC; 
    strcpy(test.destination, "RRLRL");
    makeAction (g, test);

    //build second arc    
    test.actionCode = OBTAIN_ARC;
    strcpy(test.destination, "RRLR"); 
    makeAction (g, test);

    //build another campus on those arcs   
    test.actionCode = BUILD_CAMPUS; 
    strcpy(test.destination, "RRL");
    makeAction (g, test);
    
    char testLocation [PATH_LIMIT] = "RRLRL"; 
    assert (getARC(g, testLocation) == ARC_B); //testing ARC ID
    
    strcpy(testLocation, "RRLR");
    assert (getARC(g, testLocation) == ARC_B); //testing ARC ID

    strcpy(testLocation, "RRL");
    assert (getCampus(g, testLocation) == CAMPUS_B); //testing campus ID

    assert (getKPIpoints (g, UNI_B) == 30); //testing increase in KPI points

    throwDice(g,3);
    assert (getWhoseTurn(g) == UNI_C);

    throwDice(g,3);
    assert (getWhoseTurn(g) == UNI_A);

    throwDice(g,3);
    assert (getWhoseTurn(g) == UNI_B);

    throwDice(g,3);
    assert (getWhoseTurn(g) == UNI_C);

    disposeGame (g);

//test block 2
 g = newGame(disciplines, dice);
    assert(g != NULL);

    // at the start, game state is TERRA_NULLIUS so it's nobody's turn
    assert(getTurnNumber(g) == -1);


	//testing for correct amount of students for each player
    assert(getStudents(g, UNI_A, STUDENT_MTV) == 1);
    assert(getStudents(g, UNI_A, STUDENT_MJ) == 1);
    assert(getStudents(g, UNI_A, STUDENT_BQN) == 3);
    assert(getStudents(g, UNI_A, STUDENT_BPS) == 3);
    assert(getStudents(g, UNI_A, STUDENT_THD) == 0);
    assert(getStudents(g, UNI_A, STUDENT_MMONEY) == 1);

    assert(getStudents(g, UNI_B, STUDENT_MTV) == 1);
    assert(getStudents(g, UNI_B, STUDENT_MJ) == 1);
    assert(getStudents(g, UNI_B, STUDENT_BQN) == 3);
    assert(getStudents(g, UNI_B, STUDENT_BPS) == 3);
    assert(getStudents(g, UNI_B, STUDENT_THD) == 0);
    assert(getStudents(g, UNI_B, STUDENT_MMONEY) == 1);

    assert(getStudents(g, UNI_C, STUDENT_MTV) == 1);
    assert(getStudents(g, UNI_C, STUDENT_MJ) == 1);
    assert(getStudents(g, UNI_C, STUDENT_BQN) == 3);
    assert(getStudents(g, UNI_C, STUDENT_BPS) == 3);
    assert(getStudents(g, UNI_C, STUDENT_THD) == 0);
    assert(getStudents(g, UNI_C, STUDENT_MMONEY) == 1);


	//tests for GO8
    /*assert(getGO8s(g, UNI_A) == 0);
    assert(getGO8s(g, UNI_B) == 0);
    assert(getGO8s(g, UNI_C) == 0);*/

	//tests for the IPS and PUBLICATIONS

    assert(getIPs(g, UNI_A) == 0);
    assert(getIPs(g, UNI_B) == 0);
    assert(getIPs(g, UNI_C) == 0);

    assert(getPublications(g, UNI_A) == 0);
    assert(getPublications(g, UNI_B) == 0);
    assert(getPublications(g, UNI_C) == 0);

	//tests for campuses
  /*  assert(getCampuses(g, UNI_A) == 2);
    assert(getCampuses(g, UNI_B) == 2);
    assert(getCampuses(g, UNI_C) == 2);*/

	//tests for ARCs
  /*  assert(getARCs(g, UNI_A) == 2);
    assert(getARCs(g, UNI_B) == 2);
    assert(getARCs(g, UNI_C) == 2);*/

	//tests for ExchangeRate
  //  assert(getg, UNI_A,

      int uni = UNI_A;

      while(uni <= UNI_C){
          assert(getKPIpoints(g,uni) == 20);
          assert(getARCs(g,uni) == 2);
          assert(getGO8s(g,uni) == 0);
          assert(getCampuses(g,uni) == 2);

          int discipline = STUDENT_BPS;
          while(discipline <= STUDENT_MMONEY){
               /*assert(getExchangeRate(g,uni,discipline,STUDENT_BPS) == 3);
               assert(getExchangeRate(g,uni,discipline,STUDENT_BQN) == 3);
               assert(getExchangeRate(g,uni,discipline,STUDENT_MJ) == 3);
               assert(getExchangeRate(g,uni,discipline,STUDENT_MTV) == 3);*/
               assert(getExchangeRate(g,uni,discipline,STUDENT_MMONEY) == 3);
               discipline++;
          }
          uni++;
      }


    throwDice(g, 11);

    // turn number is now 1. we have rolled 11
      assert(getTurnNumber(g) == 0);
    // player A has a campus at 11 which generates 1 MTV
    //testing for correct amount of students for each player
      assert(getStudents(g, UNI_A, STUDENT_MTV) == 2);
      assert(getStudents(g, UNI_A, STUDENT_MJ) == 1);
      assert(getStudents(g, UNI_A, STUDENT_BQN) == 3);
      assert(getStudents(g, UNI_A, STUDENT_BPS) == 3);
      assert(getStudents(g, UNI_A, STUDENT_THD) == 0);
      assert(getStudents(g, UNI_A, STUDENT_MMONEY) == 1);

      assert(getStudents(g, UNI_B, STUDENT_MTV) == 1);
      assert(getStudents(g, UNI_B, STUDENT_MJ) == 1);
      assert(getStudents(g, UNI_B, STUDENT_BQN) == 3);
      assert(getStudents(g, UNI_B, STUDENT_BPS) == 3);
      assert(getStudents(g, UNI_B, STUDENT_THD) == 0);
      assert(getStudents(g, UNI_B, STUDENT_MMONEY) == 1);

      assert(getStudents(g, UNI_C, STUDENT_MTV) == 1);
      assert(getStudents(g, UNI_C, STUDENT_MJ) == 1);
      assert(getStudents(g, UNI_C, STUDENT_BQN) == 3);
      assert(getStudents(g, UNI_C, STUDENT_BPS) == 3);
      assert(getStudents(g, UNI_C, STUDENT_THD) == 0);
      assert(getStudents(g, UNI_C, STUDENT_MMONEY) == 1);


  	//tests for GO8
      /*assert(getGO8s(g, UNI_A) == 0);
      assert(getGO8s(g, UNI_B) == 0);
      assert(getGO8s(g, UNI_C) == 0);*/

  	//tests for the IPS and PUBLICATIONS

      assert(getIPs(g, UNI_A) == 0);
      assert(getIPs(g, UNI_B) == 0);
      assert(getIPs(g, UNI_C) == 0);

      assert(getPublications(g, UNI_A) == 0);
      assert(getPublications(g, UNI_B) == 0);
      assert(getPublications(g, UNI_C) == 0);

  	//tests for campuses
    /*  assert(getCampuses(g, UNI_A) == 2);
      assert(getCampuses(g, UNI_B) == 2);
      assert(getCampuses(g, UNI_C) == 2);*/

  	//tests for ARCs
    /*  assert(getARCs(g, UNI_A) == 2);
      assert(getARCs(g, UNI_B) == 2);
      assert(getARCs(g, UNI_C) == 2);*/

  	//tests for ExchangeRate
    //  assert(getg, UNI_A,

      //  int uni = UNI_A;

        while(uni <= UNI_C){
            assert(getKPIpoints(g,uni) == 20);
            assert(getARCs(g,uni) == 2);
            assert(getGO8s(g,uni) == 0);
            assert(getCampuses(g,uni) == 2);

            int discipline = STUDENT_BPS;
            while(discipline <= STUDENT_MMONEY){
                 /*assert(getExchangeRate(g,uni,discipline,STUDENT_BPS) == 3);
                 assert(getExchangeRate(g,uni,discipline,STUDENT_BQN) == 3);
                 assert(getExchangeRate(g,uni,discipline,STUDENT_MJ) == 3);
                 assert(getExchangeRate(g,uni,discipline,STUDENT_MTV) == 3);*/
                 assert(getExchangeRate(g,uni,discipline,STUDENT_MMONEY) == 3);
                 discipline++;
            }
            uni++;
        }

       disposeGame (g);    

//test block 3
g = newGame (disciplines, dice);

    int regionID = 0;
    //while() loop tests all 19 (indeces 0-18) regions
    while (regionID < NUM_REGIONS) {
        
        assert (getDiscipline (g, regionID) == disciplines[regionID]);
        
        //similar to disciplines, a regionID corresponds to
        //an index of the DEFAULT_DICE array,
        //e.g. regionID 0 is dice value 9
        assert (getDiceValue (g, regionID) == dice[regionID]);

        regionID++;
    }

    //action test;

    //Initial
    assert (getMostARCs (g) == NO_ONE);
    assert (getMostPublications (g) == NO_ONE);
    assert (getTurnNumber (g) == -1);

    //Assuming player A starts first
    test.actionCode = OBTAIN_ARC;
    makeAction (g, test);
    assert (getMostARCs (g) == UNI_A);
   
    test.actionCode = PASS;
    makeAction (g, test);

    throwDice (g, 2);
    assert (getTurnNumber (g) == 0);
    
    test.actionCode = OBTAIN_ARC;
    makeAction (g, test);
    makeAction (g, test);
    
    test.actionCode = OBTAIN_PUBLICATION;
    makeAction (g, test);
    
    test.actionCode = PASS;
    makeAction (g, test);
    
    assert (getMostARCs (g) == UNI_B);
    assert (getMostPublications (g) == UNI_B);

    throwDice (g, 2);
    assert (getTurnNumber (g) == 1);

    test.actionCode = OBTAIN_ARC;
    makeAction (g, test);

    test.actionCode = OBTAIN_PUBLICATION;
    makeAction (g, test);
    makeAction (g, test);
    makeAction (g, test);

    assert (getMostARCs (g) == UNI_B); //Since UNI_B has 2 arcs
    assert (getMostPublications (g) == UNI_C);

    disposeGame (g);

    
    printf("All tests passed! You are awesome!");
return EXIT_SUCCESS;
} 


    
