#include "simulation.h"
#include <unistd.h>
#include "math.h"

void simulate(std::vector<std::vector<double>> &height, std::vector<std::vector<double>> &velocity,
              std::vector<std::vector<double>> &mass,
              int IMG_SCALE) {
    const unsigned WINDOW_WIDTH = height.size();
    const unsigned WINDOW_HEIGHT = height[0].size();

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH * IMG_SCALE, WINDOW_HEIGHT * IMG_SCALE), "none");
    sf::View myView(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2),
                    sf::Vector2f(WINDOW_WIDTH / IMG_SCALE * 2, WINDOW_HEIGHT / IMG_SCALE * 2));
    window.setView(myView);

    sf::Image buffer;
    buffer.create(WINDOW_WIDTH, WINDOW_HEIGHT, sf::Color(200, 0, 0));
    sf::Sprite bufferSprite;
    sf::Texture bufferTexture;
    bufferTexture.loadFromImage(buffer);
    bufferSprite.setTexture(bufferTexture, true);

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }
        double max_abs_height = 0.01;
        window.clear();
        window.draw(bufferSprite);
        bufferTexture.loadFromImage(buffer);
        window.display();
        for (int i = 1; i < WINDOW_WIDTH - 1; i++) {
            for (int j = 1; j < WINDOW_HEIGHT - 1; j++) {

                height[i][j] = height[i][j] + velocity[i][j];
                max_abs_height = std::max(abs(height[i][j]), max_abs_height);
            }
        }

        for (int i = 1; i < WINDOW_WIDTH - 1; i++) {
            for (int j = 1; j < WINDOW_HEIGHT - 1; j++) {
                //height[i][j] = height_new[i][j];
                double cnt = 0.0;
                double sumheight = 0.0;
                if (i != 0) {
                    cnt++;
                    sumheight += height[i - 1][j];
                }
                if (j != 0) {
                    cnt++;
                    sumheight += height[i][j - 1];
                }
                if (i != WINDOW_WIDTH - 1) {
                    cnt++;
                    sumheight += height[i + 1][j];
                }
                if (j != WINDOW_HEIGHT - 1) {
                    cnt++;
                    sumheight += height[i][j + 1];
                }
                double averageHeight = sumheight / cnt;

                velocity[i][j] = velocity[i][j] - (height[i][j] - averageHeight) / mass[i][j];
                int add = static_cast<int>(127.0*(height[i][j]/max_abs_height));
                buffer.setPixel(i, j, sf::Color(127 + add, static_cast<int>(127.0+127.0*cos(mass[i][j])*20.0) ,
                                                127 - add));

            }

        }
        usleep(1000);
        //std::cout << max_abs_height << '\n';
    }
}
