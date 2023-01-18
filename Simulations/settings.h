#include <vector>

void set_defaut_mass(std::vector<std::vector<double>> &mass,int DEFAULT_MASS);

auto setting_clear(std::vector<std::vector<double>> &velocity,
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