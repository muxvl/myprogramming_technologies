//
//  Game.cpp
//  technology_progamming
//
//  Created by Елизавета Михеенко 
//  Copyright © 2020 Елизавета Михеенко. All rights reserved.
//

#include "Game.hpp"

void Game::clear()
{
    turn = false;
    number = false;
    ended = false;
    counted = false;

    for (int i = 0; i < n; ++i)
    {
        delete[] field[i];
        delete[] num[i];
        delete[] net[i];
    }
    delete[] field;
    delete[] num;
    delete[] net;
}

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
        option[i].setFillColor(sf::Color(192, 224, 224));
        option[i].setFont(font);
        option[i].setCharacterSize(30);
        option[i].setOutlineColor(sf::Color(64, 128, 128));
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
    //option[3].move(400, 120);
    option[3].move(50, 190);
    
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
    option[12].setString(L"Назад");
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
                    else if (sf::IntRect(50, 190, 140, 40).contains(sf::Mouse::getPosition(window)))
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
                    else if (sf::IntRect(50, 190, 130, 40).contains(sf::Mouse::getPosition(window)))
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
                    option[0].setFillColor(sf::Color(192, 224, 224));
                    option[1].setFillColor(sf::Color(192, 224, 224));
                }
                break;
            case 1:
                if (sf::IntRect(50, 120, 175, 40).contains(sf::Mouse::getPosition(window)))
                    
                    option[2].setFillColor(sf::Color(0, 32, 32));
                    
                else if (sf::IntRect(50, 190, 140, 40).contains(sf::Mouse::getPosition(window)))
                    
                    option[3].setFillColor(sf::Color(0, 32, 32));
                else
                {
                    option[2].setFillColor(sf::Color(192, 224, 224));
                    option[3].setFillColor(sf::Color(192, 224, 224));
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
                        option[i].setFillColor(sf::Color(192, 224, 224));
                    }
                }
                break;
            case 3:
                if (sf::IntRect(50, 120, 300, 40).contains(sf::Mouse::getPosition(window)))
                    
                    option[11].setFillColor(sf::Color(0, 32, 32));
                    
                else if (sf::IntRect(50, 190, 130, 40).contains(sf::Mouse::getPosition(window)))
                    
                    option[12].setFillColor(sf::Color(0, 32, 32));
                    
                else
                {
                    option[11].setFillColor(sf::Color(192, 224, 224));
                    option[12].setFillColor(sf::Color(192, 224, 224));
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

    field = new int*[n];
    for (int i = 0; i < n; ++i)
        field[i] = new int[n];
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            field[i][j] = -1;

    sf::Font font;
    font.loadFromFile(resourcePath() + "PTMono.ttc");

    sf::Text cursor, cname;;
    sf::Text queue, qname, pause;
    
    num = new sf::Text* [n];
    
    for (int i = 0; i < n; ++i)
        num[i] = new sf::Text[n];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            num[i][j].setFont(font);
            num[i][j].setOutlineColor(sf::Color(60, 177, 188));
            num[i][j].setOutlineThickness(1);
            num[i][j].move((0.1021 * n * n - 3.0154 * n + 36.6780) + (340 / n) * i,
                (-0.0579 * n * n + 1.8743 * n - 4.9971) + (340 / n) * j);
            num[i][j].setCharacterSize(340 / n - 5);
        }

    }
    cursor.setCharacterSize(30);
    cursor.setFont(font);
    cursor.setOutlineColor(sf::Color(60, 177, 188));
    cursor.setOutlineThickness(1);
    cursor.setFillColor(sf::Color(227, 244, 244));
    cursor.move(385, 180);
    cursor.setCharacterSize(35);
    
    cname.setFont(font);
    cname.setOutlineColor(sf::Color(60, 177, 188));
    cname.setOutlineThickness(1);
    cname.setFillColor(sf::Color(227, 244, 244));
    cname.setString(L"Выбранное число:");
    cname.setCharacterSize(25);
    cname.move(385, 150);

    pause.setFont(font);
    pause.setOutlineColor(sf::Color(60, 177, 188));
    pause.setOutlineThickness(1);
    pause.setString(L"Пауза");
    pause.setCharacterSize(40);
    pause.move(470, 5);
    
    qname.setFont(font);
    qname.setOutlineColor(sf::Color(60, 177, 188));
    qname.setOutlineThickness(1);
    qname.setFillColor(sf::Color(227, 244, 244));
    qname.setString(L"Ход:");
    qname.setCharacterSize(45);
    qname.move(385, 55);
    
    queue.setCharacterSize(30);
    queue.setFont(font);
    queue.move(385, 105);
    queue.setOutlineColor(sf::Color(60, 177, 188));
    queue.setOutlineThickness(1);

    net = new sf::RectangleShape* [n];
    
    for (int i = 0; i < n; ++i)
        net[i] = new sf::RectangleShape[n];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            net[i][j].setSize(sf::Vector2f(340 / n, 340 / n));
            net[i][j].setOutlineColor(sf::Color(60, 177, 188));
            net[i][j].setOutlineThickness(2);
            net[i][j].setFillColor(sf::Color(214, 237, 240));
            net[i][j].move(10 + (340 / n) * i, 10 + (340 / n) * j);
        }
    }

    int nechet[3], chet[3], sum = 0;
    float timer = 0;
    sf::Text result[12];
    
    for (int i = 0; i < 12; ++i)
    {
        result[i].setFont(font);
        result[i].setOutlineColor(sf::Color(60, 177, 188));
        result[i].move(360, 5 + 20 * i);
        result[i].move(0, ((i + 2) / 3) * 15);
        result[i].move(0, (i / 3) * 10);
        if (i % 3 == 0)
        {
            result[i].setOutlineThickness(1);
            result[i].setCharacterSize(30);
            result[i].setFillColor(sf::Color(227, 244, 244));
        }
        else
        {
            result[i].setCharacterSize(20);
            result[i].setFillColor(sf::Color(60, 177, 188));
        }

        if (i < 3)
        {
            nechet[i] = 0;
            chet[i] = 0;
        }
    }
    result[0].setString(L"По строкам:");
    result[3].setString(L"По столбцам:");
    result[6].setString(L"По диагонали:");
    result[9].setString(L"Победитель:");
    result[10].setCharacterSize(30);
    result[11].move(0, 10);

    int cnt = 0, si, sj, snum;
    bool userturn = turn;
    
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                clear();
                window.close();
                return;
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    for (int i = 0; i < n; ++i)
                    {
                        for (int j = 0; j < n; ++j)
                        {
                            if (sf::IntRect(10 + (340 / n) * i, 10 + (340 / n) * j, 340 / n, 340 / n).
                                contains(sf::Mouse::getPosition(window)) && field[i][j] == -1 &&
                                (!server || (server && turn == userturn)))
                            {
                                if (turn)
                                    num[i][j].setFillColor(sf::Color::White);
                                else
                                    num[i][j].setFillColor(sf::Color::Black);
                                if (number)
                                    num[i][j].setString('1');
                                else
                                    num[i][j].setString('0');

                                if (number)
                                    field[i][j] = 1;
                                else
                                    field[i][j] = 0;

                                if (!turn)
                                    turn = true;
                                else
                                    turn = false;
                            }
                        }
                    }
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    if (!number)
                        number = true;
                    else
                        number = false;
                }
            }

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (sf::IntRect(10 + (340 / n) * i, 10 + (340 / n) * j, 340 / n, 340 / n).
                        contains(sf::Mouse::getPosition(window)) && field[i][j] == -1)
                    {
                        if (turn)
                            net[i][j].setFillColor(sf::Color::White);
                        else
                            net[i][j].setFillColor(sf::Color::Black);
                    }
                    else
                        net[i][j].setFillColor(sf::Color(214, 237, 240));
                }
            }

            if (sf::IntRect(470, 5, 155, 40).contains(sf::Mouse::getPosition(window)) && !ended)
            {
                pause.setFillColor(sf::Color::Black);

                if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                {
                    if (menu_choice(3,window))
                    {
                        clear();
                        return;
                    }
                }
            }
            else
                pause.setFillColor(sf::Color(227,244,244));

            if (cnt == 12)
            {
                if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                {
                    clear();
                    return;
                }
            }
        }

        window.clear(sf::Color(214, 237, 240));

        if (server && turn != userturn && !ended)
        {
            if (!timer)
            {
                si = rand() % n;
                sj = rand() % n;
            }
            
            if (field[si][sj] == -1)
            {
                if (!timer)
                {
                    snum = rand() % 2;
                }

                if (!timer)
                    timer = clk.getElapsedTime().asSeconds();
                if ((clk.getElapsedTime().asSeconds() - timer) >= 1)
                {
                    field[si][sj] = snum;
                    if (turn)
                        num[si][sj].setFillColor(sf::Color::White);
                    else
                        num[si][sj].setFillColor(sf::Color::Black);
                    if (snum)
                        num[si][sj].setString('1');
                    else
                        num[si][sj].setString('0');
                    turn = userturn;
                    timer = 0;
                }
            }
        }

        if (turn)
        {
            queue.setFillColor(sf::Color::White);
            queue.setString(L"Чётный");
        }
        else
        {
            queue.setFillColor(sf::Color::Black);
            queue.setString(L"Нечётный");
        }
            
        if (number)
            cursor.setString('1');
        else
            cursor.setString('0');
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                window.draw(net[i][j]);
                window.draw(num[i][j]);
            }
        }

        ended = true;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (field[i][j] == -1)
                {
                    ended = false;
                    break;
                }
            }
            if (!ended)
                break;
        }

        if (!ended)
        {
            window.draw(cursor);
            window.draw(cname);
            window.draw(pause);
            window.draw(queue);
            window.draw(qname);
        }
        else
        {
            if (!counted)
            {
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                        sum += field[j][i];
                    
                    if (sum % 2 == 1)
                        ++nechet[0];
                    else ++chet[0];
                        sum = 0;
                }
                result[1].setString(L"нечетные: " + std::to_wstring(nechet[0]));
                result[2].setString(L"чётные: " + std::to_wstring(chet[0]));

                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                        sum += field[i][j];
                    if (sum % 2 == 1) ++nechet[1];
                    else ++chet[1];
                    sum = 0;
                }
                result[4].setString(L"нечётные: " + std::to_wstring(nechet[1]));
                result[5].setString(L"чётные: " + std::to_wstring(chet[1]));

                for (int i = 0; i < n; ++i)
                    sum += field[i][i];
                if (sum % 2 == 1) ++nechet[2];
                else ++chet[2];
                sum = 0;
                for (int i = 0; i < n; ++i)
                    sum += field[i][n - 1 - i];
                if (sum % 2 == 1) ++nechet[2];
                else ++chet[2];
                result[7].setString(L"нечётные: " + std::to_wstring(nechet[2]));
                result[8].setString(L"чётные: " + std::to_wstring(chet[2]));

                if (nechet[0] + nechet[1] + nechet[2] >
                    chet[0] + chet[1] + chet[2])
                {
                    result[10].setFillColor(sf::Color::Black);
                    result[10].setOutlineColor(sf::Color(60,177,188));
                    result[10].setOutlineThickness(1);
                    result[10].setString(L"Нечётный");
                    result[11].setFillColor(sf::Color(60,177,188));
                    result[11].setString(std::to_string(nechet[0] + nechet[1] + nechet[2]) +
                        "-" + std::to_string(chet[0] + chet[1] + chet[2]));
                }
                else if (nechet[0] + nechet[1] + nechet[2] <
                    chet[0] + chet[1] + chet[2])
                {
                    result[10].setFillColor(sf::Color::White);
                    result[10].setOutlineColor(sf::Color(60,177,188));
                    result[10].setOutlineThickness(1);
                    result[10].setString(L"Чётный");
                    result[11].setFillColor(sf::Color(60,177,188));
                    result[11].setString(std::to_string(chet[0] + chet[1] + chet[2]) +
                        "-" + std::to_string(nechet[0] + nechet[1] + nechet[2]));
                }
                else
                {
                    result[10].setFillColor(sf::Color::Yellow);
                    result[10].setString(L"Ничья");
                    result[11].setFillColor(sf::Color::Yellow);
                    result[11].setString(std::to_string(chet[0] + chet[1] + chet[2]) +
                        "-" + std::to_string(nechet[0] + nechet[1] + nechet[2]));
                }

                counted = true;
            }

            if (!timer)
                timer = clk.getElapsedTime().asSeconds();
            
            if ((clk.getElapsedTime().asSeconds() - timer >= 1) && cnt < 12)
            {
                timer = 0;
                ++cnt;
            }

            for (int i = 0; i < cnt; ++i)
            {
                window.draw(result[i]);
            }
        }

        window.display();
    }
}
