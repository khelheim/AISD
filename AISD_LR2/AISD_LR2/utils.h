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
        cout << "0. ������/���������� ���� ������ �� �������\n";
        if (is_show_BST_menu) {
            cout << "<BSTree>\n";
            cout << "1.  ����� ������� ������\n";
            cout << "2.  ������� ������\n";
            cout << "3.  �������� ������ �� �������\n";
            cout << "4.  �������� �� ������� �����\n";
            cout << "5.  �������� ������ �� �����\n";
            cout << "6.  �������� ������ �� �����\n";
            cout << "7.  ��������� ������ � �������� ������\n";
            cout << "8.  �������� ������ � �������� ������\n";
            cout << "9.  ������������ ������ ������ � ������� t->Lt->Rt\n";
            cout << "10. ����������� ������ ������\n";
        }
        cout << "<iterator>\n";
        cout << "11. ������ ������� ��������� ���. �� begin\n";
        if (is_iterator_init) {
            cout << "12. ������ �����. ������� ��������� end\n";
            cout << "13. �������� ������� ��������� �� ��������� end\n";
            cout << "14. ����������������� ������� ���������\n";
            cout << "15. ��������� �������� �� ������� ���������\n";
            cout << "16. ������� �������� �� ������� ���������\n";
        }
        cout << "<reverse iterator>\n";
        cout << "17. ������ ��������� ���������  ���. �� rbegin\n";
        if (is_reverse_iterator_init) {
            cout << "18. ������ �����. ��������� ��������� rend\n";
            cout << "19. �������� ��������� ��������� �� ��������� rend\n";
            cout << "20. ����������������� ��������� ���������\n";
            cout << "21. ��������� �������� �� ��������� ���������\n";
            cout << "22. ��������� �������� �� ��������� ���������\n";
        }
        cout << "<menu>\n";
        cout << "23. ��������� ������ �� �������\n";
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
                is_show_BST_menu = !is_show_BST_menu;
                break;
            case 1:
                cout << "-->������ ������: " << myBST.get_size() << endl;
                break;

            case 2:
                myBST.clear();
                is_iterator_init = is_reverse_iterator_init = false;
                cout << "-->������ ������� �������.\n";
                break;

            case 3:
                cout << (myBST.is_empty() ? "-->������ �����.\n" : "-->������ �� �����.\n");
                break;

            case 4:
                cout << "==>������� ���� ��� �������� ��� ������� � ������: ";
                cin >> key;
                if (myBST.search(key)) {
                    cout << "-->���� ������ � ������.\n";
                }
                break;

            case 5:
                cout << "==>������� ���� ��� ��������� ��������: ";
                cin >> key;
                cout << "-->��������: ";
                myBST.show_data(key);
                break;

            case 6:
                cout << "==>������� ����: ";
                cin >> key;
                cout << "==>������� ������: ";
                cin >> value;
                myBST.change(key, value);
                break;

            case 7:
                cout << "==>������� ����: ";
                cin >> key;
                cout << "==>������� ������: ";
                cin >> value;
                myBST.insert(key, value);
                is_iterator_init = is_reverse_iterator_init = false;
                break;

            case 8:
                cout << "==>������� ����: ";
                cin >> key;
                myBST.remove(key);
                is_iterator_init = is_reverse_iterator_init = false;
                break;

            case 9:
                cout << "==>�������������� ������ ������: ";
                myBST.display_inorder();
                break;

            case 10:
                cout << "==>������ ������: " << myBST.height() << endl;
                break;

            case 11:
                is_iterator_init = true;
                it = myBST.begin();
                cout << "-->���������� ������ �������� �� begin" << endl;
                break;

            case 12:
                it = myBST.end();
                cout << "-->���������� ������ �������� �� end" << endl;
                break;

            case 13:
                if (is_iterator_init) {
                    if (myBST.is_iterator_equal_to_end(it)) {
                        cout << "-->�������� ����� end" << endl;
                    }
                    else {
                        cout << "-->�������� �� ����� end" << endl;
                    }
                }
                break;

            case 14:
                if (!myBST.is_iterator_equal_to_end(it) && is_iterator_init) {
                    ++it;
                    cout << "-->�������� ���������������" << endl;
                }
                else {
                    cout << "�������� ��������� �� end" << endl;
                }
                break;

            case 15:
                if (!myBST.is_iterator_equal_to_end(it) && is_iterator_init) {
                    cout << "-->�������� �� ���������: ";
                    myBST.show_node_data(it.cur);
                }
                else {
                    cout << "�������� ��������� �� end" << endl;
                }
                break;

            case 16:
                if (!myBST.is_iterator_equal_to_end(it)) {
                    cout << "==>������� ��������: ";
                    cin >> value;
                    myBST.change_node_data(it.cur, value);
                }
                else {
                    cout << "�������� ��������� �� end" << endl;
                }
                break;

            case 17:
                is_reverse_iterator_init = true;
                rit = myBST.rbegin();
                cout << "-->���������� �������� �������� �� rbegin" << endl;
                break;

            case 18:
                rit = myBST.rend();
                cout << "-->���������� �������� �������� �� rend" << endl;
                break;

            case 19:
                if (is_reverse_iterator_init) {
                    if (myBST.is_reverse_iterator_equal_to_rend(rit)) {
                        cout << "-->�������� ����� rend" << endl;
                    }
                    else {
                        cout << "-->�������� �� ����� rend" << endl;
                    }
                }
                break;

            case 20:
                if (!myBST.is_reverse_iterator_equal_to_rend(rit) && is_reverse_iterator_init) {
                    --rit;
                    cout << "-->�������� �������� ���������������" << endl;
                }
                else {
                    cout << "�������� �������� ��������� �� rend" << endl;
                }
                break;

            case 21:
                if (!myBST.is_reverse_iterator_equal_to_rend(rit) && is_reverse_iterator_init) {
                    cout << "-->�������� �� ��������� ���������: ";
                    myBST.show_node_data(rit.cur);
                }
                else {
                    cout << "�������� �������� ��������� �� rend" << endl;
                }
                break;

            case 22:
                if (!myBST.is_reverse_iterator_equal_to_rend(rit)) {
                    cout << "==>������� ��������: ";
                    cin >> value;
                    myBST.change_node_data(rit.cur, value);
                }
                else {
                    cout << "�������� �������� ��������� �� rend" << endl;
                }
                break;

            case 23:
                return;

            default:
                cout << "-->����������� ��������. ����������, ���������� �����.\n";
                break;
            }
        }
        catch ( std::out_of_range& e) {
            cout << e.what() << '\n';
        }
        catch ( std::bad_alloc& e) {
            cout << "������ ��������� ������: " << e.what() << '\n';
        }
        catch ( std::exception& e) {
            cout << "��������� ������: " << e.what() << "\n";
        }
    }
}

void testBST(void) {
    int choice = 0;
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
            cout << "�������� ��� ������ ������: \n";
            cout << "1. Integer \n";
            cout << "2. Float \n";
            cout << "3. Char \n";
            cout << "==>������� ��������� ���: ";
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
