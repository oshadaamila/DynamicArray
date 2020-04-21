#include <iostream>
#include "dynamicarray.h"
  
using namespace std; 
  
int main() 
{ 
    DynamicArray *d_array = new DynamicArray();
    int val = d_array->getOne();
    cout<<"getOne method returns "<<val<<endl; 
  
    return 0; 
}
