#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "airp.hpp"
using namespace std;

int main(int ac, char *av[]) {
     if(ac<=2){
	cout<<"Не заданы имена файлов"<<endl;
        cout<<"Необходимо задать 2 имя файла"<<endl;
        return 0;
       }
    ifstream f(av[1]);
     if(!f.is_open()){
         cout<<"ошибка открытия";
         return 0;
       }
   int N=500;
   char file[N];
   airport reis;
   f.close();
   int b;
    for(;;){
       system("clear");
       cout<<"Выберите одну из команд:\n";
       cout<<"1-Заказать билет\n";
       cout<<"2-Посмотреть рейсы\n";
       cout<<"3-Удалить рейс\n";
       cout<<"4-Выход\n";
       cin>>b;
       while (b==1){
          ofstream f(av[1],ios::app);
	  system("clear");
      	  cout<<"Ваш номер рейса\n";
          reis.random(); 
          f<<reis.numb<<" ";
          cout<<"Введите день и месяц:\n";
          cin>>reis.name;
          f<<reis.name<<".";
          cin>>reis.name;
          f<<reis.name<<" ";
          cout<<"\nСтрану отправления:";
          cin>>reis.name;
          f<<reis.name<<"-";
          cout<<"\nСтрану прибытия:"; 
          cin>>reis.name;
          f<<reis.name<<endl;
	  f.close();
	  cout<<"1-Добавить еще рейс\n";
          cout<<"0-Вернуться назад\n";
          cin>>b;

      }


      while (b==2){
        system("clear");
        ifstream f(av[1]);
        while(!f.eof()) {
      	  getline(f,reis.all);
      	  cout<<reis.all<<endl;
	}
        cout<<"0-Вернуться назад\n";
        cin>>b;
        f.close();
      }


      while (b==3){
        system("clear");
        ofstream f2(av[2]);
	ifstream f(av[1]);
	cout<<"Введите номер рейса"<<endl;
	cin>>reis.numb1;
        while(!f.eof()) {
           getline(f,reis.all);
	   string::size_type p = reis.all.find(reis.numb1);
	   if(p != reis.all.npos){
		reis.all.erase(p,30);
           }
           f2<<reis.all<<endl;

        }
	f.close();
	f2.close();
	remove (av[1]);
	rename (av[2],av[1]);
        printf("3-Удалить еще один рейс\n");
        printf("0-Вернуться назад\n");
        cin>>b;

       }

       if (b==4){
          f.close();
          return 0;
       }


   }
}

