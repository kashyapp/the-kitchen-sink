#include <iostream>                                          
using namespace std;                                         
                                                             
#ifndef WHICH                                                
#define WHICH  3                                             
#endif                                                       
                                                             
struct node{                                                 
    node *next;                                              
    int val;                                                 
};                                                           
                                                             
//PICK ONE OF THE REVERSE FUNCTIONS                          
#if WHICH==1                                                 
//Iterative                                                  
node* reverse(node* start){                                  
    node *p1=NULL;                                           
    node *p2=start;                                          
    while(p2 != NULL){                                       
        node *p3=p2->next;                                   
        p2->next=p1;                                         
        p1=p2;                                               
        p2=p3;                                               
    }                                                        
    return p1;                                               
}                                                            
                                                             
#elif WHICH==2                                               
//recursive                                                  
node* reverse(node* start){                                  
    if(start==NULL || start->next==NULL)                     
        return start;                                        
    node *tail = reverse(start->next);                       
    start->next->next = start;                               
    start->next = NULL;                                      
    return tail;                                             
}                                                            
                                                             
#elif WHICH==3                                               
//tail recursive                                             
node* myreverse(node *p1, node *p2){                         
    node *p3=p2->next;                                       
    p2->next=p1;                                             
    return (p3==NULL) ? p2 : myreverse(p2,p3);               
}                                                            
                                                             
node* reverse(node* start){                                  
    return start==NULL ? start : myreverse(NULL, start);     
}                                                            
                                                             
#endif                                                       
//END OF CHOICES                                             
                                                             
int main(){                                                  
    int i;                                                   
    node *head= NULL;                                        
    while(cin >> i){                                         
        node *p = new node;                                  
        p->val = i;                                          
        p->next=head;                                        
        head=p;                                              
    }                                                        
    for(node *i = head; i!=NULL; i=i->next){                 
        cerr<<i->val<<" ";                                   
    }                                                        
    cerr<<endl;

    cerr<<"Reverse method #"<<WHICH<<endl;
    head = reverse(head);

    for(node *i = head; i!=NULL; i=i->next){                 
        cout<<i->val<<" ";                                   
    }                                                        
    cout<<endl;
    return 0;
}
