#pragma once

using namespace System;
using System::ComponentModel::INotifyPropertyChanged;

/// <summary>
/// �ύX���̒ʒm�𔺂��v���p�e�B�ύX��s
/// </summary>
public ref class PropertyAgent
{
protected:
	property INotifyPropertyChanged^ Owner;

protected:
	Action<String^>^ PropertyChangingAction;
	Action<String^>^ PropertyChangedAction;

public:
	PropertyAgent(INotifyPropertyChanged^ owner, Action<String^>^ onPropertyChanged);
	PropertyAgent(INotifyPropertyChanged^ owner, Action<String^>^ onPropertyChanged, Action<String^>^ onPropertyChanging);

public:
	/// <summary>
	/// �l�ɕω�������ꍇ�́A�w��v���p�e�B�̒l��ύX���A����̒ʒm�𔭏o
	/// </summary>
	/// <param name="storage">�Ώۂ̃v���p�e�B</param>
	/// <param name="newValue">�ݒ肷��l</param>
	/// <param name="propertyName">�v���p�e�B��</param>
	/// <returns>true: �l�ɕω����� / false: �l�ɕω��Ȃ�</returns>
	generic<typename T>
	bool Set(T% storage, T newValue, String^ propertyName);

public:
	void RaisePropertyChanging(String^ propertyName);
	void RaisePropertyChanged(String^ propertyName);
};
