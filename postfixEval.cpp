#include <iostream>
#include <stdlib.h>
#include <ctype.h>
using namespace std;
#define max 20
class postfix
{
	int stk[max],top;
	char a[20];
	public:
	postfix() { top=-1; }
	void push(int r)
	{
		if(top==max-1)
		{
			cout<<"Stack Over Flow\n";
		}
		else
		{
			top=top+1;
			stk[top]=r;
		}
	}
	int pop()
	{
		if(top==-1)
		{
			cout<<"StackUnderFlow\n";
			return -1;
		}
		else
		{
			return stk[top--];
		}
	}
	void read_postfix()
	{
		cout<<"Enter the Postfix Expression\n";
		cin>>a;
	}
	void eval()
	{
		int n,n1,n2,n3;
		for (int i=0;a[i]!='\0';i++)
		{	
			if(isdigit(a[i]))
			{
				n=a[i]-'0';
				push(n);
			}
			else
			{
				n1=pop();
				n2=pop();
				switch (a[i])
				{
					case '+' : n3=n1+n2;break;
					case '-' : n3=n1-n2;break;
					case '*' : n3=n1*n2;break;
					case '/' : n3=n1/n2;break;
					default : cout<<"Wrong INput\n";
				}
			push(n);
			}			
		}
	cout<<"The Solutin is "<<n3<<endl;
	}

};
int main()
{
	postfix p;
	p.read_postfix();
	p.eval();
	return 0;
}












