#include <iostream>
#include <vector>
using namespace std;

enum Doc_type { Text_doc_id = 0, Grafic_doc_id };
class Editor
{
public:
	void  Creation() { cout << "Creation" << endl; };
	void Open() { cout << "Open" << endl; };
	void Save() { cout << "Save" << endl; };
	void Save_ass() { cout << "Save_ass" << endl; };
	void Print() { cout << "Print" << endl; };
	void Close() { cout << "Close" << endl; };
	static Editor* create_doc(Doc_type id);
};

class Text_doc :public Editor
{

};

class Grafic_doc :public Editor
{

};

class Doc : public Editor
{
public:
	void create(Editor* edit)
	{
		vector<Editor*> v;
		v.push_back(Editor::create_doc(Text_doc_id));

		for (int i = 0; i < v.size(); i++)
		{
			v[i]->Creation();
			v[i]->Open();
			v[i]->Save();
			v[i]->Save_ass();
			v[i]->Print();
			v[i]->Close();
		}

	}

};

Editor* Editor::create_doc(Doc_type id)
{
	Editor* doc = nullptr;
	switch (id)
	{
	case Text_doc_id:
	{
		cout << "For text doc" << endl;
		doc = new Editor();
	}
	break;
	case Grafic_doc_id:
	{
		cout << "For grafic doc" << endl;
		doc = new Editor();
	}
	break;
	}
	return doc;
}

int main()
{
	Doc d;
	Text_doc a;
	d.create(&a);
	
}


