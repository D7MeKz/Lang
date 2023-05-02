#include <iostream>
#include "SpreadsheetCell.h"


int main()
{
	// Stack�� ��ü ���� 
	SpreadSheetCell cell(5);
	std::cout << "Stack Object: " << cell.getValue() << std::endl;

	// Heap�� ��ü ���� 
	// If you want to set up nothing, use nullptr!
	SpreadSheetCell* heap_cell = nullptr;
	heap_cell->setValue(7);
	std::cout << "Heap Object: " << heap_cell->getValue() << std::endl; 
	delete heap_cell; // �׻� �����ؾ� �Ѵ�. 

	// Secure!
	auto secure_cell = std::make_unique<SpreadSheetCell>(10);
	std::cout << "Secure Heap Object: " << secure_cell->getValue() << std::endl;

}
