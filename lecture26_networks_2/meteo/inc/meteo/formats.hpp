#pragma once

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
  float temp;
  float humidity;
  float wind_velocity;
  Datetime datetime;
};
}