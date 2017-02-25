/ File Name: pgm1.cpp
// Author: Chance Borgman
// Student ID: x576g772
// Assignment Number: 1
// Description: This program takes user input to create a list of inventory items a long with information about each item, and then prints it to the screen when the user is finished.
// Last Changed: August 24, 2015

#include <iostream>
#include <string>
#include <fstream>

using namespace::std;

struct Item     //Structure used for each item of the inventory.
{
    string description;
    int quantity;
    float price;
    float total_cost;
};

int main(void)
{
    char menu_choice;               //Menu variable.
    Item item[50];                  //Array used to store each item.
    int inventory_cost = 0;         //Initializes total inventory cost variable.
    ofstream item_file;
    item_file.open("inventory.txt");
    
    if (item_file.fail())           //Tests to make sure the file opened correctly.
    {
        cout << "Could not open file.\n";
    }
    else                            //Loop that performs the main procedures of the program.
    {
        for(int i = 0; i <= 50; i++)
        {
            cout << "Enter item description: ";     //User inputted data for each item.
            cin >> item[i].description;
            cout << "Enter item quantity: ";
            cin >> item[i].quantity;
            cout << "Enter item price: ";
            cin >> item[i].price;
            item[i].total_cost = item[i].quantity * item[i].price;      //Calculates total cost for each item.
            
            
            do{                      //Error loop for the menu choices.
                cout << "Would you like to enter another item? Y = yes, N = no\n";
                cin >> menu_choice;
            
                if(menu_choice != 'Y' && menu_choice != 'y' && menu_choice != 'N' && menu_choice != 'n')
                {
                    cout << "Invalid input. Try again.\n";
                }
            }while (menu_choice != 'Y' && menu_choice != 'y' && menu_choice != 'N' && menu_choice != 'n');
            
            if (menu_choice == 'N' || menu_choice == 'n')    //Loop used to print to file and to screen when user inputs n.
            {
                for (int j = 0; j <= i; j++)
                {
                    item_file << "Item #" << j + 1 << "\nDescription: "<< item[j].description << "\nQuantity: " << item[j].quantity << "\nPrice: $" << item[j].price << "\nTotal Cost: $" << item[j].total_cost << "\n\n";
                    
                    cout << "Item #" << j+1 << " Total Cost: $" << item[j].total_cost << "\n";
                    inventory_cost = inventory_cost + item[j].total_cost;
                }
                
                cout << "Total cost for entire inventory: $" << inventory_cost << "\n";
                
                item_file.close();
                return 0;
            }
        }
    }
}
