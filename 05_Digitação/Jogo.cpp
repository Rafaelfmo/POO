#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
using namespace sf;

struct Pincel 
{
    Font font;
    Text text;
    RenderWindow& window;

    Pincel(RenderWindow& window) : window{window}
    {
        if(!font.loadFromFile("Ubuntu.ttf"))
            cout << "Erro no carregamento da fonte\n";
        text.setFont(font);
    }

    void write(string str, int x, int y, int size, Color color) 
    {
        text.setString(str);
        text.setCharacterSize(size);
        text.setPosition(x, y);
        text.setFillColor(color);
        window.draw(text);
    }
};

struct Bubble
{
    int x;
    int y;
    char letter;
    int speed;
    bool alive {true};

    static const int radius {10};

    Bubble(int x, int y, char letter, int speed)

    {
        this->x = x;
        this->y= y;
        this->letter = letter;
        this->speed = speed;
    }

    void update()
    {
        this-> y += this -> speed;
    }

    void draw(RenderWindow& window)
    {
        static Pincel pincel(window);
        CircleShape bubble(Bubble::radius);
        bubble.setPosition(x,y);
        bubble.setFillColor(Color::White);
        window.draw(bubble);

        static Pincel pincel(window);
        pincel.write(string(1, letter), x + 0.2 * Bubble::radius, y, Bubble::radius * 1.5, Color::Blue);
    }

};

struct Board
{
    RenderWindow& window;
    vector<Bubble> bubble;
    Pincel pincel;
    const int new_bubble_timeout{30};
    int new_bubble_timer{0};
    int hits{0};
    int misses{0};

    Board(RenderWindow& window) : window(window), pincel(window)
    {
        bubble.push_back(Bubble(100, 100, 'A', 1)); 
        bubble.push_back(Bubble(200, 100, 'B', 2));
        bubble.push_back(Bubble(300, 100, 'C', 3));
    }

    void update() 
    {
        if (this-> check_new_letter())
        this->add_new_bubble();

        for (Bubble& bubble : bubble)
        {
            bubble.update();
        }
        this->mark_outside_bubbles();
        this->remove_dead_bubbles();
    }

    void mark_outside_bubbles()
    {
        for (Bubble& bubble : bubble)
        {
            if (bubble.y + 2 * Bubble::radius > (int) this-> window.getSize().y)
            {
                if(bubble.alive){
                bubble.alive = false;
                this-> misses++;
                }
            }
        }
        
    }

    void mark_by_hit(char letter)
    {
        for (Bubble& bubble : bubble)
        {
            if (bubble.letter == letter)
            {
                bubble.alive = false;
                this-> hits++;
                break;
            }
        }
    }

    void remove_dead_bubbles()
    {
        vector<Bubble> vivas;
        for(Bubble& bubble : bubble)
        {
            if (bubble.alive)
            {
                vivas.push_back(bubble);
            }
        }
        this->bubble = vivas;
    }

    bool check_new_letter() 
    {
        new_bubble_timer--;
        if (new_bubble_timer <= 0)
        {
            new_bubble_timer = this->new_bubble_timeout;
            return true;
        }
        return false;
    }

    void add_new_bubble()
    {
        int x = rand() % ((int) this-> window.getSize().x - 2 * Bubble::radius);
        int y = -2 * Bubble::radius;
        int speed = rand() % 5 + 1;
        char letter = rand() % 26 + 'A';
        bubble.push_back(Bubble(x, y, letter, speed));
    }

    void draw()
    {
        pincel.write("Hits: " + to_string(this->hits) + "Misses: " + to_string(this->misses), 10, 10, 20, Color::White);
        pincel.write("Size; " + to_string(this->bubble.size()), 10, 30, 20, Color::White);
        for (Bubble& bubble : bubble)
        {
            bubble.draw(window);
        }
    }
};

struct Game 
{

    RenderWindow window;
    Board board;
    function<void()> on_update;

    Game() : window(VideoMode(800, 600), "Bubbles"), board(window)
    {
        this->on_update = [&]()
        {
            this->gameplay();
        };
        window.setFramerateLimit(60);
    }

    void process_events()
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
            window.close();
            } else if(event.type == Event::TextEntered) {
            char code = static_cast<char>(event.text.unicode);
            code = toupper(code);
            board.mark_by_hit(code);
            }
        }
    }

    void gameplay()
    {
        board.update();
        window.clear(Color::Black);
        board.draw();
        window.display();
        if(board.misses > 10)
        {
            this->on_update = [&]()
            {
                this->gameover();
            };
        }
    }

    void gameover()
    {
        static Pincel pincel(window);
        window.clear(Color::Red);
        pincel.write("Game Over", 400, 300, 50, Color::White);
        window.display();
    }

    void main_loop()
    {
        while (window.isOpen())
        {
            process_events();
            gameplay();
        }
    }
};

int main()
{
    Game game;
    game.main_loop();
    return 0;
}