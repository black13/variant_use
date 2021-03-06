#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>
#include <map>
template<class T> struct always_false : std::false_type {};
 
using var_t = std::variant<int, long, double, std::string>;
 
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;


int main()
{
  std::map<std::string,var_t> map_of_var_t;
  map_of_var_t["1"] = 1;
  map_of_var_t["2"] = 2.0;
  map_of_var_t["3"] = "three";

  for (auto& kv : map_of_var_t) {
    std::cout << kv.first << std::endl;
  }

  for (auto& kv: map_of_var_t) {
    std::cout << kv.first << ":" ;
        std::visit(overloaded {
            [](auto arg) { std::cout << arg << "---" << std::endl; },
	      [](double arg) { std::cout << std::fixed << arg << ' ' << std::endl; },
		[](const std::string& arg) { std::cout << std::quoted(arg) << ' ' << std::endl; },
        }, kv.second);
  }
  return 0;
}
