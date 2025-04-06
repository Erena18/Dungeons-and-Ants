#define SFML_STATIC
#include <SFML/Graphics.hpp>
using namespace sf;

/*int main()
{
    RenderWindow window(VideoMode(200, 200), "SFML works!");
    CircleShape shape(100.f);
    shape.setFillColor(Color::Cyan);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color(25, 100, 200, 0));
        window.draw(shape);
        window.display();
    }

    return 0;
}

*/