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
        cout << "\n--- ���� �������� ---\n";
        cout << "0. ������/���������� ���� ������ �� �������\n";
        if (is_show_list_menu) {
            cout << "<array>\n";
            cout << "1. ������ ������ ������\n";
            cout << "2. �������� ������\n";
            cout << "3. ���������, ���� �� ������\n";
            cout << "4. ��������� ������� ��������� ��������\n";
            cout << "5. �������� �������� �� �������\n";
            cout << "6. �������� �������� �� �������\n";
            cout << "7. ����� ������ ��������� ��������\n";
            cout << "8. �������� ������� � ����� ������\n";
            cout << "9. �������� ������� �� �������\n";
            cout << "10. ������� ������� �� ��������\n";
            cout << "11. ������� ������� �� �������\n";
            cout << "12. ������� ���������� ������������� ��������� ��������� ��������\n";
            cout << "13. ������� �������� ������\n";
            cout << "14. ������� ����������� ������\n";
        }
        cout << "<iterator>\n";
        cout << "15. ���������� ������ �������� �� begin\n";
        if (is_iterator_init) {
            cout << "16. ���������� ������ �������� �� end\n";
            cout << "17. ��������� �������� �� ��������� end\n";
            cout << "18. ���������������� ��������\n";
            cout << "19. �������� �������� �� ���������\n";
            cout << "20. �������� �������� �� ���������\n";
        }
        cout << "<reverse iterator>\n";
        cout << "21. ���������� �������� �������� �� rbegin\n";
        if (is_reverse_iterator_init) {
            cout << "22. ���������� �������� �������� �� rend\n";
            cout << "23. ��������� �������� �������� �� ��������� rend\n";
            cout << "24. ���������������� �������� ��������\n";
            cout << "25. �������� �������� �� ��������� ���������\n";
            cout << "26. �������� �������� �� ��������� ���������\n";
        }
        cout << "<menu>\n";
        cout << "27. ��������� ������ �� �������\n";
        cout << "==>�������� ��������: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();  // �������������� ������, ���� ������������ ���� �� �����
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ���������� ������������ ���� �� ����� ������
            cout << "-->������� ������������ ��������. ����������, ���������� �����.\n";
            continue;
        }

        try {
            switch (choice) {
            case 0:
                is_show_list_menu = !is_show_list_menu;
                break;
            case 1:
                cout << "-->������ ������: " << myList.get_size() << endl;
                break;
            
            case 2:
                myList.clear();
                is_iterator_init = is_reverse_iterator_init = false;
                cout << "-->������ ������� ������.\n";
                break;
            
            case 3:
                cout << (myList.is_empty() ? "-->������ ����.\n" : "-->������ �� ����.\n");
                break;
            
            case 4:
                cout << "==>������� �������� ��� �������� ��� ������� � ������: ";
                cin >> value;
                cout << (myList.contains(value) ? "-->�������� ������� � ������.\n" : "-->�������� � ������ �����������.\n");
                break;
            
            case 5:
                cout << "==>������� ������ ��� ��������� ��������: ";
                cin >> index;
                cout << "-->��������: " << myList.get(index) << endl;
                break;
            
            case 6:
                cout << "==>������� ������ � ����� ��������: ";
                cin >> index >> value;
                myList.set(index, value);
                cout << "-->�������� ������� ��������.\n";
                break;
            
            case 7:
                cout << "==>������� �������� ��� ������ ������� : ";
                cin >> value;
                cout << "==>������ ��������� ��������: " << myList.index_of(value) << endl;
                break;
            
            case 8:
                cout << "==>������� �������� ��������: ";
                cin >> value;
                myList.push_back(value);
                is_iterator_init = is_reverse_iterator_init = false;
                cout << "-->������� ��������.\n" << endl;
                break;
            
            case 9:
                cout << "==>������� ������ � �������� ��� �������: ";
                cin >> index >> value;
                myList.insert(index, value);
                is_iterator_init = is_reverse_iterator_init = false;
                cout << "-->������� ��������.\n";
                break;
            
            case 10:
                cout << "==>������� �������� ��������: ";
                cin >> value;
                is_iterator_init = is_reverse_iterator_init = false;
                myList.remove(value) ? cout << "-->������� ������.\n" : cout << "-->������� �� ������.\n";
                break;
            
            case 11:
                cout << "==>������� ������ ���������� ��������: ";
                cin >> index;
                myList.erase(index);
                is_iterator_init = is_reverse_iterator_init = false;
                cout << "-->������� ������.\n";
                break;
            
            case 12:
                cout << "-->���������� ������������� ��������� ��������� ��������: " 
                    << myList.get_last_operation_count() << endl;
                break;
    
            case 13:
                cout << "-->�������� ������: ";
                myList.display();
                break;   

            case 14:
                cout << "-->����������� ������: " << myList.get_capacity() << endl;
                break; 

            case 15:
                is_iterator_init = true;
                it = myList.begin();
                cout << "-->���������� ������ �������� �� begin" << endl;
                break;

            case 16:
                it = myList.end();
                cout << "-->���������� ������ �������� �� end" << endl;
                break;

            case 17:
                if (is_iterator_init) {
                    if (myList.is_forward_iterator_equal_to_end(it)) {
                        cout << "-->�������� ����� end" << endl;
                    }
                    else {
                        cout << "-->�������� �� ����� end" << endl;
                    }
                }
                break;

            case 18:
                if (!myList.is_forward_iterator_equal_to_end(it) && is_iterator_init) {
                    it++;
                    cout << "-->�������� ���������������" << endl;
                }
                else {
                    cout << "�������� ���������� �� end" << endl;
                }
                break;

            case 19:
                if (!myList.is_forward_iterator_equal_to_end(it) && is_iterator_init) {
                    cout << "-->�������� �� ���������: " << *it << endl;
                }
                else {
                    cout << "�������� ��������� �� end" << endl;
                }
                break;

            case 20:
                if (!myList.is_forward_iterator_equal_to_end(it)) {
                    cout << "==>������� ��������: ";
                    cin >> value;
                    *it = value;
                }
                else {
                    cout << "�������� ��������� �� end" << endl;
                }
                break;

            case 21:
                is_reverse_iterator_init = true;
                rit = myList.rbegin();
                cout << "-->���������� �������� �������� �� rbegin" << endl;
                break;

            case 22:
                rit = myList.rend();
                cout << "-->���������� �������� �������� �� rend" << endl;
                break;

            case 23:
                if (is_reverse_iterator_init) {
                    if (myList.is_reverse_iterator_equal_to_rend(rit)) {
                        cout << "-->�������� �������� ����� rend" << endl;
                    }
                    else {
                        cout << "-->�������� �������� �� ����� rend" << endl;
                    }
                }
                break;

            case 24:
                if (!myList.is_reverse_iterator_equal_to_rend(rit) && is_reverse_iterator_init) {
                    rit--;
                    cout << "-->�������� ���������������" << endl;
                }
                else {
                    cout << "�������� �������� ���������� �� rend" << endl;
                }
                break;

            case 25:
                if (!myList.is_reverse_iterator_equal_to_rend(rit) && is_reverse_iterator_init) {
                    cout << "-->�������� �� ��������� ���������: " << *rit << endl;
                }
                else {
                    cout << "�������� �������� ��������� �� rend" << endl;
                }
                break;

            case 26:
                if (!myList.is_reverse_iterator_equal_to_rend(rit) && is_reverse_iterator_init) {
                    cout << "==>������� ��������: ";
                    cin >> value;
                    *rit = value;
                }
                else {
                    cout << "�������� �������� ��������� �� rend" << endl;
                }
                break;

            case 27:
                cout << "-->��������� ������ �� �������.\n";
                return;
            
            default:
                cout << "-->����������� ��������. ����������, ���������� �����.\n";
                break;
            }
        }
        catch (const std::out_of_range& e) {
            cout << e.what() << '\n';
        }
        catch (const std::bad_alloc& e) {
            cout << "������ ��������� ������: " << e.what() << '\n';
        }
        catch (const std::exception& e) {
            cout << "��������� ������: " << e.what() << "\n";
        }
    }
}

void testList(void) {
    int choice = 0;
    int capacity = 0;
    while (true) {
        cout << "\n--- ���� �������� ---\n";
        cout << "1. ������ ������ �� �������\n";
        cout << "2. ����� �� ���������\n";
        cout << "==>�������� ��������: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();  // �������������� ������, ���� ������������ ���� �� �����
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ���������� ������������ ���� �� ����� ������
            cout << "-->������� ������������ ��������. ����������, ���������� �����.\n";
            continue;
        }
        switch (choice) {
        case 1:
            cout << "==>������� ����������� ������ ������: ";
            cin >> capacity;

            if (capacity <= 0) {
                cout << "-->����� ������������ ������ ������\n";
                break;
            }

            cout << "�������� ��� ������ ������: \n";
            cout << "1. Integer \n";
            cout << "2. Float \n";
            cout << "3. Char \n";
            cout << "==>������� ��������� ���: ";
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
                cout << "-->������������ ��� ������ \n";
                break;
            }
            break;
        case 2:
            cout << "-->����� �� ���������.\n";
            return;
        default:
            cout << "-->����������� ��������. ����������, ���������� �����.\n";
            break;
        }
    }
}
