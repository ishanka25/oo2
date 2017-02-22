#include "Product.h"
#include "ProductVisitor.h"


#include <iostream>
using namespace std;


int main()
{
  // Declare a couple of fresh vegetables and
  // a canned item, giving their name and their price.
  
  FreshVegetable carrot("carrot", 50.0), peas("peas", 60.0), parsnips("parsnips", 55.0);
  CannedItem mushyPeas("mushyPeas", 80.0), bakedbeans("bakedBeans", 100.0);
  
  
  // Declare some packages that can contain multiple products
  
  Package pack1, pack2;

  // Add products to the packages - pack2 contains pack1 

  pack1.addProduct(&carrot);
  pack1.addProduct(&peas);
  pack1.addProduct(&mushyPeas);

  pack2.addProduct(&pack1);
  pack2.addProduct(&bakedbeans);
  pack2.addProduct(&parsnips);

  // The Cheapest Visitor calculates the price of the cheapest
  // item in the package

  CheapestVisitor cheap;
  pack2.accept(&cheap);
  cout << "The cheapest item is "
       << cheap.getMinItem()->getName() << " at price "
       << cheap.getMinPrice() << " rupies." << endl;

  // The ReducePriceVisitor takes two arguments - a percentage (0.80) by
  // which to reduce the price of FreshVegetable products and
  // a percentage (0.50) by which to reduce CannedItem products

  ReducePriceVisitor priceModifier(0.90,0.50);
  pack2.accept(&priceModifier);

  // Use CheapestVisitor to re-calculate price of cheapest item

  cheap.reset();       // re-set to compute a new minimum price
  pack2.accept(&cheap);
  cout << "The cheapest product is "
       << cheap.getMinItem()->getName() << " at price "
       << cheap.getMinPrice() << " rupies." << endl;

  return 0;
}
