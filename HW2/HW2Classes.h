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
    
    
// Represents one particular die and the integer value of that die's six sides
class Die
{
    
private:
    
    // Underlying representation of die is a vector with six indeces
    vector<int> dieSides = {5,4,3,2,1,0};
    
    // Is 'num' displayed on one of this die's six faces?
    bool checkForDigit(int num) const
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
    
    Die(const Die& orig);
   
    ~Die();
    
    vector<int> GetDieSides() const
    {
        return dieSides;
    }
    
    void SetDieSides(vector<int> dieSides = {5,4,3,2,1,0})
    {
        this->dieSides = dieSides;
    }

    int GetSide1() const
    {
        return this->dieSides[0];
    }
    int SetSide1(int num) 
    {
        this->dieSides[0] = num;
        return this->dieSides[0];
    }
    
    int GetSide2() const
    {
        return this->dieSides[1];
    }
    int SetSide2(int num) 
    {
        this->dieSides[1] = num;
        return this->dieSides[1];
    }
    
    int GetSide3() const
    {
        return this->dieSides[2];
    }
    int SetSide3(int num) 
    {
        this->dieSides[2] = num;
        return this->dieSides[2];
    }
    
    int GetSide4() const
    {
        return this->dieSides[3];
    }
    int SetSide4(int num) 
    {
        this->dieSides[3] = num;
        return this->dieSides[3];
    }

    int GetSide5() const
    {
        return this->dieSides[4];
    }
    int SetSide5(int num) 
    {
        this->dieSides[4] = num;
        return this->dieSides[4];
    }

    int GetSide6() const 
    {
        return this->dieSides[5];
    }
    int SetSide6(int num) 
    {
        this->dieSides[5] = num;
        return this->dieSides[5];
    }
   
    bool ContainsNumber(int num) const;
    
    int GetCurrentSidesInteger();
   
    int IncrementCurrentSidesDigit();
    
    DieSide IncrementSide();
    
    bool Increment();
    
};

#endif	/* HW2CLASSES_H */
