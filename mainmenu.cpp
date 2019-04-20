#include <iostream>
#include <string>
#include <cmath>
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
  cout << "\t\t\t\t\t4. Go to Check out " << endl;
  cout << "\t\t\t\t\t5. Back to Main Menu" << endl;
  cout << "\t\t\t\t\t6. Quit" << endl;
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
        string name;
        string type;
        string year;
        switch(choice2)
        {
          case 1:
          cout << "Please enter your name: " << endl;
          //use is unique function
          getline(cin, name);
          cout << "You entered: " ;
          for(int i = 0; i < name.size(); i++)
          {
          cout << name[i];
          }
          break;

          case 2:
          cout << "Please enter your desire car model:" << endl;
          getline(cin, type);
          cout << "Searching for the desired brand: " ;
          for(int i = 0; i < type.size(); i++)
          {
          cout << type[i];
          }
          // look for the car
          break;

          case 3:
          cout << "Please enter your desire car year:" << endl;
          cin >> year;
          cout << "Searching for the desired year: " ;
          for(int i = 0; i < year.size(); i++)
          {
          cout << year[i];
          }
          // start looking for the car using a funciton
          break;

          case 4:
          // if the model exist and name hasnt check out a car already

          cout << "You, ";
          for(int i = 0; i < name.size() ; i++)
          {
           cout << name[i];
          }
         cout << ", have checked out model: ";
         for(int i = 0; i < type.size(); i++)
          {
          cout << type[i];
          }
          cout  << "year: " ;
          for(int i = 0; i < year.size(); i++)
          {
          cout << year[i] << endl;
          }
          break;

          case 5:
          displayMenu();
          break;

          case 6:
          cout << "Goodbye! See you soon!" << endl;
          exit(0);
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
          exit(0);
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
