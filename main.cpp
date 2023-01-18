#include <SFML/Graphics.hpp>
#include <iostream>
#include "Simulations/simulation.h"
#include <math.h>
#include <vector>
#include <unistd.h>

const unsigned int WINDOW_WIDTH = 600;
const unsigned int WINDOW_HEIGHT = 600;
const unsigned int IMG_SCALE = 2;
const unsigned int DEFAULT_MASS = 2;

void set_defaut_mass(std::vector<std::vector<double>> &mass) {
    for (int i = 1; i < mass.size() - 1; ++i) {
        for (int j = 1; j < mass[i].size() - 1; ++j) {
            mass[i][j] = DEFAULT_MASS;
        }
    }
}

void setting_clear(std::vector<std::vector<double>> &velocity,
                   std::vector<std::vector<double>> &height,
                   std::vector<std::vector<double>> &mass) {
    set_defaut_mass(mass);

    velocity[WINDOW_WIDTH / 2][WINDOW_HEIGHT / 2] = 100;

}

void setting_glass_ball(std::vector<std::vector<double>> &velocity,
                        std::vector<std::vector<double>> &height,
                        std::vector<std::vector<double>> &mass) {
    set_defaut_mass(mass);
    int centrex = WINDOW_WIDTH / 5;
    int centrey = WINDOW_HEIGHT / 4;
    int radius = 40;
    for (int i = 1; i < mass.size() - 1; ++i) {
        for (int j = 1; j < mass[i].size() - 1; ++j) {
            int di = i - centrex;
            int dj = j - centrey;
            if (di * di + dj * dj < radius * radius) {
                mass[i][j] = DEFAULT_MASS * 10;
            }


        }
    }

    velocity[WINDOW_WIDTH / 2][WINDOW_HEIGHT / 2] = 100;

}

void setting_interferention(std::vector<std::vector<double>> &velocity,
                            std::vector<std::vector<double>> &height,
                            std::vector<std::vector<double>> &mass) {
    set_defaut_mass(mass);
    velocity[WINDOW_WIDTH / 2 - 30][WINDOW_HEIGHT / 2] = 40;
    velocity[WINDOW_WIDTH / 2 + 30][WINDOW_HEIGHT / 2] = 40;

}

void setting_test(std::vector<std::vector<double>> &velocity,
                  std::vector<std::vector<double>> &height,
                  std::vector<std::vector<double>> &mass) {
    set_defaut_mass(mass);
    int centrex = WINDOW_WIDTH / 2;
    int centrey = WINDOW_HEIGHT / 2;
    int radius = 40;
    int radius_s = 25;
    for (int i = 1; i < mass.size() - 1; ++i) {
        for (int j = 1; j < mass[i].size() - 1; ++j) {
            int di = i - centrex;
            int dj = j - centrey;
            if (di * di + dj * dj < radius * radius && di * di + dj * dj >= radius_s * radius_s) {
                height[i][j] = 10;
            }


        }
    }
}

int main() {
    std::vector<std::vector<double>> velocity(WINDOW_WIDTH, std::vector<double>(WINDOW_HEIGHT, 0.0));
    std::vector<std::vector<double>> height(WINDOW_WIDTH, std::vector<double>(WINDOW_HEIGHT, 0.0));
    std::vector<std::vector<double>> mass(WINDOW_WIDTH, std::vector<double>(WINDOW_HEIGHT, 0.0));

    std::string output = "1 - Clear plane with 1 pixel a the centre in motion \n 2 - Plane with a glass ball.\n 3 - Interferention demonstration.";
    std::cout << output;
    std::string input = "";
    std::cin >> input;
    if (input == "1") {
        setting_clear(velocity, height, mass);
    } else if (input == "2") {
        setting_glass_ball(velocity, height, mass);
    } else if (input == "3") {
        setting_interferention(velocity, height, mass);
    } else if (input == "t") {
        setting_test(velocity, height, mass);
    } else {
        return 0;
    }
    simulate(height, velocity, mass, IMG_SCALE);
    return 0;
}