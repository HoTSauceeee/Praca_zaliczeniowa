#include "top_classes.hpp"


unsigned int rgen::operator()()
{
    uniform_int_distribution<> distrib(0, 4095);
    return distrib(generator);
}
void rgen::display_id() {cout<<hex<<id<<endl;}


void menu::maketitle(enum choice c)
{
    switch(c)
    {
        case 0: cout<< title_small;
            break;
        case 1: cout<< title_big;
    }
}


zone::zone(const unsigned int rand, const zone* object) : model(rand)
{
    
}
zone::display_id()
{
    for(ptr: objects) cout << ptr->id;
}


person::person(const unsigned int rand) : entity(rand)
{
    string choice;
    cout<< "Choose legitimation from: ";
    for(int i=0;i<4;i++) cout<< avail[i]<< ", ";
    cout<<endl; cin >> choice;
    for(int i=0;i<4;i++)
    {
        if(choice == avail[i])
            {
        legitimation = avail[i]; i = 4;
            }
        else
        {
            legitimation = "guest";;
            cout<< "legitimation defaulted to ""guest""";
        }
    }
    people.insert({this->id,this});
}


void model::display_id(){cout<<hex<<id<<endl;};



person::~person()
{
    people.erase(this->id);
}
void person::display_id()
{
    cout<<name<<" "<<surname<< ", id: "<<hex<<id<<endl;
}


void menu::menu_display()
{
    char i;
    cout<<"1. Add user\n"<<"2. Add zone\n"<<"3. Change zone\n\n"<<"enter a number from 1 to 3 or 'q' to exit: ";
    cin>> i;
    switch(i)
    {
        case '1':
            person(rgen{}()); break;
        case '2':
            zone(rgen{}()); break;
        case '3':
            break;
        case 'q':
            exit(0);
        default:
            cout<<"Wrong character has been entered";
    }
}
