#include "menus.hpp"
#include "helperfunctions.hpp"
#include "carhash.cpp"
#include <iomanip>
#include <string>
#include <fstream>


using namespace std;


int main()
{
  int hashSize = 100;
  int size = 100; // max number of users in the system
  customer* arrayOfCustomers[size];   // array that holds all the customer objects.
  string name;
  int currentSize = loadcustomerinformation(arrayOfCustomers,size);      // how many people are currently in the system

  int choice = 0;
  while(choice != 3)
  {
    loadcustomerinformation(arrayOfCustomers,size);
    displayMenu();
    cin>>choice;      // take in the user input
    cin.ignore();
    switch(choice)
    {
      case 1:
      cout << "Please enter your name: " << endl;
      getline(cin,name);
      int check;
      check = searchForUserInArray(arrayOfCustomers, currentSize, name);
      if(check == -1) // if the customer isn't in the system
      {
        cout << "You have been added to our database!" << endl;
        customer* newCustomer = new customer;
        newCustomer->name = name;
        newCustomer->carBrand = "";
        newCustomer->year = "";
        newCustomer->isRented = 0;
        arrayOfCustomers[currentSize] = newCustomer;

        currentSize++;  // at this point a new customer should have been added to the array

        cout << "These are all the cars available in our inventory:" << endl;
        carTextFile();

        cout << "Enter name of car you would like to rent." << endl;
        string brand;
        getline(cin,brand);

        //input validation
        while(brand != "Toyota" && brand != "Honda" && brand !="Tesla" && brand !="Lexus" && brand !="Audi" && brand !="BMW" && brand !="Nissan" && brand != "Kia" && brand != "Jeep" && brand != "Ferrari")
        {
          cout << "Error, please try again" << endl;
          cout << "Enter name of car you would like to rent." << endl;
          getline(cin,brand);
          if(brand == "Toyota" || brand == "Honda" || brand =="Tesla" || brand =="Lexus" || brand =="Audi" || brand =="BMW" || brand =="Nissan" || brand == "Kia" || brand == "Jeep" || brand == "Ferrari")
          {
            break;
          }
        }
        cout << "Enter your desire year" << endl;
        string enteredYear;
        getline(cin,enteredYear);

        //input validation
        while(enteredYear != "2017" && enteredYear != "2018" && enteredYear != "2019")
        {
          cout << "Error, please try again" << endl;
          cout << "Enter your desire year" << endl;
          getline(cin,enteredYear);
          if(enteredYear == "2017" || enteredYear == "2018" || enteredYear == "2019")
          {
            break;
          }
        }
        newCustomer->carBrand = brand;
        newCustomer->year = enteredYear;
        newCustomer->isRented = 1;

      }
      else if (check != -1 ) // if they are in the system
      {
        if (arrayOfCustomers[check]->carBrand != ""){
          cout << "You are currently renting out a " << arrayOfCustomers[check]->year << " " << arrayOfCustomers[check]->carBrand << endl;
        }
        // rents car
        else{
          cout << "These are all the cars available in our inventory:" << endl;
          carTextFile();
          cout << "Enter name of car you would like to rent." << endl;
          string brand;
          getline(cin,brand);

          //input validation
          while(brand != "Toyota" && brand != "Honda" && brand !="Tesla" && brand !="Lexus" && brand !="Audi" && brand !="BMW" && brand !="Nissan" && brand != "Kia" && brand != "Jeep" && brand != "Ferrari")
          {
            cout << "Error, please try again" << endl;
            cout << "Enter name of car you would like to rent." << endl;
            getline(cin,brand);
            if(brand == "Toyota" || brand == "Honda" || brand =="Tesla" || brand =="Lexus" || brand =="Audi" || brand =="BMW" || brand =="Nissan" || brand == "Kia" || brand == "Jeep" || brand == "Ferrari")
            {
              break;
            }
          }
          cout << "Enter your desire year" << endl;
          string enteredYear;
          getline(cin,enteredYear);

          while(enteredYear != "2017" && enteredYear != "2018" && enteredYear != "2019")
          {
            cout << "Error, please try again" << endl;
            cout << "Enter your desire year" << endl;
            getline(cin,enteredYear);
            if(enteredYear == "2017" || enteredYear == "2018" || enteredYear == "2019")
            {
              break;
            }
          }
          arrayOfCustomers[check]->carBrand = brand;
          arrayOfCustomers[check]->year = enteredYear;
          arrayOfCustomers[check]->isRented = 1;
          cout << "You have successfully checked a " << arrayOfCustomers[check]->carBrand <<  " " << arrayOfCustomers[check]->year << endl;
          writeOutAllArrayInformation(arrayOfCustomers, currentSize);
          exit(0);

        }

      break;

      case 2:  // this is when they want to return it

      cout << "Enter name: " << endl;
      getline(cin,name);
      int check;
      check = searchForUserInArray(arrayOfCustomers, currentSize, name);
      if (check == -1) // not found in the system
      {
        cout << "User not found." << endl;
        // ask them again for a different name
      }
      else if (check != -1){ // they are in the system, clear the flag in the hashtable of the car, and clear their variable for car
        cout << "returning car..." << endl;
        // clear the private member of the user
        arrayOfCustomers[check]->carBrand = "";
        arrayOfCustomers[check]->year = "";
        arrayOfCustomers[check]->isRented = 0;
        /* need to set the flag in the hashtable of the object of cars back to 0
          go through the hashtable and find that car if it exits
            if it does change its flag to 0
            if it doesn't exist then tell the user the car doesn't exists and ask again or exit.
        */
        cout << "You have successfully returned the car!" << endl;
        cout << "What's the number of days you've checked out? " << endl;
        string days;
        getline(cin,days);
        int random = rand() * stoi(days);
        cout << "Your total cost is: $" << random << endl;
        cout << "Have a good day!" << endl;
        writeOutAllArrayInformation(arrayOfCustomers, currentSize);
        exit(0);
      }
      break;

      case 3:
      cout << "Thank you, hope to see you soon!" << endl;
      writeOutAllArrayInformation(arrayOfCustomers, currentSize);
      // write the arrayOfCustomers to a text file in the format of the customer structure
      // everytime the program starts the that text file of the user should be read in and new objects
      // should be created and fill the array with what was previously there before.
      // call the writeOutAllArrayInformation function so it write all the information to text file so it can be loaded next runtime
      exit(0);
    }
  }
    }
  }
