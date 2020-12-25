#include "Head.hpp"
#include "Rules.hpp"
#include "Game.hpp"
#include "Context.hpp"

sf::RenderWindow window(sf::VideoMode(640, 360), "Let's play!");

void ClientCode()
{
    Head *head = new Head(window);
    Game *game = new Game(window);
    Rules *rules = new Rules(window);
    
    Context *play1 = new Context(head);
    while (1)
    {
        switch (play1->dohead(window))
        {
        case 0:
            play1->set_strategy(game);
            play1->dohead(window);
            break;
        case 1:
            play1->set_strategy(rules);
            play1->dohead(window);
            break;
        case 2:
            return 0;
        }
    }
    delete game;
    delete head;
    delete rules;
    delete play1;
}

int main()
{
    ClientCode();
}

