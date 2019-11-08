//
//  linked_list_practice.cpp
//  linked_list_default_practice
//
//  Created by Brandon Johns on 4/3/19.
//  Copyright © 2019 Brandon Johns. All rights reserved.
//

#include "linked_list_practice.hpp"

template <class elemType>
linkedListIterator<elemType>:: linkedListIterator()
{
    current=NULL;
}
template <class elemType>
linkedListIterator<elemType>:: linkedListIterator(nodeType<elemType> *ptr)
{
    current=ptr;
}

template <class elemType>
elemType linkedListIterator<elemType>:: operator *()
{
    return current->info;
}

template <class elemType>
linkedListIterator<elemType> linkedListIterator<elemType>:: operator++()
{
    current=current->link;
    return *this;
}
template <class elemType>
bool linkedListIterator<elemType>:: operator ==(const linkedListIterator<elemType> & rhs)
{
    return (current == rhs.current);
}

template <class elemType>
bool  linkedListIterator<elemType>:: operator !=(const linkedListIterator<elemType> &rhs)
{
    return (current!=rhs.current); 
}


template <class elemType>
const linkedListType<elemType> & linkedListType<elemType>:: operator = (const linkedListType<elemType> &  other)
{
    if(this!= &other)
    {
        copyList(other);
    }
    return *this; 
}


template <class elemType>
void linkedListType<elemType>:: initializedList()
{
    destoryList();
}

template <class elemType>
bool linkedListType<elemType>:: isEmptyList() const
{
    return first==NULL;
}

template <class elemType>
void linkedListType<elemType>:: print() const
{
    nodeType<elemType> *current;
    current=first;
    while(current!=NULL)
    {
        cout<< current->info << " ";
        current=current->link;
    }
}

template <class elemType>
int linkedListType<elemType>:: size() const
{
    return length;
}

template <class elemType>
void linkedListType<elemType>:: destoryList()
{
    nodeType<elemType>*temp;
    while(first!=NULL)
    {
        temp=first;
        first=first->link;
        delete temp;
    }
    last=NULL;
    length=0;
}

template <class elemType>
elemType linkedListType<elemType>:: Front() const
{
    assert(first!=NULL);
    return first->info;
}

template <class elemType>
elemType linkedListType<elemType>:: Back() const
{
    assert(last!=NULL);
    return last->info;
}

template <class elemType>
bool linkedListType<elemType>:: search_unordered(const elemType& search_element)
{
    nodeType<elemType> *current;
    bool found=false;
    current=first;
    
    while(current!= NULL && !found)
    {
        if(current->info== search_element)
            found=true;
        else
            current=current->link;
    }
    return found;
}

template <class elemType>
void linkedListType<elemType>:: insertFirst_unordered(const elemType& element)
{
    nodeType<elemType>* newNode;
    newNode= new nodeType<elemType>;
    newNode->info = element;
    newNode->link=first;
    length++;
    
    if(last==NULL)
        last=newNode;
}

template <class elemType>
void  linkedListType<elemType>:: insertLast_unordered(const elemType& element)
{
    nodeType<elemType>* newNode;
    newNode= new nodeType<elemType>;
    newNode->info=element;
    newNode->link=NULL;
    
    if(first==NULL)
    {
        first=newNode;
        last=newNode;
        length++;
    }
    else
    {
        last->link=newNode;
        last=newNode;
        length++;
    }
    
}


template <class elemType>
bool linkedListType<elemType>:: search_ordered(const elemType& search_element)
{
    bool found=false;
    
    nodeType<elemType>*current;
    current=first;
    while(current!=NULL &&!found)
    {
        if(current->info>= search_element)
            found=true;
        else
            current=current->link;
    }
    
    if(found)
        found=(current->info==search_element);
    
    return found;
}

template <class elemType>
    void linkedListType<elemType>:: insert_ordered(const elemType& element)
{
    
    
}


template <class elemType>
void linkedListType<elemType>::  insertFirst_ordered(const elemType& element)
{
    insert_ordered(element);
}

template <class elemType>
void linkedListType<elemType>::  insertLast_ordered(const elemType& element)
{
    insert_ordered(element);
}

template <class elemType>
void linkedListType<elemType>:: deleteNode(const elemType& delete_node)
{
    nodeType<elemType>*current;
    nodeType<elemType>*trailCurrent;
    bool found;
    
    if(first==NULL)
        cout<<"cannot delete from empty list"<<endl;
    else
    {
        if(first->info==delete_node)
        {
            current=first;
            first=first->link;
            length--;
            if(first==NULL)
                last= NULL;
            
            delete current;
        }
        else
        {
            found = false;
            trailCurrent=first;
            current=first->link;
            
            while(current!=NULL && !found)
            {
                if(current->info !=delete_node)
                {
                    trailCurrent=current;
                    current=current->link;
                }
                else
                    found=true;
                
            }
            
            if(found)
            {
                trailCurrent->link=current->link;
                length--;
                
                if(last==current)
                    last=trailCurrent;
                
                delete current;
            }
            else
                cout<<"item is not in the list"<<endl;
        }
    }
}

template <class elemType>
linkedListIterator<elemType> linkedListType<elemType>:: begin()
{
    linkedListIterator<elemType> temp(first);
    return temp;
}

template <class elemType>
linkedListIterator<elemType> linkedListType<elemType>:: end()
{
    linkedListIterator<elemType> temp(NULL);
    return temp;
}

template <class elemType>
linkedListType<elemType>:: linkedListType()
{
    first=NULL;
    last=NULL;
    length=0;
}

template <class elemType>
linkedListType<elemType>:: linkedListType( const linkedListType<elemType>& other)
{
    first=NULL;
    copyList(other);
}

template <class elemType>
linkedListType<elemType>:: ~linkedListType()
{
    destoryList();
}

template <class elemType>
void linkedListType<elemType>:: copyList(const linkedListType<elemType> &other)
{
    nodeType<elemType> *newNode;
    nodeType<elemType> *current;
    
    if(first!= NULL)
        destoryList();
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
        first= new nodeType<elemType>;
        first->info=current->info;
        first->link=NULL;
        last=first;
        
        while(current!=NULL)
        {
            newNode= new nodeType<elemType>;
            newNode->info=current->info;
            newNode->link=NULL;
            
            last->link=newNode;
            last=newNode;
        }
    }
}
