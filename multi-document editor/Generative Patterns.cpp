#include <iostream>
#include <vector>
using namespace std;

class Editor
{
public:
	virtual void action() = 0;
	virtual ~Editor() {}
};

class Creation : public Editor
{
public:
	void action() { cout << "Creation" << endl; };
};

class Open : public Editor
{
public:
	void action() { cout << "Open" << endl; };
};

class Save : public Editor
{
public:
	void action() { cout << "Save" << endl; };
};

class Save_ass : public Editor
{
public:
	void action() { cout << "Save_ass" << endl; };
};

class Print : public Editor
{
public:
	void action() { cout << "Print" << endl; };
};

class Close : public Editor
{
public:
	void action() { cout << "Close" << endl; };
};


class Factory
{
public:
	virtual Editor* createEditor() = 0;
	virtual ~Factory() {}
};

class CreationFactory : public Factory
{
public:
	Editor* createEditor() { return new Creation; }
};

class OpenFactory : public Factory
{
public:
	Editor* createEditor() { return new Open; }
};

class SaveFactory : public Factory
{
public:
	Editor* createEditor() { return new Save; }
};

class Save_assFactory : public Factory
{
public:
	Editor* createEditor() { return new Save_ass; }
};

class PrintFactory : public Factory
{
public:
	Editor* createEditor() { return new Print; }
};

class CloseFactory : public Factory
{
public:
	Editor* createEditor() { return new Close; }
};


class Text_doc
{
public:
	void Print(Editor& edit) { edit.action(); };
};

class Grafic_doc : public Save
{
public:
	
	void Save::Editor::action() { cout << "NOt save" << endl; };
	void Print(Editor& edit) { edit.action(); };
};



int main()
{
	OpenFactory* open_factory = new OpenFactory;
	CreationFactory* creation_factory = new CreationFactory;
	SaveFactory* save_factory = new SaveFactory;
	Save_assFactory* save_ass_factory = new Save_assFactory;
	PrintFactory* print_factory = new PrintFactory;
	CloseFactory* close_factory = new CloseFactory;

	Text_doc x;
	x.Print(*creation_factory->createEditor());
	x.Print(*open_factory->createEditor());
	x.Print(*save_factory->createEditor());
	x.Print(*save_ass_factory->createEditor());
	x.Print(*print_factory->createEditor());
	x.Print(*close_factory->createEditor());

	Grafic_doc graff;
	graff.Print(*save_factory->createEditor());

}

