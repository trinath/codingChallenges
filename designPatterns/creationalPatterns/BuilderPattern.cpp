/*
@Author @Source: https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns
Creational Patterns are design patterns that deal with the object creation mechanisms,
trying to create objects in a manner suitable to the situation.

Builder Pattern
It is used to separate the construction of complex object from its representation.
Define an intermediate object whose member functions define the desired object part
by part before the object is available to the client. Builder Pattern lets us defer
the construction of the object until all the options for creation have been specified.
*/

#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Pizza{
private:
	string m_dough;
	string m_sauce;
	string m_topping;
public:
  void setDough(const string &dough){
    m_dough = dough;
  }
  void setSauce(const string &sauce){
    m_sauce = sauce;
  }
  void setTopping(const string &topping){
    m_topping = topping;
  }
  void open() const{
    cout << "Pizza with " << m_dough << " dough, " << m_sauce << " sauce and "
			<< m_topping << " topping. Mmm." << endl;
  }
};

// "Abstract Builder"
class PizzaBuilder
{

protected:
	unique_ptr<Pizza> m_pizza;

public:
	virtual ~PizzaBuilder() {};

	Pizza* getPizza()
	{
		return m_pizza.get();
	}
	void createNewPizzaProduct()
	{
		m_pizza = make_unique<Pizza>();
	}
	virtual void buildDough() = 0;
	virtual void buildSauce() = 0;
	virtual void buildTopping() = 0;
};

class HawaiianPizzaBuilder : public PizzaBuilder
{
public:
	virtual ~HawaiianPizzaBuilder() {};

	virtual void buildDough()
	{
		m_pizza->setDough("cross");
	}
	virtual void buildSauce()
	{
		m_pizza->setSauce("mild");
	}
	virtual void buildTopping()
	{
		m_pizza->setTopping("ham+pineapple");
	}
};

class SpicyPizzaBuilder : public PizzaBuilder
{
public:
	virtual ~SpicyPizzaBuilder() {};

	virtual void buildDough()
	{
		m_pizza->setDough("pan baked");
	}
	virtual void buildSauce()
	{
		m_pizza->setSauce("hot");
	}
	virtual void buildTopping()
	{
		m_pizza->setTopping("pepperoni+salami");
	}
};

class Cook{
private:
  PizzaBuilder *m_pizzaBuilder;
public:
  void openPizza(){
    m_pizzaBuilder->getPizza()->open();
  }
  void makePizza(PizzaBuilder *pb){
    m_pizzaBuilder = pb;
    m_pizzaBuilder->createNewPizzaProduct();
    m_pizzaBuilder->buildDough();
    m_pizzaBuilder->buildSauce();
    m_pizzaBuilder->buildTopping();
  }
};

int main(){
	Cook cook;
	HawaiianPizzaBuilder hawaiianPizzaBuilder;
	SpicyPizzaBuilder    spicyPizzaBuilder;

	cook.makePizza(&hawaiianPizzaBuilder);
	cook.openPizza();

	cook.makePizza(&spicyPizzaBuilder);
	cook.openPizza();
  return 0;
}
