#include "top_classes.hpp"


map<const unsigned int, const zone*> zone::objects;
map<const unsigned int, const zone*>::iterator zone::it;
std::map<const unsigned int, const person*> person::people;


unsigned int rgen::operator()()
{
    uniform_int_distribution<> distrib(0, 4095);
    return distrib(generator);
}
void rgen::display_id() {cout<<hex<<id<<endl;}


zone::zone(const unsigned int rand) : entity(rand)
{
    string temp_name;
    while(true)
    {
        cout << "Enter device name"; cin >> temp_name;
        
        
    }                      //Dodawanie obiektów do mapy static w pętli
}
void zone::display_id()
{
    for(it = objects.begin(); it != objects.end();it++) cout<<(it->second)->name<<" with id: "<<hex<<it->first<<endl;; //wyświetlanie nazw i id obiektów w strefie
}

device::device()
{
    
}


person::person(const unsigned int rand) : entity(rand)
{
    string choice;
    bool found = false;
    cout<< "Choose legitimation from: ";
    for(int i=0;i<4;i++)
    { if(i<3) cout<< avail[i]<< ", ";
    else cout<< avail[i]<<endl;
    }
    cout<<endl; cin >> choice;
    for(int i=0;i<4;i++)
    {
        if( choice == avail[i] )
        {
            legitimation = avail[i]; found = true;
        }
    }
    // zapis do pliku csv
   if(!found)
    {cout<< "legitimation defaulted to ""guest""\n\n" << flush; legitimation = avail[0]; }
    string name,surname;
    cout<<" Enter name: "; cin>>name;
    cout<<" Enter surname: "; cin>>surname;
    ofstream File; File.open("people.csv",ios::app);
    if(File.good()) File<<name<<", "<<surname<<", "<< this->id<<endl;
    else cout<<"\n-----Could not save data-----\n";
    File.close();
    people.insert({this->id,this});
}

person::~person()
{
    people.erase(this->id);
}
void person::display_id()
{
    cout<<name<<" "<<surname<< ", id: "<<hex<<id<<endl;
}


void menu::maketitle(enum choice c)
{
    switch(c)
    {
        case 0: cout<< title_small;
            break;
        case 1: cout<< title_big;
    }
}

void menu::menu_display()
{
    char i;
    enum choice c = big;
    menu::maketitle(c);
    while(true){
        cout<<"1. Add user\n"<</*"2. Add zone\n"<<"3. Change zone\n\n"<<"enter a number from 1 to 3 or 'q' to exit: "*/"enter 1 or q to exit:"<<endl;
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
}
