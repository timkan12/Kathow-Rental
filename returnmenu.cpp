#include <iostream>

using namespace std;

void rentMenu()
{
  cout << "     Return Menu       " << endl;
  cout << "1. Username:" << endl;
  cout << "2. Day(s) of Rental" << endl;
  cout << "3. Total Cost " << endl;
  cout << "4. Quit" << endl;
}
int main()
{
  int choice=0;
  while(choice != 5)
  {
    rentMenu();
    cin>>choice;
    cin.ignore();
    switch(choice)
    {
      case 1:

      break;

      case 2:

      break;

      case 3:

      break;

      case 4:

      cout << "Goodbye! See you soon!" << endl;

      break;
    }
  }
  return 0;
}
