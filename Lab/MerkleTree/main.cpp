/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Merkle Tree 
 * Created on May 21, 2018, 11:12 AM
 */

#include <iostream>
#include <string>

#include "GeneralHashFunctions.h"

using namespace std;

//Function Prototypes
unsigned int hshFunc(string,unsigned int);

int main(int argc, char** argv) {
    //Declare Variables 
    const string L1="Then out spake brave Horatius,The Captain of the Gate:";
    const string L2="To every man upon this earth.Death cometh soon or late.";
    const string L3="And how can man die better.Than facing fearful odds,";
    const string L4="For the ashes of his fathers,And the temples of his Gods.";
    
    //First Row of Hashes L1-L4
    unsigned int hash00=APHash(L1);
    unsigned int hash01=APHash(L2);
    unsigned int hash10=APHash(L3);
    unsigned int hash11=APHash(L4);
    
    //Concatenating hash 00 with hash 01 and then hashes 10 and 11
    string r1=to_string(hash00)+to_string(hash01);
    string r2=to_string(hash10)+to_string(hash11);
    
    //Second row of hashes 
    unsigned int hash0=APHash(r1);
    unsigned int hash1=APHash(r2);
    
    //Concatenating Hash 0 with hash 1
    string r3=to_string(hash0)+to_string(hash1);
    
    //Top Hash
    unsigned int topHsh=APHash(r3);
    
    //Visual for Tree
    cout<<"                       "<<topHsh<<endl;
    cout<<"        "<<hash0<<"                     "<<hash1<<endl;
    cout<<hash00<<"       "<<hash01<<"   "<<hash10<<"        "<<hash11<<endl;
    
    return 0;
}
