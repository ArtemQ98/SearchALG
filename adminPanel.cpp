#include "adminPanel.h"
using namespace System;
using namespace System::Windows::Forms;
namespace global {
	 bool valueX = false;
}
[STAThreadAttribute]
void adminpanel(cli::array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Project2::adminPanel form;
	Application::Run(% form);
}


inline System::Void Project2::adminPanel::btn_cancel_Click(System::Object^ sender, System::EventArgs^ e) {
	adminPanel::Close();
}

inline System::Void Project2::adminPanel::btn_enter_Click(System::Object^ sender, System::EventArgs^ e) {
	
	String^ password = tx_password->Text;
	String^ login = tx_login->Text;
	String^ connectionString = "Data Source=ARTTEAM-DESKTOP\\SQLEXPRESS;Initial Catalog=Academy;Integrated Security=True";

	SqlConnection^ connection = gcnew SqlConnection(connectionString);
	String^ query = "SELECT COUNT(*) FROM Admins WHERE Login = '" + login+ "' AND Password = '"+ password +"'";

	SqlCommand^ command = gcnew SqlCommand(query, connection);

	try {
		connection->Open();

		int result = (int)command->ExecuteScalar();

		if (result > 0)
		{

			MyForm^ mf = gcnew MyForm();
			global::valueX = true;
			connection->Close();
			adminPanel::Close();
			return;
		}
		else
		{
			MessageBox::Show("Данные некорректны!", "Ошибка!");
			return;
		}

		connection->Close();

	}
	catch (SqlException^ ex) {
		MessageBox::Show(ex->Message);
	}
}
