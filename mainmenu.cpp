#include <iostream>
using namespace std;
void displayMenu()
{
  cout << "\t\t\t\t\tHello! Welcome to Kathow Rental" << endl;
  cout << endl;
  cout << "\t\t\t\t\tAre you here to rent or return?" << endl;
  cout << endl;
  cout << "\t\t\t\t\t=== Enter 1 for Rent ===" << endl;
  cout << endl;
  cout << "\t\t\t\t\t=== Enter 2 for Return ===" << endl;
  cout << endl;
  cout << "\t\t\t\t\t=== Enter 3 for to Exit ===" << endl;
  cout << endl;
}

void rentMenu()
{
  cout << "\t\t\t\t\t     Rent Menu       " << endl;
  cout << "\t\t\t\t\t1. Username:" << endl;
  cout << "\t\t\t\t\t2. Car Model:" << endl;
  cout << "\t\t\t\t\t3. Car Year:" << endl;
  cout << "\t\t\t\t\t4. Back to Main Menu" << endl;
  cout << "\t\t\t\t\t5. Quit" << endl;
}

void returnMenu()
{
  cout << "\t\t\t\t\t     Return Menu       " << endl;
  cout << "\t\t\t\t\t1. Username:" << endl;
  cout << "\t\t\t\t\t2. Day(s) of Rental" << endl;
  cout << "\t\t\t\t\t3. Total Cost " << endl;
  cout << "\t\t\t\t\t4. Back to Main Menu" << endl;
  cout << "\t\t\t\t\t5. Quit" << endl;
}


int main()
{
  int choice;
  while(choice != 3)
  {
    displayMenu();
    cin>>choice;
    cin.ignore();
    switch(choice)
    {
      case 1:
      int choice2;
      while(choice2 !=5)
      {
        rentMenu();
        cin>> choice2;
        cin.ignore();
        switch(choice2)
        {
          case 1:

          break;

          case 2:

          break;

          case 3:

          break;

          case 4:
          displayMenu();
          break;

          case 5:
          cout << "Goodbye! See you soon!" << endl;

      break;
    }
  }

      case 2:
      int choice3;
      while(choice3 !=5)
      {
        returnMenu();
        cin>> choice3;
        cin.ignore();
        switch(choice3)
        {
          case 1:

          break;

          case 2:

          break;

          case 3:

          break;

          case 4:
          displayMenu();
          break;

          case 5:
          cout << "Goodbye! See you soon!" << endl;

          break;
        }
      }

      case 3:
      cout << "Goodbye! See you soon!" << endl;
      break;
    }
  }
  return 0;
}
