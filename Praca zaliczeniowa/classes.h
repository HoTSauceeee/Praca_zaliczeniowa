#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <string>
//#include <cstddef>
#include <random>
using namespace std;
class entity{
    public: const unsigned int id;
    protected: ~entity();
    entity(unsigned int rand):id(rand){};
    virtual bool access()=0;
};
struct rgen:entity{
    rgen() : generator(std::random_device{}()), entity(std::random_device{}()) {}
    unsigned int operator()(){uniform_int_distribution<> distrib(0, stoi("fff",nullptr,16));
                                                    return distrib(generator);};
    private: mt19937 generator;
    bool access(){return true;};
};
class model:protected entity{};
class interface:protected entity{};
class person:protected entity{
    private: enum legitimation {guest, apprentice, regular, manager};
    public: person(const unsigned int rand) : entity(rand){};
};
class zone:protected entity{
    friend class entity;
    static zone* objects[];
    protected: zone(const unsigned int rand, const zone* object) : entity(rand){};
};
class device:zone{
    device(const unsigned int rand) : zone(rand, this){};
};
class relation:entity{
    static relation* relations[];
    pair<const person*, const entity*> definition;
    public: relation(const unsigned int rand, const person* a, const entity* b) : definition(pair(a,b)), entity(rand){}
};
class creator:entity{
    private: string login, password;
    creator(const unsigned int rand, const string& login, const string& password) : login(login), password(password), entity(rand){};
};
#endif
