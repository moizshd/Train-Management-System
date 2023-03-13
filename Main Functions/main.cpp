#include <iostream>
#include <cstring>
#include <string.h>
#include <SFML/Graphics.hpp>
#define ma_x 7
using namespace std;
int bog;
class Person {
	string Name;
	int Age;
	string Gender;
public:
	Person()
	{
		this->Name = '\0';
		this->Age = 0;
		this->Gender = '\0';
	}
	virtual void set()
	{
		cout << "Enter Name Of The Person  = ";
		cin >> Name;
		cout << endl << "Enter Age Of The Person  = ";
		cin >> Age;
		cout << endl << "Enter Gender Of The Person  = ";
		cin >> this->Gender;
	}
	string getname()
	{
		return this->Name;
	}
	string getgender()
	{
		return this->Gender;
	}
	int getage()
	{
		return this->Age;
	}
	virtual void print()
	{
		cout << endl << "Name = " << this->Name << endl;
		cout << "Age = " << this->Age << endl;
		cout << "Gender = " << this->Gender << endl;
	}
};
class Adult :public Person {
	string Occupation;
	string Qualification;
	string NIC;
public:
	Adult()
	{
		this->Occupation = '\0';
		this->Qualification = '\0';
		this->NIC = '\0';
	};
	void set()
	{
		Person::set();
		cout << endl << "Enter Occupation Of The Adult  = ";
		cin >> Occupation;
		cout << endl << "Enter Qualification Of The Adult  = ";
		cin >> Qualification;
		cout << endl << "Enter NIC Of The Adult  = ";
		cin >> NIC;
	}
	string getOccupation()
	{
		return this->Occupation;
	}
	string getQualification()
	{
		return this->Qualification;
	}
	string getNIC()
	{
		return this->NIC;
	}
	void print()
	{
		Person::print();
		cout << "Occupation = " << Occupation << endl;
		cout << "Qualification = " << Qualification << endl;
		cout << "NIC = " << NIC << endl;
	}
};
class kid :public Person {
	string B_form_number;
public:
	kid()
	{
		B_form_number = '\0';
	}
	void set()
	{
		Person::set();
		cout << endl << "Enter B form Number Of The Kid  = ";
		cin >> B_form_number;
	}
	string getBform()
	{
		return this->B_form_number;
	}
	void print()
	{
		Person::print();
		cout << "B-Form Number = " << B_form_number << endl;
	}
};
class Bogie {
	int Bogie_ID;
	Bogie** next;
	Person** Adults;
	Person** kids;
	string familyName;
	int y, z;
public:
	Bogie()
	{
		Bogie_ID = 0;
		next = NULL;
		Adults = NULL;
		kids = NULL;
		familyName = '\0';
	}
	void Add()
	{
		cout << "Write Bogie ID  ";
		cin >> this->Bogie_ID;
	}
	void bogienext(Bogie** bogies)
	{
		next = new Bogie * [bog];
		for (int i = 0; i < bog; i++)
		{
			next[i] = new Bogie;
			next[i] = bogies[i];
		}
	}
	void AddPassengers()
	{
		
		int x;
		cout << "How Many Passengers You Want to Add  ? ";
		cin >> x;
		if (x > 10)
		{
			cout << endl << "Maximum 10 persons can be accomodated ";
		}
		if (x <= 10)
		{
			cout << endl << "Enter Number Of Adults ";
			cin >> y;
			if (y > 4)
			{
				cout << endl << "Maximum 4 Adults Should Be Present ";
			}
			if (y <= 4)
			{
				Adults = new Person * [y];
				for (int k = 0; k < y; k++)
				{
					Adults[k] = new Adult;
					Adults[k]->set();
				}
			}
			cout << endl << "Enter Number Of Kids ";
			cin >> z;
			if (z > 6)
			{
				cout << endl << "Maximum 6 kids Should Be Present ";
			}
			if (z <= 6)
			{
				kids = new Person * [z];
				for (int k = 0; k < z; k++)
				{
					kids[k] = new kid;
					kids[k]->set();
				}
			}
		}

	}
	void Print()
	{
		cout <<endl <<"BOGIE ID = " << Bogie_ID << endl;
		for (int k = 0; k < y; k++)
		{
			Adults[k]->print();
		}
		for (int k = 0; k < z; k++)
		{
			kids[k]->print();
		}
	}
	int getid()
	{
		return Bogie_ID;
	}
};
class train {
	Bogie** engine;
	Bogie** bogies;
	int i;
public:
	train() {
		engine = nullptr;
		i = 0;
	}
	void initialadd()
	{
		cout << "You Have To Add Bogies First  " << endl << endl;
		cout << "How Many Bogies You Want To Add ";
		cin >> bog;
		int x;
		bogies = new Bogie * [bog];
		for (i; i < bog; i++)
		{
			bogies[i] = new Bogie;
			bogies[i]->Add();
			cout << "Would You Like to Add Passengers in This Bogie? " << endl;
			cout << "Press 1 if You want to and Press 0 If you Dont ";
			cin >> x;
			if (x == 1)
			{
				bogies[i]->AddPassengers();
			}
			else cout << "";
		}
		engineattach();
	}
	void engineattach()
	{
		for (int i = 0; i < bog; i++)
		{
			if (bogies[i] != NULL)
			{
				engine = &bogies[i];
				cout << endl << "Engine Is Attached To " << i + 1 << " Bogie" << endl;
				break;
			}
		}

	}
	void addBogie()
	{
		int x;
		bog++;
		bogies[i] = new Bogie;
		bogies[i]->Add();
		cout << "Would You Like to Add Passengers in This Bogie? " << endl;
		cout << "Press 1 if You want to and Press 0 If you Dont ";
		cin >> x;
		if (x == 1)
		{
			bogies[i]->AddPassengers();
		}
		else cout << "";
		i++;
	}
	void removeBogie()
	{
		int x;
		cout << "Write Bogie ID You Want To Remove ";
		cin >> x;
		for (int i = 0; i < bog; i++)
		{
			if (bogies[i] != NULL)
			{
				if (bogies[i]->getid() == x)
				{
					bogies[i] = NULL;
					cout << x << " is Removed From The Train ";
					x = -1;
				}
			}
		}
		for (int i = 0; i < bog; i++)
		{
			if (bogies[i] != NULL)
			{
				break;
			}
			else
			{
				engineattach();
			}
		}
		if (x != -1)
		{
			cout << "This Bogie ID is Not Present In The Train " << endl;
		}
	}
	void printTrain()
	{
		cout << endl<<endl;
		cout << "|Engine|";
		for (int i = 0; i < bog; i++)
		{

			if (bogies[i] != NULL)
				cout <<"--|"<< bogies[i]->getid()<<"|";
		}
	}
	void SearchBogie()
	{
		int x;
		cout << "Enter Bogie ID You Want To Search  ";
		cin >> x;
		for (int i = 0; i < bog; i++)
		{
			if (bogies[i] != NULL)
			{
				if (bogies[i]->getid() == x)
				{
					cout << "This Bogie is Present on " << i + 1 << " number " << endl;
					cout << "Do You Want to Know Information of Passengers in This Bogie,Press 1 else Press 0 ";
					int y;
					cin >> y;
					if (y == 1)
					{
						bogies[i]->Print();
					}
					else cout << endl << "Thankyou" << endl;
					x = -1;
				}
			}
		}
		if (x != -1)
		{
			cout << "This Bogie ID is Not Present In The Train " << endl;
		}
	}
	void printwithpassenger()
	{
		for (int i = 0; i < bog; i++)
		{
			bogies[i]->Print();
		}
	}
};


class Buttons
{
	sf::Text butt_ons[7];
	int selec_t;
	sf::Font fn_t;
public:
	Buttons()
	{
		selec_t = 0;
		fn_t.loadFromFile("heather.TTF");
		int x = 100;
		butt_ons[0].setString("Initial ADD");
		butt_ons[1].setString("Add Boogie");
		butt_ons[2].setString("Remove Boogie");
		butt_ons[3].setString("Search Boogie");
		butt_ons[4].setString("Print Train With Passengers");
		butt_ons[5].setString("Print Train With ID");
		butt_ons[6].setString("Exit");

		for (int i = 0; i < ma_x; i++)
		{
			butt_ons[i].setFont(fn_t);
			butt_ons[i].setFillColor(sf::Color::Red);
			butt_ons[i].setPosition(sf::Vector2f(0, x + 30));
			x = 50 + x;
		}

	}
	int selec_t_ed()
	{
		return selec_t;
	}

	void dr_w(sf::RenderWindow& window)
	{
		int i = 0;
		while (i < ma_x)
		{
			window.draw(butt_ons[i]);
			i++;
		}
	}

	void dow_n()
	{
		if (selec_t + 1 < ma_x)
		{
			butt_ons[selec_t].setFillColor(sf::Color::Red);
			selec_t = selec_t + 1;
			butt_ons[selec_t].setFillColor(sf::Color::White);
		}
	}

	void u_p()
	{
		if (selec_t - 1 >= 0)
		{
			butt_ons[selec_t].setFillColor(sf::Color::Red);
			selec_t = selec_t - 1;
			butt_ons[selec_t].setFillColor(sf::Color::White);
		}
	}



};

int main()
{
	train b;
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	sf::Texture background;
	Buttons bt_n;

	background.loadFromFile("train.jpg");
	sf::Sprite bk_gnd;
	bk_gnd.setTexture(background);
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					bt_n.u_p();
					break;
				case sf::Keyboard::Down:
					bt_n.dow_n();
					break;
				case sf::Keyboard::Return:
					switch (bt_n.selec_t_ed())
					{
					case 0:
						system("CLS");
						b.initialadd();
						break;
					case 1:
						system("CLS");
						b.addBogie();
						break;
					case 2:
						system("CLS");
						b.removeBogie();
						break;
					case 3:
						system("CLS");
						b.SearchBogie();
						break;
					case 4:
						system("CLS");
						b.printwithpassenger();
						break;
					case 5:
						system("CLS");
						b.printTrain();
						break;
					case 6:
						cout << "ThankYou";
						sf::Event::Closed;
						break;
					}break;
				}
				if (event.type == sf::Event::Closed)
					window.close();
				break;
			}
		}
		window.clear(sf::Color::Black);

		window.draw(bk_gnd);
		bt_n.dr_w(window);
		window.display();
	}
	return 0;
}