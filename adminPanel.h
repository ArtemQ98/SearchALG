#pragma once
#include <iostream>
#include <string>
#include "MyForm.h"
namespace global {
	extern bool valueX;
}

namespace Project2 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// —водка дл€ adminPanel
	/// </summary>
	public ref class adminPanel : public System::Windows::Forms::Form	
	{
	public:
		adminPanel()
		{
			InitializeComponent();
		}
	
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~adminPanel()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_cancel;
	protected:

	private: System::Windows::Forms::TextBox^ tx_login;

	private: System::Windows::Forms::TextBox^ tx_password;
	private: System::Windows::Forms::Label^ lb_login;
	private: System::Windows::Forms::Label^ lb_password;
	public: System::Windows::Forms::Button^ btn_enter;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			this->tx_login = (gcnew System::Windows::Forms::TextBox());
			this->tx_password = (gcnew System::Windows::Forms::TextBox());
			this->lb_login = (gcnew System::Windows::Forms::Label());
			this->lb_password = (gcnew System::Windows::Forms::Label());
			this->btn_enter = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_cancel
			// 
			this->btn_cancel->ForeColor = System::Drawing::Color::OliveDrab;
			this->btn_cancel->Location = System::Drawing::Point(359, 12);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(29, 29);
			this->btn_cancel->TabIndex = 0;
			this->btn_cancel->Text = L"X";
			this->btn_cancel->UseVisualStyleBackColor = true;
			this->btn_cancel->Click += gcnew System::EventHandler(this, &adminPanel::btn_cancel_Click);
			// 
			// tx_login
			// 
			this->tx_login->BackColor = System::Drawing::Color::White;
			this->tx_login->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tx_login->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tx_login->Location = System::Drawing::Point(67, 55);
			this->tx_login->Multiline = true;
			this->tx_login->Name = L"tx_login";
			this->tx_login->Size = System::Drawing::Size(266, 22);
			this->tx_login->TabIndex = 1;
			// 
			// tx_password
			// 
			this->tx_password->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tx_password->Location = System::Drawing::Point(67, 115);
			this->tx_password->Multiline = true;
			this->tx_password->Name = L"tx_password";
			this->tx_password->PasswordChar = '*';
			this->tx_password->Size = System::Drawing::Size(266, 22);
			this->tx_password->TabIndex = 2;
			// 
			// lb_login
			// 
			this->lb_login->AutoSize = true;
			this->lb_login->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lb_login->ForeColor = System::Drawing::Color::White;
			this->lb_login->Location = System::Drawing::Point(67, 33);
			this->lb_login->Name = L"lb_login";
			this->lb_login->Size = System::Drawing::Size(63, 20);
			this->lb_login->TabIndex = 3;
			this->lb_login->Text = L"Ћогин:";
			// 
			// lb_password
			// 
			this->lb_password->AutoSize = true;
			this->lb_password->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lb_password->ForeColor = System::Drawing::Color::White;
			this->lb_password->Location = System::Drawing::Point(67, 92);
			this->lb_password->Name = L"lb_password";
			this->lb_password->Size = System::Drawing::Size(72, 20);
			this->lb_password->TabIndex = 4;
			this->lb_password->Text = L"ѕароль:";
			// 
			// btn_enter
			// 
			this->btn_enter->ForeColor = System::Drawing::Color::OliveDrab;
			this->btn_enter->Location = System::Drawing::Point(289, 159);
			this->btn_enter->Name = L"btn_enter";
			this->btn_enter->Size = System::Drawing::Size(99, 29);
			this->btn_enter->TabIndex = 5;
			this->btn_enter->Text = L"¬ход";
			this->btn_enter->UseVisualStyleBackColor = true;
			this->btn_enter->Click += gcnew System::EventHandler(this, &adminPanel::btn_enter_Click);
			// 
			// adminPanel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::OliveDrab;
			this->ClientSize = System::Drawing::Size(400, 200);
			this->Controls->Add(this->btn_enter);
			this->Controls->Add(this->lb_password);
			this->Controls->Add(this->lb_login);
			this->Controls->Add(this->tx_password);
			this->Controls->Add(this->tx_login);
			this->Controls->Add(this->btn_cancel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"adminPanel";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"adminPanel";
			this->Load += gcnew System::EventHandler(this, &adminPanel::adminPanel_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void adminPanel_Load(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void btn_cancel_Click(System::Object^ sender, System::EventArgs^ e);
public: System::Void btn_enter_Click(System::Object^ sender, System::EventArgs^ e);
};
}
