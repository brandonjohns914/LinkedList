//
//  doubleLinkedList_practice.cpp
//  linked_list_default_practice
//
//  Created by Brandon Johns on 4/3/19.
//  Copyright © 2019 Brandon Johns. All rights reserved.
//

#include "doubleLinkedList_practice.hpp"
#include <iostream>

using namespace std;

template <class elemType>
D_linkedListIterator<elemType>:: D_linkedListIterator()
{
    current=NULL;
}
template <class elemType>
D_linkedListIterator<elemType>:: D_linkedListIterator(D_nodeType<elemType> *ptr)
{
    current=ptr;
}

template <class elemType>
elemType D_linkedListIterator<elemType>:: operator *()
{
    return current->info;
}

template <class elemType>
D_linkedListIterator<elemType> D_linkedListIterator<elemType>:: operator++()
{
    current=current->next;
    return *this;
}
template <class elemType>
bool D_linkedListIterator<elemType>:: operator ==(const D_linkedListIterator<elemType> & rhs)
{
    return (current == rhs.current);
}

template <class elemType>
bool  D_linkedListIterator<elemType>:: operator !=(const D_linkedListIterator<elemType> &rhs)
{
    return (current!=rhs.current);
}


template <class elemType>
const Double_linkedListType<elemType> & Double_linkedListType<elemType>:: operator = (const Double_linkedListType<elemType> &  other)
{
    if(this!= &other)
    {
        copyList(other);
    }
    return *this;
}


template <class elemType>
void Double_linkedListType<elemType>:: Double_initializedList()
{
    destoryDoubleList();
}

template <class elemType>
bool Double_linkedListType<elemType>:: isEmptyList() const
{
    return first==NULL;
}

template <class elemType>
void Double_linkedListType<elemType>:: print() const
{
    D_nodeType<elemType> *current;
    current=first;
    while(current!=NULL)
    {
        cout<< current->info << " ";
        current=current->next;
    }
}

template <class elemType>
int Double_linkedListType<elemType>:: size() const
{
    return length;
}

template <class elemType>
void Double_linkedListType<elemType>:: reversePrint() const
{
    D_nodeType<elemType> *current;
    current=last;
    while(current!=NULL)
    {
        cout<<current->info<< " ";
        current=current->back; 
    }
}


template <class elemType>
void Double_linkedListType<elemType>:: destoryDoubleList()
{
    D_nodeType<elemType>*temp;
    while(first!=NULL)
    {
        temp=first;
        first=first->next;
        delete temp;
    }
    last=NULL;
    length=0;
}

template <class elemType>
elemType Double_linkedListType<elemType>:: Front() const
{
    assert(first!=NULL);
    return first->info;
}

template <class elemType>
elemType Double_linkedListType<elemType>:: Back() const
{
    assert(last!=NULL);
    return last->info;
}

template <class elemType>
bool Double_linkedListType<elemType>:: search_unordered(const elemType& search_element)
{
    D_nodeType<elemType> *current;
    bool found=false;
    current=first;
    
    while(current!= NULL && !found)
    {
        if(current->info== search_element)
            found=true;
        else
            current=current->next;
    }
    return found;
}

template <class elemType>
void Double_linkedListType<elemType>:: insertFirst_unordered(const elemType& element)
{
    D_nodeType<elemType>* newNode;
    newNode= new D_nodeType<elemType>;
    newNode->info = element;
    newNode->next=first;
    length++;
    
    if(last==NULL)
        last=newNode;
}

template <class elemType>
void  Double_linkedListType<elemType>:: insertLast_unordered(const elemType& element)
{
    D_nodeType<elemType>* newNode;
    newNode= new D_nodeType<elemType>;
    newNode->info=element;
    newNode->next=NULL;
    
    if(first==NULL)
    {
        first=newNode;
        last=newNode;
        length++;
    }
    else
    {
        last->next=newNode;
        last=newNode;
        length++;
    }
    
}


template <class elemType>
bool Double_linkedListType<elemType>:: search_ordered(const elemType& search_element)
{
    bool found=false;
    
    D_nodeType<elemType>*current;
    current=first;
    while(current!=NULL &&!found)
    {
        if(current->info>= search_element)
            found=true;
        else
            current=current->next;
    }
    
    if(found)
        found=(current->info==search_element);
    
    return found;
}

template <class elemType>
void Double_linkedListType<elemType>:: insert_ordered(const elemType& element)
{
    D_nodeType<elemType> *current;
    D_nodeType<elemType> *trailcurrent;
    D_nodeType<elemType> *newNode;
    bool found;
    
    newNode=new D_nodeType<elemType>;
    newNode->info=element;
    newNode->next=NULL;
    newNode->back=NULL;
    
    if(first==NULL)
    {
        first=newNode;
        last=newNode;
        length++;
    }
    else
    {
        found=false;
        current=first;
        
        while(current!=NULL&& !found)
        {
            if(current->info>=element)
                found=true;
            else
            {
                trailcurrent=current;
                current=current->next;
            }
        }
        if(current==first)
        {
            first->back=newNode;
            newNode->next=first;
            first=newNode;
            length++;
        }
        else
        {
            if(current!=NULL)
            {
                trailcurrent->next=newNode;
                newNode->back=trailcurrent;
                newNode->next=current;
                current->back=newNode;
            }
            else
            {
                trailcurrent->next=newNode;
                newNode->back=trailcurrent;
                last=newNode;
            }
            
            length++;
        }
    }
}


template <class elemType>
void Double_linkedListType<elemType>::  insertFirst_ordered(const elemType& element)
{
    insert_ordered(element);
}

template <class elemType>
void Double_linkedListType<elemType>::  insertLast_ordered(const elemType& element)
{
    insert_ordered(element);
}

template <class elemType>
void Double_linkedListType<elemType>:: deleteNode(const elemType& delete_node)
{
    D_nodeType<elemType>*current;
    D_nodeType<elemType>*trailCurrent;
    bool found;
    
    if(first==NULL)
        cout<<"cannot delete from empty list"<<endl;
    else
    {
        if(first->info==delete_node)
        {
            current=first;
            first=first->next;
            
            if(first!=NULL)
                first->back=NULL;
            else
                last=NULL;
            
            length--;
            
            delete current;
        }
        else
        {
            found= false;
            current=first;
            
            while(current!= NULL && !found)
            {
                if(current->info>= delete_node)
                    found=true;
                else
                    current=current->next;
            }
            if(current==NULL)
                cout<<"item is not in the list" <<endl;
            else if(current->info== delete_node)
            {
                trailCurrent=current->back;
                trailCurrent->next= current->next;
                
                if(current->next!=NULL)
                    current->next->back=trailCurrent;
                if(current==last)
                    last=trailCurrent;
                
                length--;
                
                delete current;
            }
            else
                cout<<"item not in the list"<<endl;
        }
        
    }
        
    
}

template <class elemType>
D_linkedListIterator<elemType> Double_linkedListType<elemType>:: begin()
{
    D_linkedListIterator<elemType> temp(first);
    return temp;
}

template <class elemType>
D_linkedListIterator<elemType> Double_linkedListType<elemType>:: end()
{
    D_linkedListIterator<elemType> temp(NULL);
    return temp;
}

template <class elemType>
Double_linkedListType<elemType>:: Double_linkedListType()
{
    first=NULL;
    last=NULL;
    length=0;
}

template <class elemType>
Double_linkedListType<elemType>:: Double_linkedListType( const Double_linkedListType<elemType>& other)
{
    first=NULL;
    copyList(other);
}

template <class elemType>
Double_linkedListType<elemType>:: ~Double_linkedListType()
{
    destoryDoubleList();
}

template <class elemType>
void Double_linkedListType<elemType>:: copyList(const Double_linkedListType<elemType> &other)
{
    D_nodeType<elemType> *newNode;
    D_nodeType<elemType> *current;
    
    if(first!= NULL)
        destoryDoubleList();
    if(other.first==NULL)
    {
        first=NULL;
        last=NULL;
        length=0;
    }
    else
    {
        current=other.first;
        length=other.length;
        first= new D_nodeType<elemType>;
        first->info=current->info;
        first->next=NULL;
        last=first;
        
        while(current!=NULL)
        {
            newNode= new D_nodeType<elemType>;
            newNode->info=current->info;
            newNode->next=NULL;
            
            last->next=newNode;
            last=newNode;
        }
    }
}
