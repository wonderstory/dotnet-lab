#pragma comment(linker, "/subsystem:\"windows\" /entry:\"main\"") 
#include "MainForm.h"
#include "MainViewModel.h"
#include "Binder.h"

[System::STAThread]
int main(array<System::String^>^ args)
{
	System::Windows::Forms::Application::Run(gcnew CppCliProject::MainForm());
	return 0;
}

inline System::Void CppCliProject::MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	_context = gcnew MainViewModel();

	_context->Channels->Add(_context->Count.ToString());


	//label1->DataBindings->Add("Text", _context, "Count");
	//Binder::BindText(label1, _context, "Count");
	_context->BindAsText("Count", label1);


	//checkBox1->DataBindings->Add("Checked", _context, "IsChecked", false, DataSourceUpdateMode::OnPropertyChanged);//CheckBoxでは第5引数のOnPropertyChangedが必要
	//Binder::BindChecked(checkBox1, _context, "IsChecked");
	_context->BindAsChecked("IsChecked", checkBox1);

	//button2->DataBindings->Add("Enabled", _context->CountUpCommand, "CanExecute");
	//Binder::BindEnabled(button2, _context->CountUpCommand);
	//_context->BindAsEnabled(_context->CountUpCommand, button2);
	_context->CountUpCommand->BindAsEnabled(button2);
	//listView1->DataBindings->Add("Enabled", _context->CountUpCommand, "CanExecute");
	//Binder::BindEnabled(listView1, _context->CountUpCommand);
	//_context->BindAsEnabled(_context->CountUpCommand, listView1);
	_context->CountUpCommand->BindAsEnabled(listView1);
	//checkedListBox1->DataBindings->Add("Enabled", _context->CountUpCommand, "CanExecute");
	//Binder::BindEnabled(checkedListBox1, _context->CountUpCommand);
	//_context->BindAsEnabled(_context->CountUpCommand, checkedListBox1);
	_context->CountUpCommand->BindAsEnabled(checkedListBox1);

	// , true, DataSourceUpdateMode::OnPropertyChanged);

	listBox1->DataSource = _context->Checks;

	
	auto bs = gcnew BindingSource();
	bs->DataSource = _context->Channels;
	//bs->AddingNew += gcnew System::ComponentModel::AddingNewEventHandler(this, &MainForm::Adding);
	_context->Channels->ListChanged += gcnew System::ComponentModel::ListChangedEventHandler(this, &CppCliProject::MainForm::OnListChanged);

	comboBox1->DataSource = bs;
	dataGridView1->DataSource = bs;
	checkedListBox1->DataSource = bs;
	//label2->DataBindings->Add("Text", bs, "");
	//Binder::Bind(label2, "Text", bs, "");
	//Binder::BindText(label2, bs, "");
	_context->BindAsText(bs, "", label2);

	checkedListBox1->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &CppCliProject::MainForm::OnItemCheck);


	//textBox1->DataBindings->Add("Text", _context, "Path");//), false, DataSourceUpdateMode::OnPropertyChanged);
	//Binder::BindText(textBox1, _context, "Path");// true);
	_context->BindAsText("Path", textBox1, true);
	//label3->DataBindings->Add("Text", _context, "Path");
	//Binder::BindText(label3, _context, "Path");
	_context->BindAsText("Path", label3);

	//numericUpDown1->DataBindings->Add("Value", _context, "Volume", false, DataSourceUpdateMode::OnPropertyChanged);
	//Binder::BindValue(numericUpDown1, _context, "Volume");
	_context->BindAsValue("Volume", numericUpDown1);
	//label4->DataBindings->Add("Text", _context, "Volume");
	//Binder::BindText(label4, _context, "Volume");
	_context->BindAsText("Volume", label4);

	_context->Count = 5;
}

void CppCliProject::MainForm::Adding(Object^ sender, System::ComponentModel::AddingNewEventArgs^ e)
{
	//e->NewObject = _context->Count.ToString();
}

inline System::Void CppCliProject::MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	_context->PlusAction();
}


void CppCliProject::MainForm::OnItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e)
{
	// データソースの中身が変わるとチェック状態がリセットされる。そのときはこれが呼ばれない。

	_context->Checks->Clear();

	auto box = safe_cast<CheckedListBox^>(sender);
	auto list = gcnew System::Collections::Generic::List<String^>();

	for (int i = 0; i < box->Items->Count; i++)
	{
		String^ target = safe_cast<String^>(box->Items[i]);

		if (i == e->Index)
		{
			if (e->NewValue == CheckState::Checked)
			{
				list->Add(target);
			}

			continue;
		}

		if (box->CheckedItems->Contains(box->Items[i]))
		{
			list->Add(target);
			continue;
		}
	}

	for each (auto a in list)
	{
		_context->Checks->Add(a);
	}
}


void CppCliProject::MainForm::OnListChanged(System::Object^ sender, System::ComponentModel::ListChangedEventArgs^ e)
{
	auto a = gcnew array<ListViewItem^>(_context->Channels->Count);

	for (int i = 0; i < _context->Channels->Count; i++)
	{
		a[i] = gcnew ListViewItem(_context->Channels[i]);
	}

	listView1->Items->Clear();
	listView1->Items->AddRange(a);
}

inline System::Void CppCliProject::MainForm::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}

inline System::Void CppCliProject::MainForm::checkBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	auto b = safe_cast<CheckBox^>(sender);
}

inline System::Void CppCliProject::MainForm::checkBox1_Leave(System::Object^ sender, System::EventArgs^ e) {
	auto b = safe_cast<CheckBox^>(sender);
}

inline System::Void CppCliProject::MainForm::textBox1_DragOver(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
}

inline System::Void CppCliProject::MainForm::textBox1_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
	if (e->Data->GetDataPresent(DataFormats::FileDrop))
	{
		// ドラッグ中のファイルやディレクトリの取得
		auto drags = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false));

		for each (String^ path in drags)
		{
			if (! System::IO::File::Exists(path))
			{
				// ファイル以外であればイベント・ハンドラを抜ける
				return;
			}
		}

		e->Effect = DragDropEffects::Copy;
	}
}

inline System::Void CppCliProject::MainForm::textBox1_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
		auto drags = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false));

		for each (String ^ path in drags)
		{
			if (System::IO::File::Exists(path))
			{
				_context->Path = path;
				break;
			}
		}
}

inline System::Void CppCliProject::MainForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	_context->CountUpCommand->Execute();
}
