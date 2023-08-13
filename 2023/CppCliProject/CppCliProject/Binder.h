#pragma once

#include "ICanExecuteAware.h"

using namespace System;
using System::ComponentModel::INotifyPropertyChanged;
using System::Windows::Forms::Binding;
using System::Windows::Forms::Control;
using System::Windows::Forms::CheckBox;
using System::Windows::Forms::RadioButton;
using System::Windows::Forms::NumericUpDown;
using System::Windows::Forms::BindingSource;
using System::Windows::Forms::DataSourceUpdateMode;

ref class Binder abstract sealed
{
private:
	static DataSourceUpdateMode GetUpdateMode(bool isOnChanged)
	{
		return isOnChanged ? DataSourceUpdateMode::OnPropertyChanged : DataSourceUpdateMode::OnValidation;
	}

public:
	static Binding^ BindChecked(CheckBox^ checkBox, INotifyPropertyChanged^ dataSource, String^ dataMember)
	{
		return checkBox->DataBindings->Add("Checked", dataSource, dataMember, false, DataSourceUpdateMode::OnPropertyChanged);
	}
	static Binding^ BindChecked(RadioButton^ radioButton, INotifyPropertyChanged^ dataSource, String^ dataMember)
	{
		return radioButton->DataBindings->Add("Checked", dataSource, dataMember, false, DataSourceUpdateMode::OnPropertyChanged);
	}

	static Binding^ BindEnabled(Control^ control, INotifyPropertyChanged^ dataSource, String^ dataMember)
	{
		return control->DataBindings->Add("Enabled", dataSource, dataMember);
	}
	static Binding^ BindEnabled(Control^ control, ICanExecuteAware^ command)
	{
		return control->DataBindings->Add("Enabled", command, "CanExecute");
	}

	static Binding^ BindVisible(Control^ control, INotifyPropertyChanged^ dataSource, String^ dataMember)
	{
		return control->DataBindings->Add("Visible", dataSource, dataMember);
	}
	static Binding^ BindVisible(Control^ control, ICanExecuteAware^ command)
	{
		return control->DataBindings->Add("Visible", command, "CanExecute");
	}

	static Binding^ BindValue(NumericUpDown^ numericUpDown, INotifyPropertyChanged^ dataSource, String^ dataMember)
	{
		return numericUpDown->DataBindings->Add("Value", dataSource, dataMember, false, DataSourceUpdateMode::OnPropertyChanged);
	}

	static Binding^ BindText(Control^ control, INotifyPropertyChanged^ dataSource, String^ dataMember)
	{
		return control->DataBindings->Add("Text", dataSource, dataMember);
	}
	static Binding^ BindText(Control^ control, INotifyPropertyChanged^ dataSource, String^ dataMember, bool isOnChanged)
	{
		return control->DataBindings->Add("Text", dataSource, dataMember, false, GetUpdateMode(isOnChanged));
	}

	static Binding^ BindText(Control^ control, BindingSource^ dataSource, String^ dataMember)
	{
		return control->DataBindings->Add("Text", dataSource, dataMember);
	}

	static Binding^ Bind(Control^ control, String^ propertyName, INotifyPropertyChanged^ dataSource, String^ dataMember)
	{
		return control->DataBindings->Add(propertyName, dataSource, dataMember);
	}
	static Binding^ Bind(Control^ control, String^ propertyName, INotifyPropertyChanged^ dataSource, String^ dataMember, bool isOnChanged)
	{
		return control->DataBindings->Add(propertyName, dataSource, dataMember, false, GetUpdateMode(isOnChanged));
	}

	static Binding^ Bind(Control^ control, String^ propertyName, BindingSource^ dataSource, String^ dataMember)
	{
		return control->DataBindings->Add(propertyName, dataSource, dataMember);
	}
	static Binding^ Bind(Control^ control, String^ propertyName, BindingSource^ dataSource, String^ dataMember, bool isOnChanged)
	{
		return control->DataBindings->Add(propertyName, dataSource, dataMember, false, GetUpdateMode(isOnChanged));
	}
};

