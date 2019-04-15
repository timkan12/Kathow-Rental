#include <iostream>

using namespace std;

void rentMenu()
{
  cout << "     Rent Menu       " << endl;
  cout << "1. Username:" << endl;
  cout << "2. Car Model:" << endl;
  cout << "3. Car Year:" << endl;
  cout << "4. Back to Main Menu" << endl;
  cout << "5. Quit" << endl;
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

      break;

      case 5:
      cout << "Goodbye! See you soon!" << endl;

      break;
    }
  }
  return 0;
}
