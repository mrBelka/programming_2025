#include <meteo/utils.hpp>
#include <meteo/types.hpp>
#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>

namespace meteo {
using json = nlohmann::json;
std::vector<meteo::Meteostation> read_configuration(const std::string& filename) {
  std::ifstream in(filename);
  if (!in.is_open()) {
      throw std::runtime_error("Config.json not found");
  }
  json data = json::parse(in);

  std::vector<meteo::Meteostation> meteostations;
  meteostations.reserve(data.size());

  for(const auto& elem : data) {
      meteo::Meteostation meteostation;
      meteostation.ip = elem["ip"];
      meteostation.port = elem["port"].get<unsigned short>();
      meteostation.description = elem["description"];
      
      meteostations.emplace_back(meteostation);
  }
  return meteostations;
}
} // namespace