#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

int main()
{
	unordered_map <string,int> m;

	//Insert
	m["Mango"] = 100;

	m.insert(make_pair("Apple",120));

	//Search
	if(m.count("Apple")) //return 0 if not and 1 if present
	{
		cout<<" Price of Apple " <<m["Apple"]<<endl;
	}

	//Iterators to search
	for(auto f = m.begin();f != m.end();f++)
	{
		cout<<f->first<<" : "<<f->second<<endl;
	}

	auto f = m.find("Mango");
	if(f != m.end()) cout<<f->first<<" : "<<f->second<<endl;
	else cout<<"NOt found"<<endl;

	f = m.find("Guava");
	if(f != m.end()) cout<<f->first<<" : "<<f->second<<endl;
	else cout<<"NOt found"<<endl;

	//Deletion  = erase function
	m.erase("Mango");
	// OR
	auto it = m.find("Mango");
	m.erase(it); // erase can be provided with the element or the iterator pointing that element




	return 0;
}