#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "AntVisual.h"
#include "Vec2.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    const int WIDTH = 800;
    const int HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Ant Simulation");
    window.setFramerateLimit(60);

    std::vector<AntVisual> ants;
    for (int i = 0; i < 50; ++i) {
        ants.emplace_back(Vec2(rand() % WIDTH, rand() % HEIGHT));
    }

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();

        for (auto& ant : ants) {
            ant.update(dt, WIDTH, HEIGHT);
        }

        window.clear(sf::Color::White);
        for (auto& ant : ants) {
            ant.draw(window);
        }
        window.display();
    }

    return 0;
}