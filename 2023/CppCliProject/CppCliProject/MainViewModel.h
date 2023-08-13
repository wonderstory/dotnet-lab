#pragma once

#include "ViewModelBase.h"
#include "RelayCommand.h"

using namespace System;

namespace CppCliProject
{
	ref class MainViewModel : ViewModelBase
	{
	private:
		int _count;
	public:
		property int Count
		{
			int get() { return _count; }
			void set(int value) { Property->Set(_count, value, "Count"); }
		}

	private:
		bool _isChecked;
	public:
		property bool IsChecked
		{
			bool get() { return _isChecked; }
			void set(bool value)
			{
				if (Property->Set(_isChecked, value, "IsChecked"))
				{
					CountUpCommand->RaiseCanExecuteChanged();
				}
			}
		}

	private:
		BindingList<String^>^ _channels = gcnew BindingList<String^>();
	public:
		property BindingList<String^>^ Channels
		{
			BindingList<String^>^ get() { return _channels; }
		}

	private:
		BindingList<String^>^ _checks = gcnew BindingList<String^>();
	public:
		property BindingList<String^>^ Checks
		{
			BindingList<String^>^ get() { return _checks; }
		}

	private:
		RelayCommand^ _countUpCommand = gcnew RelayCommand(
			gcnew Action(this, &MainViewModel::CountUpCommand_Execute),
			gcnew Func<bool>(this, &MainViewModel::CountUpCommand_CanExecute));
	public:
		property RelayCommand^ CountUpCommand
		{
			RelayCommand^ get() { return _countUpCommand; }
		}
	private:
		void CountUpCommand_Execute()
		{
			Count++;
		}
		bool CountUpCommand_CanExecute()
		{
			return IsChecked;
		}

	private:
		String^ _path;
	public:
		property String^ Path
		{
			String^ get() { return _path; }
			void set(String^ value) { Property->Set(_path, value, "Path"); }
		}

	private:
		Decimal _volume;
	public:
		property Decimal Volume
		{
			Decimal get() { return _volume; }
			void set(Decimal value) { Property->Set(_volume, value, "Volume"); }
		}

	public:
		MainViewModel();


		void PlusAction();
	};
}
