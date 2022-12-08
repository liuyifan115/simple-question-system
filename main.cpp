#include "iostream"

using namespace std;

void menu();
int practise();
int exam();
int query();
int sort();
int del();

typedef struct score{
    int id;
    struct score *next;
}SCORE;

typedef struct student{
    char name[20];
    int num;
    SCORE score;
    struct student *next;
}STUDENT;

int main(int argc, char *argv[]){
    menu();
    return 0;
}

void menu(){
    while (true){
        cout << "Ð¡ÅóÓÑ£¬»¶Ó­ÄãÀ´µ½Ð¡Ñ§ËãÊý" << endl
             << "\t\t\t\t1.¼ÆËãÁ·Ï°" << endl
             << "\t\t\t\t2.¼ÆËã¿¼ÊÔ" << endl
             << "\t\t\t\t3.³É¼¨²éÑ¯" << endl
             << "\t\t\t\t4.³É¼¨ÅÅÐò" << endl
             << "\t\t\t\t5.³É¼¨É¾³ý" << endl
             << "\t\t\t\t0.ÍË³ö" << endl
             << "ÇëÑ¡Ôñ£º";
        switch(getchar() - '0')
        {
            getchar();
            case 0: {
                exit(1);
            }
            case 1:{
                practise();
            }
            case 2:{
                exam();
            }
            case 3:{
                query();
            }
            case 4:{
                sort();
            }
            case 5:{
                del();
            }
            default:{
                system("cls");
                continue;
            }
        }
    }

}

int practise(){

    return 0;
}

int exam(){

    return 0;
}

int query(){

    return 0;
}

int sort(){

    return 0;
}

int del(){

    return 0;
}