/*
 * File:   main.cpp
 * Author: Javier Ventura
 * Purpose: Luhn Algorithm 2 
 * Created on March 4, 2018, 10:16 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

//Global Constants
enum CrdCard {AmericanExpress,Visa,MasterCard,Discover,ALL};

//Function Prototypes
void genCC(CrdCard,char *);
void flipDig(char *card);
bool validCC(char *card);
char dblLuhn(char);

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=16;
    char crdCard[SIZE];
    int crd;
    CrdCard crdType;
    
    //Output/Input Credit Card Selection Menu
    //crdMenu(crdCard);
    
    cout<<"Select your card type:"<<endl;
    cout<<"1.) American Express     2.) Visa"<<endl;
    cout<<"3.) Master Card          4.) Discover"<<endl;
    cin>>crd;
    switch(crd){
        case 1:{
            genCC(AmericanExpress,crdCard);
            break;
        }
        case 2:{
            genCC(Visa,crdCard);
            break;
        }
        case 3:{
            genCC(MasterCard,crdCard);
            break;
        }   
        default:{
            genCC(Discover,crdCard);
            break;
        }         
    }
    

    return 0;
}

void genCC(CrdCard crdType,char *card) {
    //Declare variables and initialize new card
    int crdLen = 16;
    int valids=0;
    int nValids=0;
    
    for(int j=0;j<10000;j++){
        //Generate Valid Card
        for(int i=0;i<16;i++){
            card[i]=rand()%10+48;
        }

        //Put null terminator at the end
        card[16]='\0';


        //Generate CreditCard Number using Card Type
        switch(crdType){
            case AmericanExpress:
                card[0] = '3';
                break;
            case Visa:
                card[0] = '4';
                break;
            case MasterCard:
                card[0] = '5';
                break;
            default:
                card[0] = '6';
                card[1] = '0';
                card[2] = '1';
                card[3] = '1';
                break;
        }       

        flipDig(card);

        if(validCC(card)){
            valids++;
        }
        else{
            nValids++;
        }
    }
    
    cout<<"Looped 10,00 Times to Check Credit Cards"<<endl;
    cout<<"Valid Cards: "<<valids<<endl;
    cout<<"Non-Valids: "<<nValids<<endl;
    
}

void flipDig(char *card) {
    //Random index
    int i=(rand() % 16) + 1;
   
    //Flip digit in credit card number
    card[i] = rand()%10+48;
    
}

bool validCC(char *card){
    int sum=0;
    
    //Perform Luhn Loop
    for(int i=16; i>=0; i-=2){
        (card[i]>'4')?card[i]=dblLuhn(card[i]):card[i]=(card[i]*2)-48;
    }     
    
    //Perform loop to sum credit card digits
    for (int i=0; i<16; i++){
        sum+=static_cast<unsigned int>(card[i]-48);
    }
    
    return ((sum*9)%10)==0;
}

char dblLuhn(char c) {
    const int val  = static_cast<unsigned short>(c-48);
    const int vDbl = val*2;    //Character value doubled
    const int fDgt = (vDbl/10);//First Digit in doubled character value
    const int sDgt = (vDbl%10);//Second Digit in doubled character value
    
    return '0'+(fDgt+sDgt);      //Return Sum of first and second digit
}