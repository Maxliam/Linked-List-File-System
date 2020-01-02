#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class cnode
{
public:
	int id;
	float gpa;
	string name;
	cnode *pnext;
};
class clist
{
public:
	cnode *phead;
	cnode *ptail;

	clist()
	{
		phead = NULL;
		ptail = NULL;
	}

	~clist()
	{
		cnode *ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead;
		}
	}

	void Attach(cnode *pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
};

void main()
{
	clist L;
	cnode *ptrav;
	int max;
	fstream f;
	f.open("N:\students.txt");
	if(!f)
	{
		cout << "Not opened" << endl;
	}
	else
	{
		string x;
		while(getline(f,x))
		{
			string temp[3]; int it = 0;
			for (int i = 0; i < x.length(); i++)
			{
				if (x[i] == ',')
				{
					it++;
				}
				else
				{
					temp[it]+=x[i];
				}
			}
			cnode *pnn = new cnode;
			pnn->name = temp[0];
			pnn->id = stoi(temp[1]);
			pnn->gpa = stof(temp[2]);
			pnn->pnext = NULL;
			L.Attach(pnn);
		}
	}

	ptrav = L.phead;
	while (ptrav!=NULL)
		{
		cout << ptrav->name << ',';
		cout << ptrav->id << ',';
		cout << ptrav->gpa << ',' << endl;
		ptrav=ptrav->pnext;
		}


	f.close();
	system ("pause");
}
