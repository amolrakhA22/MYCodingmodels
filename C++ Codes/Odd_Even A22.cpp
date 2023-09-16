// C++ Program using oop's concept for odd_even number  
// By Amol Rakh

#include <iostream>
using namespace std;
 
 class amol //class
 {
    public:
    int num;
    int odd_even() //function for odd even number
    {
        cout<<"Enter a number :";
        cin>>num;
        if ( num % 2 == 0) //condition for comparing number
        {
            cout<<num<<" is even number";
        }
        else
        {
            cout<<num<<" is odd number";
        }
        return 0;
    }
 };
 
 int main()
 {
     amol rakh; //giving name to class as 'rakh'
     rakh.odd_even(); //calling Function from class amol
     return 0;
 }
