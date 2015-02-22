

#include "HW2Classes.h"

// I could not figure this class separation stuff

Die::Die()
{
    this->dieSides = {5,4,3,2,1,0};
    this->CurrentSide = DieSide::One;
}

Die::Die(int side1, int side2, int side3, int side4, int side5, int side6)
{
    Die();

    this->dieSides[0] = side1;
    this->dieSides[1] = side2;
    this->dieSides[2] = side3;
    this->dieSides[3] = side4;
    this->dieSides[4] = side5;
    this->dieSides[5] = side6;   

}

Die::Die(vector<int> sides)
{
    Die();

    if (sides.empty())
        this->dieSides = {5,4,3,2,1,0};
    else
        SetDieSides(sides);
}

Die::~Die(){}

bool Die::ContainsNumber(int num)
{
    return this->checkForDigit(num);
}

int Die::GetCurrentSidesInteger()
{
    switch (this->CurrentSide)
    {
        case DieSide::One:
            return this->GetSide1();
            //break;
        case DieSide::Two:
            return this->GetSide2();
            //break;
        case DieSide::Three:
            return this->GetSide3();
            //break;
        case DieSide::Four:
            return this->GetSide4();
            //break;
        case DieSide::Five:
            return this->GetSide5();
            //break;
        case DieSide::Six:
            return this->GetSide6();
            //break;
        default:
            return -1;
            break;
    }

    return -1;
}

int Die::IncrementCurrentSidesDigit()
{
    if (this->CurrentDigit == 8)
        this->CurrentDigit = 0;
    else
        this->CurrentDigit++;

    return this->CurrentDigit;
}

DieSide Die::IncrementSide()
{
    switch (this->CurrentSide)
    {
        case DieSide::One:
            this->CurrentSide = DieSide::Two;
            break;
        case DieSide::Two:
            this->CurrentSide = DieSide::Three;
            break;
        case DieSide::Three:
            this->CurrentSide = DieSide::Four;
            break;
        case DieSide::Four:
            this->CurrentSide = DieSide::Five;
            break;
        case DieSide::Five:
            this->CurrentSide = DieSide::Six;
            break;
        case DieSide::Six:
            this->CurrentSide = DieSide::One;
            break;
        default:
            //return -1;
            break;
    }

    return this->CurrentSide;
}
