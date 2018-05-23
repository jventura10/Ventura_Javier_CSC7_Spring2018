/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Merkle Tree 2, 4 Levels 
 * Created on May 23, 2018, 11:09 AM
 */

#include <iostream>
#include <string>

#include "GeneralHashFunctions.h"

using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    string orgStr[8]={ "Javier","Arlene","Roberto","Elena",
                        "Rebeca","Marcos","Daniel","Esteban" };
    
    unsigned int hashes1[8];    //First row of hashes
    unsigned int hashes2[4];    //Second row of hashes
    unsigned int hashes3[2];    //Third Row of hashes
    unsigned int topHash;
    string str1[8];
    string str2[4];
    string str3[4];
    string str4[2];
    string str5[2];
    string topStr;
    
    //Fill array of first hashes with corresponding string hashed
    for(int j=0;j<8;j++){
        hashes1[j]=APHash(orgStr[j]);
    }
    
    //Copy first row of hashes to a string array to concatenate next
    for(int j=0;j<8;j++){
        str1[j]=to_string(hashes1[j]);
    }
    
    //Concatenate pairs of strings from 1st row of hashes
    str2[0]=str1[0]+str1[1];
    str2[1]=str1[2]+str1[3];
    str2[2]=str1[4]+str1[5];
    str2[3]=str1[6]+str1[7];
    
    //Hash Concatenated strings of hashes for 2nd row of hashes
    for(int j=0;j<4;j++){
        hashes2[j]=APHash(str2[j]);
    }
    
    //Copy 2nd row of hashes to a string array to later concatenate next
    for(int j=0;j<4;j++){
        str3[j]=to_string(hashes2[j]);
    }
    
    //Concatenate pairs of strings from 2nd row of hashes
    str4[0]=str3[0]+str3[1];
    str4[1]=str3[2]+str3[3];
    
    //Third row of hashes
    for(int j=0;j<2;j++){
        hashes3[j]=APHash(str4[j]);
    }
    
    //Copy third row to string
    for(int j=0;j<2;j++){
        str5[j]=to_string(hashes3[j]);
    }
    
    //Concatenate third row to final string to hash
    topStr=str5[0]+str5[1];
    
    //Hash Final string
    topHash=APHash(topStr);
    
    //Visual for Tree
    cout<<"                              "<<topHash<<endl;
    cout<<"                      ";
    for(int j=0;j<2;j++){
        cout<<hashes3[j]<<"      ";
    }
    cout<<endl;
    cout<<"         ";
    for(int j=0;j<4;j++){
        cout<<hashes2[j]<<"    ";
    }
    cout<<endl;
    for(int j=0;j<8;j++){
        cout<<hashes1[j]<<" ";
    }
    
    return 0;
}

