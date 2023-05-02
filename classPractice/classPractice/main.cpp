#include <iostream>
#include "SpreadsheetCell.h"


int main()
{
	// Stack에 객체 생성 
	SpreadSheetCell cell(5);
	std::cout << "Stack Object: " << cell.getValue() << std::endl;

	// Heap에 객체 생성 
	// If you want to set up nothing, use nullptr!
	SpreadSheetCell* heap_cell = nullptr;
	heap_cell->setValue(7);
	std::cout << "Heap Object: " << heap_cell->getValue() << std::endl; 
	delete heap_cell; // 항상 해제해야 한다. 

	// Secure!
	auto secure_cell = std::make_unique<SpreadSheetCell>(10);
	std::cout << "Secure Heap Object: " << secure_cell->getValue() << std::endl;

}
