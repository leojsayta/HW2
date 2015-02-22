
/*
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
    
    bool containsSix;
    
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
    
    Die()
    {
        this->dieSides = {-1};
        this->containsSix = false;
        this->CurrentSide = DieSide::One;
        this->CurrentDigit = -1;
    }
    
    Die(int side1, int side2, int side3, int side4, int side5, int side6)
    {
        Die();
        
        this->dieSides[0] = side1;
        this->dieSides[1] = side2;
        this->dieSides[2] = side3;
        this->dieSides[3] = side4;
        this->dieSides[4] = side5;
        this->dieSides[5] = side6;   
   
    }
    
    Die(vector<int> sides)
    {
        Die();

        if (sides.empty())
            this->dieSides = {-1};
        else
            SetDieSides(sides);
    }
    
    ~Die()
    {
    
    }
    
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
   
    bool ContainsSix() const 
    {
        return this->containsSix;
    }

    bool ContainsNumber(int num)
    {
        return this->checkForDigit(num);
    }
    
    int GetCurrentSidesInteger()
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
    
    int IncrementCurrentSidesDigit()
    {
        if (this->CurrentDigit == 8)
            this->CurrentDigit = 0;
        else
            this->CurrentDigit++;

        return this->CurrentDigit;
    }
    
    DieSide IncrementSide()
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
    
 
    
};
*/


/*
template< typename T >
class Enum {
public:

    class Iterator {
    public:

        Iterator(int value) :
        m_value(value) {
        }

        T operator*(void) const {
            return (T) m_value;
        }

        void operator++(void) {
            ++m_value;
        }

        bool operator!=(Iterator rhs) {
            return m_value != rhs.m_value;
        }

    private:
        int m_value;
    };

};

template< typename T >
typename Enum<T>::Iterator begin(Enum<T>) {
    return typename Enum<T>::Iterator((int) T::First);
}

template< typename T >
typename Enum<T>::Iterator end(Enum<T>) {
    return typename Enum<T>::Iterator(((int) T::Last) + 1);
}

 */

