/** A class hierarchy for representing items of a library. **/
#include <iostream>
#include <string>

using namespace std;

class work {
public:
	work() = default;
	work(work const&) = default;
	work(string const& id, string const& title) : id_{id}, title_{title} {}
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
	book() : work{}, author_{}, pubyear_{0} {}
	book(string const& id, string const& title, string const& author, int pubyear)
	: work{id, title}, author_{author}, pubyear_{pubyear} {}
	string const& author() const { return author_; }
	int pubyear()		   const { return pubyear_; }
	void print(ostream& out) const override {
		out << author() << ", " << title() << ", " << pubyear() << ".";
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


void showoff (work const& w) {
	w.print (std::cout) ;
	std::cout << "\n" ;
}



int main() {
	book sc {"1", "The Sun Also Crashes" , "Ernest Lemmingway" , 2000} ;
	book ecpp {"2" , "Exploding C++" , "Ray Lischner", 2013} ;
	periodical pop {"3" , "Popular C++", 13, 42, "January 1, 2000"} ;
	periodical today {"4", "C++ Today" , 1 , 1 , "January 13, 1984"} ;
	/*showoff(sc) ;
	showoff(ecpp) ;
	showoff(pop) ;
	showoff(today) ;
*/

}