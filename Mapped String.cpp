

#include<bits/stdc++.h>
using namespace std;

void mappedString( char * in , char *out , int i , int j){
	if(in[i]== '\0'){
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}
	if(in[i]!='0'){
		int value = int(in[i]-'0');
		char c = 'A' + value - 1;
		out[j] = c;
		mappedString(in , out , i+1 , j+1);
	}
	

	if(i+1!='\0'){ //changed
		int value = (int(in[i]-'0'))*10 + (int(in[i+1]-'0')); //i and i+1
        char c;
		if(value<=25&&value>=10){//updated this
		c = 'A' + value -1;
		}else{
			return;
		}
		out[j] = c;//updated
		mappedString(in , out , i+2 , j+1); //updated i+2,j+1
        return;
	}
}

int main(){
	char in[7];
	cin>>in;
	char out[10];
	mappedString(in , out , 0 , 0);

	return 0;

}
