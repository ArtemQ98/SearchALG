#include "MyForm.h"
#include "adminPanel.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::IO;

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
		query = "SELECT * FROM Students WHERE (Name LIKE '%' + '" + text1 + "' + '%'OR Surname LIKE '%' + '" + text1 + "' + '%' OR CAST(Score	AS varchar(10)) = '" + text1 + "' OR CAST(ID AS varchar(10)) = '" + text1 + "')";
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
			cli::array<Byte>^ imageData = static_cast<cli::array<Byte>^>(dbReader["Picture"]);
			Bitmap^ image = nullptr;
			if (imageData != nullptr && imageData->Length > 0) {
				try {
					// Создание потока из двоичных данных
					System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(imageData);
					// Используем Image::FromStream для создания изображения
					image = safe_cast<System::Drawing::Bitmap^>(System::Drawing::Image::FromStream(ms));
				}
				catch (System::ArgumentException^ ex) {
					// Обработка исключения, если данные изображения недействительны
					System::Console::WriteLine("Ошибка при загрузке изображения: " + ex->Message);
				}
			}
			dataGridView1->Rows->Add(dbReader["ID"], dbReader["Name"], dbReader["Surname"], dbReader["Score"], image);
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

inline System::Void Project2::MyForm::btn_Image_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (global::valueX == true)
	{
		OpenFileDialog^ ofd = gcnew OpenFileDialog;
		ofd->Title = "Выберите фото";
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			imgloc = ofd->FileName->ToString();
		}

		/*int index = this->dataGridView1->SelectedCells[0]->RowIndex;
		String^ id; 
		if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr)
		{
			MessageBox::Show("Сначала загрузите данные, фото в последнюю очередь!");
			return;
		}
		else
		{
			id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();

		}

		int a = Convert::ToInt32(id);
		if (this->dataGridView1->Rows[index]->Cells[4]->Selected)
		{
			String^ connectionString = "Data Source=ARTTEAM-DESKTOP\\SQLEXPRESS;Initial Catalog=Academy;Integrated Security=True";
			SqlConnection^ connection = gcnew SqlConnection(connectionString);
			String^ query;
			query = "UPDATE Students SET Picture = ( SELECT * FROM OPENROWSET(BULK '"+ imgloc +"', SINGLE_BLOB) AS Image) WHERE ID = " + id;

			SqlCommand^ command = gcnew SqlCommand(query, connection);


			SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command);
			DataSet^ dataSet = gcnew DataSet();


			try {
				connection->Open();
				this->dataGridView1->Rows->Clear();
				command->ExecuteReader();

				connection->Close();

				MessageBox::Show("Фото загружено!");
				
			}
			catch (SqlException^ ex) {
					MessageBox::Show(ex->Message);
			}
		}*/
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

		while (dbReader->Read())
		{
		
			// Получение двоичных данных изображения
			cli::array<Byte>^ imageData = static_cast<cli::array<Byte>^>(dbReader["Picture"]);
			Bitmap^ image = nullptr;
			if (imageData != nullptr && imageData->Length > 0) {
				try {
					// Создание потока из двоичных данных
					System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(imageData);
					// Используем Image::FromStream для создания изображения
					image = safe_cast<System::Drawing::Bitmap^>(System::Drawing::Image::FromStream(ms));
				}
				catch (System::ArgumentException^ ex) {
					// Обработка исключения, если данные изображения недействительны
					System::Console::WriteLine("Ошибка при загрузке изображения: " + ex->Message);
				}
			}
			dataGridView1->Rows->Add(dbReader["ID"], dbReader["Name"], dbReader["Surname"], dbReader["Score"], image);
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
		dataGridView1->Rows[index]->Cells[3] == nullptr ||
		dataGridView1->Rows[index]->Cells[4] == nullptr)
	{
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}
	String^ id;
	try {
		id = dataGridView1->Rows[index - 1]->Cells[0]->Value->ToString();
	}
	catch (System::ArgumentOutOfRangeException^ ex) {
		MessageBox::Show("Вы пытаетесь добавить уже существующую строку!", "Внимание!");
		return;
	}
	int i = Int32::Parse(id) + 1;
	id = Convert::ToString(i);
	String^ name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ surname = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ score = dataGridView1->Rows[index]->Cells[3]->Value->ToString();

	String^ connectionString = "Data Source=ARTTEAM-DESKTOP\\SQLEXPRESS;Initial Catalog=Academy;Integrated Security=True";
	SqlConnection^ connection = gcnew SqlConnection(connectionString);
	String^ query2 = "UPDATE Students SET Picture = ( SELECT * FROM OPENROWSET(BULK '" + imgloc + "', SINGLE_BLOB) AS Image) WHERE ID = " + id;
	String^ query = "INSERT INTO [Students] VALUES ("+ id +", '"+ name +"', '"+ surname +"', "+ score +", (SELECT * FROM OPENROWSET(BULK '" + imgloc + "', SINGLE_BLOB) AS Image))";
	SqlCommand^ command = gcnew SqlCommand(query, connection);
	SqlCommand^ command2 = gcnew SqlCommand(query2, connection);

	try {
		connection->Open();
		if (command->ExecuteNonQuery() != 1)
		{
			MessageBox::Show("Ошибка выполнения запроса", "Ошибка!");
		}
		/*if (command2->ExecuteNonQuery() != 1)
		{
			MessageBox::Show("Ошибка добавления фотографии", "Ошибка!");
		}*/
		else
		{
			MessageBox::Show("Данные были добавлены", "Готово!");
		}
		imgloc = nullptr;
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
		dataGridView1->Rows[index]->Cells[3] == nullptr ||
		dataGridView1->Rows[index]->Cells[4] == nullptr)
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
	String^ query;
	if (imgloc == nullptr)
	{
		query = "UPDATE [Students] SET Name = '" + name + "', Surname = '" + surname + "', Score = " + score + " WHERE ID = " + id;
	}
	else
	{
		query = "UPDATE [Students] SET Name = '" + name + "', Surname = '" + surname + "', Score = " + score + ", Picture = (SELECT * FROM OPENROWSET(BULK '" + imgloc + "', SINGLE_BLOB) AS Image) WHERE ID = " + id;

	}
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
		imgloc = nullptr;
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
		MessageBox::Show("Выберите одну строку для удаления!", "Внимание!");
		return;
	}
	int index = dataGridView1->SelectedRows[0]->Index;

	if (dataGridView1->Rows[index]->Cells[0] == nullptr ||
		dataGridView1->Rows[index]->Cells[1] == nullptr ||
		dataGridView1->Rows[index]->Cells[2] == nullptr ||
		dataGridView1->Rows[index]->Cells[3] == nullptr ||
		dataGridView1->Rows[index]->Cells[4] == nullptr)
	{
		MessageBox::Show("Не все данные введены!", "Внимание!");
		return;
	}

	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	int mainID = Int32::Parse(id);
	int nextID = Int32::Parse(id)+1;
	
	String^ s = Convert::ToString(nextID);
	
	String^ connectionString = "Data Source=ARTTEAM-DESKTOP\\SQLEXPRESS;Initial Catalog=Academy;Integrated Security=True";
	SqlConnection^ connection = gcnew SqlConnection(connectionString);

	String^ query2 = "UPDATE [Students] SET ID = "+ mainID +" WHERE ID = " + nextID;
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
		command2->ExecuteNonQuery();
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
			this->button_Add->Visible = false;
			this->button_Update->Visible = false;
			this->button_Delete->Visible = false;
			this->dataGridView1->AllowUserToAddRows = false;
			this->lb_userOrAdmin->Text = "Пользователь";
			return;
		}
	}
	else
	{
		
	}
	adminPanel^ varAdminPanel = gcnew adminPanel();
	varAdminPanel->ShowDialog();
	if (global::valueX == true)
	{
		this->lb_userOrAdmin->Text = "Администратор";
		this->button_Add->Visible = true;
		this->button_Update->Visible = true;
		this->button_Delete->Visible = true;
		this->dataGridView1->AllowUserToAddRows = true;
	}
	return;
}

inline System::Void Project2::MyForm::button_Action_Click(System::Object^ sender, System::EventArgs^ e) {
	if (global::valueX == false)
	{
		
	}
	else
	{
		
	}
}



