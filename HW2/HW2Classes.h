/* 
 * File:   HW2Classes.h
 * Author: Joel Atyas
 *
 * Created on February 16, 2015, 5:01 PM
 */

#ifndef HW2CLASSES_H
#define	HW2CLASSES_H

#include <iostream>
#include <string.h>
#include <exception>
#include <vector>

using namespace std;

enum class DieSide {
        One = 0, 
        Two = 1, 
        Three = 2, 
        Four = 3, 
        Five = 4, 
        Six = 5};
    
    

class Die
{
    
private:
    
    vector<int> dieSides = {5,4,3,2,1,0};
    
    bool checkForDigit(int num)
    {
        for(int i = 0; i < this->dieSides.size(); i++)
        {
            if (this->dieSides[i] == num)
                return true;
        }
    
        return false;
    }
    
public:
    
    DieSide CurrentSide;
    
    int CurrentDigit;
    
    Die();
    
    Die(int side1, int side2, int side3, int side4, int side5, int side6);
    
    Die(vector<int> sides);
   
    ~Die();
    
    vector<int> GetDieSides()
    {
        return dieSides;
    }
    
    void SetDieSides(vector<int> dieSides)
    {
        this->dieSides.clear();
        this->dieSides = dieSides;
    }

    int GetSide1() 
    {
        return this->dieSides[0];
    }
    int SetSide1(int num) 
    {
        this->dieSides[0] = num;
        return this->dieSides[0];
    }
    
    int GetSide2()
    {
        return this->dieSides[1];
    }
    int SetSide2(int num) 
    {
        this->dieSides[1] = num;
        return this->dieSides[1];
    }
    
    int GetSide3()
    {
        return this->dieSides[2];
    }
    int SetSide3(int num) 
    {
        this->dieSides[2] = num;
        return this->dieSides[2];
    }
    
    int GetSide4() 
    {
        return this->dieSides[3];
    }
    int SetSide4(int num) 
    {
        this->dieSides[3] = num;
        return this->dieSides[3];
    }

    int GetSide5() 
    {
        return this->dieSides[4];
    }
    int SetSide5(int num) 
    {
        this->dieSides[4] = num;
        return this->dieSides[4];
    }

    int GetSide6() 
    {
        return this->dieSides[5];
    }
    int SetSide6(int num) 
    {
        this->dieSides[5] = num;
        return this->dieSides[5];
    }
   
    bool ContainsNumber(int num);
    
    int GetCurrentSidesInteger();
   
    int IncrementCurrentSidesDigit();
    
    DieSide IncrementSide();
    
};

#endif	/* HW2CLASSES_H */
