
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "ResourcePath.hpp"

using namespace std;
using namespace sf;

RenderWindow window(VideoMode(640, 360), "Let's play!");

int n;

bool server = false;
bool turn = false;

int Head::head()
{
    if (!window.isOpen()) return 2;//если окно не открыто, то выход
    
    Font font;

    if (!font.loadFromFile(resourcePath() + "PTMono.ttc"))
        return EXIT_FAILURE;

    Text name[2], menu[3];
    
    for (int i = 0; i < 2; ++i)
    {
        name[i].setFillColor(Color(227, 244, 244));
        name[i].setFont(font);
        name[i].setCharacterSize(70);
        name[i].move(100 + 225 * i, 30);
        name[i].setOutlineColor(Color(60, 177, 188));
        name[i].setOutlineThickness(4);
    }
    
    for (int i = 0; i < 3; ++i)
    {
        menu[i].setFillColor(Color(192, 224, 224));
        menu[i].setFont(font);
        menu[i].setCharacterSize(30);
        menu[i].move(100, 140 + 50 * i);
        menu[i].setOutlineColor(Color(64, 128, 128));
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
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                return 2;
            }

            for (int i = 0; i < 3; ++i)
            {
                if (IntRect(100, 140 + 50 * i, 330, 40).contains(Mouse::getPosition(window)))
                {
                    menu[i].setFillColor(Color(0, 32, 32));

                    if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
                    {
                        return i;
                    }
                }
                else
                {
                    menu[i].setFillColor(Color(192, 224, 224));
                }
            }
        }

        window.clear(Color(214, 237, 240));

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

void Rules:: rules()
{
    Font font;
    font.loadFromFile(resourcePath() + "PTMono.ttc");
    
    Text g_rule, rules[10], away;
    
    g_rule.setFillColor(Color(227, 244, 244));
    g_rule.setFont(font);
    g_rule.setCharacterSize(40);
    g_rule.setOutlineColor(Color(60, 177, 188));
    g_rule.setOutlineThickness(1);
    g_rule.move(170,0);
    
    away.setFillColor(Color(227, 244, 244));
    away.setFont(font);
    away.setCharacterSize(20);
    away.setOutlineColor(Color(60, 177, 188));
    away.setOutlineThickness(1);
    away.move(450, 300);
    
    for (int i = 0; i < 10; ++i)
    {
        rules[i].setFillColor(Color(60, 177, 188));
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
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                return;
            }
            
            if (IntRect(450, 300, 160, 40).contains(Mouse::getPosition(window)))
            {
                away.setFillColor(Color(0, 32, 32));

                if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
                    return;
            }
            else
            {
                away.setFillColor(Color(227, 244, 244));
            }
        }

        window.clear(Color(214, 237, 240));

        window.draw(g_rule);
        
        for (int i = 0; i < 10; ++i)
        {
            window.draw(rules[i]);
        }
        
        window.draw(away);

        window.display();
    }
}


int menu_choice(int c)
{
    Font font;
    font.loadFromFile(resourcePath() + "PTMono.ttc");

    Text name[4], option[13];
    
    for (int i = 0; i < 4; ++i)
    {
        name[i].setFillColor(Color(227, 244, 244));
        name[i].setFont(font);
        name[i].setCharacterSize(35);
        name[i].setOutlineColor(Color(60, 177, 188));
        name[i].setOutlineThickness(2);
    }
    for (int i = 0; i < 13; ++i)
    {
        option[i].setFillColor(Color(227, 244, 244));
        option[i].setFont(font);
        option[i].setCharacterSize(30);
        option[i].setOutlineColor(Color(60, 177, 188));
        option[i].setOutlineThickness(2);
    }
    
    name[0].setString(L"Выбери напарника?");
    name[0].move(50, 30);
    name[0].setString(L"- играть с другом");
    name[1].setString(L"- играть с компьютером");
    name[0].move(50, 120);
    name[1].move(50, 190);
    
    name[1].setString(L"Выбор игрока:");
    name[1].move(50, 30);
    name[2].setString(L"- Нечётный");
    name[3].setString(L"- Чётный");
    name[2].move(50, 120);
    name[3].move(400, 120);
    
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
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                return 1;
            }

            switch (c)
            {
            case 0:
                if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
                {
                    if (IntRect(50, 120, 160, 40).contains(Mouse::getPosition(window)))
                        server = false;
                    else if (IntRect(50, 190, 160, 40).contains(Mouse::getPosition(window)))
                        server = true;
                    return 0;
                }
                break;
            case 1:
                if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
                {
                    if (IntRect(50, 120, 175, 40).contains(Mouse::getPosition(window)))
                        turn = false;
                    else if (IntRect(400, 120, 140, 40).contains(Mouse::getPosition(window)))
                        turn = true;
                    return 0;
                }
                break;
            case 2:
                for (int i = 4; i < 11; ++i)
                {
                    if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
                    {
                        if (i < 7 && IntRect(50, 130 + 40 * (i - 5), 115, 40).contains(Mouse::getPosition(window)))
                        {
                            n = i - 1;
                            return 0;
                        }
                        else if (i < 10 && i >= 7 &&
                            IntRect(225, 130 + 40 * (i - 8), 115, 40).contains(Mouse::getPosition(window)))
                        {
                            n = i - 1;
                            return 0;
                        }
                        else if (i == 10 &&
                            IntRect(400, 130 + 40 * (i - 11), 115, 40).contains(Mouse::getPosition(window)))
                        {
                            n = i - 1;
                            return 0;
                        }
                    }
                }
                break;
            case 3:
                if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
                {
                    if (IntRect(50, 120, 300, 40).contains(Mouse::getPosition(window)))
                        return 0;
                    else if (IntRect(400, 120, 130, 40).contains(Mouse::getPosition(window)))
                        return 1;
                }
                break;
            }

            switch (c)
            {
            case 0:
                if (IntRect(50, 120, 160, 40).contains(Mouse::getPosition(window)))
                    option[0].setFillColor(Color(0, 32, 32));
                else if (IntRect(50, 190, 160, 40).contains(Mouse::getPosition(window)))
                    option[1].setFillColor(Color(0, 32, 32));
                else
                {
                    option[0].setFillColor(Color(227, 244, 244));
                    option[1].setFillColor(Color(227, 244, 244));
                }
                break;
            case 1:
                if (IntRect(50, 120, 175, 40).contains(Mouse::getPosition(window)))
                    
                    option[2].setFillColor(Color(0, 32, 32));
                    
                else if (IntRect(400, 120, 140, 40).contains(Mouse::getPosition(window)))
                    
                    option[3].setFillColor(Color(0, 32, 32));
                else
                {
                    option[2].setFillColor(Color(227, 244, 244));
                    option[3].setFillColor(Color(227, 244, 244));
                }
                break;
            case 2:
                for (int i = 4; i < 11; ++i)
                {
                    if (i < 7 && IntRect(50, 130 + 40 * (i - 5), 115, 40).contains(Mouse::getPosition(window)))
                        
                        option[i].setFillColor(Color(0, 32, 32));
                    
                    else if (i < 10 && i >= 7 &&
                        IntRect(225, 130 + 40 * (i - 8), 115, 40).contains(Mouse::getPosition(window)))
                        
                        option[i].setFillColor(Color(0, 32, 32));
                    
                    else if (i == 10 &&
                        IntRect(400, 130 + 40 * (i - 11), 115, 40).contains(Mouse::getPosition(window)))
                        option[i].setFillColor(Color(0, 32, 32));
                    else
                    {
                        option[i].setFillColor(Color(227, 244, 244));
                    }
                }
                break;
            case 3:
                if (IntRect(50, 120, 300, 40).contains(Mouse::getPosition(window)))
                    
                    option[11].setFillColor(Color(0, 32, 32));
                    
                else if (IntRect(400, 120, 130, 40).contains(Mouse::getPosition(window)))
                    
                    option[12].setFillColor(Color(0, 32, 32));
                    
                else
                {
                    option[11].setFillColor(Color(227, 244, 244));
                    option[12].setFillColor(Color(225, 244, 244));
                }
                break;
            }
        }

        window.clear(Color(214, 237, 240));

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

void game()
{
    menu_choice(0);
    if (server)
        menu_choice(1);
    menu_choice(2);
}

int main()
{
    ClientCode();
}
