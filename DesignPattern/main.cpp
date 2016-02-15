//#include "Strategy/strategy_ui.h"
//#include "simplefactory/simplefactory_ui.h"
//#include "factory/factory_ui.h"
//#include "publish_subscribe/publish_subscribe_client.h"
//#include "state/state_client.h"
#include "memo/memo_client.h"

int main(int argc, char* argv[])
{
	/*CosmeticFactoryDisplay cometicDisplay;
	cometicDisplay.display();
	CashierDisplay cashierDisplay;
	cashierDisplay.display();
	PulishSubscribeDisplay psd;
	psd.display();
	StateDisplay stateDisplay;
	stateDisplay.display();*/
	MemoDisplay memoDisplay;
	memoDisplay.Display();
	return 0;
}
