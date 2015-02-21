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

bool diceContainAllSquares(const Die d1, const Die d2);

void solveByRecursion(Die d1, Die d2);

void solveByIteration(Die d1, Die d2);

int SetCountbyRecursion = 0;
int SetCountbyIteration = 0;

Die d1, d2;

int main(int argc, const char *argv[]) 
{
    d1 = Die(5,4,3,2,1,0);
    d2 = Die(5,4,3,2,1,0);
    
    try 
    {
        solveByRecursion(d1, d2);
        printf("The number of squares is: %d", SetCountbyRecursion);
        //solveByIteration(d1, d2);
        
    } 
    catch (exception &) 
    {
        printf("\nSomething went wrong!  Please start over.");
        return -1;
    }

    return 0;
}

void solveByRecursion(Die d1, Die d2) 
{
    if (diceContainAllSquares(d1, d2))
        SetCountbyRecursion++;
    
    if (d2.GetSide1() < 8) 
    {
        d2.SetSide1(d2.GetSide1() + 1);
        solveByRecursion(d1, d2);
    } 
    else if (d2.GetSide2() < 7) 
    {
        d2.SetSide2(d2.GetSide2() + 1);
        solveByRecursion(d1, d2);
    } 
    else if (d2.GetSide3() < 6) 
    {
        d2.SetSide3(d2.GetSide3() + 1);
        solveByRecursion(d1, d2);
    } 
    else if (d2.GetSide4() < 5) 
    {
        d2.SetSide4(d2.GetSide4() + 1);
        solveByRecursion(d1, d2);
    } 
    else if (d2.GetSide5() < 4) 
    {
        d2.SetSide5(d2.GetSide5() + 1);
        solveByRecursion(d1, d2);
    } 
    else if (d2.GetSide6() < 3) 
    {
        d2.SetSide6(d2.GetSide6() + 1);
        solveByRecursion(d1, d2);
    }
    else
    {
        d2.SetDieSides(vector<int> {5,4,3,2,1,0});
        
        if (d1.GetSide1() < 8) 
        {
            d1.SetSide1(d1.GetSide1() + 1);
            solveByRecursion(d1, d2);
        } 
        else if (d1.GetSide2() < 7) 
        {
            d1.SetSide2(d1.GetSide2() + 1);
            solveByRecursion(d1, d2);
        } 
        else if (d1.GetSide3() < 6) 
        {
            d1.SetSide3(d1.GetSide3() + 1);
            solveByRecursion(d1, d2);
        } 
        else if (d1.GetSide4() < 5) 
        {
            d1.SetSide4(d1.GetSide4() + 1);
            solveByRecursion(d1, d2);
        } 
        else if (d1.GetSide5() < 4) 
        {
            d1.SetSide5(d1.GetSide5() + 1);
            solveByRecursion(d1, d2);
        } 
        else if (d1.GetSide6() < 3) 
        {
            d1.SetSide6(d1.GetSide6() + 1);
            solveByRecursion(d1, d2);
        }
        else
        {
            return;
        }
    }
    
}

void solveByIteration(Die d1, Die d2) 
{
    if (d1.GetSide1() == 8 &&
        d1.GetSide2() == 7 &&
        d1.GetSide3() == 6 &&
        d1.GetSide4() == 5 &&
        d1.GetSide5() == 4 &&
        d1.GetSide6() == 3)
        
        
        
        return;
    else
    {
        for(int sd : d1.GetDieSides())
        {
            
        }
    }
}

bool diceContainAllSquares(Die d1, Die d2) 
{
    if (!
         ((d1.ContainsNumber(0) && d2.ContainsNumber(1) && d2.ContainsNumber(4) && d2.ContainsNumber(6))
         || 
         (d2.ContainsNumber(0) && d1.ContainsNumber(1) && d1.ContainsNumber(4) && d1.ContainsNumber(6)))   
       )
        return false;
    
    if (!
         ((d1.ContainsNumber(1) && d2.ContainsNumber(6))
         || 
         (d2.ContainsNumber(1) && d1.ContainsNumber(6)))   
       )
        return false;
    
    if (!
         ((d1.ContainsNumber(2) && d2.ContainsNumber(5))
         || 
         (d2.ContainsNumber(2) && d1.ContainsNumber(5)))   
       )
        return false;
    
    if (!
         ((d1.ContainsNumber(3) && d2.ContainsNumber(6))
         || 
         (d2.ContainsNumber(3) && d1.ContainsNumber(6)))   
       )
        return false;
    
    if (!
         ((d1.ContainsNumber(4) && d2.ContainsNumber(6))
         || 
         (d2.ContainsNumber(4) && d1.ContainsNumber(6)))   
       )
        return false;
    
    if (!
         ((d1.ContainsNumber(8) && d2.ContainsNumber(1))
         || 
         (d2.ContainsNumber(8) && d1.ContainsNumber(1)))   
       )
        return false;
    
    return true;

}