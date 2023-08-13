#pragma once

#include "PropertyAgent.h"

using namespace System;
using System::ComponentModel::INotifyPropertyChanged;
using System::ComponentModel::PropertyChangedEventHandler;
using System::ComponentModel::PropertyChangedEventArgs;
using System::ComponentModel::BindingList;

/// <summary>
/// ViewModel向けの <see cref="INotifyPropertyChanged"/> 実装
/// </summary>
public ref class BindableBase abstract : INotifyPropertyChanged
{
public:
	// プロパティ変更の通知
	virtual event PropertyChangedEventHandler^ PropertyChanged;

protected:
	// プロパティ変更後のAction
	Action<String^>^ PropertyChangedAction = gcnew Action<String^>(this, &BindableBase::OnPropertyChanged);
	inline void OnPropertyChanged(String^ propertyName)
	{
		PropertyChanged(this, gcnew PropertyChangedEventArgs(propertyName));
	}

private:
	PropertyAgent^ _propertyAgent = gcnew PropertyAgent(this, PropertyChangedAction);
public:
	// 変更時の通知を伴うプロパティ変更代行オブジェクト
	property PropertyAgent^ Property
	{
		PropertyAgent^ get() { return _propertyAgent; }
	}
};
