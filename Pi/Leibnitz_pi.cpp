#include <cfloat>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {

  int n = 0;
  double pi = 0.0;

  cout << "Please enter a non-negative integer: " << endl;
  cin >> n;

  for (int k = 0; k <= n; k++) {
    pi += 4.0 * pow(-1, k) / (2 * k + 1);
  }
  cout << "PI (approx): " << pi << "; n: " << setw(7) << n << endl;
  cout << "PI (actual): "
       << "3.141592653589793" << endl;

  std::cout << "Decimal digits of precision: " << DBL_DIG << std::endl;
  std::cout << "Number of base 2 mantissa digits of double precision floating "
               "point value: "
            << DBL_MANT_DIG << std::endl;
  std::cout << "Next representable number from 3.141592653589793: "
            << std::nextafter(3.141592653589793, 3.14) << std::endl;

  return 0;
}
