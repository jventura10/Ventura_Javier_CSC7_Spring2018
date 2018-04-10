/*
 * File:   main.cpp
 * Author: Javier Ventura 
 * Purpose: Project 1 MasterMind Game
 * Created on April 6, 2018, 12:42 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;


int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables 
    int choice;
    bool quit=false;
    
    do{
        cout<<"MasterMind"<<endl;
        cout<<"----------"<<endl;
        cout<<"(1)Play Game"<<endl;
        cout<<"(2)Watch AI Play"<<endl;
        cout<<"(3)Quit Game"<<endl;
        cout<<"Enter Choice: ";
        cin>>choice;
        
        while(choice<1 || choice>3){
            cout<<"Not a Valid Option, Try Again: ";
            cin>>choice;
        }
        
        switch(choice){
            case 1:{
                //Declare Local Variable
                int a[4];   //Array Holding Key, Each element will be a spot 
                int x1;     //1st Spot, Player Enters
                int x2;     //2nd Spot, Player Enters
                int x3;     //3rd Spot, Player Enters
                int x4;     //4th Spot, Player Enters
                bool one=false,two=false,three=false,four=false;    //Marks when Player Guesses All 4
                int tries=3; //Number of Tries, Player gets
                
                //Fill Array with the Contents 1-8 
                for(int i=0;i<4;i++){
                    a[i]=rand()%8+1;    //1-8 is equivalent to 8 colors
                }
                
                cout<<endl;
                for(int i=0;i<4;i++){
                    cout<<a[i]<<" ";
                }
                cout<<endl;
                
                do{
                    cout<<endl;
                    cout<<"4 Spots, 1-8 is Possible in Each!"<<endl;
                    cout<<"Enter Your 4 Tries: "<<endl;
                    cin>>x1;
                    cin>>x2;
                    cin>>x3;
                    cin>>x4;

                    cout<<endl;
                    
                    if(x1==a[0]){
                        cout<<"One of Your Guesses is in the Right Spot"<<endl;
                        one=true;
                    }
                    else if(x1==a[1] || x1==a[2] || x1==a[3]){
                        cout<<"One of Your Guesses is in the Wrong Spot"<<endl;
                    }
                    
                    
                    if(x2==a[1]){
                        cout<<"One of Your Guesses is in the Right Spot"<<endl;
                        two=true;
                    }
                    else if(x2==a[0] || x2==a[2] || x2==a[3]){
                        cout<<"One of Your Guesses is in the Wrong Spot"<<endl;
                    }
                    
                    if(x3==a[2]){
                        cout<<"One of Your Guesses is in the Right Spot"<<endl;
                        three=true;
                    }
                    else if(x3==a[0] || x3==a[1] || x4==a[3]){
                        cout<<"One of Your Guesses is in the Wrong Spot"<<endl;
                    }
                    
                    if(x4==a[3]){
                        cout<<"One of Your Guesses is in the Right Spot"<<endl;
                        four=true;
                    }
                    else if(x4==a[0] || x4==a[1] || x4==a[2]){
                        cout<<"One of Your Guesses is in the Wrong Spot"<<endl;
                    }
                    
                    cout<<endl;

                    if(one==true && two==true && three==true && four==true){
                        cout<<"You Won!"<<endl;
                        cout<<endl;
                        break;
                    }

                    tries--;    //Tries goes down
                
                    cout<<tries<<endl;
                    
                    if(tries<=0){
                        cout<<endl;
                        cout<<"You Lost Sorry! Try Again"<<endl;
                        cout<<endl;
                        break;
                    }
                    
                }while(tries>0); 
                
            }
            case 2:{
                cout<<endl;
                cout<<"AI Coming Soon.... :]"<<endl;
                cout<<endl;
                break;
            }
            case 3:{
                cout<<endl;
                cout<<"Exiting Game... :("<<endl;
                cout<<endl;
                return 0;
            }
            default:{
                cout<<endl;
                cout<<"Not a Valid Option! Sorry, Try Again."<<endl;
                cout<<endl;
            }
        }
        
    }while(quit==false);
    

    return 0;
}

