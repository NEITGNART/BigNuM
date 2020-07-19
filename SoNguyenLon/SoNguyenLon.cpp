#include "SoNguyenLon.h"

// Implementation SoNguyenLon::

void SoNguyenLon::Init() {
	head = tail = nullptr;
}

SoNguyenLon::SoNguyenLon(string str) {
	Init();
	head = tail = CreateNode(str);
}

SoNguyenLon::SoNguyenLon() {
	Init();
	head = tail = CreateNode("0");
}

SoNguyenLon::SoNguyenLon(ll x) {
	Init();
	head = tail = CreateNode(to_string(x));
}
SoNguyenLon::SoNguyenLon(ll x, ll y) {
	
	Init();
	string tmp;
	for (int i = 0; i < y; ++i)
		tmp += to_string(x); 
	head = tail = CreateNode(tmp);
}
node* SoNguyenLon::CreateNode(const string& n) {
	node* p = new node();
	if (p == nullptr) {
		return nullptr;
	}
	else {
		p->next = nullptr;
		p->data = n;
	}
	return p;
}

ostream& operator<<(ostream& os, const SoNguyenLon& x) {
	if (x.head == nullptr) return os;
	node* p = x.head;
	while (p) {
		os << p->data;
		p = p->next;
	}
	return os;
}
//ll& SoNguyenLon::operator[](const int& i) {
//
//	
//}

//
bool operator>=(SoNguyenLon x, SoNguyenLon y) {
	if (x == y) return true;
	string str1 = x.head->data;
	string str2 = y.head->data;
	ll size1 = str1.size();
	ll size2 = str2.size();
	if (size1 < size2) return false;
	if (size1 > size2) return true;
	for (int i = 0; i < size1; ++i) {
		if (str1[i] < str2[i]) return false;
	}
	return true;
}
bool operator==(SoNguyenLon x, SoNguyenLon y) {
	string str1 = x.head->data;
	string str2 = y.head->data;
	ll size1 = str1.size();
	ll size2 = str2.size();
	if (size1 < size2 || size2 < size1) return false;
	for (int i = 0; i < size1; ++i) {
		if (str1[i] != str2[i]) return false;
	}
	return true;
}


SoNguyenLon operator-(SoNguyenLon x, SoNguyenLon y) {
	
	string str1 = x.head->data;
	string str2 = y.head->data;
	
	// reverse the string str1 and str2 and get the length both of them
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	ll size1 = str1.size();
	ll size2 = str2.size();
	bool flag = false;
	if (y >= x) {
		flag = true;
		swap(str1, str2);
	}
	int sum, carry = 0, i = 0, j = 0; string result;


	while (i < size1 && j < size2) {
		sum = (str1[i] - 48) -  ( (str2[j] - 48) + carry ) ;
		if (sum < 0) {
			sum = (str1[i] - 48) + 10 - ( (str2[j] - 48) + carry) ;
			carry = 1;
		}
		else carry = 0;
		i++, j++;
		result += to_string(sum);
	}
	while (i < size1) {
		sum = (str1[i]- 48) - carry;
		if (sum < 0) {
			sum = (str1[i] - 48) + 10 - carry;
			carry = 1;
		}
		else carry = 0;
		i++;
		result += to_string(sum);
	}
	/*if (carry == 1) result += to_string(carry);*/
	if (flag) result += "-";
	reverse(result.begin(), result.end());
	SoNguyenLon res(result);
	return res;
}

string operator+(string str1, string str2) {
	ll size1 = str1.size();
	ll size2 = str2.size();
	int sum, carry = 0, i = 0, j = 0; string result;

	// Algo look like same Heap's algorithm and easy to emplement
	while (i < size1 && j < size2) {
		sum = (str1[i] - 48) + (str2[j] - 48) + carry;
		if (sum > 9) {
			carry = 1;
			sum %= 10;
		}
		else carry = 0;
		result += to_string(sum);
		i++; j++;
	}

	while (i < size1) {
		sum = (str1[i] - 48) + carry;
		if (sum > 9) {
			carry = 1;
			sum %= 10;
		}
		else carry = 0;
		result += to_string(sum);
		i++;
	}
	while (j < size2) {
		sum = (str2[i] - 48) + carry;
		if (sum > 9) {
			carry = 1;
			sum %= 10;
		}
		else carry = 0;
		result += to_string(sum);
		j++;
	}

	if (carry == 1) result += to_string(carry);
	reverse(result.begin(), result.end());
	return result;
}

SoNguyenLon operator+(SoNguyenLon x, SoNguyenLon y){
	// Time complexity is max(0(x.x.head->data, y.head->data)) but I think it has more constant factor
	string str1 = x.head->data;
	string str2 = y.head->data;

	// reverse the string str1 and str2 and get the length both of them
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	string result = str1 + str2;
	SoNguyenLon res(result);
	return res;
	
}

SoNguyenLon operator-(ll x, SoNguyenLon y) {
	SoNguyenLon tmp(x);
	return tmp - y;
}
SoNguyenLon operator-(SoNguyenLon x, ll y) {
	SoNguyenLon tmp(x);
	return tmp - y;
}
SoNguyenLon operator+(ll x, SoNguyenLon y) {
	SoNguyenLon tmp(x);
	return tmp + y;
}
SoNguyenLon operator+(SoNguyenLon x, ll y) {
	SoNguyenLon tmp(y);
	return x + tmp;
}
SoNguyenLon operator*(SoNguyenLon x, SoNguyenLon y) {
	string str1 = x.head->data;
	string str2 = y.head->data;

	// reverse the string str1 and str2 and get the length both of them
	ll size1 = str1.size();
	ll size2 = str2.size();
	SoNguyenLon res("0");
	SoNguyenLon ans("0");
	int i = 0;
	while (i < size2) {
		
		int length = size1;

		for (int j = 0; j < (str2[i]-48); ++j)
			res = res + x;
		
		string tmp1 = res.head->data;
		string tmp;
		for (int j = 0; j < i; ++j) {
			tmp += '0';
		}

		SoNguyenLon z(tmp1 + tmp);
		ans = ans + z;
		++i;
	}

	return ans;
}