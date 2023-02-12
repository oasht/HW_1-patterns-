#define CRT_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include <iomanip>
#include <vector>
#include<algorithm>
using namespace std;



enum Doc_type { Text_t = 0, Picture_t};
enum Pic_type{JPEG, PNG};
                                   
class Editor
{
public:
    virtual void options() = 0;
	virtual void Create() = 0;
	virtual void Open() = 0;
	virtual void Save() = 0;
	virtual void Save_as() = 0;
	virtual void Correct() = 0;
	virtual void Print() = 0;
	virtual void Close() = 0;
    virtual ~Editor() {}                                              
    static Editor* Edit_file(Doc_type t);
};

class Text : public Editor
{
public:
	void Create()
	{
		cout << "Document created" << endl;
	}
	void Open()
	{
		cout << "Document opened" << endl;
	}
	void Save()
	{
		cout << "Document saved" << endl;
	}
	void Save_as()
	{
		cout << "Document saved as..." << endl;
	}
	void Correct() {};
	void Print()
	{
		cout << "Document printed" << endl;
	}
	void Close()
	{
		cout << "Document closed" << endl;
	}
    void options() 
    {
		bool key_1;
		do
		{
			system("cls");

			cout << " Choose what you want to do with the file: 1 - create, 2 - open,\n3 - save, 4 - save under the new name, 5 - print,\n6 - close"<< endl;
			short key;
			cout << endl;
			cin >> key;
			cout << endl;

			switch (key)
			{
			case 1:
			{

				Create();
			}

			break;

			case 2:
			{
				Open();
			}


			break;

			case 3:
			{
				Save();
			}

			break;

			case 4:
			{
				Save_as();
			}
			break;
			case 5:
			{
				Print();

			}

			break;

			case 6:
			{
				Close();
			}


			break;
			}

			cout << "  " << endl;
			cout << " Another action? 1 - yes, 0 - no" << endl;
			cout << endl;
			cin >> key_1;
		} while (key_1);
		cout << endl;
    }
};

class Picture : public Editor
{
public:
	void Create()
	{
		cout << "Picture created" << endl;
	}
	void Open()
	{
		cout << "Picture opened" << endl;
	}
	void Save()
	{
		cout << "Picture saved" << endl;
	}
	void Save_as ()
	{   bool b = 0;
		string str;
		cout << "Save as JPG or PNG?" << endl;
		cin >> str;
		transform(str.begin(), str.end(), str.begin(), toupper);
		do 
		{
			
			system("cls");
			try
			{
				if (str != "JPG" || str != "PNG")
				{
					throw exception("Incorrect data");
					b = 1;
				}
			}

			catch (exception& str)
			{
				cout << str.what() << endl;
			}
		} while (b = 1);
		cout << "Document saved as "<<str << endl;

	}
	void Correct()
	{
		bool key_1;
		do
		{
			system("cls");

			cout << "Choose the instruments to correct image: 1 - brush, 2 - cut, 3 - change color " << endl;
			short key;
			cout << endl;
			cin >> key;
			cout << endl;

			switch (key)
			{
			case 1:
			{
				cout << "You used brush" << endl;
			}
			break;
			case 2:
			{
				cout << "Picture is cut" << endl;
			}
			break;
			case 3:
			{
				cout << "Color changed " << endl;
			}
			break;
			}
			cout << "Use one more instrument? 1 - yes, 0 - no" << endl;
			cin >> key_1;
		} while (key_1);
	}
	void Print()
	{
		cout << "Picture printed" << endl;
	}
	void Close()
	{
		cout << "Picture closed" << endl;
	}
	void options()
	{
		bool key_1;
		do
		{
			system("cls");

			cout << " Choose what you want to do with the file: 1 - create, 2 - open,\n3 - save, 4 - save as, 5 - correct, 6 - print,\n7 - close" << endl;
			short key;
			cout << endl;
			cin >> key;
			cout << endl;

			switch (key)
			{
			case 1:
			{

				Create();
			}

			break;

			case 2:
			{
				Open();
			}


			break;

			case 3:
			{
				Save();
			}

			break;

			case 4:
			{
				Save_as();
			}
			break;
			case 5:
			{
				Correct();

			}

			break;

			case 6:
			{
				Print();
			}


			break;
			case 7:
			{
				Close();;
			}
			break;
			}

			cout << "  " << endl;
			cout << " Another action? 1 - yes, 0 - no" << endl;
			cout << endl;
			cin >> key_1;
		} while (key_1);
		cout << endl;
	}
};




                                                 
Editor* Editor::Edit_file(Doc_type t)
{
	Editor* p = nullptr;
	switch (t)
	{
	case Text_t:
		p = new Text();
		break;
	case Picture_t:
		p = new Picture();
		break;


	}
	return p;
};


//                                                                    
int main()
{
	vector<Editor*> v;
	v.push_back(Editor::Edit_file(Text_t));
	v.push_back(Editor::Edit_file(Picture_t));
	
	
	bool key_1;

	do
	{
		system("cls");
		
		cout << " Choose file: 1 - text, 2 - picture" << endl;
		short key;
		cout << endl;
		cin >> key;
		cout << endl;

		switch (key)
		{
		case 1:
		{
			v[0]->options();
		}
		break;
		case 2:
		{
			v[1]->options();
		}
		break;
		}
		cout << "  " << endl;
		cout << " Edit another file? 1 - yes, 0 - no" << endl;
		cout << endl;
		cin >> key_1;
	} while (key_1);
	cout << endl;
}
