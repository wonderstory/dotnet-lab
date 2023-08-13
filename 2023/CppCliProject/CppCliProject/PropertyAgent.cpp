#include "PropertyAgent.h"

PropertyAgent::PropertyAgent(INotifyPropertyChanged^ owner, Action<String^>^ onPropertyChanged)
	: PropertyAgent(owner, onPropertyChanged, nullptr)
{
}

PropertyAgent::PropertyAgent(INotifyPropertyChanged^ owner, Action<String^>^ onPropertyChanged, Action<String^>^ onPropertyChanging)
{
	Owner = owner;
	PropertyChangingAction = onPropertyChanging;
	PropertyChangedAction = onPropertyChanged;
}

generic<typename T>
bool PropertyAgent::Set(T% storage, T newValue, String^ propertyName)
{
	if (System::Collections::Generic::EqualityComparer<T>::Default->Equals(storage, newValue))
	{
		return false;
	}

	RaisePropertyChanging(propertyName);
	storage = newValue;
	RaisePropertyChanged(propertyName);

	return true;
}

void PropertyAgent::RaisePropertyChanging(String^ propertyName)
{
	if (PropertyChangingAction)
	{
		PropertyChangingAction->Invoke(propertyName);
	}
}

void PropertyAgent::RaisePropertyChanged(String^ propertyName)
{
	if (PropertyChangedAction)
	{
		PropertyChangedAction->Invoke(propertyName);
	}
}
