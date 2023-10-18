/*
Линейный списки

Картотека в бюро обмена квартир организована как линейный список.
Сведения о каждой квартире содержат:
- количество комнат;
- этаж;
- площадь;
- адрес.

Разработать программу, которая обеспечивает:
- начальное формирование картотеки;
- ввод заявки на обмен;
- поиск в картотеке подходящего варианта по следующим критериям: 
количество комнат, этажи, площадь, адрес;
- вывод всего списка.
Программа должна обеспечивать диалог с помощью меню и контроль
ошибок при вводе.
*/

#include <iostream>
#include <string>
#include <windows.h>
#include <regex>

using namespace std;

//Стуктура, описывающая узел связанного списка
struct Node
{
    int rooms; //Кол-во комнат
    int floor; //Этаж
    float area; //Площадь
    string address; //Адрес
    Node* next;
};

//Класс, описывающий объект "связанный список"
class Apartments_cards
{
private:
    Node* head;

public:
    Apartments_cards()
    {
        head = NULL;
    }

    ~Apartments_cards()
    {
        Node* current = head;
        for(;current != NULL;)
        {
            Node* next = current->next;
            delete current; //Удаление узла линейного списка
            current = next;
        }
    }

    //Метод, добавляющий новый узел в список
    void addApartment(int rooms, int floor, float area, string address)
    {
        Node* apr = new Node; //Динамически создаём новый узел
        //Задаём узлу данные
        apr->rooms = rooms;
        apr->floor = floor;
        apr->area = area;
        apr->address = address;
        apr->next = NULL; //Новый узел в конце, потому null

        if (head == NULL) //Если создаём первый узел
            head = apr;
        else { //Если узел уже не первый
            Node* current = head;
            //Ищем в цикле предшествующий последнему узел
            for (;current->next != NULL; current = current->next);
            //Предшествующий указывает на последний
            current->next = apr;
        }
    }

    //Метод поиска подходящих вариантов в картотеке
    void searchApartment()
    {
        Node* current = head;

        if (current == NULL) {
            cout << "Картотека квартир пуста\n";
            return;
        }
        //Фукнции, используемые для корректного ввода данных
        int user_menu();
        int integer_number();
        float float_number();

        int rooms, floor; //Комнаты, этаж
        float area; //Площадь
        string address; //Адрес
        bool is_find = false; //Нашлись ли нужные квартиры

        //Меню пользователя
        printf("Выберите операцию:\n1 - Поиск по количеству комнат\n");
        printf("2 - Поиск по этажу\n3 - Поиск по площади\n");
        printf("4 - Поиск по адресу\n");

        switch (int choice = user_menu())
        {
        case 1: //Поиск по количеству комнат
            printf("Количество комнат");
            rooms = integer_number();
            for (; current != NULL; current = current->next)
            {
                if (current->rooms == rooms) {
                    if (!is_find) { //Комната нашлась в первый раз
                        cout << "Подходящие квартиры:\n";
                        is_find = true;
                    }
                    cout << "Количество комнат: " << current->rooms;
                    cout << " Этаж: " << current->floor;
                    cout << " Площадь " << current->area;
                    cout << " Адрес: " << current->address << endl;
                }
            }
            if (!is_find) {
                cout << "Подходящих квартир не обнаружено\n";
                break;
            }
            break;
        case 2: //Поиск по этажу
            printf("Этаж");
            floor = integer_number();
            for (; current != NULL; current = current->next)
            {
                if (current->floor == floor) {
                    if (!is_find) { //Комната нашлась в первый раз
                        cout << "Подходящие квартиры:\n";
                        is_find = true;
                    }
                    cout << "Количество комнат: " << current->rooms;
                    cout << " Этаж: " << current->floor;
                    cout << " Площадь " << current->area;
                    cout << " Адрес: " << current->address << endl;
                }
            }
            if (!is_find) {
                cout << "Подходящих квартир не обнаружено\n";
                break;
            }
            break;
        case 3: //Поиск по площади квартиры
            printf("Площадь квартиры");
            area = float_number();
            for (; current != NULL; current = current->next)
            {
                if (current->area == area) {
                    if (!is_find) { //Комната нашлась в первый раз
                        cout << "Подходящие квартиры:\n";
                        is_find = true;
                    }
                    cout << "Количество комнат: " << current->rooms;
                    cout << " Этаж: " << current->floor;
                    cout << " Площадь " << current->area;
                    cout << " Адрес: " << current->address << endl;
                }
            }
            if (!is_find) {
                cout << "Подходящих квартир не обнаружено\n";
                break;
            }
            break;
        case 4: //Поиск по адресу квартиры
            printf("Адрес квартиры\nВведите адрес квартиры: ");
            getline(cin, address);
            for (; current != NULL; current = current->next)
            {
                if (current->address == address) {
                    if (!is_find) { //Комната нашлась в первый раз
                        cout << "\nПодходящие квартиры:\n";
                        is_find = true;
                    }
                    cout << "Количество комнат: " << current->rooms;
                    cout << " Этаж: " << current->floor;
                    cout << " Площадь " << current->area;
                    cout << " Адрес: " << current->address << endl;
                }
            }
            if (!is_find) {
                cout << "Подходящих квартир не обнаружено\n";
                break;
            }
            break;
        }
        return;
    }

    //Метод, выводящий линейный список на экран
    void printList()
    {
        Node* current = head;

        if (current == NULL)
            cout << "Картотека квартир пуста\n";
        else {
            cout << "Список квартир:\n";
            for (int i = 1; current != NULL; i++, current = current->next)
            {
                cout << "Квартира #" << i << endl;
                cout << "Количество комнат: " << current->rooms;
                cout << " Этаж: " << current->floor;
                cout << " Площадь " << current->area;
                cout << " Адрес: " << current->address << endl;
            }
        }
    }
};

//Функция-меню, организующая выбор выполняемой операции
//Возвращает число, характеризующее выбранную операцию
int user_menu()
{
    string option;
    regex option_regex("[1-4]");

    //Выбор операции
    do {
        printf("\nВыбранная операция: ");
        getline(cin, option);
        printf("\n");
        //Проверка корректности введённой операции
        if (!regex_match(option, option_regex))
            printf("Операция не опознана. Попробуйте снова\n");
    } while (!regex_match(option, option_regex));

    return stoi(option);
}

//Функция ввода целых положительных чисел и проверки корректности ввода
//Возвращает введённое число
int integer_number()
{
    string number;

    regex integer_regex("^[1-9][0-9]*$");

    do {
        printf("\nВведите число: ");
        getline(cin, number);
        printf("\n");
        //Проверка корректности ввода целого числа
        if (!regex_match(number, integer_regex))
            printf("Вы некорректное значение. Попробуйте снова\n");
    } while (!regex_match(number, integer_regex));

    return stoi(number);
}

float float_number()
{
    string number;

    regex float_regex("^[1-9]+\\.?[0-9]*$");

    do {
        printf("\nВведите число: ");
        getline(cin, number);
        printf("\n");
        //Проверка корректности ввода вещественного числа
        if (!regex_match(number, float_regex))
            printf("Вы ввели некорректное значение. Попробуйте снова\n");

    } while (!regex_match(number, float_regex));

    return stof(number);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Apartments_cards myApartment;

    int rooms, floor, choice;
    float area;
    string address;

    //Начальное формирование картотеки
    myApartment.addApartment(3, 5, 31, "Улица Лесная");
    myApartment.addApartment(11, 55, 231, "Улица Петропавловская");
    myApartment.addApartment(112, 25, 2, "Петропавловская");

    //Заголовок программы
    printf("Программа, реализующая картотеку квартир\n");

    do
    {
        //Меню пользователя
        printf("\nВыберите операцию:\n1 - Добавление квартиры в список\n");
        printf("2 - Поиск в картотеке подходящего варианта\n3 - Вывод картотеки\n");
        printf("4 - Завершение работы программы\n");

        switch (choice = user_menu())
        {
        case 1: //Ввод квартиры в список
            //Ввод данных о добавляемой квартире
            printf("Количество комнат");
            rooms = integer_number();
            printf("Номер этажа");
            floor = integer_number();
            printf("Площадь квартиры");
            area = float_number();
            printf("Адрес квартиры\nВведите адрес квартиры: ");
            getline(cin, address);
            printf("\nКвартира добавлена в картотеку\n");
            //Вызов метода добавления квартиры
            myApartment.addApartment(rooms, floor, area, address);
            break;
        case 2: //Поиск в картотеке подходящего варианта
            myApartment.searchApartment();
            break;
        case 3: //Вывод всего списка картотеки
            myApartment.printList();
            break;
        case 4: //Завершение работы программы
            printf("До свидания!\n");
            break;
        }
    } while (choice != 4);

    return 0;
}


