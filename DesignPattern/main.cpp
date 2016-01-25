#include "Strategy/strategy_ui.h"
#include "simplefactory/simplefactory_ui.h"

int main(int argc, char* argv[])
{
	CosmeticDisplay cometicDisplay;
	cometicDisplay.display();
	CashierDisplay cashierDisplay;
	cashierDisplay.display();
	return 0;
}
