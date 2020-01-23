#include <iostream>
#include <memory>

using namespace std;

struct Myclass
{
    int var = 0;
    ~Myclass() {
        cout << "Destructor ~Myclass" << endl;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
int main()
{

unique_ptr<Myclass> mypointer{new Myclass}; // defining unique_ptr  and creating int object in memory

if(!mypointer){
        cout << "Pointer holds null value";}


    {//another scope created to show that when life of lambda_pointer is finish
        // life of object Myclass created using operator new is finished as well
        auto mylambda = [lambda_pointer = move(mypointer)](int arg)
        {

        lambda_pointer->var = arg;
        cout << lambda_pointer->var << endl;
        };

        mylambda(123); // using mylambda
        cout << "That's the end of lambda expression life\n";
    }


if(!mypointer) // mypointer now holds null value that shows that its value has been successfully moved to lambda_pointer
    {
        cout << "\nPointer holds null value\n";
    }

}
