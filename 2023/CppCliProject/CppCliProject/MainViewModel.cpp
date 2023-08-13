#include "MainViewModel.h"

CppCliProject::MainViewModel::MainViewModel()
{
}

void CppCliProject::MainViewModel::PlusAction()
{
	Count++;
	Channels->Add(Count.ToString());

	Checks->Clear();
}
