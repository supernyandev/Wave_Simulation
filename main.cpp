#include <SFML/Graphics.hpp>
#include <iostream>
#include "Simulations/simulation.h"
#include <math.h>
#include <vector>
#include <unistd.h>
#include "Simulations/settings.h"
const unsigned int WINDOW_WIDTH = 600;
const unsigned int WINDOW_HEIGHT = 600;
const unsigned int IMG_SCALE = 2;
const unsigned int DEFAULT_MASS = 2;



int main() {
    std::vector<std::vector<double>> velocity(WINDOW_WIDTH, std::vector<double>(WINDOW_HEIGHT, 0.0));
    std::vector<std::vector<double>> height(WINDOW_WIDTH, std::vector<double>(WINDOW_HEIGHT, 0.0));
    std::vector<std::vector<double>> mass(WINDOW_WIDTH, std::vector<double>(WINDOW_HEIGHT, 0.0));

    std::string output = "1 - Clear plane with 1 pixel a the centre in motion \n 2 - Plane with a glass ball.\n 3 - Interferention demonstration.";
    std::cout << output;
    std::string input = "";
    std::cin >> input;
    if (input == "1") {
        setting_clear(velocity, height, mass,DEFAULT_MASS);
    } else if (input == "2") {
        setting_glass_ball(velocity, height, mass,DEFAULT_MASS);
    } else if (input == "3") {
        setting_interferention(velocity, height, mass,DEFAULT_MASS);
    } else if (input == "t") {
        setting_test(velocity, height, mass,DEFAULT_MASS);
    } else {
        return 0;
    }
    simulate(height, velocity, mass, IMG_SCALE);
    return 0;
}