#include <iostream>
#include "SoNguyenLon.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	SoNguyenLon snl1;
	SoNguyenLon snl2(400);
	SoNguyenLon snl3(5, 2);
	SoNguyenLon snl4(7, 30);
	SoNguyenLon snl5 = snl3 - snl2;
	SoNguyenLon snl6 = 1098765432 - snl2;
	SoNguyenLon snl7 = snl4 - snl3 + 123456789;
	SoNguyenLon snl8 = snl2 * snl3;
	cout << snl1 << endl << snl2 << endl << snl3 << endl;
	cout << snl4 << endl << snl5 << endl << snl6 << endl;
	cout << snl7 << endl << snl8 << endl << endl;
  return 0;
}