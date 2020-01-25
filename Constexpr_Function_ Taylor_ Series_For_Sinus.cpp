//To calculate sinus value of certain angle we can use Taylor series
//One way is to take a certain amount of terms (the more terms you take, the more accurate the approximation)
// from the Taylor series for sine:
//                                      sin x = x − x3/3! + x5/5! − x7/7! + ...,
//                                       where x is in radians
//

#include<iostream>
using namespace std;

constexpr long double pi{3.14159265};

constexpr unsigned long long  fractorial(long long number)//first we it's nice to have fractorial calculation function
{
    unsigned long long  sum = 1; // it's allowed from C++14 standard to create and initialize variable in constexpr function

    for(int n = 1;n <= number;n++) // loops are allowed too :)
        {
          sum = sum * n;
        }

    return sum;
}
//********************************************************************************************************
constexpr double sinus_degree_calculator(int angle, int accuracy = 10)
{

    //we need to change angle degree to rad
    //it's nice to pass angle in degree but Taylor series works on radians!

    //simple calculation
    long double rad_angle = angle * pi / 180.0;

    double result{};

    for(int i = 0 ; i <= accuracy; i++)
        {
            int sign = ((i % 2)? (-1) :  (1) );// in Taylor series we start from '-' sign (x − x3/3! + x5/5! − x7/7! + ...,)
            int exponent = (2*i + 1); // 1 ,3 ,5 ,7 ,9


            long double power_of_rad_angle{rad_angle};
              for(int i = 1; i < exponent;i++ ) // calculating power of rad_angle
                  {
                      power_of_rad_angle = power_of_rad_angle * rad_angle;
                  }

            double chain_cell = sign * power_of_rad_angle / fractorial(exponent);
            result = result + chain_cell;
        }
   return result;


}

constexpr double sinus_30_degree = sinus_degree_calculator(30); // this calculated by compiler before program starts

int main()
{
   cout << fractorial(3) << endl; // that function is calculated during compile time
   cout << sinus_30_degree << endl;
}
