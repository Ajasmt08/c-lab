#include <iostream>
using namespace std;
class abc
{
    protected:
    int a,b;
    public:
    void read()
    {
        cout<<"abc::Enter 2 Numbers\n";
        cin>>a>>b; 
    }
};
class xyz:public abc
{
    protected:
    int c,d,sum;
    public :
    void read()
    {
        cout<<"xyz::enter 2 numbers \n";
        cin>>c>>d;
    }
    void display()
    {
        cout<<"The sum is "<<sum<<endl;
    }
    friend void calc(xyz cal);
};
void calc(xyz cal)
{
    cal.abc::read();
    cal.read();
    cal.sum=cal.a+cal.b+cal.c+cal.d;
    cal.display();
}
int main()
{
    xyz w;
    calc(w);
    return 0;
}