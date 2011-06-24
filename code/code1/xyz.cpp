#include<iostream>
using namespace std;
 
char stack[50];
int top=-1;
struct node
{
       char data;
       node *child;
       node *sib;
}*root;

void push(char a)
{
  stack[++top]=a;
}

void pop()
{
   top--;
}

char top_element()
{
    return stack[top];
}

node* makenode()
{
      node *ptr=(node *)malloc(sizeof(struct node));
      ptr->child=NULL;
      ptr->sib=NULL;
      return ptr;
}
      
node* search_sib(node* t,char data)
{
  while(t->sib!=NULL)
  {
    t=t->sib;
    if(t->data==data)  return t;
   }
   return NULL;
}                         

node* search(node* t,char data)
{
   if(top==t->data) { 
                       return t;  
                       }         
     else {
            node* x=search_sib(t,data);
            if(x!=NULL) return x;
            else {
                   x=search(t->child,data);
                   if(x!=NULL) return x;
                    else return NULL;
                  }
          }       
}            

int add_element(char a,char top)
{
    node *t=root,*t1;
    int flag=0;
    t1=search(t,top);
    cout<<top;
    if(t1!=NULL) {
                  node *ptr=makenode();
                  ptr->data=a;
                  if(t1->child!=NULL)
                  {
                     t1=t1->child;
                     while(t1->sib!=NULL)
                       t1=t->sib;
                     t1->sib=ptr;
                  }
                  else t1->child=ptr;
                  cout<<"added"<<a;
                  return 1;
                  }
       else return 0;                                    
}

node* g()
{
      char *str="(1(2(3)(4))(5)(6(7)))";         
      int i=0;
      
      //node *root;
      if(i==0 && str[i]=='(') {
                                    push(str[i+1]);
                                    node *ptr=makenode();
                                    ptr->data=str[i+1];
                                    i=2; 
                                    root=ptr;
                                    
                                  }
       
      while(str[i]!='\0')
      {
                if(str[i]=='(') {
                                   if(add_element(str[i],top_element())==0) cout<<"cant do";
                                   push(str[++i]);
                                  }
                    else if(str[i]==')') pop();             
                  i++;                
      }
      return root;
      
}                            


int main()
{
    node *t=g();
    //getch();
    return 0;
}
                                                                                                                                                                   
