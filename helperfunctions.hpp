#include <iostream>
#include <string>
#include <iostream>
using namespace std;

// struct to make user objects.
struct customer{
public:
  string name;
  string carBrand;
  string year;
};

int searchForUserInArray(customer* myArray[], int currentSize, string given_name)
{
  for(int i = 0 ; i < currentSize; i++)
  {
    if (myArray[i]->name == given_name)
    {
      return i; // returns the index of the customer that it found.
    }
  }
  return 0;
}

/*
  function should take the user name and assign it the car in the hash table if its
  not already taken ( you know its taken if the flag in the car struct is set to 0 or 1)
  so you have to find the car name in the hashtable and look at that flag
  if its set to 1
    tell the user the car is taken and ask for a different one or just exit the program
  if its set to 0
    then set the user objects carBrand to that cars name and year, then change its flag to 1
    then exit 
*/
void rentCar(string userName){
  cout << "Enter name of car you would like to rent. " << endl;
  string enteredCarName;
  getline(cin,enteredCarName);
}


/*
  this will be called when the program exits, write out all the information
  currently in the user array to the text file so it can be read from
  and loaded when the program starts. It will be loaded from the function below

  break down each object and write it on its own line

*/
void writeOutAllArrayInformation(customer* myArray[], int currentSize)
{
  string textFileName = "customerinformation.txt";
  // write to that text file

}


/*
  read in from this text file and for every line should be a user, and for every user
  create a object and put it in the array.

  everytime you put something in the array increment a counter for currentUser in the array
  then


  need to parse everyline and create new objects
*/
int loadcustomerinformation(customer* myArray[], int size){
    string textFileName = "customerinformation.txt";
    int currentSize = 0;
    // for loop creates new objects everything from the read in file
    //// for loop here




    return currentSize;
}
