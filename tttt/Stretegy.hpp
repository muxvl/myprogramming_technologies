//
//  Stretegy.hpp
//  technology_progamming
//
//  Created by Елизавета Михеенко on 25/12/2020.
//  Copyright © 2020 Елизавета Михеенко. All rights reserved.
//

#ifndef Stretegy_hpp
#define Stretegy_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <string>
#include "ResourcePath.hpp"

extern bool server, turn, number, ended, counted;
extern int n;



class Strategy
{
protected:
    sf::RenderWindow window_;
public:
    Strategy(){}
    virtual ~Strategy() {}
    virtual int game(sf::RenderWindow &window) = 0;
};


#endif /* Stretegy_hpp */

