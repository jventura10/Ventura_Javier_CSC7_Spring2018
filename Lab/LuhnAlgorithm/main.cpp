/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Luhn Algorithm 
 * Created on February 14, 2018, 1:04 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

//Function Prototypes 
void GenCard(int []);
void Luhn(int []);

int main(int argc, char** argv) {
    //Declare Variables 
    srand(static_cast<unsigned int>(time(0)));
    
    int card[10];   //Array to hold 

    GenCard(card);
    Luhn(card);
    
    return 0;
}

void GenCard(int card[]){
    for(int i=0;i<=9;i++){
        card[i]=rand()%9+1;
    }
    cout<<"A random number created in Prep for Luhn Digit: ";
    for(int i=0;i<=9;i++){
        cout<<card[i];
    }
    cout<<endl;
}

void Luhn(int card[]){
    //Declare Variables
    int x[9];       // Array to hold each digit times 1 or 2 if needed, must be int because it will be added later
    int sum=0;      // Sum of all digits in the card (after digits processed)
    int chkDgt;     // Check Digit multiplying sum by 9 %10 
    
    x[0]=card[0]*1;
    x[1]=card[1]*2;
    x[2]=card[2]*1;
    x[3]=card[3]*2;
    x[4]=card[4]*1;
    x[5]=card[5]*2;
    x[6]=card[6]*1;
    x[7]=card[7]*2;
    x[8]=card[8]*1;
    x[9]=card[9]*2;
    
    cout<<endl;
    for(int i=0;i<=9;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
    
    for(int i=0;i<=9;i++){
        if(x[i]>9){
            x[i]=x[i]-9;
        }
    }
    
    cout<<endl;
    for(int i=0;i<=9;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
    
    for(int i=0;i<=9;i++){
        sum+=x[i];
    }
    
    cout<<endl;
    cout<<"Sum: "<<sum;
    cout<<endl;
    
    chkDgt = (sum *9)%10;
    cout<<endl;
    
    if(chkDgt==0){
        cout<<"Check Digit equals 0, Card Valid"<<endl;
    }
    else{
        cout<<"Check Digit "<<chkDgt<<" is not equal to zero, Card not Valid"<<endl;
    }
}