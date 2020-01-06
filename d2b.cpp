#include <iostream>
#define max 10
using namespace std;
class d2b
{
int num;
int top,stk[max];
public:
d2b() { top=-1; }
void read()
{
	cout<<"Enter The Number ";
	cin>>num;
}
void push(int ele)
{
	if(top==(max-1))
	{
		cout<<"STACK OVER FLOW\n";
	}
	else
	{
		top=top+1;
		stk[top]=ele;
	}
}
void display()
{
	cout<<"Array ";
	for(int i=top;i>-1;i--){
	cout<<stk[i];}
	cout<<"\n";
}

void function()
{
	int rem;
	while(num>0)
	{
		rem=num%2;
		push(rem);
		num=num/2;
	}
}
};
int main()
{
	d2b n1;
	n1.read();
	n1.function();
	n1.display();
	return 0;
}

