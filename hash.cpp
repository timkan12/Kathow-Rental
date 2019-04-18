#include <iostream>
#include "HASH.HPP"

using namespace std;

userHashTable::HashTable(int tableSize)
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

userHashTable::~HashTable()
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

void userHashTable::addUser(string name)
{
  userName *newUser = new userName;
  newUser->name = name;
  newUser->next = NULL:
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

bool userHashTable::isInTable(string name)
{
  int count = getHash(name);
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
        check true;
        return true;
      }
      temp = temp->next;
    }
    return check;
  }
}
