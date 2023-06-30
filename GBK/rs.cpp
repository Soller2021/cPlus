#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item
{
private:
    string title;
    string author;
    int indexCode;
    string barcode;

public:
    Item(string title, string author, int indexCode, string barcode)
    {
        this->title = title;
        this->author = author;
        this->indexCode = indexCode;
        this->barcode = barcode;
    }

    // ���Ĭ�Ϲ��캯��
    Item()
    {
        this->title = "";
        this->author = "";
        this->indexCode = 0;
        this->barcode = "";
    }

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    int getIndexCode()
    {
        return indexCode;
    }

    string getBarcode()
    {
        return barcode;
    }
};

class Reader
{
private:
    string name;
    string position;
    int code;
    vector<Item> borrowedItems;

public:
    Reader(string name, string position, int code)
    {
        this->name = name;
        this->position = position;
        this->code = code;
    }

    // ���Ĭ�Ϲ��캯��
    Reader()
    {
        this->name = "";
        this->position = "";
        this->code = 0;
    }

    string getName()
    {
        return name;
    }

    string getPosition()
    {
        return position;
    }

    int getCode()
    {
        return code;
    }

    void borrowItem(Item item)
    {
        borrowedItems.push_back(item);
    }

    void returnItem(Item item)
    {
        for (int i = 0; i < borrowedItems.size(); i++)
        {
            if (borrowedItems[i].getBarcode() == item.getBarcode())
            {
                borrowedItems.erase(borrowedItems.begin() + i);
                break;
            }
        }
    }

    vector<Item> getBorrowedItems()
    {
        return borrowedItems;
    }
};

class CMain
{
private:
    vector<Item> items;
    vector<Reader> readers;

public:
    void createItem()
    {
        string title, author, barcode;
        int indexCode;

        cout << "������ͼ����⣺ ";
        cin >> title;
        cout << "���������������� ";
        cin >> author;
        cout << "�������������룺 ";
        cin >> indexCode;
        cout << "�����������룺 ";
        cin >> barcode;

        Item item(title, author, indexCode, barcode);
        items.push_back(item);

        cout << "ͼ����Ŀ�����ɹ���" << endl;
    }

    void createReader()
    {
        string name, position;
        int code;

        cout << "����������ƣ� ";
        cin >> name;
        cout << "�������ְλ�� ";
        cin >> position;
        cout << "������ߴ��룺";
        cin >> code;

        Reader reader(name, position, code);
        readers.push_back(reader);

        cout << "����ע��ɹ�." << endl;
    }

    void borrowItem()
    {
        int readerCode;
        string barcode;

        cout << "��������ߴ��룺";
        cin >> readerCode;
        cout << "������ͼ�������룺 ";
        cin >> barcode;

        Item item;
        Reader reader;

        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].getBarcode() == barcode)
            {
                item = items[i];
                break;
            }
        }

        for (int i = 0; i < readers.size(); i++)
        {
            if (readers[i].getCode() == readerCode)
            {
                reader = readers[i];
                break;
            }
        }

        reader.borrowItem(item);

        cout << "ͼ����ĳɹ�." << endl;
    }

    void returnItem()
    {
        int readerCode;
        string barcode;

        cout << "��������ߴ��룺 ";
        cin >> readerCode;
        cout << "������ͼ�������룺";
        cin >> barcode;

        Item item;
        Reader reader;

        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].getBarcode() == barcode)
            {
                item = items[i];
                break;
            }
        }

        for (int i = 0; i < readers.size(); i++)
        {
            if (readers[i].getCode() == readerCode)
            {
                reader = readers[i];
                break;
            }
        }

        reader.returnItem(item);

        cout << "ͼ��黹�ɹ�." << endl;
    }

    void searchBorrowedBooks()
    {
        int readerCode;

        cout << "��������ߴ��룺";
        cin >> readerCode;

        Reader reader;

        for (int i = 0; i < readers.size(); i++)
        {
            if (readers[i].getCode() == readerCode)
            {
                reader = readers[i];
                break;
            }
        }

        vector<Item> borrowedItems = reader.getBorrowedItems();

        cout << "�����е�ͼ�飺" << endl;

        for (int i = 0; i < borrowedItems.size(); i++)
        {
            cout << "���⣺ " << borrowedItems[i].getTitle() << endl;
            cout << "���ߣ� " << borrowedItems[i].getAuthor() << endl;
            cout << "�����룺" << borrowedItems[i].getIndexCode() << endl;
            cout << "�����룺 " << borrowedItems[i].getBarcode() << endl;
            cout << endl;
        }
    }
};

int main()
{
    CMain main;

    int choice;

    do
    {
        cout << "1. ����ͼ��" << endl;
        cout << "2. ע�����" << endl;
        cout << "3. ����ͼ��" << endl;
        cout << "4. �黹ͼ��" << endl;
        cout << "5. ��ѯ����ͼ��" << endl;
        cout << "6. �˳�" << endl;
        cout << "����������ѡ��: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            main.createItem();
            break;
        case 2:
            main.createReader();
            break;
        case 3:
            main.borrowItem();
            break;
        case 4:
            main.returnItem();
            break;
        case 5:
            main.searchBorrowedBooks();
            break;
        case 6:
            cout << "�˳�����..." << endl;
            break;
        default:
            cout << "��Ч��ѡ��������һ�Ρ�" << endl;
        }

        cout << endl;
    } while (choice != 6);

    return 0;
}
