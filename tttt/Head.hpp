//
//  Head.hpp
//  technology_progamming
//
//  Created by Елизавета Михеенко on 25/12/2020.
//  Copyright © 2020 Елизавета Михеенко. All rights reserved.
//

#ifndef Head_hpp
#define Head_hpp
#include "Stretegy.hpp"

class Head : public Strategy{
public:
    Head(sf::RenderWindow &window){}
    virtual ~Head() {};
    int game(sf::RenderWindow &window) override;
};
#endif /* Head_hpp */

