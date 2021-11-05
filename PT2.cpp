//Performance Task 2:
//Description: Console Debugging App using functions [Dollar to Peso & Peso to Dollar]

//Name: Kim Carlo Larino

#include <iostream>
#include <string>

using namespace std;

struct group_facet: public numpunct<char> {
    protected:
        string do_grouping() const {return "/003";}
};

float conversionRate = 50.73;
unsigned dollarsIn,pesoIn;
int ch, ans=0;

void promptAndWait()
{
    cin.ignore(100, '\n');
    cout << "\nPress Enter or Return to continue...";
    cin.get();
};

void dollarsToPeso(float conversionRate, unsigned dollar)
{
    cout.setf(ios::fixed);
    cout.precision(2);

    cout.imbue(locale(cout.getloc(), new group_facet));
    cout << "\n$"<<dollar<<" US = " << (conversionRate * dollar) << " Pesos.\n";
};

void pesoToDollars(float conversionRate, unsigned peso)
{
    cout.setf(ios::fixed);
    cout.precision(2);

    cout.imbue(locale(cout.getloc(), new group_facet));
    cout <<endl;
    cout <<peso<< " Pesos = " <<(peso / conversionRate) << " Dollars.";
    cout <<endl;
}

int main(){

    do{
        system("cls");
        cout << endl;
        cout << "Dollar to Peso Conversion App" <<endl <<endl;
        cout << "[1] Dollar to Peso" <<endl;
        cout << "[2] Peso to Dollar" <<endl;
        cout << "[3] Exit the Conversion App" <<endl;
        cout << "Select Conversion: ";
        cin >> ch;

        switch(ch){
            case 1: {
                cout << endl;
                cout << "<<Convert Dollar to Peso>>" <<endl<<endl; 
                cout << "Enter US dollar amount (without the dollar sign, commas, or decimal): ";
                cin >> dollarsIn;
                dollarsToPeso(conversionRate, dollarsIn);
                promptAndWait();
            break;
            }

            case 2:{
                cout << endl;
                cout <<"<<Convert Peso to Dollar>>"<< endl<<endl;
                cout << "Enter Philippine Peso amount (without the peso sign, commas, or decimal): ";
                cin >> pesoIn;
                pesoToDollars(conversionRate, pesoIn);
                cout <<endl;
                promptAndWait();
            break;
            }

            case 3:{
                cout << endl;
                cout << "Conversion App Terminated" <<endl; 
                cout << "Thank you for using the app!";
                cout << endl<<endl;
                return 0;
            break;
            }
            default:{
                cout << endl;
                cout << endl;
                cout << "Invalid Input!";
                cout << endl;
                promptAndWait();
            break;
            }
        }
    }while(ans == 0);
}