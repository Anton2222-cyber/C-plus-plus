#include <iostream>
#include <list>
using namespace std;
class Landmark;
class Church;
class Monument;

class BaseVisitor
{
public:
	virtual void VisitConcreteChurch(Church* pA) = 0;
	virtual void VisitConcreteMonument(Monument* pB) = 0;
};

class Landmark
{
protected:
	string name;
public:
	string GetName()
	{
		return name;
	}
	virtual void Accept(BaseVisitor* pVisitor) = 0;
};

class Monument :public Landmark
{
protected:
	string material;
	int year;
public:
	Monument()
	{
		name = "TGS";
		material = "bronze";
		year = 1900;
	}
	int GetYear()
	{
		return year;
	}
	string GetMaterial()
	{
		return material;
	}
	void Accept(BaseVisitor* pVisitor) {
		pVisitor->VisitConcreteMonument(this);
	}
};

class Church :public Landmark
{
	int year;
public:
	Church()
	{
		name = "HR";
		year = 1900;
	}
	int GetYear()
	{
		return year;
	}
	void Accept(BaseVisitor* pVisitor) {
		pVisitor->VisitConcreteChurch(this);
	}
};

class ExportNameForLandmarks : public BaseVisitor
{
	virtual void VisitConcreteChurch(Church* pA)
	{
		cout << pA->GetName() << endl;
	}
	virtual void VisitConcreteMonument(Monument* pB)
	{
		cout << pB->GetName() << endl;
	}
};

class ExportWithMaterial : public BaseVisitor
{
	virtual void VisitConcreteChurch(Church* pA)
	{
		cout << pA->GetName() << endl;
	}
	virtual void VisitConcreteMonument(Monument* pB)
	{
		cout << pB->GetName() << endl;
		cout << pB->GetMaterial() << endl;
	}
};

class ExportWithYear : public BaseVisitor
{
	virtual void VisitConcreteChurch(Church* pA)
	{
		cout << pA->GetName() << endl;
		cout << pA->GetYear() << endl;
	}
	virtual void VisitConcreteMonument(Monument* pB)
	{
		cout << pB->GetName() << endl;
		cout << pB->GetMaterial() << endl;
		cout << pB->GetYear() << endl;
	}
};

class LutskLandmarks
{
private:
	list<Landmark*> landmarks;
public:
	LutskLandmarks()
	{

	}
	void Attach(Landmark* pNew)
	{
		landmarks.push_back(pNew);
	}
	void Detach(Landmark* pDelete)
	{
		landmarks.remove(pDelete);
	}
	void Accept(BaseVisitor* pVisitor)
	{
		for (auto it = landmarks.begin(); it != landmarks.end(); it++)
		{
			(*it)->Accept(pVisitor);
		}

		/*if (pVisitor)
			delete pVisitor;*/
	}
};

int main()
{
	LutskLandmarks* ll = new LutskLandmarks();
	ll->Attach(new Monument());
	ll->Attach(new Church());
	ll->Attach(new Monument());
	ll->Attach(new Monument());

	ExportNameForLandmarks* enfl = new ExportNameForLandmarks();

	ll->Accept(enfl);

	ll->Accept(new ExportWithMaterial());

	ll->Accept(new ExportWithYear());

	system("pause");
}