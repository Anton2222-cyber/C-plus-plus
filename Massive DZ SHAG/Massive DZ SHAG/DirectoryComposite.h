#pragma once
#include"Data.h"
#include"File.h"
#include <iostream>
#include <vector>
#include<io.h>
using namespace std;

class DirectoryComposite :public Data
{

	vector<Data*>general_catalog;
	
	bool Is_dir(_finddata_t& f)
	{
		return (f.attrib == 16) && strcmp(f.name, "..") && strcmp(f.name, ".");
	}

	bool Is_file(_finddata_t& f)
	{
		return !(f.attrib == 18 || f.attrib == 16);
	}
public:
	DirectoryComposite()
	{
		
	}
	DirectoryComposite(string n)
	{
		name = n;
	}
	int Get_Size()
	{
		return general_catalog.size();
	}
	virtual ~DirectoryComposite()
	{
		for (int i = 0; i < general_catalog.size(); i++)
		{
			delete general_catalog[i];
		}
	}
	
	void Show(int a=0)
	{
		for (int i = 0; i < general_catalog.size(); i++)
		{
			for (int i = 0; i < a; i++)
				cout << "\t";
				cout << general_catalog[i]->GetName() << endl;
				if (general_catalog[i]->GetName().back() == '>')
				{

					general_catalog[i]->Show(a + 1);
				}
			
			
		}
	}
	
	string GetName()
	{
		return name;
	}
	

	void ADDDIR(string general_dir)
	{
		
		string dir_now = general_dir;
		dir_now += "\\*.*";
		_finddata_t file;
		intptr_t Path = _findfirst(dir_now.c_str(), &file);

		string tmp_dir;

		do
		{
			if (Is_dir(file))
			{
				string modify;
				tmp_dir += general_dir;
				tmp_dir += "\\";
				tmp_dir += file.name;

				modify = file.name;
				modify += "-->";
				DirectoryComposite* d = new DirectoryComposite(modify);
				d->ADDDIR(tmp_dir);

				general_catalog.push_back(d);
				
				tmp_dir.clear();
			}
			if (Is_file(file))
			{
				general_catalog.push_back(new File(file.name));
			}
		} while (_findnext(Path, &file) == 0);
	}
	

};