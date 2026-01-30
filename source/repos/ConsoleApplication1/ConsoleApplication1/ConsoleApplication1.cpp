#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Record {
    int id;
    string name;
    int age;
    double salary;
};

class TableEditor {
    vector<Record> table;
    int nextId = 1;
public:
    TableEditor() {
        
        // тестовые данные
        table.push_back({ nextId++, "Иван", 30, 50000 });
        table.push_back({ nextId++, "Анна", 25, 45000 });
    }

    void showAll() {
        cout << "\nID  Имя        Возраст  Зарплата\n";
        cout << "--------------------------------\n";
        for (auto& r : table)
            cout << setw(2) << r.id << "  " << setw(10) << r.name
            << setw(8) << r.age << setw(10) << r.salary << endl;
    }

    void add() {
        Record r;
        r.id = nextId++;
        cout << "\nИмя: "; getline(cin, r.name);
        cout << "Возраст: "; cin >> r.age;
        cout << "Зарплата: "; cin >> r.salary;
        cin.ignore();
        table.push_back(r);
        cout << "Добавлено!\n";
    }

    void edit() {
        showAll();
        int id;
        cout << "\nID для редактирования: "; cin >> id;
        cin.ignore();

        for (auto& r : table) {
            if (r.id == id) {
                cout << "Новое имя [" << r.name << "]: ";
                string input; getline(cin, input);
                if (!input.empty()) r.name = input;

                cout << "Новый возраст [" << r.age << "]: ";
                getline(cin, input);
                if (!input.empty()) r.age = stoi(input);

                cout << "Новая зарплата [" << r.salary << "]: ";
                getline(cin, input);
                if (!input.empty()) r.salary = stod(input);

                cout << "Обновлено!\n";
                return;
            }
        }
        cout << "Запись не найдена!\n";
    }

    void remove() {
        showAll();
        int id;
        cout << "\nID для удаления: "; cin >> id;
        cin.ignore();

        for (auto it = table.begin(); it != table.end(); ++it) {
            if (it->id == id) {
                table.erase(it);
                cout << "Удалено!\n";
                return;
            }
        }
        cout << "Запись не найдена!\n";
    }

    void run() {
        while (true) {
            cout << "\n1.Показать 2.Добавить 3.Редакт 4.Удалить 5.Выход\nВыбор: ";
            int choice; cin >> choice;
            cin.ignore();

            switch (choice) {
            case 1: showAll(); break;
            case 2: add(); break;
            case 3: edit(); break;
            case 4: remove(); break;
            case 5: return;
            default: cout << "Неверный выбор!\n";
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    TableEditor editor;
    editor.run();
    return 0;
}