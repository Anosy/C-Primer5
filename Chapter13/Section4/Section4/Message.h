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
	explicit Message(const string &str = "") :contents(str) {} // 默认初始化
	Message(const Message &); // 拷贝构造函数
	Message &operator=(const Message&); // 拷贝赋值函数
	~Message() {} // 析构函数
	void save(Folder&); // 向Floder集合添加和删除本Message
	void remove(Folder&);

private:
	string contents; // 实际消息
	set<Folder*> folders; // 包含本Message的Floder
	void add_to_Folders(const Message&); // 将本Message添加到指定的参数的Folder中
	void remove_from_Folders(); // 从folders中的每个Folder中删除本message
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
	folders.insert(&f); // 将给定的Folders添加到我们的Folder列表中
	f.addMsg(this); // 将本Message添加到f的Message集合中
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders) // 对于每个包含m的Floder
		f->addMsg(this); // 向该Folder添加一个指向本Message的指针
}
// 拷贝构造函数，因此新生成的Message需要添加到Folder中
Message::Message(const Message &m) :
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m); // 将本消息添加到指向m的Folder中
}

void Message::remove_from_Folders()
{
	for (auto f : folders) // 对于每个包含m的Floder
		f->remMsg(this);   // 从该Folder中删除本Message
}

Message::~Message()
{
	remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
	// 通过先删除指针再插入它们来处理自赋值情况
	remove_from_Folders();    // 更新已有的Folder
	contents = rhs.contents;  // 从rhs拷贝消息内容
	folders = rhs.folders;    // 从rhs拷贝Folder指针
	add_to_Folders(rhs);      // 将本Message添加到那些Folder中
	return *this;
}

void swap(Message &lhs, Message &rhs)
{
	using std::swap;  

	// 将每个消息的指针从他(原来)所在的Folder中删除
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);

	// 交换contents和Folder指针set
	swap(lhs.folders, rhs.folders);    
	swap(lhs.contents, rhs.contents); 

    // 将每个Message的指针添加到它的(新)Folder中
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