//
//  Rules.cpp
//  technology_progamming
//
//  Created by Елизавета Михеенко on 25/12/2020.
//  Copyright © 2020 Елизавета Михеенко. All rights reserved.
//

#include "Rules.hpp"

int Rules::game(sf::RenderWindow &window)
{
    sf::Font font;
    font.loadFromFile(resourcePath() + "PTMono.ttc");
    
    sf::Text g_rule, rules[10], away;
    
    g_rule.setFillColor(sf::Color(227, 244, 244));
    g_rule.setFont(font);
    g_rule.setCharacterSize(40);
    g_rule.setOutlineColor(sf::Color(60, 177, 188));
    g_rule.setOutlineThickness(1);
    g_rule.move(170,0);
    
    away.setFillColor(sf::Color(227, 244, 244));
    away.setFont(font);
    away.setCharacterSize(20);
    away.setOutlineColor(sf::Color(60, 177, 188));
    away.setOutlineThickness(1);
    away.move(450, 300);
    
    for (int i = 0; i < 10; ++i)
    {
        rules[i].setFillColor(sf::Color(60, 177, 188));
        rules[i].setFont(font);
        rules[i].setCharacterSize(15);
        rules[i].move(10, 50 + 15 * i);
    }
    g_rule.setString(L"Правила игры:");
    rules[0].setString(L"Два игрока, «нечетный» и «четный», по очереди ставят единицы и нули в");
    rules[1].setString(L"незанятые позиции поля N на N. Каждый из игроков может ставить 1 или 0");
    rules[2].setString(L"в произвольную свободную позицию, тем самым занимая ее. Игра продолжа-");
    rules[3].setString(L"ется до заполнения всех позиций. После этого суммируются числа вдоль");
    rules[4].setString(L"каждой строки, каждого столбца и главных диагоналей. Число нечетных");
    rules[5].setString(L"сравнивается с числом четных сумм.");
    rules[6].setString(L"Если *Число нечетных сумм больше Числа четных сумм*, выигрывает");
    rules[7].setString(L"«нечетный»; иначе выигрывает «четный»; если числа равны, результат счи-");
    rules[8].setString(L"тается ничейным.");
    rules[9].setString(L"ЛКМ - число ставится на поле; ПКМ - смена числа 0/1");
    away.setString(L"Вернуться");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
            
            if (sf::IntRect(450, 300, 160, 40).contains(sf::Mouse::getPosition(window)))
            {
                away.setFillColor(sf::Color(0, 32, 32));

                if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                    return;
            }
            else
            {
                away.setFillColor(sf::Color(227, 244, 244));
            }
        }

        window.clear(sf::Color(214, 237, 240));

        window.draw(g_rule);
        
        for (int i = 0; i < 10; ++i)
        {
            window.draw(rules[i]);
        }
        
        window.draw(away);

        window.display();
        return 0;
    }
    return 0;
}
