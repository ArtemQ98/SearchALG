#include "MyForm.h"
#include "adminPanel.h"
using namespace System;
using namespace System::Windows::Forms;

int intsym[]{0,1,2,3,4,5,6,7,8,9};
[STAThreadAttribute]
void main(cli::array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Project2::MyForm form;
	Application::Run(% form);
}

inline System::Void Project2::MyForm::btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {

	
	this->result->Text = "";
	String^ text1 = this->textBox1->Text;
	String^ result = this->result->Text;
	String^ connectionString = "Data Source=ARTTEAM-DESKTOP\\SQLEXPRESS;Initial Catalog=Academy;Integrated Security=True";

	SqlConnection^ connection = gcnew SqlConnection(connectionString);
	String^ query;
	if (text1 == "")
	{
		query = "SELECT * FROM Students";
		dataGridView1->Rows->Clear();
	}
	else
	{
		query = "SELECT * FROM Students WHERE (Name LIKE '%' + '" + text1 + "' + '%' OR CAST(Score	AS varchar(10)) = '" + text1 + "' OR CAST(ID AS varchar(10)) = '" + text1 + "')";
	}
	for (int i = 0; i < text1->Length; i++)
	{
		if (text1[i] == ' ')
		{
			String^ text2 = text1->Substring(i + 1);
			text1 = text1->Substring(0, i);
			query = "SELECT * FROM Students WHERE (Name LIKE '%' + '" + text1 + "' + '%' AND Surname LIKE '%' + '" + text2 + "' + '%')";
			break;
		}
	}
	


	SqlCommand^ command = gcnew SqlCommand(query, connection);


	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command);
	DataSet^ dataSet = gcnew DataSet();


	try {
		connection->Open();
		dataGridView1->Rows->Clear();

		
		SqlDataReader^ dbReader = command->ExecuteReader();

		while (dbReader->Read())
		{
			dataGridView1->Rows->Add(dbReader["ID"], dbReader["Name"], dbReader["Surname"], dbReader["Score"]);
		}

		dbReader->Close();
		connection->Close();

	}
	catch (SqlException^ ex) {
		MessageBox::Show(ex->Message);
	}


	/*for (int i = 0; i < size(arr); i++)
	{
		if (text1 == "")
		{
			this->result->Text = "";
			break;
		}
		for (int j = 0; j < text1->Length; j++)
		{
			if (j > size(arr[i]))
			{
				continue;
			}
			if (tolower(text1[j]) == tolower(arr[i][j]))
			{
				c++;
			}
		}

		if (c == text1->Length)
		{
			c = 0;
			this->result->Text += gcnew String(arr[i].c_str());
			this->result->Text += Environment::NewLine;
		}
		else
		{
			c = 0;
		}
	}*/
}

inline System::Void Project2::MyForm::textBox1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter)
	{
		this->textBox1->Text = "";
	}
}

inline System::Void Project2::MyForm::button_Download_Click(System::Object^ sender, System::EventArgs^ e) {
	
	
	String^ text1 = this->textBox1->Text;
	this->textBox1->Text = "";
	String^ connectionString = "Data Source=ARTTEAM-DESKTOP\\SQLEXPRESS;Initial Catalog=Academy;Integrated Security=True";
	SqlConnection^ connection = gcnew SqlConnection(connectionString);
	String^ query;
	query = "SELECT * FROM Students";

	SqlCommand^ command = gcnew SqlCommand(query, connection);
	

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command);
	DataSet^ dataSet = gcnew DataSet();


	try {
		connection->Open();
		dataGridView1->Rows->Clear();
		SqlDataReader^ dbReader = command->ExecuteReader();
		//dataAdapter->Fill(dataSet, "Students");
		//dataGridView1->DataSource = dataSet->Tables["Students"];

		while (dbReader->Read())
		{
			dataGridView1->Rows->Add(dbReader["ID"], dbReader["Name"], dbReader["Surname"], dbReader["Score"]);
		}

		dbReader->Close();
		connection->Close();
	}
	catch (SqlException^ ex) {
		MessageBox::Show(ex->Message);
	}
}

inline System::Void Project2::MyForm::button_Add_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (global::valueX != true)
	{
		MessageBox::Show("У вас нет доступа", "Ошибка!");
		return;
	}
	this->lb_userOrAdmin->Text = "Администратор";
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("Выберите одну строку для добавления!","Внимание!");
		return;
	}
	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0] == nullptr ||
		dataGridView1->Rows[index]->Cells[1] == nullptr ||
		dataGridView1->Rows[index]->Cells[2] == nullptr ||
		dataGridView1->Rows[index]->Cells[3] == nullptr)
	{
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}
	String^ id = dataGridView1->Rows[index-1]->Cells[0]->Value->ToString();
	int i = Int32::Parse(id) + 1;
	id = Convert::ToString(i);
	String^ name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ surname = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ score = dataGridView1->Rows[index]->Cells[3]->Value->ToString();

	String^ connectionString = "Data Source=ARTTEAM-DESKTOP\\SQLEXPRESS;Initial Catalog=Academy;Integrated Security=True";
	SqlConnection^ connection = gcnew SqlConnection(connectionString);
	String^ query = "INSERT INTO [Students] VALUES ("+ id +", '"+ name +"', '"+ surname +"', "+ score +")";
	SqlCommand^ command = gcnew SqlCommand(query, connection);

	try {
		connection->Open();
		if (command->ExecuteNonQuery() != 1)
		{
			MessageBox::Show("Ошибка выполнения запроса", "Ошибка!");
		}
		else
		{
			MessageBox::Show("Данные были добавлены", "Готово!");
		}

		connection->Close();
	}
	catch (SqlException^ ex) {
		MessageBox::Show(ex->Message);
	}


}

inline System::Void Project2::MyForm::button_Update_Click(System::Object^ sender, System::EventArgs^ e) {

	if (global::valueX != true)
	{
		MessageBox::Show("У вас нет доступа", "Ошибка!");
		return;
	}
	this->lb_userOrAdmin->Text = "Администратор";

	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("Выберите одну строку для добавления!", "Внимание!");
		return;
	}

	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0] == nullptr ||
		dataGridView1->Rows[index]->Cells[1] == nullptr ||
		dataGridView1->Rows[index]->Cells[2] == nullptr ||
		dataGridView1->Rows[index]->Cells[3] == nullptr)
	{
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ surname = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ score = dataGridView1->Rows[index]->Cells[3]->Value->ToString();

	String^ connectionString = "Data Source=ARTTEAM-DESKTOP\\SQLEXPRESS;Initial Catalog=Academy;Integrated Security=True";
	SqlConnection^ connection = gcnew SqlConnection(connectionString);
	String^ query = "UPDATE [Students] SET Name = '"+ name +"', Surname = '"+ surname +"', Score = "+ score +" WHERE ID = "+ id;
	SqlCommand^ command = gcnew SqlCommand(query, connection);


	try {
		connection->Open();
		if (command->ExecuteNonQuery() != 1)
		{
			MessageBox::Show("Ошибка выполнения запроса", "Ошибка!");
		}
		else
		{
			MessageBox::Show("Данные были изменены!", "Готово!");
		}

		connection->Close();
	}
	catch (SqlException^ ex) {
		MessageBox::Show(ex->Message);
	}

}

inline System::Void Project2::MyForm::button_Delete_Click(System::Object^ sender, System::EventArgs^ e) {

	if (global::valueX != true)
	{
		MessageBox::Show("У вас нет доступа", "Ошибка!");
		return;
	}
	this->lb_userOrAdmin->Text = "Администратор";

	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("Выберите одну строку для добавления!", "Внимание!");
		return;
	}
	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0] == nullptr ||
		dataGridView1->Rows[index]->Cells[1] == nullptr ||
		dataGridView1->Rows[index]->Cells[2] == nullptr ||
		dataGridView1->Rows[index]->Cells[3] == nullptr)
	{
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	int nextID = Int32::Parse(id)+1;
	
	String^ s = Convert::ToString(nextID);
	
	String^ connectionString = "Data Source=ARTTEAM-DESKTOP\\SQLEXPRESS;Initial Catalog=Academy;Integrated Security=True";
	SqlConnection^ connection = gcnew SqlConnection(connectionString);

	String^ query2 = "UPDATE [Students] SET ID = "+ id +" WHERE ID = " + s;
	SqlCommand^ command2;
	if (dataGridView1->Rows[index + 1]->Cells[0] != nullptr)
	{
		command2 = gcnew SqlCommand(query2, connection);
	}
	String^ query = "DELETE FROM [Students] WHERE ID = " + id;
	SqlCommand^ command = gcnew SqlCommand(query, connection);
	try {
		connection->Open();
		if (command->ExecuteNonQuery() != 1)
		{
			MessageBox::Show("Ошибка выполнения запроса", "Ошибка!");
		}
		else
		{
			MessageBox::Show("Данные были удалены!", "Готово!");
		}
		if (command2->ExecuteNonQuery() < 0)
		{
			MessageBox::Show("Ошибка выполнения запроса", "Ошибка!");
		}
		connection->Close();
	}
	catch (SqlException^ ex) {
		MessageBox::Show(ex->Message);
	}

}

inline System::Void Project2::MyForm::btn_adminPanel_Click(System::Object^ sender, System::EventArgs^ e) {
	if (global::valueX == true)
	{	
		if (MessageBox::Show("Вы уверены что хотите выйти?", "Вопрос", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No)
		{
			return;
		}
		else
		{
			global::valueX = false;
			this->lb_userOrAdmin->Text = "Пользователь";
			return;
		}
	}
	adminPanel^ varAdminPanel = gcnew adminPanel();
	varAdminPanel->ShowDialog();
	if (global::valueX == true)
	{
		this->lb_userOrAdmin->Text = "Администратор";
	}
	return;
}