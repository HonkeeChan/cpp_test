// get_money manipulator example
#include <iostream>     // std::cin, std::cout
#include <iomanip>      // std::get_money
#include <string>

int main ()
{
  std::string price;
  std::cout << "Please, enter the price: ";
  std::cin >> std::get_money(price);

  if (std::cin.fail()) std::cout << "Error reading price\n";
  else std::cout << "The price entered is: " << price << '\n';

  return 0;
}
