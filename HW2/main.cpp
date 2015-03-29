//
//  main.cpp
//  Euler Problem 90
//
//  Created by Joel Atyas on 1/25/15.
//  Copyright (c) 2015 Joel Atyas. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <exception>
#include <array>
#include <vector>
#include "HW2Classes.h"

using namespace std;

bool diceContainAllSquares(const Die& d1, const Die& d2);

void solveByRecursion();
bool solveByRecursion(Die& d1, Die& d2);

void solveByIteration();

int SetCountbyRecursion = 0;
int SetCountbyIteration = 0;
int RecursiveCount = 0;
int IterativeCount = 0;

int main(int argc, const char *argv[]) 
{    
    try
    {
        solveByRecursion();
        printf("Solving by recursion, the number of squares is: %d\n", SetCountbyRecursion);
        printf("The number of recursive calls is: %d\n", RecursiveCount);
        
        solveByIteration();
        printf("Solving by iteration, the number of squares is: %d\n", SetCountbyIteration);
        printf("The number of iterations is: %d\n", IterativeCount);
    } 
    catch (exception &)
    {
        printf("\nSomething went wrong!  Please start over.");
        return -1;
    }

    return 0;
}

/*
 In order to avoid repeated sets (and duplicates) of face numbers,
 we have to increment more than one side at a time.
 */
bool solveByRecursion(Die& d1, Die& d2)
{
    RecursiveCount++;
    
    if (diceContainAllSquares(d1, d2))
    {
//        SetCountbyRecursion++;
        
//        printf("Die 1: %d, %d, %d, %d, %d, %d\n",
//               d1.GetSide1(), d1.GetSide2(), d1.GetSide3(),
//               d1.GetSide4(), d1.GetSide5(), d1.GetSide6());
//        printf("Die 2: %d, %d, %d, %d, %d, %d\n\n",
//               d2.GetSide1(), d2.GetSide2(), d2.GetSide3(),
//               d2.GetSide4(), d2.GetSide5(), d2.GetSide6());
        if (!d2.Increment())
        {
            if (!d1.Increment())
            {
                return false;
            }
        }
        
        return true;
    }
    else
    {
        if (!d2.Increment())
        {
            if (!d1.Increment())
            {
                return false;
            }
            else
            {
                // reset d2
                d2.SetDieSides(vector<int>{5,4,3,2,1,0});
            }
        }
        
        return solveByRecursion(d1, d2);
    }
    
//    if (d2.GetSide1() < 8)
//    {
//        d2.SetSide1(d2.GetSide1() + 1);
//        
//        return solveByRecursion(d1, d2);
//    } 
//    else if (d2.GetSide2() < 7) 
//    {
//        d2.SetSide2(d2.GetSide2() + 1);
//        
//        d2.SetSide1(d2.GetSide2() + 1);
//        
//        return solveByRecursion(d1, d2);
//    } 
//    else if (d2.GetSide3() < 6) 
//    {
//        d2.SetSide3(d2.GetSide3() + 1);
//        
//        d2.SetSide2(d2.GetSide3() + 1);
//        d2.SetSide1(d2.GetSide2() + 1);
//        
//        return solveByRecursion(d1, d2);
//    } 
//    else if (d2.GetSide4() < 5) 
//    {
//        d2.SetSide4(d2.GetSide4() + 1);
//        
//        d2.SetSide3(d2.GetSide4() + 1);
//        d2.SetSide2(d2.GetSide3() + 1);
//        d2.SetSide1(d2.GetSide2() + 1);
//        
//        return solveByRecursion(d1, d2);
//    } 
//    else if (d2.GetSide5() < 4) 
//    {
//        d2.SetSide5(d2.GetSide5() + 1);
//        
//        d2.SetSide4(d2.GetSide5() + 1);
//        d2.SetSide3(d2.GetSide4() + 1);
//        d2.SetSide2(d2.GetSide3() + 1);
//        d2.SetSide1(d2.GetSide2() + 1);
//        
//        return solveByRecursion(d1, d2);
//    } 
//    else if (d2.GetSide6() < 3) 
//    {
//        d2.SetSide6(d2.GetSide6() + 1);
//        
//        d2.SetSide5(d2.GetSide6() + 1);
//        d2.SetSide4(d2.GetSide5() + 1);
//        d2.SetSide3(d2.GetSide4() + 1);
//        d2.SetSide2(d2.GetSide3() + 1);
//        d2.SetSide1(d2.GetSide2() + 1);
//        
//        return solveByRecursion(d1, d2);
//    }
//    else if (d1.GetSide1() < 8)
//    {
//        d1.SetSide1(d1.GetSide1() + 1);
//        
//        // reset d2
//        d2.SetDieSides(vector<int>{5,4,3,2,1,0});
//        
//        return solveByRecursion(d1, d2);
//    } 
//    else if (d1.GetSide2() < 7) 
//    {
//        d1.SetSide2(d1.GetSide2() + 1);
//        
//        d1.SetSide1(d1.GetSide2() + 1);
//        
//        // reset d2
//        d2.SetDieSides(vector<int>{5,4,3,2,1,0});
//        
//        return solveByRecursion(d1, d2);
//    } 
//    else if (d1.GetSide3() < 6) 
//    {
//        d1.SetSide3(d1.GetSide3() + 1);
//        
//        d1.SetSide2(d1.GetSide3() + 1);
//        d1.SetSide1(d1.GetSide2() + 1);
//        
//        // reset d2
//        d2.SetDieSides(vector<int>{5,4,3,2,1,0});
//        
//        return solveByRecursion(d1, d2);
//    } 
//    else if (d1.GetSide4() < 5) 
//    {
//        d1.SetSide4(d1.GetSide4() + 1);
//        
//        d1.SetSide3(d1.GetSide4() + 1);
//        d1.SetSide2(d1.GetSide3() + 1);
//        d1.SetSide1(d1.GetSide2() + 1);
//        
//        // reset d2
//        d2.SetDieSides(vector<int>{5,4,3,2,1,0});
//        
//        return solveByRecursion(d1, d2);
//    } 
//    else if (d1.GetSide5() < 4) 
//    {
//        d1.SetSide5(d1.GetSide5() + 1);
//        
//        d1.SetSide4(d1.GetSide5() + 1);
//        d1.SetSide3(d1.GetSide4() + 1);
//        d1.SetSide2(d1.GetSide3() + 1);
//        d1.SetSide1(d1.GetSide2() + 1);
//        
//        // reset d2
//        d2.SetDieSides(vector<int>{5,4,3,2,1,0});
//        
//        return solveByRecursion(d1, d2);
//    } 
//    else if (d1.GetSide6() < 3) 
//    {
//        d1.SetSide6(d1.GetSide6() + 1);
//        
//        d1.SetSide5(d1.GetSide6() + 1);
//        d1.SetSide4(d1.GetSide5() + 1);
//        d1.SetSide3(d1.GetSide4() + 1);
//        d1.SetSide2(d1.GetSide3() + 1);
//        d1.SetSide1(d1.GetSide2() + 1);
//        
//        // reset d2
//        d2.SetDieSides(vector<int>{5,4,3,2,1,0});
//        
//        return solveByRecursion(d1, d2);
//    }
//    else
//    {
//        return false;
//    }
}

void solveByRecursion()
{
    Die d1(5,4,3,2,1,0);
    Die d2(5,4,3,2,1,0);
    
    while (solveByRecursion(d1, d2))
    {
        SetCountbyRecursion++;
        
    }
}

/*
 In order to avoid repeated sets (and duplicates) of face numbers,
 we have to increment more than one side at a time.
 */
void solveByIteration()
{
    int d1s6 = 0;
    int d1s5 = 1;
    int d1s4 = 2;
    int d1s3 = 3;
    int d1s2 = 4;
    int d1s1 = 5;
    
    int d2s6 = 0;
    int d2s5 = 1;
    int d2s4 = 2;
    int d2s3 = 3;
    int d2s2 = 4;
    int d2s1 = 5;
    
// Die 1
    for (d1s6 = 0; d1s6 <= 3; d1s6++)
    {
        for (d1s5 = (d1s6 + 1); d1s5 <= 4; d1s5++)
        {
            for (d1s4 = (d1s5 + 1); d1s4 <= 5; d1s4++)
            {
                for (d1s3 = (d1s4 + 1); d1s3 <= 6; d1s3++)
                {
                    for (d1s2 = (d1s3 + 1); d1s2 <= 7; d1s2++)
                    {
                        for (d1s1 = (d1s2 + 1); d1s1 <= 8; d1s1++)
                        {
// Die 2
                            for (d2s6 = 0; d2s6 <= 3; d2s6++)
                            {
                                for (d2s5 = (d2s6 + 1); d2s5 <= 4; d2s5++)
                                {
                                    for (d2s4 = (d2s5 + 1); d2s4 <= 5; d2s4++)
                                    {
                                        for (d2s3 = (d2s4 + 1); d2s3 <= 6; d2s3++)
                                        {
                                            for (d2s2 = (d2s3 + 1); d2s2 <= 7; d2s2++)
                                            {
                                                for (d2s1 = (d2s2 + 1); d2s1 <= 8; d2s1++)
                                                {
                                                    IterativeCount++;
                                                    
                                                    Die d1 = Die(d1s1, d1s2, d1s3, d1s4, d1s5, d1s6);
                                                    Die d2 = Die(d2s1, d2s2, d2s3, d2s4, d2s5, d2s6);
                                                    
                                                    if (diceContainAllSquares(d1, d2))
                                                    {
                                                        SetCountbyIteration++;
                                                        
//                                                        printf("Die 1: %d, %d, %d, %d, %d, %d\n",
//                                                               d1.GetSide1(), d1.GetSide2(), d1.GetSide3(),
//                                                               d1.GetSide4(), d1.GetSide5(), d1.GetSide6());
//                                                        printf("Die 2: %d, %d, %d, %d, %d, %d\n\n",
//                                                               d2.GetSide1(), d2.GetSide2(), d2.GetSide3(),
//                                                               d2.GetSide4(), d2.GetSide5(), d2.GetSide6());
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
// Die 2
                        }
                    }
                }
            }
        }
    }
// Die 1
}

// Check die faces for squares below 100
bool diceContainAllSquares(const Die& d1, const Die& d2)
{
    int combos[9][2] = { {0,1}, {0,4}, {0,6}, {1,6}, {2,5}, {3,6},{4,6}, {6,4}, {8,1} };
    
    for (int i = 0; i < 9; i++)
    {
        if (
            !( (d1.ContainsNumber(combos[i][0]) && d2.ContainsNumber(combos[i][1]))
              ||
               (d2.ContainsNumber(combos[i][0]) && d1.ContainsNumber(combos[i][1]))) )
        {
            return false;
        }
    }
    
    return true;
}