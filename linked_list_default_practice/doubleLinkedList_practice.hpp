//
//  doubleLinkedList_practice.hpp
//  linked_list_default_practice
//
//  Created by Brandon Johns on 4/3/19.
//  Copyright © 2019 Brandon Johns. All rights reserved.
//

#ifndef doubleLinkedList_practice_hpp
#define doubleLinkedList_practice_hpp

#include <stdio.h>
using namespace std; 

template <class elemType>
struct D_nodeType
{
    elemType info;
    D_nodeType<elemType> *next;
    D_nodeType<elemType> *back;

};

template <class elemType>
class D_linkedListIterator
{
public: D_linkedListIterator();
    D_linkedListIterator(D_nodeType<elemType> *ptr);
    elemType operator *();
    D_linkedListIterator<elemType> operator++();
    bool operator ==(const D_linkedListIterator<elemType> & rhs);
    bool operator !=(const D_linkedListIterator<elemType> &rhs);
private:
    D_nodeType<elemType> *current;
};


template <class elemType>
class Double_linkedListType
{
    
public:
    const Double_linkedListType<elemType> & operator = (const Double_linkedListType<elemType> &  other);
    void Double_initializedList();
    bool isEmptyList() const;
    void print() const;
    int size() const;
    void destoryDoubleList();
    elemType Front() const;
    elemType Back() const;
    bool search_unordered(const elemType& search_element);
    bool search_ordered(const elemType & search_element);
    void insertFirst_unordered(const elemType& element);
    void insertLast_unordered(const elemType& element);
    void insert_ordered(const elemType& element);
    void insertFirst_ordered(const elemType& element);
    void insertLast_ordered(const elemType& element);
    void deleteNode(const elemType& delete_node);
    D_linkedListIterator<elemType> begin();
    D_linkedListIterator<elemType> end();
    Double_linkedListType();
    Double_linkedListType( const Double_linkedListType<elemType>& other);
    ~Double_linkedListType();
    
    void reversePrint() const;
    
    
    
protected:
    int length;
    D_nodeType<elemType> *first;
    D_nodeType<elemType> *last;
private:
    void copyList(const Double_linkedListType<elemType> &other);
};
#endif /* doubleLinkedList_practice_hpp */
