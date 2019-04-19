#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct users{
public:
  string name;
};


void addUser(users& arrayOfUsers[], int currentSize)
{
  string username;
  cout << "input name" << endl;
  getline(cin, username);
  users *newUser = new users;
  newUser->name =  username;
  arrayOfUsers[currentSize] = newUser;


}

int main(int argc, char* argv[])
{
  int currentSize = 0;
  int size = 10;
  users arrayOfUsers[size];
  for (int i = 0; i < size; i++)
  {
    //users arrayOfUsers[size];
    addUser(*arrayOfUsers, currentSize);
    currentSize++;
  }
  int i;
  for(i = 0 ; i < size; i++)
  {
    cout << arrayOfUsers[i].name << "<<<"<< endl;
  }
  return 0;
}
