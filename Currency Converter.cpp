#include <iostream>
using namespace std;



int new_option;



// Function for operations in Currency Converter

void currency_converter(){

    cout << "Available options for currency conversion are:" << endl;

    cout << "1. Convert to USD" << endl;

    cout << "2. Convert to Euro" << endl;

    cout << "3. Convert to Pound" << endl;

    cout << "\n";

    /*

        Take an appropriate option to select which operation

        you want to be performed by the currency converter.

    */

   

    int option;

    cout << "Your option: ";

    cin >> option;

    float Tk;



    switch(option)

    {

        // Case for Converting Tk to USD(US Dollar)

        case 1:

            cout << "\nEnter the Tk amount to convert into USD: ";

            cin >> Tk;

            Tk *= 0.0082;



            cout << "The converted USD amount: " << Tk << endl;

            cout << "Do you want to convert to a new currency?\nPress 1 to 'proceed' and 2 to 'exit' from here\n" << endl;

            cout << "Your option: ";

            cin >> new_option;

            if (new_option == 1){

                currency_converter();

            }

        break;

       

        // Case for Converting INR to EUR(Euro)

        case 2:

            cout << "\nEnter the Tk amount to convert into EUR: ";

            cin >> Tk;

            Tk *= 0.0072;



            cout << "The converted Pound amount: " << Tk << endl;

            cout << "Do you want to convert to a new currency?\nPress 1 to 'proceed' and 2 to 'exit' from here\n" << endl;

            cout << "Your option: ";

            cin >> new_option;

            if (new_option == 1){

                currency_converter();

            }

        break;

       

        // Case for Converting INR to Pound

        case 3:

            cout << "\nEnter the Tk amount to convert into Pound: ";

            cin >> Tk;

            Tk *= 0.0060;



            cout << "The converted Pound amount: " << Tk << endl;

            cout << "Do you want to convert to a new currency??\nPress 1 to 'proceed' and 2 to 'exit' from here\n" << endl;

            cout << "Your option: ";

            cin >> new_option;

            if (new_option == 1){

                currency_converter();

            }

        break;

    }

}



int main()

{

    currency_converter();

    cout << "Thank you!";

    return 0;

}