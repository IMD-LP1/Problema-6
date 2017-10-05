/** A class hierarchy for representing items of a library. **/
#include <iostream>
#include <string>

using namespace std;

class work {
public:
	work() = default;
	work(work const&) = default;
	work(string const& id, string const& title) : id_{id}, title_title{} {}
	virtual ~work() {}
	string const& id() const { return id_; }
	string const& title() const { return title_; }
	virtual void print(ostream&) const {}
private:
	string id_;
	string title_;	
};

class book : public work {
public:
	book() : work, author_{}, pubyear_{0} {}
	book(string const& id, string const& title, string const& author, int pubyear)
	: work{id, title}, author_{author}, pubyear_{pubyear} {}
	string const& author() const { return author_; }
	int pubyear()		   const { return pubyear_; }
	void print(ostream& out) const override {
		out << author() << ", " << title() << ", " pubyear() << ".";
	}
private:
	string author_;
	int pubyear_; ///< year of publication
};

class periodical : public work {
public:
	periodical() : work{}, volume_{0}, number_{0}, date_{} {}
	periodical(string const& id, string const& title, int volume, int number, string const& date)
	: work{id, title}, volume_{volume}, number_{number}, date_{date} {}
	int volume() const { return volume_; }
	int number() const { return number_; }
	string const& date() const { return date_; }
	void print(ostream& out) const override {
		out << title() << ", "
			<< volume() << "(" << number() << ")," << date() << ".";
	}
private:
int volume_;		///< volume number
int number_;		///< issue number
string date_;		///< publication date
};

int main() {}