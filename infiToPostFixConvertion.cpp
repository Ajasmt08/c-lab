#include <iostream>
using namespace std;
#define max 20
class stack
{
	char stk[max];
	int top;
	public:
	stack() { top=-1; }
	void push( char symbol)
	{
		if(top==max-1)
		{
			cout<<"STACKOVERFLOW\n";
		}	
		else
		{
			top++;
			stk[top]=symbol;
		}
	}
	char pop()
	{
		if(top==-1)
		{
			cout<<"STACKUNDERFLOW\n";
			return  '#';
		}
		else
		{
			char ele;
			ele=stk[top];
			top--;
			return ele;

		}
	}
	int empty()
	{
		if(top==-1)
		return 1;
		else
		return 0;
	}
	
};
class infixtopostfix
{
	stack s;
	char infix[20],postfix[20];
	public :
	void read()
	{
		cout<<"Enter the Expression\n";
		cin>>infix;
	}
	int white_space(char symbol)
	{
		if(symbol==' ' || symbol=='\t' || symbol=='\0' )
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void convertion()
	{
		char entry1,entry2;
		int precedence,l,p=0;
		for(int i=0;infix[i]!='\0';i++)
		{
			entry1=infix[i];
			if(!white_space(entry1))
			{   
				switch(entry1)
				{
					case '(' : s.push(entry1);break;
					case ')' : while((entry2=s.pop())!='(')
							{
								postfix[p++]=entry2;
							}
							break;
					case '+' :
					case '-' :
					case '*' :
					case '/' :
							if(!s.empty())
							{
								precedence=prec(entry1);
								entry2=s.pop();
								while(precedence<=prec(entry2))
								{
									postfix[p++]=entry2;
									if(!s.empty())
									{
										entry2=s.pop();
									}
									else
									{
										break;
									}
								}
								if(precedence>prec(entry2))
								{
									s.push(entry2);
								}
							}
				s.push(entry1);
				break;	
				default : postfix[p++]=entry1;
				break;
				}	
			}	
		}
		while(!s.empty())
		{
			postfix[p++]=s.pop();
		}
		postfix[p]='\0';
		cout<<"\n The post fix expression is "<<postfix<<endl;
	}
	int prec(char symbol)
	{
		switch (symbol)
		{
			case '/' : return 4;
			case '*' : return 3;
			case '+' : return 2;
			case '-' : return 1;
			case '(' : return 0;
			default : return -1;
			
		}
	}
};
int main()
{
	infixtopostfix c;
	c.read();
	c.convertion();
	return 0;
}





























