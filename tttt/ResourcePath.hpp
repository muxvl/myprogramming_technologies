////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Marco Antognini (antognini.marco@gmail.com),
//                         Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
#ifndef RESOURCE_PATH_HPP
#define RESOURCE_PATH_HPP
#include <string>

using namespace std;

class Strategy
{
public:
    Strategy() {}
    virtual ~Strategy() {}
    virtual int head() = 0;
    virtual void rules() = 0;
    virtual void game() = 0;
};


class Context
{
private:
    Strategy *strategy_;
    
public:
    Context(Strategy *strategy = nullptr) : strategy_(strategy)
    {
    }
    
    ~Context()
    {
        delete this->strategy_;
    }
    
    void set_strategy(Strategy *strategy)
    {
        delete this->strategy_;
        this->strategy_ = strategy;
    }
    int dohead() const
    {
        int result = this->strategy_->head();
        return result;
    }
    
    void dorules() const
    {
        this->strategy_->rules();
    }
};

class Head : public Strategy{
public:
    Head(){}
    virtual ~Head();
    
    int head() override;
    
    void game() override{
    }
    void rules() override{
        int a = 3;
    }
    
};

class Game : public Strategy
{
    public:
    Game() {}
    virtual ~Game();
    void game() override;
};

class Rules : public Strategy
{
    public:
    Rules() {}
    virtual ~Rules();
    void rules() override;
    void game() override{
           int a = 5;
    }
    int head() override{
        int a = 3;
        return a;
    }
};

void ClientCode()
{
    Context *play = new Context(new Head);
    Context *rules1 = new Context(new Rules);
    while (1)
    {
        switch (play->dohead())
        {
        case 0:
            //game();
            break;
        case 1:
            rules1->dorules();
            break;
        case 2:
            return 0;
        }
    }
    delete play;
}


string resourcePath(void);

#endif
