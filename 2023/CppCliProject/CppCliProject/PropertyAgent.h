#pragma once

using namespace System;
using System::ComponentModel::INotifyPropertyChanged;

/// <summary>
/// 変更時の通知を伴うプロパティ変更代行
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
	/// 値に変化がある場合は、指定プロパティの値を変更し、所定の通知を発出
	/// </summary>
	/// <param name="storage">対象のプロパティ</param>
	/// <param name="newValue">設定する値</param>
	/// <param name="propertyName">プロパティ名</param>
	/// <returns>true: 値に変化あり / false: 値に変化なし</returns>
	generic<typename T>
	bool Set(T% storage, T newValue, String^ propertyName);

public:
	void RaisePropertyChanging(String^ propertyName);
	void RaisePropertyChanged(String^ propertyName);
};
