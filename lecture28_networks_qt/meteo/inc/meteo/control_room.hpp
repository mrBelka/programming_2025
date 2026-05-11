#pragma once
#include <string>
#include <vector>

#include <meteo/types.hpp>
#include <meteo/formats.hpp>

namespace meteo {
class ControlRoom {
public:
  struct Params {
    std::vector<Meteostation> meteostations;
  };
public:
  explicit ControlRoom(const Params& params);
  void run();
  std::vector<meteo::MeteoInfo> run_once();

private:
  const Params params_;
};
} // namespace meteo