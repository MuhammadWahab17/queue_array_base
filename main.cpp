//
//  main.cpp
//  queue
//
//  Created by Ch Muhammad Wahab on 10/11/2020.
//  Copyright © 2020 Ch Muhammad Wahab. All rights reserved.
//

#include<iostream>
#include<string.h>
using namespace std;
template<typename T>
class queue
{
private:
    int rear_idx,front_idx,size;
    T*data;                      // store the value of array
public:
    queue(int s=4)
    {
        size=s+1;                // 5
        rear_idx=0;
        front_idx=0;
        
        //data=new int [size];    // pointer values
        data=new T[size];        // data [5]
    }
    ~queue()
    {
        delete[]data;      // memory delete free
    }
    void push(const T &val)           // &val so that it avoid making copy and store only address
    {
        if(full())
        throw "Stack overflow!";
        
        rear_idx=(rear_idx+1)%size;      //5%5=0
        data[rear_idx]=val;                 // data[1]
        /*
         if(rear_idx==size-1)       // 5-1=4
         {
         rear_idx=0;
         }
         else
         rear_idx++;                index inc
         */
    }
    void pop()
    {
        front_idx=(front_idx+1)%size;      //5%5=0
        
        /*if(front_idx=size-1)
         {
         front_idx=0;
         }
         else
         front_idx++;
         */
    }
    T front() const
    {
        return data[(front_idx+1)%size];   // return value
        
        // return data[front_indx];
    }
    bool empty() const
    {
        return (rear_idx==front_idx);             // 0==0 empty
    }
    bool full()
    {
        return ((rear_idx+1)%size==front_idx);             // 11%11=0
        //    return(rear_idx=front_idx-1)                  last index so full
    }
    
};
int main()
{
    queue<char>q;
    try
    {
        q.push('A');
        q.push('B');
        q.push('C');
        q.push('D');
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    while(!q.empty())
    {
        char val=q.front();
        q.pop();
        cout<<val<<endl;
    }
    q.push('F');
    cout<<q.front();
    cout<<endl;
    q.pop();
    
    return 0;
}
