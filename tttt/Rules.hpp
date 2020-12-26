//
//  Rules.hpp
//  technology_progamming
//
//  Created by Елизавета Михеенко 
//  Copyright © 2020 Елизавета Михеенко. All rights reserved.
//

#ifndef Rules_hpp
#define Rules_hpp
#include "Stretegy.hpp"

class Rules : public Strategy
{
    public:
    Rules(sf::RenderWindow &window) {}
    virtual ~Rules() {};
    int game(sf::RenderWindow &window) override;
};
#endif /* Rules_hpp */

