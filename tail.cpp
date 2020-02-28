#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
class linkedlist
{
	private:class node
					{
						friend class linkedlist;
						private: T value;
						node *next;
						
						public:node(T val,node *nx=NULL)
									{
										value=val;
										next=nx;
									}
					}*m_head,*m_tail;
					int m_size;
					public:linkedlist()
								{
									m_head=NULL;
									m_tail=NULL;
									m_size=0;
								}
								
								int size()
								{
									return m_size;
								}
								
								void add_head(T item)
								{
									m_head=new node(item,m_head);
									if(m_tail==NULL)
									{
										m_tail=m_head;
									}
									m_size++;
								}
								
								T remove_head()
								{
									node *t=m_head;
									T t1=t->value;
									m_head=m_head->next;
									if(m_head==NULL)
									{
										m_tail=m_head;
									}
									m_size--;
									
									delete t;
									
									return t1;
								}
								
								void add_tail(T item)
								{
									if(m_size==0)
									add_head(item);
									else
									{
									node *t=new node(item);
									m_tail->next=t;
									m_tail=t;
									m_size++;
									}
								}
									
									T remove_tail()
									{
										if(m_head==m_tail)
										return remove_head();
										else
										{
											node *ptail=m_head;
											T v=m_tail->value;
											while(ptail->next!=m_tail)
											{
												ptail=ptail->next;
											}
											ptail->next=NULL;	
											delete m_tail;
											;
											m_tail=ptail;
											m_size--;
											return v;
										}
									}
								
								void display()
								{
									if(m_size==0)
									cout<<"The linked list  is empty";
									else
									{
										node *p=m_head;
										while(p!=NULL)
										{
											cout<<p->value;
											p=p->next;
											cout<<"-->";
										}
									}
								}
								
								void insert(int p,T item )
								{
									if(p==1)
									add_head(item);
									else if(p==size()+1)
									add_tail(item);
									else
									{
										node *here=m_head;
										for(int i=1;i<p-1;i++)
										here=here->next;
										here->next=new node(item,here->next);
										m_size++;
									}
								}
								
								T remove(int p)
								{
									if(p==1)
									return remove_head();
									else if(p==size()+1)
									return remove_tail();
									else
									{
										node *here=m_head;
										for(int i=1;i<p-1;i++)
										here=here->next;
										node *kill=here->next;
										T rvalue=kill->value;
										here->next=kill->next;
										delete kill;
										m_size--;
										return rvalue;
									}
								}
								
								void empty()
								{ 
									m_size=0;
									cout<<"Linked list empty";
								}
								
								void find(T ele)
								{
									int f=0,i=0;
										node *p=m_head;
										while(p!=NULL)
										{
											i++; 
											if(p->value==ele)
											{					  
											cout<<"found at position "<<i;
											f=1;
											
											}
										p=p->next;
									 }
									 if(f==0)
									 cout<<"not found";
									
									}							
									
									
								T findkth( int k1)
								{
									int i=0;
										node *p=m_head;
										while(p!=NULL)
										{
											i++; 
											if(k1==i)
											{
											cout<<p->value;
											}
													p=p->next;
										}
								
									 }
									 
																		
									 
									
								
};
int main() 
{
linkedlist<int>l;
   int ch,v,v2,x,p,el,p1,rv,ele,k;
   cout<<"1.Insert into head\n2.Delete from head\n3.Insert into tail\n4.Delete from tail\n5.Size\n6.Display\n7.To insert anywher\n8.To delete any node\n9.Make empty\n10.Find element\n11.Find kth element\n12.Exit";
 
do {
   cout<<"\nEnter your choice : ";
   cin>>ch;
   switch (ch) 
   {
      case 1:cout<<"Enter the item:";
      				cin>>v;
      				l.add_head(v); break;
        
      case 2:l.remove_head();
         break;
      
      case 3:cout<<"Enter the item:";
      				cin>>v2;
      				l.add_tail(v2); break;
      				
      case 4:l.remove_tail();break;
        
         
      case 5:x=l.size();
      				cout<<x;break;
      case 6:l.display();
         break;
      
      
      case 7:cout<<"Enter the position and element:";
      				cin>>p>>el;
      				l.insert(p,el);break;
      				
      case 8:cout<<"Enter the position of element to remove:";
     				cin>>p1;rv=l.remove(p1);
     				cout<<"Element "<<rv<<" removed";break;
      case 9:l.empty();break;
      case 10:cout<<"Enter the element";
     				cin>>ele;l.find(ele);break;
     				
      case 11:cout<<"Enter the position:";
     					cin>>k;l.findkth(k);break;
      case 12:cout<<"EXIT";exit(0);break;
     
        
      default: cout<<"Invalid choice"<<endl;break;
   }
} while(ch!=12);
   return 0;
}
