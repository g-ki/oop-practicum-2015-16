#include <iostream>

#include "warehouse.h"

using namespace std;

int main()
{
	Package oven("AEG-55X2", 80, 170);
	Package fridge("ELLUX-66Y", 90, 230);
	Package wMachine("IND-1IP56", 70, 150);
	Package shoeShipment("GUCCI-75VN", 100, 430);
	
	Lorry pesho("Pe$h0", 75, 150);
	Lorry gosho("G.$h0", 85, 200);
	Lorry ivan("Vanquo", 110, 210);
	
	Warehouse w;

	w.addLorry(pesho);
	w.addLorry(gosho);
	w.addLorry(ivan);

	w.addPackage(oven);
	w.addPackage(fridge);
	w.addPackage(wMachine);
	w.addPackage(shoeShipment);
	
	w.print();
	
	w.setPackageToLorry(shoeShipment.getId(), pesho.getId());
	w.print();
	
	w.setPackageToLorry(wMachine.getId(), pesho.getId());
	w.print();

	w.setPackageToBestLorry(oven.getId());
	w.print();
	
	cout << w.profit();
}