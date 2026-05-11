#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include <meteo/formats.hpp>
#include <meteo/types.hpp>
#include <meteo/control_room.hpp>

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

int main() {
    try {
        meteo::ControlRoom::Params params;
        params.meteostations = read_configuration("config.json");

        meteo::ControlRoom room(params);
        room.run();
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unhandled exception!" << std::endl;
    }
    
    return 0;
}