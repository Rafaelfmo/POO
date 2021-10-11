#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

void setSize(sf:: Sprite& sprite, int width, int height)
{
    auto dim = sprite.getLocalBounds();
    sprite.setScale((float) width / dim.width, (float) height / dim.height);
}

struct Entity 
{
    int x {0};
    int y {0};
    int step {0};
    sf:: Sprite sprite;

    Entity (int x, int y, int step, sf:: Texture& texture) 
    {
        this-> x = x;
        this-> y = y;
        this-> step = step;
        this-> sprite.setTexture(texture);
    }

    void draw (sf:: RenderWindow& window)
    {
        this-> sprite.setPosition(x * step, y *step);
        setSize(this -> sprite, step, step);
        window.draw(this -> sprite);
    }
};

struct Board 
{
    int nc = 0;
    int nl = 0;
    int step = 0;
    sf:: Sprite sprite;
    sf:: RectangleShape rect;
    Board(int nc, int nl, int step, sf::Texture& texture)
    {
        this-> nc = nc;
        this->nl = nl;
        this-> step = step;
        this-> sprite.setTexture(texture);
        this-> rect.setSize(sf::Vector2f(step, step));
        this-> rect.setFillColor(sf::Color:: Transparent);
        this-> rect.setOutlineColor(sf::Color::Black);
        this-> rect.setOutlineThickness(2);
        setSize(this->sprite, nc  * step, nl * step);
        this-> sprite.setPosition(0, 0);
    }
    void draw(sf::RenderWindow& window)
    {
        window.draw(this-> sprite);
    }
};

void moveEntity(sf::Keyboard::Key key, Entity& entity, vector<sf::Keyboard::Key> move_keys)  
{
    if (key == move_keys[0])
    entity. x--; 
    else if (key == move_keys[1])
    entity. y--;
    else if (key == move_keys[2])
    entity. x++;
    else if (key == move_keys[3])
    entity. y++;
}

int main()
{   
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::Texture wolf_text;
    wolf_text.loadFromFile("lobo.png");
    

    sf::Texture rabbit_text;
    rabbit_text.loadFromFile("coelho.png");

    sf::Texture grass_text;
    grass_text.loadFromFile("grama.jpg");

    const int STEP{100};

    Entity wolf (1, 1, STEP, wolf_text);
    Entity rabbit (3,3, STEP, rabbit_text);
    Board board(7, 5, STEP, grass_text);

    sf:: RenderWindow(sf:: VideoMode(board.nc * STEP, board.nl * STEP), "SFML works!");
       
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                {
                window.close();
                }
                    else if (event.type == sf:: Event::KeyPressed) 
                    {
                        moveEntity(event.key.code, wolf, {sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Right, sf::Keyboard::Down});
                        moveEntity(event.key.code, rabbit, {sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::D, sf::Keyboard::S});
                    }
            }   
        
        window.clear();
        board.draw(window);
        wolf.draw(window);
        rabbit.draw(window);
        window.display();
    }
    return 0;
}