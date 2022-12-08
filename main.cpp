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
        cout << "С���ѣ���ӭ������Сѧ����" << endl
             << "\t\t\t\t1.������ϰ" << endl
             << "\t\t\t\t2.���㿼��" << endl
             << "\t\t\t\t3.�ɼ���ѯ" << endl
             << "\t\t\t\t4.�ɼ�����" << endl
             << "\t\t\t\t5.�ɼ�ɾ��" << endl
             << "\t\t\t\t0.�˳�" << endl
             << "��ѡ��";
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