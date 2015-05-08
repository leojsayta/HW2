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

//vector<vector<int>> allCombination(int k, int n);

bool diceContainAllSquares(const Die& d1, const Die& d2);

void solveByRecursion();
bool solveByRecursion(Die& d1, Die& d2);

void solveByIteration();

int SquaresbyRecursion = 0;
int SquaresbyIteration = 0;
int RecursiveCount = 0;
int IterativeCount = 0;

int main(int argc, const char *argv[]) 
{
    try
    {
        solveByRecursion();
        solveByIteration();
        
        // Have to divide by 2 b/c each particular set of 2 die values is represented twice:
        // For example: Die 1 = {0,4,5,6,7,8} & Die 2 = {1,2,3,4,5,6};
        // later Die 1 = {1,2,3,4,5,6} & Die 2 = {0,4,5,6,7,8}.  A partiuclar solution will
        // be represented twice.
        int actualSqrsByRec = SquaresbyRecursion;
        int actualSqrsbyIter = SquaresbyIteration;
        
        printf("Solving by recursion, the number of squares is: %d\n", actualSqrsByRec);
        printf("The number of recursive calls is: %d\n", RecursiveCount);
        
        printf("Solving by iteration, the number of squares is: %d\n", actualSqrsbyIter);
        printf("The number of iterations is: %d\n", IterativeCount);
        
    } 
    catch (exception &)
    {
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
    
    bool allSquares = diceContainAllSquares(d1, d2);
    
    if (allSquares)
    {
        SquaresbyRecursion++;
        
//        printf("Die 1: %d, %d, %d, %d, %d, %d\n",
//               d1.GetSide1(), d1.GetSide2(), d1.GetSide3(),
//               d1.GetSide4(), d1.GetSide5(), d1.GetSide6());
//        printf("Die 2: %d, %d, %d, %d, %d, %d\n\n",
//               d2.GetSide1(), d2.GetSide2(), d2.GetSide3(),
//               d2.GetSide4(), d2.GetSide5(), d2.GetSide6());
    }
    
    if (!d2.Increment())
    {
        if (!d1.Increment())
        {
            return false;
        }
        else
        {
            // reset d2
            //d2.SetDieSides();
            
            d2 = d1;
            if(!d2.Increment())     // Set d2 to d1++ to avoid finding dups
                return false;
            
        }
    }
    
    if (allSquares)
        return true;
    else
        return solveByRecursion(d1, d2);
}

void solveByRecursion()
{
    Die d1(5,4,3,2,1,0);
    Die d2(5,4,3,2,1,0);
    
    while (solveByRecursion(d1, d2));
}

/*
 In order to avoid repeated sets (and duplicates) of face numbers,
 we have to increment more than one side at a time.
 */
void solveByIteration()
{
    Die d1(5,4,3,2,1,0);
    Die d2(5,4,3,2,1,0);
    
    do
    {
        d2 = d1;        // Set d2 to d1++ to avoid finding dups
        d2.Increment();
        do
        {
            IterativeCount++;
            
            if (diceContainAllSquares(d1, d2))
            {
                SquaresbyIteration++;
                
                //                                                        printf("Die 1: %d, %d, %d, %d, %d, %d\n",
                //                                                               d1.GetSide1(), d1.GetSide2(), d1.GetSide3(),
                //                                                               d1.GetSide4(), d1.GetSide5(), d1.GetSide6());
                //                                                        printf("Die 2: %d, %d, %d, %d, %d, %d\n\n",
                //                                                               d2.GetSide1(), d2.GetSide2(), d2.GetSide3(),
                //                                                               d2.GetSide4(), d2.GetSide5(), d2.GetSide6());
            }
        }
        while (d2.Increment());
    }
    while (d1.Increment());
    
}

// Check die faces for squares below 100
bool diceContainAllSquares(const Die& d1, const Die& d2)
{
    const int numDiffSqrs = 8;
    int combos[numDiffSqrs][2] = { {0,1}, {0,4}, {0,6}, {1,6}, {2,5}, {3,6}, {4,6}, {8,1} };
    
    vector<int> v1 = d1.GetDieSides();
    vector<int> v2 = d2.GetDieSides();
    
    for (int j = 0; j < 6; j++)
    {
        if (v1[j] == 9) {
            v1[j] = 6;
        }
        
        if (v2[j] == 9) {
            v2[j] = 6;
        }
    }
    
    Die tmpD1 = Die(v1);
    Die tmpD2 = Die(v2);
    
    int valA = -1;
    int valB = -1;
    
    for (int i = 0; i < numDiffSqrs; i++)
    {
        valA = combos[i][0];
        valB = combos[i][1];

        if ( !(
               (tmpD1.ContainsNumber(valA) && tmpD2.ContainsNumber(valB))
               ||
               (tmpD2.ContainsNumber(valA) && tmpD1.ContainsNumber(valB))
               )
            )
        {
            return false;
        }
    }
    
    return true;
}

vector<vector<int>> allCombination(int k, int n)
{
    
    vector<vector<int>> combs = *new vector<vector<int>>();
    vector<int> comb = *new vector<int>();
    
    for (int i = 0; i < k; i++)
    {
        comb.push_back(i);
    }
    
    while (true)
    {
        combs.push_back(comb);
        //create new array with old solution
        comb = *new vector<int>(comb);
        
        //Substitute 9 with 6 in the last solution
        if (combs[combs.size() - 1][k - 1] == 9)
            combs[combs.size() - 1][k - 1] = 6;
        
        int i = k - 1;
        ++comb[i];
        while ( (i > 0) && (comb[i] >= n - k + 1 + i) )
        {
            --i;
            ++comb[i];
        }
        
        if (comb[0] > n - k)
            break;
        
        for (i = i + 1; i < k; ++i)
            comb[i] = comb[i - 1] + 1;
    }
    
    return combs;
}

