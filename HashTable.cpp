#include<iostream>
#include <list>
using namespace std;

class Hash
{
    int Cars;    // No. of buckets

    // Pointer to an array containing cars
    list<int> *table;
public:
    Hash(int V);  // Constructor

    // inserts a key into hash table
    void insertCars(int x);

    // deletes a key from hash table
    void deleteCars(int key);

    // hash function to map values to key
    int hashFunction(int x) {
        return (x % Cars);
    }

    void displayHash();
};

Hash::Hash(int b)
{
    this->Cars = b;
    table = new list<int>[BUCKET];
}

void Hash::insertCars(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteCars(int key)
{
  // get the hash index of key
  int index = hashFunction(key);

  // find the key in (inex)th list
  list <int> :: iterator i;
  for (i = table[index].begin();
           i != table[index].end(); i++) 
  {
    if (*i == key)
      break;
  }

  // if key is found in hash table, remove it
  if (i != table[index].end())
    table[index].erase(i);
}

// function to display hash table
void Hash::displayHash() 
{
  for (int i = 0; i < Cars; i++)
  {
    cout << i;
    for (auto x : table[i])
      cout << " --> " << x;
    cout << endl;
  }
}

// Driver program
int main()
{
  // array that contains keys to be mapped
  int a[] = {Toyota, Ford, Honda, Chevy, Ram};
  int n = sizeof(a)/sizeof(a[0]);

  // insert the keys into the hash table
  Hash h(7);   // 7 is count of Cars in
               // hash table
  for (int i = 0; i < n; i++)
    h.insertCars(a[i]);

  // delete Ram from hash table
  h.deleteCars(Ram);

  // display the Hash table
  h.displayHash();

  return 0;
} 
