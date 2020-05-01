#include <iostream>
#include <string>
//#include <fstream>
#include <ctime>
//#include <cstdlib>
//#include <cstring>
using namespace std;


class airport{
   public:
      string all;
      string name;
     int numb;
     string numb1;

       void random (){
            srand( time(NULL) );
            numb= 1+ rand() % 1000;
            cout<<numb<<endl;
        }
};

