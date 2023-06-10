#include <iostream>

class customer{
	int credit;
	int cash;
	int income;
	bool goodhistory;
	bool work;
	int debt;
	int propertyPrice; //for vital cases XD
	int border = credit / 10;

	void set_datas(int cr, int c, int i, bool g, bool w, int d, int p) {
		credit = cr;
		cash = c; //1 point
		income = i; //2 point
		goodhistory = g; //2 point
		work = w; //3 point
		debt = d; //2 point
		propertyPrice = p; //3 point
	}

	int check() {
		int pluses = 13; //all points together
		if (cash < border/2)
		{
			pluses -= 1;
		}
		if (income < border)
		{
			pluses -= 2;
		}
		if (!goodhistory)
		{
			pluses -= 2;
		}
		if (!work)
		{
			pluses -= 3;
		}
		if (debt > border * 2)
		{
			pluses -= 2;
		}
		if (propertyPrice < credit/2)
		{
			pluses -= 3;
		}
		return pluses;
	}

	void agreement(int plus) {
		if (plus >=  8)
		{
			std::cout << "We are minded to give you a credit(" << credit << "), please fill signature field: ...";
		}
		else
		{
			std::cout << "We will call you later ...";
		}
	}

public:
	customer() {
		std::cout << "Please fill all fields" << std::endl;
	}
	customer(int cr, int c, int i, bool g, bool w, int d, int p) {
		if (cr > 0, c > 0, i > 0, d > 0 , p > 0)
		{
			set_datas(cr, c, i, g, w, d, p);
			agreement(check());
		}
		else
		{
			std::cout << "Please fill all fields properly!" << std::endl;
		}
	}
	customer(const customer &obj ) { //copy constructor
		credit = obj.credit;
		cash = obj.cash; 
		income = obj.income; 
		goodhistory = obj.goodhistory;
		work = obj.work;
		debt = obj.debt;
		propertyPrice = obj.propertyPrice;
	}

};

int main() {
	int credit, cash, income, debt, propertyPrice;
	bool goodhistory, work;
	std::cout << "All values will be counted to Armenian Drams" << std::endl;

	std::cout << "How much credit do you want: ";
	std::cin >> credit;
	std::cout << "How much cash do you have right now: ";
	std::cin >> cash;
	std::cout << "How much income do you get: ";
	std::cin >> income;
	std::cout << "How much debt do you have: ";
	std::cin >> debt;
	std::cout << "How much is your property worth: ";
	std::cin >> propertyPrice;
	std::cout << "Do you have good bank history (enter 0 if 'No' and any other Number if 'Yes'): ";
	std::cin >> goodhistory;
	std::cout << "Do you have work (enter 0 if 'No' and any other Number if 'Yes'): ";
	std::cin >> work;

	customer datas(credit, cash, income, goodhistory, work, debt, propertyPrice);

	customer const obj(datas); //just an example
}