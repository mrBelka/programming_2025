#pragma once
#include <string>

namespace meteo {
struct Meteostation {
  std::string ip;
  std::string description;
  unsigned short port;
};
} // namespace meteo