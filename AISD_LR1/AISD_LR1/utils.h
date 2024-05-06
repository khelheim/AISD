#pragma once

#include "list.h"

template<typename T>
void testListOperations(T type, int capacity) {
    List<int> myList(capacity);
    List<int>::ForwardIterator it = myList.end();
    List<int>::ReverseIterator rit = myList.rend();
    bool is_show_list_menu = true;
    bool is_iterator_init = false;
    bool is_reverse_iterator_init = false;
    T value;
    int choice = 0;
    size_t index = 0;

    while (true) {
        cout << "\n--- Меню операций ---\n";
        cout << "0. Скрыть/Развернуть меню работы со списком\n";
        if (is_show_list_menu) {
            cout << "<array>\n";
            cout << "1. Узнать размер списка\n";
            cout << "2. Очистить список\n";
            cout << "3. Проверить, пуст ли список\n";
            cout << "4. Проверить наличие заданного значения\n";
            cout << "5. Получить значение по индексу\n";
            cout << "6. Изменить значение по индексу\n";
            cout << "7. Найти индекс заданного значения\n";
            cout << "8. Добавить элемент в конец списка\n";
            cout << "9. Вставить элемент по индексу\n";
            cout << "10. Удалить элемент по значению\n";
            cout << "11. Удалить элемент по индексу\n";
            cout << "12. Вывести количество просмотренных элементов последней операции\n";
            cout << "13. Вывести элементы списка\n";
            cout << "14. Вывести вместимость списка\n";
        }
        cout << "<iterator>\n";
        cout << "15. Установить прямой итератор на begin\n";
        if (is_iterator_init) {
            cout << "16. Установить прямой итератор на end\n";
            cout << "17. Проверить итератор на равенство end\n";
            cout << "18. Инкрементировать итератор\n";
            cout << "19. Получить значение по итератору\n";
            cout << "20. Изменить значение по итератору\n";
        }
        cout << "<reverse iterator>\n";
        cout << "21. Установить обратный итератор на rbegin\n";
        if (is_reverse_iterator_init) {
            cout << "22. Установить обратный итератор на rend\n";
            cout << "23. Проверить обратный итератор на равенство rend\n";
            cout << "24. Декрементировать обратный итератор\n";
            cout << "25. Получить значение по обратному итератору\n";
            cout << "26. Изменить значение по обратному итератору\n";
        }
        cout << "<menu>\n";
        cout << "27. Закончить работу со списком\n";
        cout << "==>Выберите операцию: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();  // Восстановление потока, если пользователь ввел не число
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Игнорируем некорректный ввод до конца строки
            cout << "-->Введено некорректное значение. Пожалуйста, попробуйте снова.\n";
            continue;
        }

        try {
            switch (choice) {
            case 0:
                is_show_list_menu = !is_show_list_menu;
                break;
            case 1:
                cout << "-->Размер списка: " << myList.get_size() << endl;
                break;
            
            case 2:
                myList.clear();
                is_iterator_init = is_reverse_iterator_init = false;
                cout << "-->Список успешно очищен.\n";
                break;
            
            case 3:
                cout << (myList.is_empty() ? "-->Список пуст.\n" : "-->Список не пуст.\n");
                break;
            
            case 4:
                cout << "==>Введите значение для проверки его наличия в списке: ";
                cin >> value;
                cout << (myList.contains(value) ? "-->Значение найдено в списке.\n" : "-->Значение в списке отсутствует.\n");
                break;
            
            case 5:
                cout << "==>Введите индекс для получения значения: ";
                cin >> index;
                cout << "-->Значение: " << myList.get(index) << endl;
                break;
            
            case 6:
                cout << "==>Введите индекс и новое значение: ";
                cin >> index >> value;
                myList.set(index, value);
                cout << "-->Значение успешно изменено.\n";
                break;
            
            case 7:
                cout << "==>Введите значение для поиска индекса : ";
                cin >> value;
                cout << "==>Индекс заданного значения: " << myList.index_of(value) << endl;
                break;
            
            case 8:
                cout << "==>Введите значение элемента: ";
                cin >> value;
                myList.push_back(value);
                is_iterator_init = is_reverse_iterator_init = false;
                cout << "-->Элемент добавлен.\n" << endl;
                break;
            
            case 9:
                cout << "==>Введите индекс и значение для вставки: ";
                cin >> index >> value;
                myList.insert(index, value);
                is_iterator_init = is_reverse_iterator_init = false;
                cout << "-->Элемент вставлен.\n";
                break;
            
            case 10:
                cout << "==>Введите значение элемента: ";
                cin >> value;
                is_iterator_init = is_reverse_iterator_init = false;
                myList.remove(value) ? cout << "-->Элемент удален.\n" : cout << "-->Элемент не удален.\n";
                break;
            
            case 11:
                cout << "==>Введите индекс удаляемого элемента: ";
                cin >> index;
                myList.erase(index);
                is_iterator_init = is_reverse_iterator_init = false;
                cout << "-->Элемент удален.\n";
                break;
            
            case 12:
                cout << "-->Количество просмотренных элементов последней операции: " 
                    << myList.get_last_operation_count() << endl;
                break;
    
            case 13:
                cout << "-->Элементы списка: ";
                myList.display();
                break;   

            case 14:
                cout << "-->Вместимость списка: " << myList.get_capacity() << endl;
                break; 

            case 15:
                is_iterator_init = true;
                it = myList.begin();
                cout << "-->Установлен прямой итератор на begin" << endl;
                break;

            case 16:
                it = myList.end();
                cout << "-->Установлен прямой итератор на end" << endl;
                break;

            case 17:
                if (is_iterator_init) {
                    if (myList.is_forward_iterator_equal_to_end(it)) {
                        cout << "-->Итератор равен end" << endl;
                    }
                    else {
                        cout << "-->Итератор не равен end" << endl;
                    }
                }
                break;

            case 18:
                if (!myList.is_forward_iterator_equal_to_end(it) && is_iterator_init) {
                    it++;
                    cout << "-->Итератор инкрементирован" << endl;
                }
                else {
                    cout << "Итератор указыввает на end" << endl;
                }
                break;

            case 19:
                if (!myList.is_forward_iterator_equal_to_end(it) && is_iterator_init) {
                    cout << "-->Значение по итератору: " << *it << endl;
                }
                else {
                    cout << "Итератор указывает на end" << endl;
                }
                break;

            case 20:
                if (!myList.is_forward_iterator_equal_to_end(it)) {
                    cout << "==>Введите значение: ";
                    cin >> value;
                    *it = value;
                }
                else {
                    cout << "Итератор указывает на end" << endl;
                }
                break;

            case 21:
                is_reverse_iterator_init = true;
                rit = myList.rbegin();
                cout << "-->Установлен обратный итератор на rbegin" << endl;
                break;

            case 22:
                rit = myList.rend();
                cout << "-->Установлен обратный итератор на rend" << endl;
                break;

            case 23:
                if (is_reverse_iterator_init) {
                    if (myList.is_reverse_iterator_equal_to_rend(rit)) {
                        cout << "-->Обратный итератор равен rend" << endl;
                    }
                    else {
                        cout << "-->Обратный итератор не равен rend" << endl;
                    }
                }
                break;

            case 24:
                if (!myList.is_reverse_iterator_equal_to_rend(rit) && is_reverse_iterator_init) {
                    rit--;
                    cout << "-->Итератор декрементирован" << endl;
                }
                else {
                    cout << "Обратный итератор указыввает на rend" << endl;
                }
                break;

            case 25:
                if (!myList.is_reverse_iterator_equal_to_rend(rit) && is_reverse_iterator_init) {
                    cout << "-->Значение по обратному итератору: " << *rit << endl;
                }
                else {
                    cout << "Обратный итератор указывает на rend" << endl;
                }
                break;

            case 26:
                if (!myList.is_reverse_iterator_equal_to_rend(rit) && is_reverse_iterator_init) {
                    cout << "==>Введите значение: ";
                    cin >> value;
                    *rit = value;
                }
                else {
                    cout << "Обратный итератор указывает на rend" << endl;
                }
                break;

            case 27:
                cout << "-->Окончание работы со списком.\n";
                return;
            
            default:
                cout << "-->Неизвестная операция. Пожалуйста, попробуйте снова.\n";
                break;
            }
        }
        catch (const std::out_of_range& e) {
            cout << e.what() << '\n';
        }
        catch (const std::bad_alloc& e) {
            cout << "Ошибка выделения памяти: " << e.what() << '\n';
        }
        catch (const std::exception& e) {
            cout << "Произошла ошибка: " << e.what() << "\n";
        }
    }
}

void testList(void) {
    int choice = 0;
    int capacity = 0;
    while (true) {
        cout << "\n--- Меню операций ---\n";
        cout << "1. Начать работу со списком\n";
        cout << "2. Выйти из программы\n";
        cout << "==>Выберите операцию: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();  // Восстановление потока, если пользователь ввел не число
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Игнорируем некорректный ввод до конца строки
            cout << "-->Введено некорректное значение. Пожалуйста, попробуйте снова.\n";
            continue;
        }
        switch (choice) {
        case 1:
            cout << "==>Введите изначальный размер списка: ";
            cin >> capacity;

            if (capacity <= 0) {
                cout << "-->Задан некорректный размер списка\n";
                break;
            }

            cout << "Выберите тип данных списка: \n";
            cout << "1. Integer \n";
            cout << "2. Float \n";
            cout << "3. Char \n";
            cout << "==>Введите выбранный тип: ";
            cin >> choice;

            if (1 == choice) {
                int itype = 0;
                testListOperations(itype, capacity);
            }
            else if (2 == choice) {
                float ftype = 0;
                testListOperations(ftype, capacity);
            }
            else if (3 == choice) {
                char ctype = 0;
                testListOperations(ctype, capacity);
            }
            else {
                cout << "-->Неправильный тип данных \n";
                break;
            }
            break;
        case 2:
            cout << "-->Выход из программы.\n";
            return;
        default:
            cout << "-->Неизвестная операция. Пожалуйста, попробуйте снова.\n";
            break;
        }
    }
}
