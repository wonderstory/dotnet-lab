#pragma once

#include "BindableBase.h"
#include "ICanExecuteAware.h"
#include "Binder.h"

using namespace System;

ref class RelayCommand : BindableBase, ICanExecuteAware
{
public:
	virtual property bool CanExecute
	{
		bool get() { return _canExecute ? _canExecute() : true; }
	}

private:
	Action^ _execute;
	Func<bool>^ _canExecute;

public:
	RelayCommand(Action^ execute);
	RelayCommand(Action^ execute, Func<bool>^ canExecute);

public:
	void Execute();
	void RaiseCanExecuteChanged();

public:
	Binding^ BindAsEnabled(Control^ control)
	{
		return Binder::BindEnabled(control, this);
	}
	Binding^ BindAsVisible(Control^ control)
	{
		return Binder::BindVisible(control, this);
	}
};
