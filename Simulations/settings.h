#include <vector>
#include "math.h"
void generator_blank(std::vector<std::vector<double>> &height, int frame);
void generator_default(std::vector<std::vector<double>> &height, int frame);
void set_defaut_mass(std::vector<std::vector<double>> &mass,int DEFAULT_MASS);

void setting_clear(std::vector<std::vector<double>> &velocity,
                   std::vector<std::vector<double>> &height,
                   std::vector<std::vector<double>> &mass,int DEFAULT_MASS);

void setting_glass_ball(std::vector<std::vector<double>> &velocity,
                        std::vector<std::vector<double>> &height,
                        std::vector<std::vector<double>> &mass,int DEFAULT_MASS);

void setting_interferention(std::vector<std::vector<double>> &velocity,
                            std::vector<std::vector<double>> &height,
                            std::vector<std::vector<double>> &mass,int DEFAULT_MASS);

void setting_test(std::vector<std::vector<double>> &velocity,
                  std::vector<std::vector<double>> &height,
                  std::vector<std::vector<double>> &mass,int DEFAULT_MASS);