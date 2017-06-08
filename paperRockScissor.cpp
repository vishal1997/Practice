#include<iostream>

using namespace std;

class Weapon
{
protected:
    int strength;
    char type;
public:
    int modified;

    virtual int return_strength()
    {
        return strength;
    }

    virtual char return_type()
    {
        return type;
    }

    void setPower (int val)
    {
        strength = val;
        return;
    }
};



class Rock: public Weapon
{

public:
    Rock()
    {
        type='r';
    }
    bool battle(Weapon w)
    {
        //Write your solution code below this line
        char type=w.return_type();
        if(type=='s') {
            return 0.5*w.return_strength() < 2*return_strength();
        }
        //default return statement below
        else if(type=='p') {
            return 0.5 * return_strength() > 2* w.return_strength();
        }
        //remove the default return statement and return your own result

    }

};

class Paper: public Weapon
{

public:
    Paper()
    {
        type='p';
    }
    bool battle(Weapon w)
    {
        //Write your solution code below this line

        //Write your solution code below this line
        char type=w.return_type();
        if(type=='s') {
            return 0.5*return_strength() > 2*w.return_strength();
        }
        //default return statement below
        else if(type=='r') {
            return 2 * return_strength() > 0.5* w.return_strength();
        }

    }

};

class Scissors: public Weapon
{

public:
    Scissors()
    {
        type='s';
    }
    bool battle(Weapon w)
    {
        //Write your solution code below this line

        //Write your solution code below this line
        char type=w.return_type();
        if(type=='r') {
            return 0.5*return_strength() > 2*w.return_strength();
        }
        //default return statement below
        else if(type=='p') {
            return 0.5 * w.return_strength() < 2* return_strength();
        }


    }

};


int main() {
    Rock r;
    Scissors s;
    Paper p;
    //for(int i=0;i<3;i++) {
        int val;
        //cin>>val;
        r.setPower(953);
        //cin>>val;
        p.setPower(85);
        s.setPower(464);
        //cin>>val;

        cout<<"\n"<<r.battle(p);
        cout<<"\n"<<p.battle(s);
        cout<<"\n"<<s.battle(r);

    //}
}
