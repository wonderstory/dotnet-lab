#pragma once

#include "BindableBase.h"
#include "Binder.h"

using namespace System;

public ref class ViewModelBase : BindableBase
{
public:
	Binding^ BindAsChecked(String^ dataMember, CheckBox^ checkBox)
	{
		return Binder::BindChecked(checkBox, this, dataMember);
	}
	Binding^ BindAsChecked(String^ dataMember, RadioButton^ radioButton)
	{
		return Binder::BindChecked(radioButton, this, dataMember);
	}

	Binding^ BindAsEnabled(String^ dataMember, Control^ control)
	{
		return Binder::BindEnabled(control, this, dataMember);
	}
	Binding^ BindAsEnabled(ICanExecuteAware^ command, Control^ control)
	{
		return Binder::BindEnabled(control, command);
	}

	Binding^ BindAsVisible(String^ dataMember, Control^ control)
	{
		return Binder::BindVisible(control, this, dataMember);
	}
	Binding^ BindAsVisible(ICanExecuteAware^ command, Control^ control)
	{
		return Binder::BindVisible(control, command);
	}

	Binding^ BindAsValue(String^ dataMember, NumericUpDown^ numericUpDown)
	{
		return Binder::BindValue(numericUpDown, this, dataMember);
	}

	Binding^ BindAsText(String^ dataMember, Control^ control)
	{
		return Binder::BindText(control, this, dataMember);
	}
	Binding^ BindAsText(String^ dataMember, Control^ control, bool isOnChanged)
	{
		return Binder::BindText(control, this, dataMember, isOnChanged);
	}

	Binding^ BindAsText(BindingSource^ dataSource, String^ dataMember, Control^ control)
	{
		return Binder::BindText(control, dataSource, dataMember);
	}

	Binding^ BindAs(String^ dataMember, Control^ control, String^ propertyName)
	{
		return Binder::Bind(control, propertyName, this, dataMember);
	}
	Binding^ BindAs(String^ dataMember, Control^ control, String^ propertyName, bool isOnChanged)
	{
		return Binder::Bind(control, propertyName, this, dataMember, isOnChanged);
	}

	Binding^ BindAs(INotifyPropertyChanged^ dataSource, String^ dataMember, Control^ control, String^ propertyName)
	{
		return Binder::Bind(control, propertyName, dataSource, dataMember);
	}
	Binding^ BindAs(INotifyPropertyChanged^ dataSource, String^ dataMember, Control^ control, String^ propertyName, bool isOnChanged)
	{
		return Binder::Bind(control, propertyName, dataSource, dataMember, isOnChanged);
	}

	Binding^ BindAs(BindingSource^ dataSource, String^ dataMember, Control^ control, String^ propertyName)
	{
		return Binder::Bind(control, propertyName, dataSource, dataMember);
	}
	Binding^ BindAs(BindingSource^ dataSource, String^ dataMember, Control^ control, String^ propertyName, bool isOnChanged)
	{
		return Binder::Bind(control, propertyName, dataSource, dataMember, isOnChanged);
	}
};
