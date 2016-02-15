#ifndef MEMO_CLIENT_H
#define MEMO_CLIENT_H

#include "memo.h"
class MemoDisplay
{
public:
	void Display();
protected:
	void ShowState(Fencer& role);
};

#endif //MEMO_CLIENT_H