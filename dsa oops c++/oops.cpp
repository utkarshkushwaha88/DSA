// # include <iostream>
// using namespace std;
// class Hero{
//     private:
//     int health;
    
//     char level;

//     public:
//     int getHealth(){
//         return health;
//     }
//     char getLevel(){
//         return level;
//     }
//     int setHealth(int h){
//         health=h;
//     }
//     char setLevel(char ch){
//         level=ch;
//     }

//     };
// int main() {
//     //static allocation
//     Hero ramesh;
//     // ramesh.health=70;
//     //ramesh.level='A';
//     // ramesh.setHealth(84);
//     // ramesh.setLevel('C');
//     // cout<<"Health is "<<ramesh.getHealth()<<endl;
//     // cout<<"Level is "<<ramesh.getLevel()<<endl;
//     // //cout<<"size of -->  "<<sizeof(h1)<<endl;

//     //Dynamically allocation
//     Hero *b=new Hero;
//     cout<<"Health is "<<(*b).getHealth()<<endl;
//     cout<<"Level is"<<(*b).getLevel()<<endl;
// return 0;
// }


//CONSTRUCTOR
# include <iostream>
# include <vector>
using namespace std;
class Hero{
    private:
    int health;
    public:
    char level;

    //constructor
    Hero(){
        cout<<"Constructor called"<<endl;
    }
    //paramerterized constructor
    Hero(int health,char level){
        this->health=health;
        this->level=level;
    }
    //copy constructor
    Hero(Hero& temp){
        cout<<"copy constructor called "<<endl;
        this->health=temp.health;
        this->level=temp.level;
    }

    void print(){
        cout<<"Health is "<<this->getHealth()<<endl;
        cout<<"Level is "<<this->getLevel()<<endl;
    }
    int getHealth(){
        return health;
    }
    char getLevel(){
        return level;
    }
    int setHealth(int h){
        health=h;
    }
    char setLevel(char ch){
        level=ch;
    }
};
int main() {
    // //statically
    // Hero ramesh(10);
    // //dynamically
    // Hero *b=new Hero;

    Hero S(70,'C');
    S.print();
    //copy constructor
    Hero R(S);
    R.print();
return 0;
}