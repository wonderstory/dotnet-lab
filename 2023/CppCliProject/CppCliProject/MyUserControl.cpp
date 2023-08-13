#include "MyUserControl.h"
#include "Binder.h"

inline System::Void CppCliProject::MyUserControl::MyUserControl_Load(System::Object^ sender, System::EventArgs^ e)
{
	_context = gcnew MyUserViewModel();

	//checkBox1->DataBindings->Add("Checked", _context, "IsEnabled", false, DataSourceUpdateMode::OnPropertyChanged);
	//Binder::BindChecked(checkBox1, _context, "IsEnabled");
	_context->BindAsChecked("IsEnabled", checkBox1);

	_context->BindAsText("Path", textBox1, true);
	_context->BindAsText("Path", checkBox2);

	//groupBox2->DataBindings->Add("Enabled", _context, "IsAvailable");
	//Binder::BindEnabled(groupBox2, _context, "IsAvailable");
	_context->BindAsEnabled("IsAvailable", groupBox2);
}
