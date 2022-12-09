#include "iostream"
#include "ctime"
#include "vector"
#include "algorithm"

using namespace std;

typedef struct{
    int id;
    double score;
}SCORE;

typedef struct{
    string name;
    string id;
    vector<SCORE>score;
}STUDENT;

void menu();
int practise();
int exam();
int query();
int sort();
int del();
bool GreaterSort (SCORE &a,SCORE &b) {
    return (a.score>b.score);
}


vector<STUDENT> student = {{"null","null",{{0,0}}}};

int main(){

    while (true){
        system("cls");
        menu();
    }
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
        int choose = -1;
        cin >> choose;
        switch(choose)
        {
            case 0: {
                exit(1);
            }
            case 1:{
                practise();
                break;
            }
            case 2:{
                exam();
                break;
            }
            case 3:{
                query();
                break;
            }
            case 4:{
                sort();
                break;
            }
            case 5:{
                del();
                break;
            }
            default:{
                system("cls");
                continue;
            }
        }
    }

}

int practise(){
    int count = 0;
    int ac = 0, wa = 0;
    while (true){
        system("cls");
        srand(time(nullptr));
        int num1 = rand()%101, num2 = rand()%101, operate = rand()%4+1;
        if (operate == 4 and num1%num2 != 0){
            continue;
        }
        int ans = -1;
        int input = 0;
        for (int i = 0; i < 3; ++i) {
            cout << "��ǰ��" << count+1 << "��\t\t��ȷ��:" << 100*(double)ac/(double)count << "%\t\t����114514�˳���ϰ" << endl << "��ش�" << endl;
            switch (operate) {
                case 1:{
                    ans = num1 + num2;
                    cout << num1 << "+" << num2 << "=";
                    break;
                }
                case 2:{
                    ans = num1 - num2;
                    cout << num1 << "-" << num2 << "=";
                    break;
                }
                case 3:{
                    ans = num1 * num2;
                    cout << num1 << "*" << num2 << "=";
                    break;
                }
                case 4:{
                    ans = num1 / num2;
                    cout << num1 << "/" << num2 << "=";
                    break;
                }
            }
            cin >> input;
            if (input == 114514){
                break;
            }
            else if(input != ans and i != 2){
                system("cls");
                cout << "�ش����������" << 2-i << "�λ��ᣬ�����»ش�" << endl;
                continue;
            }
            else if(input == ans){
                break;
            }
            else{
                cout << "�ش������ȷ��Ϊ��"<< ans << "���������������һ�⣡" << endl;
                system("pause");
                break;
            }
        }
        if (input == ans){
            ac++;
            count++;
            cout << "�ش���ȷ���������������һ�⣡" << endl;
            system("pause");
            continue;
        }
        else if(input == 114514){
            cout << "������������" << count << "����Ŀ,\t��������" << ac << "\t�������" << wa << "\t��ȷ�ʣ�" << 100*(double)ac/(double)count << "%" << endl;
            system("pause");
            break;
        }
        else{
            wa++;
            count++;
            continue;
        }
    }
    return 0;
}


int exam(){
    string name,id;
    int questionNumber = 0,count = 0,ac = 0;
    typedef struct {
        int num1;
        int num2;
        char operate;
        int ans;
        int input;
    }QUESTION;
    cout << "�������������������׼��֤��" << endl;
    cin >> name;
    cin >> id;
    cout << "���������������";
    cin >> questionNumber;
    QUESTION question[questionNumber] = {};
    for (int i = 0; i < questionNumber; ++i) {
        system("cls");
        srand(time(nullptr));
        int num1 = 0, num2 = 0, operate = 0;
        while(true){
            num1 = rand()%101;
            num2 = rand()%101;
            operate = rand()%4+1;
            if (operate == 4 and num1%num2 != 0){
                continue;
            }
            else {
                break;
            }
        }
        question[i].num1 = num1;
        question[i].num2 = num2;
        int ans = -1;
        int input = 0;
        cout << "��ǰ��" << count+1 << "��" << endl << "��ش�" << endl;
        switch (operate) {
            case 1:{
                ans = num1 + num2;
                question[i].operate = '+';
                cout << num1 << "+" << num2 << "=";
                break;
            }
            case 2:{
                ans = num1 - num2;
                question[i].operate = '-';
                cout << num1 << "-" << num2 << "=";
                break;
            }
            case 3:{
                ans = num1 * num2;
                question[i].operate = '*';
                cout << num1 << "*" << num2 << "=";
                break;
            }
            case 4:{
                ans = num1 / num2;
                question[i].operate = '/';
                cout << num1 << "/" << num2 << "=";
                break;
            }
        }
        question[i].ans = ans;
        cin >> input;
        question[i].input = input;
        if (input == ans){
            ac++;
            count++;
            continue;
        }
        else{
            count++;
            continue;
        }
    }
    system("cls");
    cout << "���Խ��������ο��Խ������" << endl;
    cout << "���ο��Թ�" << questionNumber << "����Ŀ����������" << ac << "�ܷ֣�" << 100*(double)ac/(double)count << endl
         << "����������£�" << endl << endl;
    for (int i = 0; i < questionNumber; ++i) {
        cout << "��" << i+1 << "�⣺";
        if (question[i].ans == question[i].input){
            cout << "��" << endl;
        }
        else {
            cout << "X" << endl;
        }
        cout << question[i].num1 << question[i].operate << question[i].num2 << endl
             << "��ȷ��" << question[i].ans << endl
             << "��Ĵ�" << question[i].input <<endl << endl << endl;
    }
    bool found = false;
    for (auto & iter : student) {
        if (iter.id != id){
            continue;
        }
        else{
            int num = (int)iter.score.size();
            iter.score.push_back({num+1,100*(double)ac/(double)count});
            found =! found;
            break;
        }
    }
    if (!found){
        student.push_back({name,id,{{1,100*(double)ac/(double)count}}});
    }
    system("pause");
    system("cls");
    return 0;
}

int query(){
    string name,id;
    system("cls");
    cout << "������������Ҫ��ѯ��������׼��֤��" << endl;
    cin >> name;
    cin >> id;
    cout << endl;
    bool found = false;
    for (auto & iter1 : student) {
        if (iter1.id == id and iter1.name == name){
            found =! found;
            cout << "���Դ���" << "\t���Գɼ�"<< endl;
            for (auto & iter2 : iter1.score) {
                cout << iter2.id << "\t\t" << iter2.score << endl << endl;
            }
            break;
        }
    }
    if (!found){
        cout << "û�в�ѯ�����������ѧ����Ϣ����˶���ϸ���ٴ����룡" << endl;
    }
    system("pause");
    system("cls");
    return 0;
}

int sort(){
    string name,id;
    system("cls");
    cout << "������������Ҫ�����������׼��֤��" << endl;
    cin >> name;
    cin >> id;
    cout << endl;
    bool found = false;
    for (auto & iter1 : student) {
        if (iter1.id == id and iter1.name == name){
            found =! found;
            sort(iter1.score.begin(),iter1.score.end(),GreaterSort);
            cout << "���Դ���" << "\t���Գɼ�"<< endl;
            for (auto & iter2 : iter1.score) {
                cout << iter2.id << "\t\t" << iter2.score << endl << endl;
            }
            break;
        }
    }
    if (!found){
        cout << "û�в�ѯ�����������ѧ����Ϣ����˶���ϸ���ٴ����룡" << endl;
    }
    system("pause");
    system("cls");
    return 0;
}

int del(){
    string name,id;
    system("cls");
    cout << "������������Ҫɾ����������׼��֤��" << endl;
    cin >> name;
    cin >> id;
    cout << endl;
    bool found = false;
    for (auto iter1 = student.begin(); iter1 != student.end(); iter1++) {
        if (iter1->id == id and iter1->name == name){
            found =! found;
            student.erase(iter1);
            break;
        }
    }
    if (!found){
        cout << "û�в�ѯ�����������ѧ����Ϣ����˶���ϸ���ٴ����룡" << endl;
    }
    system("pause");
    system("cls");
    return 0;
}
