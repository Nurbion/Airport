#include <iostream>
#include <string>
#include <ctime>
using namespace std;


class airport{
   public:
      string all;
      string name;
     int numb;
     string numb1;

       void random (){
            srand( time(NULL) );
            numb= 1+ rand() % 900 + 100;
            cout<<numb<<endl;
        }
};

