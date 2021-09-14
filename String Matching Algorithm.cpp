#include <iostream>
#include <fstream>
using namespace std;

int main(){
	
	string ptn, txt;
	int i=0, j=0, p=0, f= 0;
	ifstream infile1, infile2;
	
	//Get Pattern.txt File
	cout << "Enter the Pattern file name : ";
	cin >> ptn;
	string out = ptn;
	
	string FilePath1 = "pattern/" + ptn + ".txt";
	
	infile1.open(FilePath1.c_str());
	if(!infile1)
	{
		cout << "cannot open the file \n";
	}
	else
	{
		infile1 >> ptn;
		infile1.close();
		
		//Get Test.txt File
		cout << "Enter the Text file name : ";
		cin >> txt;
		
		string FilePath2 = "text/" + txt + ".txt";
		
		infile2.open(FilePath2.c_str());
		if(!infile2)
		{
			cout << "cannot open the file \n";
		}
		else
		{
			infile2 >> txt;
			infile2.close();
			p = 1;
		}
	}
	
	if(p==1)
	{
		//get length
		int n = ptn.length();		
		int m = txt.length();
		
		//create output file
		string name = out + "match.output";
		string FilePath = "output/" + name + ".txt";
		
		ofstream outfile(FilePath.c_str());	
		
		//write & display pattern and text
		outfile << "Pattern : " << ptn << "\n";
		outfile << "Text : " << txt << "\n\n";
		
		cout << "\nPattern : " << ptn << "\n";
		cout << "Text : " << txt << "\n\n";
		
		//Go thorough Text
		for(i=0; i<(m-n+1); i++)
		{
			//Match Pattern with Text
			while(j<n && (txt[i+j] == ptn[j] || ptn[j] == '_'))
			{
				j++;
				if(j == n)
				{
					f = 1;
					outfile << "Possition "<< i+1 << "\n";
					cout << "Possition "<< i+1 << "\n";
				}
			}
			j = 0;
		
		}
	
		if(f==0)
		{
			outfile << "There is no matching";
			cout << "There is no matching";
			outfile.close();
		}
		cout << "\nResult is also in the " << name << " file\n";
	}
		
	
	
	return 0;
}

