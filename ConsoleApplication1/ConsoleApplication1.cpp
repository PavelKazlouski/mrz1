#include <iostream>
#include <vector>

using namespace std;

vector<int> Cym(vector<int> x1, vector<int> y1) {
	vector<int> t;
	vector<int> x;
	int a;
	for (int i = 0; i < x1.size(); i++) {
		a = x1[i];
		x.push_back(a);
	}
	vector<int> y;
	for (int i = 0; i < y1.size(); i++) {
		a = y1[i];
		y.push_back(a);
	}
	int sizen, v;
	if (x.size() <= y.size()) {
		sizen = y.size();
		while (x.size() < y.size()) {
			x.push_back(0);
		}
	}
	else {
		sizen = x.size();
		while (x.size() > y.size()) {
			y.push_back(0);
		}
	}
	for (int i = 0; i < sizen; i++) {
		t.push_back(0);
	}
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	for (int i = 0; i < sizen; i++) {
		v = x[i] + y[i];
		if (v == 2) {
			t[i + 1] = t[i + 1] + 1;
			v = 0;
		}
		v = t[i] + v;
		if (v == 2) {
			t[i + 1] = t[i + 1] + 1;
			v = 0;
		}
		t[i] = v;
	}
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	reverse(t.begin(), t.end());
	return t;
}

vector<int> Des_v_Dv(int a) {
	vector<int> t;
	while (a != 0) {
		if (a % 2 == 0) {
			t.push_back(0);
			a = a / 2;
		}
		else {
			t.push_back(1);
			a = (a - 1) / 2;
		}
	}
	while (t.size() < 8) {
		t.push_back(0);
	}
	reverse(t.begin(), t.end());
	return t;
}

int Dv_v_Des(vector<int> x) {
	int a = 0;
	for (int s = 0; s < x.size(); s++) {
		a = a * 2;
		if (x[s] == 1) {
			a = a + 1;
		}
	}
	return a;
}

class Oper {
public: vector<int> sl1;
public: vector<int> sl2;
public: vector<int> chs;
public: vector<int> rez;
public: int no;
	  int number = 0;
	  bool sumyes;
public: bool end = false;

public: void sozrez() {
	for (int i = 0; i < 16; i++) {
		rez.push_back(0);
	}
}

public: void Konveer() {
	if (number < sl2.size()) {
		if ( no == 0) {
				cout << "opred mnozetela ";
				chast();
				no = 1;
		}
		else {
		if ( no == 1) {
			cout << "sdvig mnozetela ";
			sdvig();
			no = 2;
		}
		else {
		if ( no == 2) {
			cout << "pribavlenie k rezultatu ";
			summ();
			no = 0;
		}
		}
		}
	}
	else {
		end = true;
	}
	if (no < 0) {
		no++;
	}
}

	  void sdvig() {
		  vector<int> chast;
		  if (sumyes == true) {
			  for (int i = 0; i < number + 1; i++) {
				  chast.push_back(0);
			  }
			  for (int i = 0; i < sl1.size(); i++) {
				  chast.push_back(sl1[i]);
			  }
			  chs = chast;
			  for (int i = 0; i < chs.size(); i++) {
				  if (i == 4 || i == 8 || i == 12) {
					  cout << ".";
				  }
				  cout << chs[i];
			  }
		  }
		  else {
			  for (int i = 0; i < sl1.size(); i++) {
				  chast.push_back(0);
			  }
			  chs = chast;
			  for (int i = 0; i < chs.size(); i++) {
				  if (i == 4 || i == 8 || i == 12) {
					  cout << ".";
				  }
				  cout << chs[i];
			  }
		  }
	  }

	  void summ() {
		  rez = Cym(rez, chs);
		  for (int i = 0; i < rez.size(); i++) {
			  if (i == 4 || i == 8 || i == 12) {
				  cout << ".";
			  }
			  cout << rez[i];
		  }
		  number++;
	  }

	  void chast() {
		  if (sl2[number] == 1) {
			  for (int i = 0; i < sl2.size(); i++) {
				  if (i == 4 || i == 8 || i == 12) {
					  cout << ".";
				  }
				  cout << sl1[i];
			  }
			  sumyes = true;
		  }
		  else {
			  for (int i = 0; i < sl2.size(); i++) {
				  if (i == 4 || i == 8 || i == 12) {
					  cout << ".";
				  }
				  cout << "0";
			  }
		  }
	  }

	  void vivod1() {
		  for (int i = 0; i < sl1.size(); i++) {
			  if (i == 4) {
				  cout << ".";
			  }
			  cout << sl1[i];
		  }
	  }

	  void vivod2() {
		  for (int i = 0; i < sl2.size(); i++) {
			  if (i == 4) {
				  cout << ".";
			  }
			  cout << sl2[i];
		  }
	  }

	  void vivodrez() {
		  for (int i = 0; i < rez.size(); i++) {
			  if (i == 4 || i == 8 || i == 12) {
				  cout << ".";
			  }
			  cout << rez[i];
		  }
	  }
};

int main()
{
	int slag1[3];
	int slag2[3];
	Oper konv[3];
	int step = 0;
	bool cycle = true;
	int cycler = 0;
	for (int i = 0; i < 3; i++) {
		cout << " par " << i << " :";
		slag1[i] = rand() % 255;
		cout << slag1[i] << " ";
		slag2[i] = rand() % 255;
		cout << slag2[i] << " ";
		konv[i].sl1 = Des_v_Dv(slag1[i]);
		cout << endl;
		konv[i].vivod1();
		cout << " ";
		konv[i].sl2 = Des_v_Dv(slag2[i]);
		konv[i].vivod2();
		konv[i].sozrez();
		konv[i].no = i - 2;
		cout << endl;
	}
	while (cycle) {
		step++;
		cout << step << ": ";
		for (int i = 0; i < 3; i++) {
			cout << " par " << i + 1 << ": ";
			konv[i].Konveer();
			if (konv[i].end == true) {
				cycler++;
			}
		}
		if (cycler == 3) {
			cycle = false;
		}
		cycler = 0;
		cout << endl;
		cout << endl;
	}
	for (int i = 0; i < 3; i++) {
		cout << " rez" << i << ": ";
		konv[i].vivodrez();
		cout << endl;
	}
}