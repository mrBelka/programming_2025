#pragma once
#include <iostream>

namespace meteo {
struct Datetime {
  short year;
  char month;
  char day;
  char hour;
  char min;
  char sec;
};

struct MeteoInfo {
  size_t id;
  float temp;
  float humidity;
  float wind_velocity;
  Datetime datetime;
};

std::ostream& operator<<(std::ostream& out, const MeteoInfo& info) {
  const Datetime& idt = info.datetime;
  out << "Meteostation ID = " << info.id << "\n"
      << "Time " << idt.year << " " 
      << static_cast<int>(idt.month) << " " 
      << static_cast<int>(idt.day) << " "
      << static_cast<int>(idt.hour) << " " 
      << static_cast<int>(idt.min) << " " 
      << static_cast<int>(idt.sec) << "\n"
      << "Temp = " << info.temp << "\n"
      << "Humidity = " << info.humidity << "\n"
      << "Wind velocity = " << info.wind_velocity << std::endl;
  return out;
}
}