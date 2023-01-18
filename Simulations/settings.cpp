#include "settings.h"


void set_defaut_mass(std::vector<std::vector<double>> &mass,int DEFAULT_MASS) {
    for (int i = 1; i < mass.size() - 1; ++i) {
        for (int j = 1; j < mass[i].size() - 1; ++j) {
            mass[i][j] = DEFAULT_MASS;
        }
    }
}

void setting_clear(std::vector<std::vector<double>> &velocity,
                   std::vector<std::vector<double>> &height,
                   std::vector<std::vector<double>> &mass,int DEFAULT_MASS) {
    set_defaut_mass(mass,DEFAULT_MASS);
    int WINDOW_WIDTH = mass.size();
    int WINDOW_HEIGHT = mass[0].size();
    velocity[WINDOW_WIDTH / 2][WINDOW_HEIGHT / 2] = 100;

}

void setting_glass_ball(std::vector<std::vector<double>> &velocity,
                        std::vector<std::vector<double>> &height,
                        std::vector<std::vector<double>> &mass,int DEFAULT_MASS) {
    set_defaut_mass(mass,DEFAULT_MASS);

    int WINDOW_WIDTH = mass.size();
    int WINDOW_HEIGHT = mass[0].size();
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
                            std::vector<std::vector<double>> &mass,int DEFAULT_MASS) {
    set_defaut_mass(mass,DEFAULT_MASS);

    int WINDOW_WIDTH = mass.size();
    int WINDOW_HEIGHT = mass[0].size();
    velocity[WINDOW_WIDTH / 2 - 30][WINDOW_HEIGHT / 2] = 40;
    velocity[WINDOW_WIDTH / 2 + 30][WINDOW_HEIGHT / 2] = 40;

}

void setting_test(std::vector<std::vector<double>> &velocity,
                  std::vector<std::vector<double>> &height,
                  std::vector<std::vector<double>> &mass,int DEFAULT_MASS) {
    set_defaut_mass(mass,DEFAULT_MASS);

    int WINDOW_WIDTH = mass.size();
    int WINDOW_HEIGHT = mass[0].size();
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