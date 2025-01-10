/*
 * CS106L Assignment 4: Weather Forecast
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 */

#include <algorithm>
#include <random>
#include <vector>
#include <iostream>


/* #### Please feel free to use these values, but don't change them! #### */
double kMaxTempRequirement = 5;
double uAvgTempRequirement = 60;

struct Forecast {
  double min_temp;
  double max_temp;
  double avg_temp;
};

/*
We need to get the min, average, and max, please make use of the standard library functions:

std::min_element( ForwardIt first, ForwardIt last );
std::accumulate(InputIt first, InputIt last, T init)
std::max_element( ForwardIt first, ForwardIt last );
*/
Forecast compute_forecast(const std::vector<double>& dailyWeather) {
  // STUDENT TODO 1: return a forecast for the daily weather that is passed in.

  Forecast forecast;
  forecast.max_temp = *std::min_element(dailyWeather.begin(), dailyWeather.end());
  forecast.min_temp = *std::max_element(dailyWeather.begin(), dailyWeather.end());
  forecast.avg_temp = std::accumulate(dailyWeather.begin(), dailyWeather.end(), 0.0) / dailyWeather.size();

  return forecast;
}

std::vector<Forecast> get_forecasts(const std::vector<std::vector<double>>& weatherData) {
  /*
   * STUDENT TODO 2: returns a vector of Forecast structs for the weatherData which contains
   * std::vector<double> which contain values for the weather on that day.
   */
  std::vector<Forecast> ans(weatherData.size());

  std::transform(weatherData.begin(), weatherData.end(), ans.begin(), compute_forecast);

  
  return ans;
}

std::vector<Forecast> get_filtered_data(const std::vector<Forecast>& forecastData) {
  // STUDENT TODO 3: return a vector with Forecasts filtered for days with specific weather.
  std::vector<Forecast> ans(forecastData.size());

  ans.erase(std::remove_if(ans.begin(), ans.end(), [](Forecast forecast){
     return forecast.max_temp - forecast.min_temp > kMaxTempRequirement & forecast.avg_temp >= uAvgTempRequirement;
  }));


  return forecastData;
}


std::vector<Forecast> get_shuffled_data(const std::vector<Forecast>& forecastData) {
  // STUDENT TODO 4: Make use of a standard library algorithm(std::shuffle) to shuffle the data!
  std::vector<Forecast> ans(forecastData);

  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(ans.begin(), ans.end(), g);
  
  return ans;
}

std::vector<Forecast> run_weather_pipeline(const std::vector<std::vector<double>>& weatherData) {
  // STUDENT TODO 5: Put your functions together to run the weather pipeline!

  // Forecast compute_forecast(const std::vector<double>& dailyWeather)
  std::vector<Forecast> ans = get_forecasts(weatherData);

  std::vector<Forecast> ans_filtered = get_filtered_data(ans);

  // std::vector<Forecast> ans_shuffled = get_shuffled_data(ans_filtered);







  return ans;
}

/* #### Please don't change this line! #### */
#include "utils.cpp"