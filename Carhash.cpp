#include <iostream>
#include "Carhash.hpp"
using namespace std;

carHashTable::carHashTable()
{

}
void carHashTable::HashTable(int tableSize)
{
  hashTableSize = tableSize;
  hashTable = new userName *[hashTableSize];
  for(int i = 0; i < tableSize; i++)
  {
    hashTable[i] = NULL;
  }
  numItems = 0;
  numCollisions = 0;
}

carHashTable::~carHashTable()
{
  for(int i = 0; i < hashTableSize; i++)
  {
    userName *temp = hashTable[i];
    while(temp != NULL)
    {
      userName *del = temp->next;
      delete temp;
      temp = del;
    }
  }
  delete [] hashTable;
}

void carHashTable::addUser(string name)
{
  userName *newUser = new userName;
  newUser->name = name;
  newUser->next = NULL;
  newUser->count = 1;

  int index = getHash(name);
  userName *temp = hashTable[index];

  if(temp != NULL)
  {
    numCollisions = numCollisions + 1;
    newUser->next = hashTable[index];
    hashTable[index] = newUser;
  }
  else
  {
    hashTable[index] = newUser;
  }
  numItems++;
}

bool carHashTable::isInTable(string name)
{
  int index = getHash(name);
  if(hashTable[index] == NULL)
  {
    return false;
  }
  else
  {
    bool check = false;
    userName *temp = hashTable[index];
    while(temp != NULL)
    {
      if(temp->name == name)
      {
        return true;
      }
      temp = temp->next;
    }
    return check;
  }
}
