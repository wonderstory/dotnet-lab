#pragma once

#include "PropertyAgent.h"

using namespace System;
using System::ComponentModel::INotifyPropertyChanged;
using System::ComponentModel::PropertyChangedEventHandler;
using System::ComponentModel::PropertyChangedEventArgs;
using System::ComponentModel::BindingList;

/// <summary>
/// ViewModel������ <see cref="INotifyPropertyChanged"/> ����
/// </summary>
public ref class BindableBase abstract : INotifyPropertyChanged
{
public:
	// �v���p�e�B�ύX�̒ʒm
	virtual event PropertyChangedEventHandler^ PropertyChanged;

protected:
	// �v���p�e�B�ύX���Action
	Action<String^>^ PropertyChangedAction = gcnew Action<String^>(this, &BindableBase::OnPropertyChanged);
	inline void OnPropertyChanged(String^ propertyName)
	{
		PropertyChanged(this, gcnew PropertyChangedEventArgs(propertyName));
	}

private:
	PropertyAgent^ _propertyAgent = gcnew PropertyAgent(this, PropertyChangedAction);
public:
	// �ύX���̒ʒm�𔺂��v���p�e�B�ύX��s�I�u�W�F�N�g
	property PropertyAgent^ Property
	{
		PropertyAgent^ get() { return _propertyAgent; }
	}
};
