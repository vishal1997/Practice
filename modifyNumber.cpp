#include<iostream>
#include<cstring>
using namespace std;

class bit
{
    int M;
    int N;
    public:
    bit(int M, int N)
    {
        this->M=M;
        this->N=N;
    }
    int updateNumber(int i);
    int setNumber();
};

int bit::updateNumber(int i)
{
    M=M<<i;
    return M;
}

int bit::setNumber()
{
    N=N | M;
    return N;
}

int main()
{
    bit *num= new bit(19,32);
    cout<<num->updateNumber(2)<<endl;
    cout<<num->setNumber();
    return 0;
}
