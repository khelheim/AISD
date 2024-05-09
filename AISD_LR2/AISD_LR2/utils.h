#pragma once

#include "bst.h"

template<typename T, typename Key>
void testBSTOperations(T type, Key key_type) {
    BSTree<Key, T> myBST;
    typename BSTree<Key, T>::Iterator it = myBST.end();
    typename BSTree<Key,T>::ReverseIterator rit = myBST.rend();
    bool is_show_BST_menu = true;
    bool is_iterator_init = false;
    bool is_reverse_iterator_init = false;
    T value;
    int choice = 0;
    Key key = 0;

    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "0. Скрыть/Развернуть меню работы со списком\n";
        if (is_show_BST_menu) {
            cout << "<BSTree>\n";
            cout << "1.  Опрос размера дерева\n";
            cout << "2.  Очистка дерева\n";
            cout << "3.  Проверка дерева на пустоту\n";
            cout << "4.  Проверка на наличие ключа\n";
            cout << "5.  Получить данные по ключу\n";
            cout << "6.  Изменить данные по ключу\n";
            cout << "7.  Включение данных с заданным ключом\n";
            cout << "8.  Удаление данных с заданным ключом\n";
            cout << "9.  Формирование списка ключей в порядке t->Lt->Rt\n";
            cout << "10. Определение высоты дерева\n";
        }
        cout << "<iterator>\n";
        cout << "11. Запрос прямого итератора уст. на begin\n";
        if (is_iterator_init) {
            cout << "12. Запрос неуст. прямого итератора end\n";
            cout << "13. Проверка прямого итератора на равенство end\n";
            cout << "14. Инкрементирование прямого итератора\n";
            cout << "15. Получение значения по прямому итератору\n";
            cout << "16. Измение значения по прямому итератору\n";
        }
        cout << "<reverse iterator>\n";
        cout << "17. Запрос обратного итератора  уст. на rbegin\n";
        if (is_reverse_iterator_init) {
            cout << "18. Запрос неуст. обратного итератора rend\n";
            cout << "19. Проверка обратного итератора на равенство rend\n";
            cout << "20. Декрементирование обратного итератора\n";
            cout << "21. Получение значения по обратному итератору\n";
            cout << "22. Изменение значения по обратному итератору\n";
        }
        cout << "<menu>\n";
        cout << "23. Закончить работу со списком\n";
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
                is_show_BST_menu = !is_show_BST_menu;
                break;
            case 1:
                cout << "-->Размер дерева: " << myBST.get_size() << endl;
                break;

            case 2:
                myBST.clear();
                is_iterator_init = is_reverse_iterator_init = false;
                cout << "-->Дерево успешно очищено.\n";
                break;

            case 3:
                cout << (myBST.is_empty() ? "-->Дерево пусто.\n" : "-->Дерево не пусто.\n");
                break;

            case 4:
                cout << "==>Введите ключ для проверки его наличия в дереве: ";
                cin >> key;
                if (myBST.search(key)) {
                    cout << "-->Ключ найден в дереве.\n";
                }
                break;

            case 5:
                cout << "==>Введите ключ для получения значения: ";
                cin >> key;
                cout << "-->Значение: ";
                myBST.show_data(key);
                break;

            case 6:
                cout << "==>Введите ключ: ";
                cin >> key;
                cout << "==>Введите данные: ";
                cin >> value;
                myBST.change(key, value);
                break;

            case 7:
                cout << "==>Введите ключ: ";
                cin >> key;
                cout << "==>Введите данные: ";
                cin >> value;
                myBST.insert(key, value);
                is_iterator_init = is_reverse_iterator_init = false;
                break;

            case 8:
                cout << "==>Введите ключ: ";
                cin >> key;
                myBST.remove(key);
                is_iterator_init = is_reverse_iterator_init = false;
                break;

            case 9:
                cout << "==>Сформированные список ключей: ";
                myBST.display_inorder();
                break;

            case 10:
                cout << "==>Высота дерева: " << myBST.height() << endl;
                break;

            case 11:
                is_iterator_init = true;
                it = myBST.begin();
                cout << "-->Установлен прямой итератор на begin" << endl;
                break;

            case 12:
                it = myBST.end();
                cout << "-->Установлен прямой итератор на end" << endl;
                break;

            case 13:
                if (is_iterator_init) {
                    if (myBST.is_iterator_equal_to_end(it)) {
                        cout << "-->Итератор равен end" << endl;
                    }
                    else {
                        cout << "-->Итератор не равен end" << endl;
                    }
                }
                break;

            case 14:
                if (!myBST.is_iterator_equal_to_end(it) && is_iterator_init) {
                    ++it;
                    cout << "-->Итератор инкрементирован" << endl;
                }
                else {
                    cout << "Итератор указывает на end" << endl;
                }
                break;

            case 15:
                if (!myBST.is_iterator_equal_to_end(it) && is_iterator_init) {
                    cout << "-->Значение по итератору: ";
                    myBST.show_node_data(it.cur);
                }
                else {
                    cout << "Итератор указывает на end" << endl;
                }
                break;

            case 16:
                if (!myBST.is_iterator_equal_to_end(it)) {
                    cout << "==>Введите значение: ";
                    cin >> value;
                    myBST.change_node_data(it.cur, value);
                }
                else {
                    cout << "Итератор указывает на end" << endl;
                }
                break;

            case 17:
                is_reverse_iterator_init = true;
                rit = myBST.rbegin();
                cout << "-->Установлен обратный итератор на rbegin" << endl;
                break;

            case 18:
                rit = myBST.rend();
                cout << "-->Установлен обратный итератор на rend" << endl;
                break;

            case 19:
                if (is_reverse_iterator_init) {
                    if (myBST.is_reverse_iterator_equal_to_rend(rit)) {
                        cout << "-->Итератор равен rend" << endl;
                    }
                    else {
                        cout << "-->Итератор не равен rend" << endl;
                    }
                }
                break;

            case 20:
                if (!myBST.is_reverse_iterator_equal_to_rend(rit) && is_reverse_iterator_init) {
                    --rit;
                    cout << "-->Обратный итератор декрементирован" << endl;
                }
                else {
                    cout << "Обратный итератор указывает на rend" << endl;
                }
                break;

            case 21:
                if (!myBST.is_reverse_iterator_equal_to_rend(rit) && is_reverse_iterator_init) {
                    cout << "-->Значение по обратному итератору: ";
                    myBST.show_node_data(rit.cur);
                }
                else {
                    cout << "Обратный итератор указывает на rend" << endl;
                }
                break;

            case 22:
                if (!myBST.is_reverse_iterator_equal_to_rend(rit)) {
                    cout << "==>Введите значение: ";
                    cin >> value;
                    myBST.change_node_data(rit.cur, value);
                }
                else {
                    cout << "Обратный итератор указывает на rend" << endl;
                }
                break;

            case 23:
                return;

            default:
                cout << "-->Неизвестная операция. Пожалуйста, попробуйте снова.\n";
                break;
            }
        }
        catch ( std::out_of_range& e) {
            cout << e.what() << '\n';
        }
        catch ( std::bad_alloc& e) {
            cout << "Ошибка выделения памяти: " << e.what() << '\n';
        }
        catch ( std::exception& e) {
            cout << "Произошла ошибка: " << e.what() << "\n";
        }
    }
}

void testBST(void) {
    int choice = 0;
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
            cout << "Выберите тип данных дерева: \n";
            cout << "1. Integer \n";
            cout << "2. Float \n";
            cout << "3. Char \n";
            cout << "==>Введите выбранный тип: ";
            cin >> choice;

            if (1 == choice) {
                int itype = 0;
                testBSTOperations(itype, itype);
            }
            else if (2 == choice) {
                float ftype = 0;
                testBSTOperations(ftype, ftype);
            }
            else if (3 == choice) {
                char ctype = 0;
                testBSTOperations(ctype, ctype);
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
