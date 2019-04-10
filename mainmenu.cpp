#include <iostream>
using namespace std;
void displayMenu()
{
  cout << "Hello! Welcome to Kathow Rental" << endl;
  cout << endl;
  cout << "Are you here to rent or return?" << endl;
  cout << endl;
  cout << "=== Enter 1 for Rent ===" << endl;
  cout << endl;
  cout << "=== Enter 2 for Return ===" << endl;
  cout << endl;
  cout << "=== Enter 3 for to Exit ===" << endl;
  cout << endl;

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

      break;

      case 2:

      break;

      case 3:
      cout << "Goodbye! See you soon!" << endl;
      break;
    }
  }
  return 0;
}
