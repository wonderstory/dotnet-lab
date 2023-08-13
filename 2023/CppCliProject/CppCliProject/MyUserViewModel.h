#pragma once

#include "ViewModelBase.h"

using namespace System;

ref class MyUserViewModel : ViewModelBase
{
private:
	bool _isEnabled;
public:
	property bool IsEnabled
	{
		bool get() { return _isEnabled; }
		void set(bool value)
		{
			if (Property->Set(_isEnabled, value, "IsEnabled"))
			{
				Property->RaisePropertyChanged("IsAvailable");
			}
		}
	}

private:
	String^ _path;
public:
	property String^ Path
	{
		String^ get() { return _path; }
		void set(String^ value)
		{
			if (Property->Set(_path, value, "Path"))
			{
				Property->RaisePropertyChanged("IsAvailable");
			}
		}
	}

//private:
//	bool _isAvailable;
public:
	property bool IsAvailable
	{
		bool get() { return _isEnabled && (! String::IsNullOrWhiteSpace(Path)); }
		//void set(bool value) { Property->Set(_isAvailable, value, "IsAvailable"); }
	}

public:
	MyUserViewModel();
};
