#include <SFML/Graphics.hpp>
#include "clSource.h"
#include <iostream>

using namespace sf;

using namespace std;

int main() {
    srand(0);

    int size = 800;

    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(size, size), "Weders");
    window.setFramerateLimit(60);
    sf::Vertex background[4] =
            {
                    sf::Vertex(sf::Vector2f(0, 0), Color(130, 0, 0)),
                    sf::Vertex(sf::Vector2f(0, size), Color(130, 0, 100)),
                    sf::Vertex(sf::Vector2f(size, size), Color(130, 0, 120)),
                    sf::Vertex(sf::Vector2f(size, 0), Color(50, 0, 130)),
            };
    int key=10;
  //  cin>>key;
    Circle *arr=new Circle[key];

        for(int i=0;i<key;i++){
            if(i<(key/2)){
                arr[i]=Circle(400,400);
        }
            if(i>(key/2)){
               arr[i]=Circle((rand()%(size-300)+150),(rand()%(size-300)+150),rand()%100);
            }
            if(i==(key/2)){
               arr[i]=Circle(400,400,(rand()%50),30);
            }
    }
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(background, 4, Quads);
        for (int i = 0; i < key; i++) {
            window.draw(arr[i].draw());
        }

        switch (0) {
            case 0: {
                for (int i = 0; i < key; i++) {
                    arr[i].strMove(size);
                }
                default: {
                }
            }

                window.display();
        }

    }
}