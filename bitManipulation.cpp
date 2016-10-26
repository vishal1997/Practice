#include<iostream>
using namespace std;

class bit
{
    int num;
    public:
    bit(int num)
    {
        this->num=num;
    }
    int setBit(int i);
    int clearBit(int i);
    bool getBit(int i);
};

int bit::clearBit(int i)
{
    int mask=~(1<<i);
    num=num & mask;
    return num;
}

int bit::setBit(int i)
{
    num=num | (1<<i);
    return num;
}

bool bit::getBit(int i)
{
    return ((num & (1<<i))!=0);
}

int main()
{
    cout<<"Enter a number:";
    int num;
    cin>>num;
    cout<<endl<<"Enter a position";
    int position;
    cin>>position;
    bit *b=new bit(num);
    int value=b->getBit(position-1);
    if(value)
        cout<<endl<<b->clearBit(position-1);
    else
        cout<<endl<<b->setBit(position-1);
    return 0;
}
