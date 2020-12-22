
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

int head()
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

        window.clear(Color::White);

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

void rules()
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
        rules[i].move(10, 30 + 15 * i);
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
                away.setFillColor(Color(0, 123, 211));

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

int main()
{
    while (1)
    {
	cout << "hello" << Lendl;
        switch (head())
        {
        case 0:
            //game();
            break;
        case 1:
            rules();
            break;
        case 2:
            return 0;
        }
    }
}
