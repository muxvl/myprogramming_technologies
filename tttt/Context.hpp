//
//  Context.hpp
//  technology_progamming
//
//  Created by Елизавета Михеенко on 25/12/2020.
//  Copyright © 2020 Елизавета Михеенко. All rights reserved.
//
#ifndef Context_hpp
#define Context_hpp
#include "Stretegy.hpp"

class Context
{
private:
    Strategy *strategy_;
    
public:
    Context(Strategy *strategy = nullptr) : strategy_(strategy)
    {
    }
    
    ~Context() {}
    
    void set_strategy(Strategy *strategy);
    
    int dohead(sf::RenderWindow &window);
   
};

#endif /* Context_hpp */
