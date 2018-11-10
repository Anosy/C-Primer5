#include<string>
#include<iostream>
#include<set>

using namespace std;

class Folder;

class Message
{
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	explicit Message(const string &str = "") :contents(str) {} // Ĭ�ϳ�ʼ��
	Message(const Message &); // �������캯��
	Message &operator=(const Message&); // ������ֵ����
	~Message() {} // ��������
	void save(Folder&); // ��Floder������Ӻ�ɾ����Message
	void remove(Folder&);

private:
	string contents; // ʵ����Ϣ
	set<Folder*> folders; // ������Message��Floder
	void add_to_Folders(const Message&); // ����Message��ӵ�ָ���Ĳ�����Folder��
	void remove_from_Folders(); // ��folders�е�ÿ��Folder��ɾ����message
	void addFldr(Folder *f) { folders.insert(f); }
	void remFldr(Folder *f) { folders.erase(f); }
};

class Folder
{
	friend void swap(Message&, Message&);
	friend class Message;
public:
	~Folder();
	Folder(const Folder&);  
	Folder& operator=(const Folder&); 
	Folder(Folder&&);  
	Folder& operator=(Folder&&);  
	void remove_from_Msgs();

private:
	set<Message*> msgs;
	void add_to_Messages(const Folder&);
	void remove_from_Msgs();
	void addMsg(Message *m) { msgs.insert(m); }
	void remMsg(Message *m) { msgs.erase(m); }
};

void Message::save(Folder &f)
{
	folders.insert(&f); // ��������Folders��ӵ����ǵ�Folder�б���
	f.addMsg(this); // ����Message��ӵ�f��Message������
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders) // ����ÿ������m��Floder
		f->addMsg(this); // ���Folder���һ��ָ��Message��ָ��
}
// �������캯������������ɵ�Message��Ҫ��ӵ�Folder��
Message::Message(const Message &m) :
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m); // ������Ϣ��ӵ�ָ��m��Folder��
}

void Message::remove_from_Folders()
{
	for (auto f : folders) // ����ÿ������m��Floder
		f->remMsg(this);   // �Ӹ�Folder��ɾ����Message
}

Message::~Message()
{
	remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
	// ͨ����ɾ��ָ���ٲ��������������Ը�ֵ���
	remove_from_Folders();    // �������е�Folder
	contents = rhs.contents;  // ��rhs������Ϣ����
	folders = rhs.folders;    // ��rhs����Folderָ��
	add_to_Folders(rhs);      // ����Message��ӵ���ЩFolder��
	return *this;
}

void swap(Message &lhs, Message &rhs)
{
	using std::swap;  

	// ��ÿ����Ϣ��ָ�����(ԭ��)���ڵ�Folder��ɾ��
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);

	// ����contents��Folderָ��set
	swap(lhs.folders, rhs.folders);    
	swap(lhs.contents, rhs.contents); 

    // ��ÿ��Message��ָ����ӵ�����(��)Folder��
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

void Folder::add_to_Messages(const Folder &f)
{
	for (auto msg : f.msgs)
		msg->addFldr(this);   // add this Folder to each Message
}

void Folder::remove_from_Msgs()
{
	while (!msgs.empty())
		(*msgs.begin())->remove(*this);
}

Folder::Folder(const Folder &f) :msgs(f.msgs)
{
	add_to_Messages(f);
}

Folder::~Folder()
{
	remove_from_Msgs();
}

Folder& Folder::operator=(const Folder &f)
{
	remove_from_Msgs();
	msgs = f.msgs;
	add_to_Messages(f);
	return *this;
}