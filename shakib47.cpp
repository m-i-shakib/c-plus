/*
create 2 classes:
1. SimpleCalculator: Takes input of 2 numbers using a unility function and perfoms +,-,*,/ and
display the results using another function.
2. ScientificCalculator: takes input of 2 numbers using a utility function and perfoms any four
scientific operation of your choice and displays the results using another function.

create another class HybridCalculator and inherit it using these 2 classes:
Q1. What type of Inheritance are you using?---> Multiple Inheritance
Q2. which mode of Inheritance are you using?---> public simpleCalculator,public scientificCalculator
Q3. Create an object of Hybridcalculator and display results of simple and scientific calculator.
Q4. How is code reusability implemented?
*/
#include<iostream>
#include<cmath>
using namespace std;

class SimpleCalculator {
    int a, b;
    public:
        void getDataSimple()
        {
            cout<<"Enter the value of a"<<endl;
            cin>>a;
            cout<<"Enter the value of b"<<endl;
            cin>>b;
        }

        void performOperationsSimple(){
            cout<<"The value of a + b is: "<<a + b<<endl;
            cout<<"The value of a - b is: "<<a - b<<endl;
            cout<<"The value of a * b is: "<<a * b<<endl;
            cout<<"The value of a / b is: "<<float(a) / b<<endl;
        }
};
class ScientificCalculator{
    int a, b;

    public:
        void getDataScientific()
        {
            cout << "Enter the value of a" << endl;
            cin >> a;
            cout << "Enter the value of b" << endl;
            cin >> b;
        }

        void performOperationsScientific()
        { 
            cout << "The value of cos(a) is: " << cos(a) << endl;
            cout << "The value of sin(a) is: " << sin(a) << endl;
            cout << "The value of exp(a) is: " << exp(a) << endl;
            cout << "The value of tan(a) is: " << tan(a) << endl;
        }
};
class HybridCalculator : public SimpleCalculator, public ScientificCalculator{
    
};
int main()
{
    HybridCalculator calc;
    calc.getDataScientific();
    calc.performOperationsScientific();
    calc.getDataSimple();
    calc.performOperationsSimple();
    
    return 0;
}
