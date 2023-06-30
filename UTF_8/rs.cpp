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

    // 添加默认构造函数
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

    // 添加默认构造函数
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

        cout << "请输入图书标题： ";
        cin >> title;
        cout << "请输入作者姓名： ";
        cin >> author;
        cout << "请输入索引代码： ";
        cin >> indexCode;
        cout << "请输入条形码： ";
        cin >> barcode;

        Item item(title, author, indexCode, barcode);
        items.push_back(item);

        cout << "图书项目创建成功。" << endl;
    }

    void createReader()
    {
        string name, position;
        int code;

        cout << "输入读者名称： ";
        cin >> name;
        cout << "输入读者职位： ";
        cin >> position;
        cout << "输入读者代码：";
        cin >> code;

        Reader reader(name, position, code);
        readers.push_back(reader);

        cout << "读者注册成功." << endl;
    }

    void borrowItem()
    {
        int readerCode;
        string barcode;

        cout << "请输入读者代码：";
        cin >> readerCode;
        cout << "请输入图书条形码： ";
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

        cout << "图书借阅成功." << endl;
    }

    void returnItem()
    {
        int readerCode;
        string barcode;

        cout << "请输入读者代码： ";
        cin >> readerCode;
        cout << "请输入图书条形码：";
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

        cout << "图书归还成功." << endl;
    }

    void searchBorrowedBooks()
    {
        int readerCode;

        cout << "请输入读者代码：";
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

        cout << "借阅中的图书：" << endl;

        for (int i = 0; i < borrowedItems.size(); i++)
        {
            cout << "标题： " << borrowedItems[i].getTitle() << endl;
            cout << "作者： " << borrowedItems[i].getAuthor() << endl;
            cout << "索引码：" << borrowedItems[i].getIndexCode() << endl;
            cout << "条形码： " << borrowedItems[i].getBarcode() << endl;
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
        cout << "1. 创建图书" << endl;
        cout << "2. 注册读者" << endl;
        cout << "3. 借阅图书" << endl;
        cout << "4. 归还图书" << endl;
        cout << "5. 查询借阅图书" << endl;
        cout << "6. 退出" << endl;
        cout << "请输入您的选择: ";
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
            cout << "退出程序..." << endl;
            break;
        default:
            cout << "无效的选择！请再试一次。" << endl;
        }

        cout << endl;
    } while (choice != 6);

    return 0;
}
