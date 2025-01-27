#ifndef TOP_CLASSES_HPP
#define TOP_CLASSES_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <iomanip>
#include <exception>
#include <map>
#include <unistd.h>
#include <fstream>
using namespace std;


class entity
{
protected:
    const unsigned int id;
    virtual ~entity() = default;
    entity(unsigned int rand):id(rand){};
    virtual void display_id()=0;                                 //klasa abstrakcyjna
};


class rgen:entity
{
    mt19937 generator;
    void display_id() override;
    public: rgen() : generator(random_device{}()), entity(random_device{}()%4096){};
    unsigned int operator()();                                                              //funktor
};



class person:protected entity
{
    private:
    static map<const unsigned int, const person*> people;
    string avail[4] = {"guest","apprentice","regular","manager"};
    string legitimation, name, surname;
    static bool elevation(person &person)
    {
        return person.legitimation=="manager";
    }
    public:
    person(const unsigned int rand);
    ~person();
    void display_id() override;
    friend size_t get_count(person &person)                         //funkcja zaprzyjaźniona
    {
        if (elevation(person)) return people.size();
        else return 0;
    }
};



class zone:protected entity
{
    void display_id() override;
    static map<const unsigned int, const zone*> objects;
    static map<const unsigned int, const zone*>::iterator it;         //iterator po mapie
    public: zone(const unsigned int rand);
    string name;
    void change_objects()
    {
        
    };
};

class device:zone
{
public:
    device(const unsigned int rand) : zone(rand){};
};


class relation:entity
{
    void display_id() override;
    static relation* relations[];
    pair<const person*, const entity*> definition;
    public: relation(const unsigned int rand, const person* a, const entity* b) : definition(pair(a,b)), entity(rand){}
};


class menu{
    static constexpr string_view title_big =
    "8 8888     ,88'  ,o888888o.     b.             8 8888888 8888888888 8 888888888o.      ,o888888o.     8 8888                  .8.\n"
    "8 8888    ,88'. 8888     `88.   888o.          8       8 8888       8 8888    `88.  . 8888     `88.   8 8888                 .888.\n"
    "8 8888   ,88',8 8888       `8b  Y88888o.       8       8 8888       8 8888     `88 ,8 8888       `8b  8 8888                :88888.\n"
    "8 8888  ,88' 88 8888        `8b .`Y888888o.    8       8 8888       8 8888     ,88 88 8888        `8b 8 8888               . `88888.\n"
    "8 8888 ,88'  88 8888         88 8o. `Y888888o. 8       8 8888       8 8888.   ,88' 88 8888         88 8 8888              .8. `88888.\n"
    "8 8888 88'   88 8888         88 8`Y8o. `Y88888o8       8 8888       8 888888888P'  88 8888         88 8 8888             .8`8. `88888.\n"
    "8 888888<    88 8888        ,8P 8   `Y8o. `Y8888       8 8888       8 8888`8b      88 8888        ,8P 8 8888            .8' `8. `88888.\n"
    "8 8888 `Y8.  `8 8888       ,8P  8      `Y8o. `Y8       8 8888       8 8888 `8b.    `8 8888       ,8P  8 8888           .8'   `8. `88888.\n"
    "8 8888   `Y8. ` 8888     ,88'   8         `Y8o.`       8 8888       8 8888   `8b.   ` 8888     ,88'   8 8888          .888888888. `88888.\n"
    "8 8888     `Y8.  `8888888P'     8            `Yo       8 8888       8 8888     `88.    `8888888P'     8 888888888888 .8'       `8. `88888.\n\n"
    
    "8 888888888o.          ,o888888o.       d888888o. 8888888 8888888888 8 8888888888   8 888888888o   8 8888      88\n"
    "8 8888    `^888.    . 8888     `88.   .`8888:' `88.     8 8888       8 8888         8 8888    `88. 8 8888      88\n"
    "8 8888        `88. ,8 8888       `8b  8.`8888.   Y8     8 8888       8 8888         8 8888     `88 8 8888      88\n"
    "8 8888         `88 88 8888        `8b `8.`8888.         8 8888       8 8888         8 8888     ,88 8 8888      88\n"
    "8 8888          88 88 8888         88  `8.`8888.        8 8888       8 888888888888 8 8888.   ,88' 8 8888      88\n"
    "8 8888          88 88 8888         88   `8.`8888.       8 8888       8 8888         8 888888888P'  8 8888      88\n"
    "8 8888         ,88 88 8888        ,8P    `8.`8888.      8 8888       8 8888         8 8888         8 8888      88\n"
    "8 8888        ,88' `8 8888       ,8P 8b   `8.`8888.     8 8888       8 8888         8 8888         ` 8888     ,8P\n"
    "8 8888    ,o88P'    ` 8888     ,88'  `8b.  ;8.`8888     8 8888       8 8888         8 8888           8888   ,d8P\n"
    "8 888888888P'          `8888888P'     `Y8888P ,88P'     8 8888       8 888888888888 8 8888            `Y88888P'\n\n";
    
    static constexpr string_view title_small =
    "_   __            _             _\n"
    "| | / /           | |           | |\n"
    "| |/ /  ___  _ __ | |_ _ __ ___ | | __ _\n"
    "|    \ / _ \| '_ \| __| '__/ _ \| |/ _` |\n"
    "| |\  \ (_) | | | | |_| | | (_) | | (_| |\n"
    "\_| \_/\___/|_| |_|\__|_|  \___/|_|\__,_|\n"
    "______          _\n"
    "|  _  \        | |\n"
    "| | | |___  ___| |_ ___ _ __  _   _\n"
    "| | | / _ \/ __| __/ _ \ '_ \| | | |\n"
    "| |/ / (_) \__ \ ||  __/ |_) | |_| |\n"
    "|___/ \___/|___/\__\___| .__/ \__,_|\n"
    "                       | |\n"
    "                       |_|\n";
    
    enum choice{small,big};
public:
    static enum choice c;
    static void maketitle(enum choice c);
    static void menu_display();
};
#endif
