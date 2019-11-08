//
//  linked_list_practice.hpp
//  linked_list_default_practice
//
//  Created by Brandon Johns on 4/3/19.
//  Copyright © 2019 Brandon Johns. All rights reserved.
//

#ifndef linked_list_practice_hpp
#define linked_list_practice_hpp

#include <stdio.h>
using namespace std;

template <class elemType>
struct nodeType
{
    elemType info;
    nodeType<elemType> *link;
};

template <class elemType>
class linkedListIterator
{
public: linkedListIterator();
    linkedListIterator(nodeType<elemType> *ptr);
    elemType operator *();
    linkedListIterator<elemType> operator++();
    bool operator ==(const linkedListIterator<elemType> & rhs);
    bool operator !=(const linkedListIterator<elemType> &rhs);
private:
    nodeType<elemType> *current;
};

template <class elemType>
class linkedListType
{
   
public:
    const linkedListType<elemType> & operator = (const linkedListType<elemType> &  other);
    void initializedList();
    bool isEmptyList() const;
    void print() const;
    int size() const;
    void destoryList();
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
    linkedListIterator<elemType> begin();
    linkedListIterator<elemType> end();
    linkedListType();
    linkedListType( const linkedListType<elemType>& other);
    ~linkedListType();
protected:
    int length;
    nodeType<elemType> *first;
    nodeType<elemType> *last;
private:
    void copyList(const linkedListType<elemType> &other);
};
#endif /* linked_list_practice_hpp */
