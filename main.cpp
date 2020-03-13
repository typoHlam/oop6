#include <string>
#include <iostream>
#include <vector>
#include <locale.h>

using std::string;
using std::cin;
using std::cout;

class Family
{
private:
    string firstName;
    string lastName;
    string middleName;
    int age;
    string sex;
    string status;
    class dohod
    {
    private:
        int wage;       //wage-заработная плата
        int spending;   //spending-трата
    public:
        dohod(int wg=0, int spnd=0)
        {
            wage=wg;
            spending=spnd;
        }
        void dohodInit()
        {
            cout<<"Введите заработную плату(0 если нет): "; cin>>wage;
            cout<<"Введите затраты денег: "; cin>>spending;
        }
        void dohodShow() const
        {
            cout<<"Заработная плата: "<< wage << "\n";
            cout<<"Трата: "<< spending << "\n";
            cout<<"Доход: "<< wage-spending << "\n";
        }
        void setValues(int w, int s)
        {
            wage = w;
            spending = s;
        }
    };
    dohod intrmed={0,0};      //intermediary-посредник
public:
    Family(string l="", string f="", string m="", int a=0, string sx="", string stat="");
    Family(string f, int a);
    Family(string l, string f, int a, string stat);
    Family(string l, string f, int w, int s);
    void vvod();
    void vivod() const;
};

Family::Family(string l, string f, string m, int a, string sx, string stat)
{
    firstName=f;
    lastName=l;
    middleName=m;
    age=a;
    sex=sx;
    status=stat;
}
Family::Family(string f, int a)
{
    firstName=f;
    lastName = "";
    middleName = "";
    age=a;
    sex = "";
    status = "";
}
Family::Family(string l, string f, int a, string stat)
{
    lastName=l;
    firstName=f;
    middleName = "";
    age=a;
    sex = "";
    status=stat;
}
Family::Family(string l, string f, int w, int s)
{
    lastName = l;
    firstName = f;
    middleName = "";
    age = 0;
    sex = "";
    status = "";
    intrmed.setValues(w, s);
}
void Family::vvod()
{
    cout<<"Введите фамилию: "; cin >>lastName;
    cout<<"Введите имя: "; cin >>firstName;
    cout<<"Введите отчество: "; cin >>middleName;
    cout<<"Введите возраст: "; cin >>age;
    cout<<"Введите пол: "; cin >>sex;
    cout<<"Введите статус(учащийся, рабочий, пенсонер): "; cin >>status;
    intrmed.dohodInit();
}
void Family::vivod() const
{
    cout<<"Фамилия: " << lastName<< "\n";
    cout<<"Имя: " << firstName<< "\n";
    cout<<"Отчество: " << middleName<< "\n";
    cout<<"Возраст: " << age<< "\n";
    cout<<"Пол: " << sex<< "\n";
    cout<<"Статус: " << status<< "\n";
    intrmed.dohodShow();
}



void funcWithClass()
{
    class Family
    {
    private:
        string firstName;
        string lastName;
        string middleName;
        int age;
        string sex;
        string status;
    public:
        void vvod()
        {
            cout<<"Введите фамилию: "; cin >>lastName;
            cout<<"Введите имя: "; cin >>firstName;
            cout<<"Введите отчество: "; cin >>middleName;
            cout<<"Введите возраст: "; cin >>age;
            cout<<"Введите пол: "; cin >>sex;
            cout<<"Введите статус(учащийся, рабочий, пенсонер): "; cin >>status;
        }
        void vivod()
        {
            cout<<"Фамилия: " << lastName<< "\n";
            cout<<"Имя: " << firstName<< "\n";
            cout<<"Отчество: " << middleName<< "\n";
            cout<<"Возраст: " << age<< "\n";
            cout<<"Пол: " << sex<< "\n";
            cout<<"Статус: " << status<< "\n";
        }
    };
    int famSize=0;
    Family temp;
    cout<<"Введите количество членов семьи, которые желаете ввести: ";
    cin>>famSize;
    std::vector<Family> fam;
    for(int i=0; i<famSize; i++)
    {
        temp.vvod();
        cout<<"\n";
        fam.push_back(temp);
    }
    cout<<"Данные которые вы ввели:\n\n";
    for(Family temp : fam)
    {
        temp.vivod();
        cout<<"\n";
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    funcWithClass();
    Family test( "Ivanov", "Ivan", 10000, 9500);
//    test.vvod(); cout<<"\nВведенные данные:\n";
    test.vivod(); cout<<"\n";

    const Family constTest = {"Иванов", "Иван",20, "учащийся"};
    constTest.vivod();

    system("Pause");
    return 0;
}




//Как уже говорилось, число конструкторов может быть произвольным.Расширьте класс
//семейных отношений объявлением 3 - 4 конструкторов, имеющих различное количество параметров
//и различные их типы, позволяющих инициализировать объекты различными способами.
