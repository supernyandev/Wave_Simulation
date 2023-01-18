#include "SFML/Graphics.hpp"

void simulate(std::vector<std::vector<double>> &height,
              std::vector<std::vector<double>> &velocity,
              std::vector<std::vector<double>> &mass,
              std::function<void(std::vector<std::vector<double>> &height, int frame)>& generator,
              int IMG_SCALE);