/*
@Author @Source: https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns

The composite pattern lets clients treat objects and compositions equally. 
*/
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Graphic{
  public:
    virtual void print() const = 0;
    virtual ~Graphic() {};
};

class Ellipse : public Graphic{
  public:
    void print() const{
      cout << "Ellipse" << endl;
    }
};

class CompositeGraphic: public Graphic{
  private:
     vector<Graphic*>  graphicList;
  public:
    void print() const{
      for_each(graphicList.begin(), graphicList.end(), [](Graphic *v) { v->print();} );
    }
    void add(Graphic *g){
      graphicList.push_back(g);
    }
};

int main(){
  const auto_ptr<Ellipse> ellipse1(new Ellipse());
  const auto_ptr<Ellipse> ellipse2(new Ellipse());
  const auto_ptr<Ellipse> ellipse3(new Ellipse());
  const auto_ptr<Ellipse> ellipse4(new Ellipse());

  const auto_ptr<CompositeGraphic> graphic(new CompositeGraphic());
  const auto_ptr<CompositeGraphic> graphic1(new CompositeGraphic());
  const auto_ptr<CompositeGraphic> graphic2(new CompositeGraphic());

  graphic1->add(ellipse1.get());
  graphic1->add(ellipse2.get());
  graphic1->add(ellipse3.get());

  graphic2->add(ellipse4.get());
  
  graphic->add(graphic1.get());
  graphic->add(graphic2.get());

  graphic->print();

  return 0;
}