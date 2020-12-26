//
//  Head.cpp
//  technology_progamming
//
//  Created by Елизавета Михеенко 
//  Copyright © 2020 Елизавета Михеенко. All rights reserved.
//

#include "Head.hpp"



int Head::game(sf::RenderWindow &window)
{
    if (!window.isOpen()) return 2;
    
    sf::Font font;

    if (!font.loadFromFile(resourcePath() + "PTMono.ttc"))
        return EXIT_FAILURE;

    sf::Text name[2], menu[3];
    
    for (int i = 0; i < 2; ++i)
    {
        name[i].setFillColor(sf::Color(227, 244, 244));
        name[i].setFont(font);
        name[i].setCharacterSize(70);
        name[i].move(100 + 225 * i, 30);
        name[i].setOutlineColor(sf::Color(60, 177, 188));
        name[i].setOutlineThickness(4);
    }
    
    for (int i = 0; i < 3; ++i)
    {
        menu[i].setFillColor(sf::Color(192, 224, 224));
        menu[i].setFont(font);
        menu[i].setCharacterSize(30);
        menu[i].move(100, 140 + 50 * i);
        menu[i].setOutlineColor(sf::Color(64, 128, 128));
        menu[i].setOutlineThickness(2);
    }
    
    name[0].setString(L"ЧЕТ -");
    name[1].setString(L" НЕЧЕТ");
    menu[0].setString(L"- Поиграем?");
    menu[1].setString(L"- Узнать правила игры");
    menu[2].setString(L"- Выход");

    int i = 0;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 2;
            }

            for (int i = 0; i < 3; ++i)
            {
                if (sf::IntRect(100, 140 + 50 * i, 330, 40).contains(sf::Mouse::getPosition(window)))
                {
                    menu[i].setFillColor(sf::Color(0, 32, 32));

                    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                    {
                        return i;
                    }
                }
                else
                {
                    menu[i].setFillColor(sf::Color(192, 224, 224));
                }
            }
        }

        window.clear(sf::Color(214, 237, 240));

        for (int i = 0; i < 2; ++i)
        {
            window.draw(name[i]);
        }
        
        for (int i = 0; i < 3; ++i)
        {
            window.draw(menu[i]);
        }
        
        window.display();
    }
}

