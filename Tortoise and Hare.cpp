/* 
Brayan Villatoro (Simulation: The Tortoise and Hare) 
Project 1: 2/12/2020 (CSCI 272) 
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int RACE_END = 70; // Global race win 

// Prototype funcations 
void moveTortoise(int * const turtoisePosition);
void moveHare(int * const harePosition);
void livePositions(const int *const, const int * const);

int main()
{
   // Starting Gate    
   int tortoise = 1;
   int hare = 1;
   int timer = 0;
   
   srand( time(0));

   cout << "BANG !!!!!" << endl << "AND THEY'RE OFF !!!!!" << endl;

   while (tortoise != RACE_END && hare != RACE_END)
   {
      moveTortoise(&tortoise);
      moveHare(&hare);
	  livePositions( &tortoise, &hare);
	  timer++;
	}
     
    if (tortoise >= hare)
      	cout << "TORTIOSE WINS!!! YAY!!!" << endl;
    else if (tortoise <= hare) 
      	cout << "Hare wins. Yuch." << endl;
	else 
        cout << "It's a tie." << endl;
    
    cout << "TIME: " << timer << " Seconds" << endl;
         
   return 0;
}

void moveTortoise(int * const tortoisePosition)
{
   int step = 1 + rand() % 10; // Ran # 1-10 

   if (step >= 1 && step <= 5)
      *tortoisePosition += 3; // Fast plod
   else if (step >=6 && step <= 7)
      *tortoisePosition -= 6; // Slip
   else if (step >= 8 && step <= 10)
      *tortoisePosition += 1; // Slow plod 

   if (*tortoisePosition < 1)
      *tortoisePosition = 1;
    
    else if (*tortoisePosition > RACE_END)
    	*tortoisePosition = RACE_END;
} // Tortoise funcation close 

void moveHare(int * const harePosition)
{
   int step = 1 + (rand() % 10); // Ran # 1-10

   if (step >= 1 && step <= 2); // Sleep
   else if (step >= 3 && step <= 4)
      *harePosition += 9; // Big hope
   else if (step == 5)
      *harePosition -= 12; // Big slop 
   else if (step >= 6 && step <= 8)
      *harePosition += 1; // Small hop 
   else if (step >= 9 && step <= 10)
      *harePosition -= 2; // Small slip

   if (*harePosition < 1)
      *harePosition = 1;
	else if (*harePosition > RACE_END)
		*harePosition = RACE_END;
} // Hare funcation close 

void livePositions(const int *const turtPtr, const int * const rabbitPtr)
{
	if (*rabbitPtr == *turtPtr)
		cout << setw( *rabbitPtr) << "OUCH!!!";
	else if (rabbitPtr < turtPtr)
		cout << setw( *rabbitPtr) << 'H' << setw(*turtPtr - *rabbitPtr) << 'T';
	else  
		cout << setw(*turtPtr) << 'T' << setw(*rabbitPtr - *turtPtr) << 'H';
	
	cout << endl; 
} // Live funcation close 
