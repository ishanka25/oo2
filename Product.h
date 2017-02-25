#ifndef _PRODUCT_H
#define _PRODUCT_H
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_NAME_LEN = 200;

class ProductVisitor;

class Product
{
 public:
 Product() {};
  virtual void accept(ProductVisitor *v) = 0;
  virtual double getPrice() = 0;
 private:
  double price;

};

class Item : public Product
{
 public:
 Item(const char *n) : price(0.0) {strcpy(name, n);};
 Item(const char *n, double p) : price(p) {strcpy(name, n);};
  virtual void accept(ProductVisitor *v) = 0;
  double getPrice() {return price;};
  void setPrice(double p) { price = p;};
  char *getName() {return name;};

 private:
  double price;
  char name[MAX_NAME_LEN];
};



class FreshVegetable : public Item
{
 public:
 FreshVegetable(const char *n) : Item(n) {};
 FreshVegetable(const char *n, double p) : Item(n,p) {};
  
  void accept(ProductVisitor *v);
};

class CannedItem : public Item
{
 public:
 CannedItem(const char *n) : Item(n) {};
 CannedItem(const char *n, double p) : Item(n,p) {};
  void accept(ProductVisitor *v);
};


class Package : public Product
{
 public:
  Package() {};
  Package& addProduct(Product *product) { contents.push_back(product); return *this; };
  Product *getProduct(int i) { return contents[i];};
  int size() {return contents.size();};
  virtual void accept(ProductVisitor *v);
  double getPrice() { double p=0.0; for (int i=0;i<contents.size();i++) { p+=contents[i]->getPrice();} return p;};
 private:
  vector<Product *> contents;
};



#endif
    
