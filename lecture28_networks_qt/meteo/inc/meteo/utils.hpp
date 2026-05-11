#pragma once
#include <vector>
#include <string>
#include <meteo/types.hpp>

namespace meteo {
std::vector<meteo::Meteostation> read_configuration(const std::string& filename);
} // namespace