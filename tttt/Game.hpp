//
//  Game.hpp
//  technology_progamming
//
//  Created by Елизавета Михеенко on 25/12/2020.
//  Copyright © 2020 Елизавета Михеенко. All rights reserved.
//
#ifndef Game_hpp
#define Game_hpp
#include "Stretegy.hpp"

class Game : public Strategy
{
public:
    Game(sf::RenderWindow &window) {}
    virtual ~Game() {};
    int game(sf::RenderWindow &window) override;
    int menu_choice(int c, sf::RenderWindow &window);
    void clear();
private:
    sf::Clock clk;

    int** field;
    int n;

    sf::Text** num;
    sf::RectangleShape** grid;
};

#endif /* Game_hpp */
