//
//  sortedLinkedList.hpp
//  cmpe126_lab4
//
//  Created by Brandon Johns on 2/27/19.
//  Copyright © 2019 Brandon Johns. All rights reserved.
//

#ifndef sortedLinkedList_hpp
#define sortedLinkedList_hpp

#include <stdio.h>
using namespace std;

template<class elemType>
struct nodeType
{
    elemType stuff;
    nodeType<elemType> *next;
    nodeType<elemType> *back;
    nodeType<elemType> *link;
    nodeType<elemType> *info;

};
template <class elemType>
class sortedLinkedList
{
protected:
    int count;
    nodeType<elemType>*first;
    nodeType<elemType>*last;

    int max;
    
    
  
    
private:
  void copyList(const sortedLinkedList<elemType>& otherList);
public:
    sortedLinkedList();
    ~sortedLinkedList();
    const sortedLinkedList<elemType>& operator =(const sortedLinkedList<elemType>& other);
    bool isEmpty() const;
    bool isFull()const;
    int listSize()const;
    int maxListSize() const;
    void print();
    bool isItemAtEqual(int in, elemType t);
    void insert(elemType in);
    void remove(elemType out);
    void clearList();
    
};
template <class elemType>
sortedLinkedList<elemType>:: sortedLinkedList()
{
    first=NULL;
    last=NULL;
    count=0;
    max=100;
  


    
  
}

template <class elemType>
sortedLinkedList<elemType>::  ~sortedLinkedList()
{
    clearList();
}

template <class elemType>
void sortedLinkedList<elemType>:: copyList(const sortedLinkedList<elemType>& otherList)
{
    nodeType<elemType> *newNode;
    nodeType<elemType>*current;
    
    if(first!=NULL)
    {
        clearList();
    }
    if(otherList.first==NULL)
    {
        first=NULL;
        last=NULL;
    
        count=0;
    }
    else
    {
        
        current=otherList.first;
        count=otherList.count;
        
        first= new nodeType<elemType>;
       
        first->stuff=current->stuff;
        first-> link=NULL;
        last=first;
        current=current->link;
        
        while(current!=NULL)
        {
            newNode= new nodeType<elemType>;
            newNode->stuff = current->stuff;
            newNode->link =NULL;
            last->link=newNode;
            last=newNode;
            current=current->link;
        }
    }
}




template <class elemType>
const  sortedLinkedList<elemType>& sortedLinkedList<elemType>::operator =(const sortedLinkedList<elemType>& other)
{
    if(this!= &other)
        copyList(other);
    {
        
    }
    return *this;
}
template <class elemType>
bool sortedLinkedList<elemType>:: isEmpty() const
{
    return (first==NULL);
}
template <class elemType>
bool sortedLinkedList<elemType>:: isFull()const
{
    return max;
}
template <class elemType>
int sortedLinkedList<elemType>:: listSize() const
{
    return count;
}
template <class elemType>
int sortedLinkedList<elemType>:: maxListSize() const
{
    return max; 
}
template <class elemType>
void  sortedLinkedList<elemType>:: print()
{
    nodeType<elemType> *current;
    current=first;
    while(current!=NULL)
    {
        cout<< current->stuff << " " ;
        current= current->next;
    }
    
}
template <class elemType>
bool sortedLinkedList<elemType>::  isItemAtEqual(int in, elemType t)
{
    return (first[in]==t);
    
}
template <class elemType>
void sortedLinkedList<elemType>:: insert(elemType in)
{
    nodeType<elemType> *current;
    nodeType<elemType> *trailCurrent;
    nodeType<elemType> *newNode;
    bool found;
    newNode=new nodeType<elemType>;
    newNode->stuff = in;
    newNode->next=NULL;
    newNode->back=NULL;
    
    if(first== NULL)
    {
        first=newNode;
        last=newNode;
        count++;
    }
    else
    {
        found=false;
        current=first;
        while(current != NULL && !found)
        {
            if(current->stuff>= in)
            {
                found=true;
            }
            else
            {
                trailCurrent=current;
                current= current->next;
            }
        }
        
        if(current==first)
        {
            first->back=newNode;
            
        }
    }
    
    
    
    
    
}
template <class elemType>
void sortedLinkedList<elemType>:: remove(elemType out)
{
    nodeType<elemType> *current;
    nodeType<elemType> *trailCurrent;
    
    bool found;
    
    if(first==NULL)
    {
        cout<<"cannot delete from an empty list"<<endl;
    }
    else if(first->stuff == out)
    {
        current=first;
        first=first->next;
        if(first!= NULL)
        {
            first->back=NULL;
        }
        else
        {
            last=NULL;
        }
        count--;
        
        delete current;
    }
    else
    {
        found = false;
        current =first;
        while(current != NULL && !found)
        {
            if(current->stuff >= out)
            {
                found=true;
            }
            else
            {
                current= current->next;
            }
        }
        
        if(current==NULL)
        {
            cout<<"not in the list"<<endl;
        }
        else if (current->stuff == out)
        {
            trailCurrent=current->back;
            trailCurrent->next= current->next;
            if(current-> next !=NULL)
            {
                current->next->back=trailCurrent;
            }
            if (current == last)
            {
                last = trailCurrent;
            }
            count--;
            delete current;
        }
        else
        {
            cout<<"item is not in the list"<<endl;
        }
    }
}
template <class elemType>
void sortedLinkedList<elemType>:: clearList()
{
    nodeType<elemType> *temp;
    
    while(first!=NULL)
    {
        temp=first;
        first=first->next;
        delete temp;
    }
    
    last=NULL;
    count =0;
}

#endif /* sortedLinkedList_hpp */
