#include <any>
#include <string>
#include <iostream>
#include <list>
#include <map>
#include <variant>
#include <ctime>
#include <chrono>
#include <optional>
#include <utility>
struct Disconnected {};
struct Connecting {};
struct Connected {
  //ConnectionId m_id;
        std::chrono::system_clock::time_point m_connectedTime;
        std::optional<std::chrono::milliseconds> m_lastPingTime;
};
struct ConnectionInterrupted {
        std::chrono::system_clock::time_point m_disconnectedTime;
  //Timer m_reconnectTimer;
};

using State = std::variant<Disconnected, Connecting, Connected, ConnectionInterrupted>;

using foo   = std::variant<int,std::string>; 
using foo_pair = std::pair<std::string,foo>;
int main()
{
  std::list<foo> foolist;
  std::list<foo_pair> foo_pair_list;
  std::map<std::string,foo> string_map_foo;
  foolist.push_back(1);
  foolist.push_back("2");
  //
  foo_pair p("foo",1);
   //p_list.push_back(fo
  foo_pair_list.push_back(p);
  //string_map_foo.emplace(std::make_pair(std::string("a"), std::string("a")));
  string_map_foo["one"] = 1;
  string_map_foo["two"] = "two";
  auto r = string_map_foo["one"];
  //std::cout << string_map_foo["two"] << std::endl;
  
}
