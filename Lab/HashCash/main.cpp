/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Modify Hash Functions for HashCash
 * Created on April 4, 2018, 12:10 PM
 */


#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <vector>

#include "GeneralHashFunctions.h"

using namespace std;

void findLength(unsigned int);
vector<int> lengthFrequency(11);

int main(int argc, char* argv[]){
    //Set Random Number Seed
   srand(static_cast<unsigned int>(time(0)));
   
   //Declare Variables
   string msg = "CSC 7 Discrete Structures Lab Assignment HashCash";
   string nwMsg = "Short Message"; 
   
   unsigned int RSHashInt,
		JSHashInt,
		PJWHashInt,
		ELFHashInt,
		BKDRHashInt,
		SDBMHashInt,
		DJBHashInt,
		DEKHashInt,
		FNVHashInt;
   
   //Randomly generate a number
   unsigned int randNum = rand();

   cout << "The message: " <<  "\n" << msg << endl; 
   cout << "The random number: " << randNum << endl; 
   cout<<endl;
   

    int strTime=time(0); 
    do{
        //Converting the random number to a string
        ostringstream convert;   // stream used for the conversion
        convert<<randNum++;      // insert the textual representation of 'Number' in the characters in the stream
        string randomNumString = convert.str();
        nwMsg = msg + randomNumString;

        RSHashInt = RSHash(nwMsg);
        findLength(RSHashInt); 

        JSHashInt = JSHash(nwMsg);
        findLength(JSHashInt); 

        PJWHashInt = PJWHash(nwMsg);
        findLength(PJWHashInt); 

        ELFHashInt = ELFHash(nwMsg);
        findLength(ELFHashInt); 

        BKDRHashInt = BKDRHash(nwMsg);
        findLength(BKDRHashInt); 

        SDBMHashInt = SDBMHash(nwMsg);
        findLength(SDBMHashInt); 

        DJBHashInt = DJBHash(nwMsg);
        findLength(DJBHashInt); 

        DEKHashInt = DEKHash(nwMsg);
        findLength(DEKHashInt); 

        FNVHashInt = FNVHash(nwMsg);
        findLength(FNVHashInt); 

    }while(lengthFrequency.at(8)<100000); 
        
    int endTime=time(0);

    for(int i = 0; i<lengthFrequency.size();i++){
        cout<<"Counting of Hash of 10^"<<i<<" length: "<<lengthFrequency.at(i)<<endl; 
    }

    cout << "The Base Message: "             << "\n" << nwMsg    << endl;
    cout << "The total time take = " << endTime-strTime <<" (secs)"<<endl;
    cout << " 1. RS-Hash Function Value:   " << RSHashInt   << endl;
    cout << " 2. JS-Hash Function Value:   " << JSHashInt   << endl;
    cout << " 3. PJW-Hash Function Value:  " << PJWHashInt  << endl;
    cout << " 4. ELF-Hash Function Value:  " << ELFHashInt  << endl;
    cout << " 5. BKDR-Hash Function Value: " << BKDRHashInt << endl;
    cout << " 6. SDBM-Hash Function Value: " << SDBMHashInt << endl;
    cout << " 7. DJB-Hash Function Value:  " << DJBHashInt  << endl;
    cout << " 8. DEK-Hash Function Value:  " << DEKHashInt  << endl;
    cout << " 9. FNV-Hash Function Value:  " << FNVHashInt  << endl;


   return 0;
}

void findLength(unsigned int RSHashed){
    unsigned int HashLength = 0;
    do{
        ++HashLength;
        RSHashed/=10;
    }while(RSHashed); 
 
    lengthFrequency.at(HashLength)+=1; 

}