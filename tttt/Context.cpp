//
//  Context.cpp
//  technology_progamming
//
//  Created by Елизавета Михеенко 
//  Copyright © 2020 Елизавета Михеенко. All rights reserved.
//
#include "Context.hpp"



void Context::set_strategy(Strategy* strategy)
{
    if (strategy_ != strategy)
        this->strategy_ = strategy;
}

int Context::dohead(sf::RenderWindow &window)
{
    int result = this->strategy_->game(window);
    return result;
}

