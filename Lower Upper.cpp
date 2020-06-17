#include<iostream>
#include<string>
using namespace std;
int main() {
	char str;
	cin >> str;
	if(str=='A'||str=='B'||str=='C'||str=='D'||str=='E'||str=='F'||str=='G'||str=='H'||str=='I'||str=='J'||
	str=='K'||str=='L'||str=='M'||str=='N'||str=='O'||str=='P'||str=='Q'||str=='R'||str=='S'||str=='T'||
	str=='U'||str=='V'||str=='W'||str=='Y'||str=='X'||str=='Z')
	cout<<"UPPERCASE";
	else if(str=='a'||str=='b'||str=='c'||str=='d'||str=='e'||str=='f'||str=='g'||str=='h'||str=='i'||str=='j'||
	str=='k'||str=='l'||str=='m'||str=='n'||str=='o'||str=='p'||str=='q'||str=='r'||str=='s'||str=='t'||
	str=='u'||str=='v'||str=='w'||str=='x'||str=='y'||str=='z')
	cout<<"lowercase";
	else
	cout<<"Invalid";
	return 0;
}
