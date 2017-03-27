// time_point_cast
#include <iostream>
#include <ratio>
#include <chrono>

int main ()
{
  using namespace std::chrono;

  typedef duration<int,std::ratio<60*60*24>> days_type;

  time_point<system_clock,days_type> today = time_point_cast<days_type>(system_clock::now());

  std::cout << today.time_since_epoch().count() << " days since epoch" << std::endl;
  std::time_t tt = system_clock::to_time_t(today);
  std::cout << "time_point tp is: " << ctime(&tt);

  typedef duration<int,std::ratio<60*60>> hours_type;
  time_point<system_clock,hours_type> today1 = time_point_cast<hours_type>(system_clock::now());

  std::cout << today1.time_since_epoch().count() << " hours since epoch" << std::endl;
  std::time_t tt1 = system_clock::to_time_t(today1);
  std::cout << "time_point tp is: " << ctime(&tt1);

  typedef duration<long,std::ratio<1, 1000>> millisec_type;
  time_point<system_clock,millisec_type> today2 = time_point_cast<millisec_type>(today1);

  std::cout << today2.time_since_epoch().count() << " millisec since epoch" << std::endl;
  std::time_t tt2 = system_clock::to_time_t(today2);
  std::cout << "time_point tp is: " << ctime(&tt2);


  typedef duration<long,std::ratio<1, 1000>> millisec_type1;
  time_point<system_clock,millisec_type1> today3 = time_point_cast<millisec_type1>(system_clock::now());

  std::cout << today3.time_since_epoch().count() << " millisec since epoch" << std::endl;
  std::time_t tt3 = system_clock::to_time_t(today3);
  std::cout << "time_point tp is: " << ctime(&tt3);



  return 0;
}
