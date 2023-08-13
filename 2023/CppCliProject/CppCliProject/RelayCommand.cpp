#include "RelayCommand.h"

RelayCommand::RelayCommand(Action^ execute)
	: RelayCommand(execute, nullptr)
{
}

RelayCommand::RelayCommand(Action^ execute, Func<bool>^ canExecute)
{
	if (execute == nullptr)
	{
		throw gcnew ArgumentException("execute");
	}

	_execute = execute;
	_canExecute = canExecute;
}

void RelayCommand::Execute()
{
	if (CanExecute)
	{
		_execute();
	}
}

void RelayCommand::RaiseCanExecuteChanged()
{
	Property->RaisePropertyChanged("CanExecute");
}
