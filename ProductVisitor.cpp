#include "ProductVisitor.h"
#include "Product.h"

// Accept() method for all products that accept a
// ProductVisitor

void FreshVegetable::accept(ProductVisitor *v)
{ 
  // cout << "FreshVegetable";
  v->visit(this);
};


void CannedItem::accept(ProductVisitor *v)
{ 
  // cout << "CannedItem";
  v->visit(this);
};



void Package::accept(ProductVisitor *v)
{ 
  // cout << "Package";
  v->visit(this);
};

// Visit method for ProductVisitor class on Package class
void ProductVisitor::visit(Package *p)
{
  // cout << v;
  for (int i = 0; i < p->size(); i++)
  {
    p->getProduct(i)->accept(this);
  }
  // .. TO BE COMPLETED
}


// Visit Method for the CheapestVisitor class on CannedItem class

void CheapestVisitor::visit(CannedItem *p)
{
  // .. TO BE COMPLETED
  cout << "CheapestVisitor::visit CannedItem\n";
}

// Visit Method for the CheapestVisitor class on FreshVegetable class
void CheapestVisitor::visit(FreshVegetable *p)
{
  cout << "CheapestVisitor::visit FreshVegetable\n";
  // .. TO BE COMPLETED
  // return this;
}

ReducePriceVisitor::ReducePriceVisitor(double a, double b) {

}

// Visit Method for ReducePriceVisitor class on FreshVegetable class

void ReducePriceVisitor::visit(FreshVegetable *p)
{
  cout << "ReducePriceVisitor::visit FreshVegetable\n";
  // .. TO BE COMPLETED
}

// Visit Method for ReducePriceVisitor class on CannedItem class

void ReducePriceVisitor::visit(CannedItem *p)
{
  cout << "ReducePriceVisitor::visit FreshVegetable\n";
  // .. TO BE COMPLETED
}

// CheapestVisitor Method to return the price of the cheapest item
double CheapestVisitor::getMinPrice()
{
  // .. TO BE COMPLETED
}

// CheapestVisitor Method to return the cheapest Item

Item *CheapestVisitor::getMinItem()
{
  // .. TO BE COMPLETED
}

// CheapestVisitor Method to reset before finding the minimum item

void CheapestVisitor::reset()
{
  // .. TO BE COMPLETED
};





