#include <iostream>

struct my_true_type
{
public:
    operator bool() const
    {
        return true;
    }

};
///////////////////////////////////////////////////////////////////////
struct my_false_type
{
public:
    operator bool() const
    {
        return false;
    }

};
using namespace std;

template<typename T>
my_false_type  IsTypeNice; //variable IsTypeNice  has type my_false_type for all types represented by T

template<> // first specialization of template variable above(string specialization)
my_true_type IsTypeNice<string>; // IsTypeNice  has type true_type

template<> //second specialization(C_string specialization)
my_true_type IsTypeNice<const char*>; //we like C-strings as well



template<typename T>
void ambiguous(T arg, my_false_type var)
    {
        cout << "So lets multiply  value of argument";
        arg = arg * 12;
    }

template<typename T>
void ambiguous(T arg, my_true_type)
    {
        cout << "First element of this string is: " << arg[0] << endl;
    }



template<typename T>
void decision(T arg) //this function checks type of argument passed
                     //and then behaves different based on type passed
{
    if(IsTypeNice<T>) //struct(class) std::true_type has operator bool()  overloaded and returns true, std::my_false_type return false
        {             // so we can use them in if condition
            cout << "This is text(string or Cstring)\n";
            cout << arg << endl;
            //cout <<arg[0];   we cannot do it here because this operation is not allowed for int,double etc variables
            //despite we are in if instruction which will be executed when  string argument is passed
            //it does not matter for compiler
            //this whole function decision must be prepared for string and no strings arguments
            //we can only do here what IS POSSIBLE  with any(string or no strings) argument

        }
    else
        {
            cout << "\nThis is NOT string nor Cstring\n";
            cout << arg << endl;
            //arg = arg * 6; // this is not allowed here as well
            //we can only do here what IS POSSIBLE  with any(string or no strings) argument
        }

    //but we can call another function  below and pass argument IsTypeNice,depends on type T
    //one overloaded version is  true_type for string and c-strings
    //second overloaded version is  my_false_type

ambiguous(arg, IsTypeNice<T>);

}

int main()
{
 string text{"some text"};
 decision(text);
 decision(12);
 cout << endl;
}




