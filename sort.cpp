#include <iostream>
#include <cstdlib>//for "exit()" on some systems
#include <vector>
#include <string>

using namespace std;

/**
\fn linearSearch
\brief Search data for the first occurrence of key
\param [in] key The value being searched for
\param [in] data The data set that will be searched
\returns location of key if found or -1 if not found
*/
int linearSearch(auto data, auto key);//prototype
void selectionSort(auto& Data);
void displayData(auto& info);


int main()
{
  vector<string> inputs;
  string search_key, input;
  int result;

   cout<<"Welcome to \"search it\". We first need some input data."<<endl;
   cout<<"We'll assume the inputs do not have any spaces."<<endl<<endl;
   cout<<"To end input type the #-character (followed by Enter)"<<endl<<endl;

   cin>>input;
 
    while(input != "#")//read an unknown number of inputs from keyboard
    {
       inputs.push_back(input);
       cin>>input;
    }

   cout<<endl<<"["<<inputs.size()<<" values read from input source]"<<endl<<endl;

  if(inputs.size() == 0)//no input
  {
      cout<<endl<<"No input received, quiting..."<<endl<<endl;
       exit(1);//nothing to do but quit program
  }
 
   cout<<endl<<"To end input type the #-character (followed by Enter)"<<endl<<endl;
  cout<<"Enter a value to search for: ";


   cin>>search_key;
 
    while(search_key != "#")//perform searches until sentinel entered
    {
        result = linearSearch(inputs,search_key);

        cout<<"  '"<<search_key<<"' was ";

        if (result == -1)
          cout<<"not found";
        else
          cout<<"found at index "<<result;


        cout<<endl<<endl<<"Enter a value to search for: ";
        cin>>search_key; 
    }

   cout<<endl<<"Program \"search it\" is now finished."<<endl<<endl;


	selectionSort(inputs);
	displayData(inputs);
    return 0;
}
int linearSearch(auto data, auto key)
{
	for (int i=0; 1 < data.size(); i++)
	{
		if(data[i] == key){
			return i;
		}
	}
}
void selectionSort(auto& Data)
{
	int passes = 0;
	for (size_t i = 0; i < Data.size(); i++)
	{		
		int min = i;
		
	for (size_t j = i + 1; j < Data.size(); j++)
	{
		if (Data[j] < Data[min]){
			min = j;
		}
	}
	swap(Data[i], Data[min]);
	passes++;
	
	if( passes % 20000 == 0 )
	{
		cout << passes << endl;
	}
}
}

void displayData(auto& info)
{
	for (size_t i = 0; i < info.size(); i++)
	{
		std::cout << info[i] << " ";
	}
}
