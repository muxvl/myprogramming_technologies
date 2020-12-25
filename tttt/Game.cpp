//
//  Game.cpp
//  technology_progamming
//
//  Created by Елизавета Михеенко on 25/12/2020.
//  Copyright © 2020 Елизавета Михеенко. All rights reserved.
//

#include "Game.hpp"

//
//  Game.cpp
//  technology_progamming
//
//  Created by Елизавета Михеенко on 25/12/2020.
//  Copyright © 2020 Елизавета Михеенко. All rights reserved.
//

#include "Game.hpp"

int Game::menu_choice(int c, sf::RenderWindow &window)
{
    sf::Font font;
    font.loadFromFile(resourcePath() + "PTMono.ttc");

    sf::Text name[4], option[13];
    
    for (int i = 0; i < 4; ++i)
    {
        name[i].setFillColor(sf::Color(227, 244, 244));
        name[i].setFont(font);
        name[i].setCharacterSize(35);
        name[i].setOutlineColor(sf::Color(60, 177, 188));
        name[i].setOutlineThickness(2);
    }
    for (int i = 0; i < 13; ++i)
    {
        option[i].setFillColor(sf::Color(227, 244, 244));
        option[i].setFont(font);
        option[i].setCharacterSize(30);
        option[i].setOutlineColor(sf::Color(60, 177, 188));
        option[i].setOutlineThickness(2);
    }
    
    name[0].setString(L"Выбери напарника?");
    name[0].move(50, 30);
    option[0].setString(L"- играть с другом");
    option[1].setString(L"- играть с компьютером");
    option[0].move(50, 120);
    option[1].move(50, 190);
    
    name[1].setString(L"Выбор игрока:");
    name[1].move(50, 30);
    option[2].setString(L"- Нечётный");
    option[3].setString(L"- Чётный");
    option[2].move(50, 120);
    option[3].move(400, 120);
    
    name[2].setString(L"Выбери размер поля:");
    name[2].move(50, 30);
    option[4].setString(L"3х3");
    option[5].setString(L"4х4");
    option[6].setString(L"5х5");
    for (int i = 4; i < 7; ++i)
        option[i].move(50, 130 + 40 * (i - 5));
    
    option[7].setString(L"6х6");
    option[8].setString(L"7х7");
    option[9].setString(L"8х8");
    for (int i = 7; i < 10; ++i)
        option[i].move(225, 130 + 40 * (i - 8));
    
    option[10].setString(L"9х9");
    option[10].move(400, 130 - 40);
    
    name[3].setString(L"Пауза.Вернемся к игре?");
    name[3].move(50, 30);
    option[11].setString(L"Да,продолжаем");
    option[12].setString(L"Выход");
    option[11].move(50, 120);
    option[12].move(400, 120);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 1;
            }

            switch (c)
            {
            case 0:
                if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                {
                    if (sf::IntRect(50, 120, 160, 40).contains(sf::Mouse::getPosition(window)))
                        server = false;
                    else if (sf::IntRect(50, 190, 160, 40).contains(sf::Mouse::getPosition(window)))
                        server = true;
                    return 0;
                }
                break;
            case 1:
                if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                {
                    if (sf::IntRect(50, 120, 175, 40).contains(sf::Mouse::getPosition(window)))
                        turn = false;
                    else if (sf::IntRect(400, 120, 140, 40).contains(sf::Mouse::getPosition(window)))
                        turn = true;
                    return 0;
                }
                break;
            case 2:
                for (int i = 4; i < 11; ++i)
                {
                    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                    {
                        if (i < 7 && sf::IntRect(50, 130 + 40 * (i - 5), 115, 40).contains(sf::Mouse::getPosition(window)))
                        {
                            n = i - 1;
                            return 0;
                        }
                        else if (i < 10 && i >= 7 &&
                            sf::IntRect(225, 130 + 40 * (i - 8), 115, 40).contains(sf::Mouse::getPosition(window)))
                        {
                            n = i - 1;
                            return 0;
                        }
                        else if (i == 10 &&
                            sf::IntRect(400, 130 + 40 * (i - 11), 115, 40).contains(sf::Mouse::getPosition(window)))
                        {
                            n = i - 1;
                            return 0;
                        }
                    }
                }
                break;
            case 3:
                if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                {
                    if (sf::IntRect(50, 120, 300, 40).contains(sf::Mouse::getPosition(window)))
                        return 0;
                    else if (sf::IntRect(400, 120, 130, 40).contains(sf::Mouse::getPosition(window)))
                        return 1;
                }
                break;
            }

            switch (c)
            {
            case 0:
                if (sf::IntRect(50, 120, 160, 40).contains(sf::Mouse::getPosition(window)))
                    option[0].setFillColor(sf::Color(0, 32, 32));
                else if (sf::IntRect(50, 190, 160, 40).contains(sf::Mouse::getPosition(window)))
                    option[1].setFillColor(sf::Color(0, 32, 32));
                else
                {
                    option[0].setFillColor(sf::Color(227, 244, 244));
                    option[1].setFillColor(sf::Color(227, 244, 244));
                }
                break;
            case 1:
                if (sf::IntRect(50, 120, 175, 40).contains(sf::Mouse::getPosition(window)))
                    
                    option[2].setFillColor(sf::Color(0, 32, 32));
                    
                else if (sf::IntRect(400, 120, 140, 40).contains(sf::Mouse::getPosition(window)))
                    
                    option[3].setFillColor(sf::Color(0, 32, 32));
                else
                {
                    option[2].setFillColor(sf::Color(227, 244, 244));
                    option[3].setFillColor(sf::Color(227, 244, 244));
                }
                break;
            case 2:
                for (int i = 4; i < 11; ++i)
                {
                    if (i < 7 && sf::IntRect(50, 130 + 40 * (i - 5), 115, 40).contains(sf::Mouse::getPosition(window)))
                        
                        option[i].setFillColor(sf::Color(0, 32, 32));
                    
                    else if (i < 10 && i >= 7 &&
                        sf::IntRect(225, 130 + 40 * (i - 8), 115, 40).contains(sf::Mouse::getPosition(window)))
                        
                        option[i].setFillColor(sf::Color(0, 32, 32));
                    
                    else if (i == 10 &&
                        sf::IntRect(400, 130 + 40 * (i - 11), 115, 40).contains(sf::Mouse::getPosition(window)))
                        option[i].setFillColor(sf::Color(0, 32, 32));
                    else
                    {
                        option[i].setFillColor(sf::Color(227, 244, 244));
                    }
                }
                break;
            case 3:
                if (sf::IntRect(50, 120, 300, 40).contains(sf::Mouse::getPosition(window)))
                    
                    option[11].setFillColor(sf::Color(0, 32, 32));
                    
                else if (sf::IntRect(400, 120, 130, 40).contains(sf::Mouse::getPosition(window)))
                    
                    option[12].setFillColor(sf::Color(0, 32, 32));
                    
                else
                {
                    option[11].setFillColor(sf::Color(227, 244, 244));
                    option[12].setFillColor(sf::Color(225, 244, 244));
                }
                break;
            }
        }

        window.clear(sf::Color(214, 237, 240));

        switch(c)
        {
        case 0:
            window.draw(name[0]);
            window.draw(option[0]);
            window.draw(option[1]);
            break;
        case 1:
            window.draw(name[1]);
            window.draw(option[2]);
            window.draw(option[3]);
            break;
        case 2:
            window.draw(name[2]);
            for (int i = 4; i < 11; ++i)
                window.draw(option[i]);
            break;
        case 3:
            window.draw(name[3]);
            window.draw(option[11]);
            window.draw(option[12]);
            break;
        }

        window.display();
    }
}
int Game:: game(sf::RenderWindow &window)
{
    menu_choice(0,window);
    if (server)
        menu_choice(1,window);
    menu_choice(2,window);

        window.display();
    }
}
