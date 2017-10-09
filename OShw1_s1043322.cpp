#include<iostream>
#include<stdlib.h>
#include<string>
#include<unistd.h>
#include<sstream>

using namespace std;

int main()
{
	char* username;
	char cdcd[100];
	while(true)
	{
		if(username = getenv("USER"))
		{
			cout << username<<"@";
		}
		getcwd(cdcd,sizeof(cdcd));
		cout << cdcd<<">";
		//string 4ls("ls");
		//char 4spa(" ");
		string Input;
		getline(cin, Input);
		if(Input == "exit"){
			cout<< "ByeBye!"<<endl;
			break;
		}
		string ptr;
		int findcd = Input.find("cd ", 0);
		if(findcd == 0){
			char *dir;
			dir = new char [(Input.size()-3)];
			for(int i = 0; i<Input.size()-3; i++){ dir[i] = Input[i+3];}
	 		int cddir = chdir(dir);
			getcwd(cdcd,sizeof(cdcd));
			//cout<<cdcd<<"\n";
			delete [] dir;
		}
		else if(findcd != 0){
			int a = Input.find(' ',0);
			//cout<<Input.size()<<" "<<a<<endl;
			ptr = ptr.assign(Input, 0, a);
			cout<<"[CMD] "<<ptr<<" ";
			if(a == -1){ cout<<endl;}
			if(a != Input.size() && a != -1)
			{
				string tmp;
				tmp = tmp.assign(Input, a+1, Input.size());
				stringstream ss(tmp);
 				int n = 0;
				while(getline(ss, ptr, ' ')){
					if(n == 0){ cout<<"[ARGV] "<<ptr;}
					else { cout<<", "<<ptr;}
					n++;
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
