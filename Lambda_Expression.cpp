#include <iostream>

using namespace std;

void testLgreet(void (*pointer_greet)(string))
    {
        pointer_greet("Wieslaw");
    }

int main()
{
string surname{"Pavon"};

//A lambda can introduce new variables in its body (in C++14),
// and it can also access, or capture, variables from the surrounding scope(in this case below 'surname')
auto Lgreet1 = [sur = surname](string name){cout << "Hello " << name << " " << sur << endl;};
auto Lgreet2 = [](string name){cout << "Hello " << name << " " << endl;};



Lgreet1("Jesus");
testLgreet(Lgreet2);

}
