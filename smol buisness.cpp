#include <iostream>
#include<string.h>

using namespace std;

class Staff
{
public:
    int code;
    string name;
} a;

class eduDetails
{
public:
    string HEGS; //highest education in general studies
    string HPQ;  //highest professional qualification
} b;

class Teacher : public Staff, public eduDetails
{
    string Subject;
    string Publication;

public:
} Teacher;


class Officer : public Staff, public eduDetails
{
    char grade;
} Officer;
/

class Typist : public Staff
{
public:
    float speed;
} typistClass;


class Regular : public Typist
{

} regularTypist;


class Casual : public Typist
{
    int dailyWages;
} casualTypist;
int main()
{
    casualTypist.code = 1;
    cout << "casualTypist.code: " << casualTypist.code << endl;
    casualTypist.name = "Casual Typist name";
    cout << "casualTypist.name: " << casualTypist.name << endl;
    casualTypist.speed = 10;
    cout << "casualTypist.speed: " << casualTypist.speed << endl;

    cout << endl;
    regularTypist.code = 10;
    cout << "regularTypist.code: " << regularTypist.code << endl;
    regularTypist.name = "Regular Typist name";
    cout << "regularTypist.name: " << regularTypist.name << endl;
    regularTypist.speed = 1;
    cout << "regularTypist.speed: " << regularTypist.speed << endl;
    cout << endl;

    typistClass.code = 0;
    cout << "typistClass.code: " << typistClass.code << endl;
    typistClass.name = "main typist class name";
    cout << "typistClass.name: " << typistClass.name << endl;
    typistClass.speed = 20.0;
    cout << "typistClass.speed: " << typistClass.speed << endl;
    cout << endl;

    Officer.code = 100;
    cout << "Officer.code: " << Officer.code << endl;
    Officer.HEGS = "highest education in general studies";
    cout << "Officer.HEGS: " << Officer.HEGS << endl;
    Officer.HPQ = "highest professional qualification";
    cout << "Officer.HEGS: " << Officer.HPQ << endl;
    Officer.name = "Officer's name";
    cout << "Officer.name: " << Officer.name << endl;
    cout << endl;

    Teacher.code = 200;
    cout << "Teacher.code: " << Teacher.code << endl;
    Teacher.HEGS = "highest education in general studies";
    cout << "Teacher.HEGS: " << Teacher.HEGS << endl;
    Teacher.HPQ = "highest professional qualification";
    cout << "Teacher.HPQ: " << Teacher.HPQ << endl;
    Teacher.name = "Teacher's name";
    cout << "Teacher.name: " << Teacher.name;

    cout << "\n\nSINCE EACH CLASS CARRIES THE VARIABLE OF ITS PARENT CLASS, WE CAN SAY THAT THE INHERITENCE IS SUCCESSFUL.";
    return 0;
}
