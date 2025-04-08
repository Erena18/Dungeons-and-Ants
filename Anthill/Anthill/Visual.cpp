#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "AntVisual.h"
#include "Dimensions.h"

using namespace sf;
using namespace std;

int ants_like_to_Move_it()
{
    srand(static_cast<unsigned>(time(nullptr)));

    const int WIDTH = 1700;
    const int HEIGHT = 900;

    RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Anthill");
    window.setFramerateLimit(60);

    vector<AntVisual> ants;
    for (int i = 0; i < 30; ++i) {
        ants.emplace_back(Vec2(rand() % WIDTH, rand() % HEIGHT));
    }

    Clock clock;
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();

        for (auto& ant : ants) {
            ant.update(dt, WIDTH, HEIGHT);
        }

        window.clear(Color(255, 153, 46, 100));
        for (auto& ant : ants) {
            ant.draw(window);
        }
        window.display();
    }

    return 0;
}