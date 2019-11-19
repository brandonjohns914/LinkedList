//
//  main.cpp
//  cmpe126_lab4
//
//  Created by Brandon Johns on 2/27/19.
//  Copyright © 2019 Brandon Johns. All rights reserved.
//

#include <iostream>
#include "sortedLinkedList.hpp"

using namespace std;
int main()
{
    sortedLinkedList <int> n;

    int num1;
    cout<<"enter a number: "<<endl;
    cin>>num1;
   

    n.insert(num1);
    n.print();
    
    cout<<"empty: "<< n.isEmpty() <<endl;
    cout<<"full: "<<n.isFull()<<endl;
    cout<<"size: " << n.listSize()<<endl;
    cout<<"max size: "<< n.maxListSize()<<endl;
    n.remove(num1);
    n.clearList();

    n.print();
    
    
  
    
    
    
    
 
    

    
    
}
