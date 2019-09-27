#include <iostream>
using namespace std;
class accademic
{
    int rollno;
    char name[10];
    int m[5];
    int total;
    public:
    void read()
    {
        cout<<"Enter the Roll No : ";
        cin>>rollno;
        cout<<"Enter the Name    : ";
        cin>>name;
        cout<<"Enter the 5 Marks \n";
        for(int i=0;i<5;i++){
        cin>>m[i];}
        acctotal();
    }
    int acctotal()
    {
        total=0;
        for(int i=0;i<5;i++){
            total=total+m[i];
        }
        return total;
    }
    void display()
    {
        cout<<"NAME                 : "<<name<<endl;
        cout<<"ROLL.NO              : "<<rollno<<endl;
        cout<<"Total Accademic Mark : "<<acctotal()<<endl;
    }
};
class special
{
    int sports;
    int arts;
    int grace;
    public :
    void read()
    {
        cout<<"Enter Mark In Sports ";
        cin>>sports;
        cout<<"Enter Mark in Arts ";
        cin>>arts;
    }
    int spectotal()
    {
        grace=sports+arts;
        return grace;
    }
    void display()
    {
        cout<<"Grace Marks Scored     :"<<grace<<endl;
    }
};
class student:public accademic,public special
{
    int totalmark;
    public :
    void read()
    {
        accademic::read();
        special::read();
        studentmark();
    }
    int studentmark()
    {
        return totalmark=acctotal()+spectotal();
    }
    void display()
    {
        accademic::display();
        special::display();
        cout<<"Total Mark        : "<<studentmark();
    }
};
int main()
{
    student s1;
    s1.read();
    s1.display();
    return 0;
    
}