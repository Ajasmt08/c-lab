#include <iostream>
using namespace std;
class mean
{
    int a[100],n,avg=0;
    public :
    void read()
    {
    cout<<"Enter the Size of Array ";
    cin>>n;
    cout<<"Enter the Array ";
    for(int i=0;i<n;i++)
    cin>>a[i];
    }
    void display()
    {
    cout<<"The Mean Value is "<<avg<<endl;
    }
    friend void meanval(mean t);
};
void meanval(mean t)
{
    int sum=0;
    for(int i=0;i<t.n;i++){
    sum=sum+t.a[i];}
    t.avg=sum/t.n;
    t.display();
}
int main()
{
    mean m1;
    m1.read();
    meanval(m1);
    m1.display();
    return 0;
    
}