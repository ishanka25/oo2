#ifndef _PRODUCT_VISITOR_H
#define _PRODUCT_VISITOR_H

class Product;
class Item;
class CannedItem;
class FreshVegetable;
class Package;


class ProductVisitor
{
 public:
  ProductVisitor() {};
  virtual void visit(FreshVegetable *p)= 0;
  virtual void visit(CannedItem *p) = 0;
  void visit(Package *p);
};

class CheapestVisitor : public ProductVisitor
{
 public:
  // .. TO BE COMPLETED  (Done)  
  double getMinPrice();
  Item *getMinItem();
  void reset();
  void visit(FreshVegetable *p);
  void visit(CannedItem *p);
  void setMinItem(Item *p);
 private:
   double currentMinPrice = -1;
   Item *minItem;
    // .. TO BE COMPLETED (Done)
  
};

class ReducePriceVisitor : public ProductVisitor
{
 public:
  ReducePriceVisitor(double a, double b);
  // .. TO BE COMPLETED (Done)
  void visit(FreshVegetable *p);
  void visit(CannedItem *p);
  void reducePrice(Item *p,double percetage);
 private:
	double pFreshVeg;
	double pCanned;
  // .. TO BE COMPLETED (Done)
};
#endif


