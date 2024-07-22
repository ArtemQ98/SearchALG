#pragma once
#include <iostream>
#include <string>



using namespace std;
int c;
string arr[]{ "Alfa-Romeo", "Aurus", "Audi", "Mercedes-Benz", "Changan", "Volvo", "Chevrolet", "BMW", "Chery", "Citroen"};


namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ result;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ button_Action;

	private: System::Windows::Forms::ToolStripMenuItem^ button_Download;

	private: System::Windows::Forms::ToolStripMenuItem^ button_Add;
	private: System::Windows::Forms::ToolStripMenuItem^ button_Update;
	private: System::Windows::Forms::ToolStripMenuItem^ button_Delete;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgvID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgvName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgvSurname;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dgvScore;















	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->result = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dgvID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgvName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgvSurname = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgvScore = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->button_Action = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_Download = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_Add = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_Update = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_Delete = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->ForeColor = System::Drawing::Color::Black;
			this->textBox1->Location = System::Drawing::Point(217, 123);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(260, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::btnSearch_Click);
			this->textBox1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox1_KeyUp);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(271, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(161, 29);
			this->label1->TabIndex = 4;
			this->label1->Text = L"ARTTEAM";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// result
			// 
			this->result->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->result->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->result->ForeColor = System::Drawing::Color::White;
			this->result->Location = System::Drawing::Point(217, 337);
			this->result->Multiline = true;
			this->result->Name = L"result";
			this->result->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->result->Size = System::Drawing::Size(260, 69);
			this->result->TabIndex = 3;
			this->result->TextChanged += gcnew System::EventHandler(this, &MyForm::result_TextChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::RaisedVertical;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->dgvID,
					this->dgvName, this->dgvSurname, this->dgvScore
			});
			this->dataGridView1->GridColor = System::Drawing::Color::Black;
			this->dataGridView1->Location = System::Drawing::Point(71, 181);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::MediumTurquoise;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(545, 225);
			this->dataGridView1->TabIndex = 5;
			// 
			// dgvID
			// 
			this->dgvID->HeaderText = L"ID";
			this->dgvID->MinimumWidth = 6;
			this->dgvID->Name = L"dgvID";
			this->dgvID->Width = 125;
			// 
			// dgvName
			// 
			this->dgvName->HeaderText = L"Имя";
			this->dgvName->MinimumWidth = 6;
			this->dgvName->Name = L"dgvName";
			this->dgvName->Width = 125;
			// 
			// dgvSurname
			// 
			this->dgvSurname->HeaderText = L"Фамилия";
			this->dgvSurname->MinimumWidth = 6;
			this->dgvSurname->Name = L"dgvSurname";
			this->dgvSurname->Width = 125;
			// 
			// dgvScore
			// 
			this->dgvScore->HeaderText = L"Очки";
			this->dgvScore->MinimumWidth = 6;
			this->dgvScore->Name = L"dgvScore";
			this->dgvScore->Width = 125;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->button_Action });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(702, 28);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// button_Action
			// 
			this->button_Action->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->button_Action->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->button_Action->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->button_Download,
					this->button_Add, this->button_Update, this->button_Delete
			});
			this->button_Action->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Action->ForeColor = System::Drawing::Color::Coral;
			this->button_Action->Name = L"button_Action";
			this->button_Action->Size = System::Drawing::Size(89, 24);
			this->button_Action->Text = L"Действия";
			// 
			// button_Download
			// 
			this->button_Download->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button_Download->Name = L"button_Download";
			this->button_Download->Size = System::Drawing::Size(161, 26);
			this->button_Download->Text = L"Загрузить";
			this->button_Download->Click += gcnew System::EventHandler(this, &MyForm::button_Download_Click);
			// 
			// button_Add
			// 
			this->button_Add->Name = L"button_Add";
			this->button_Add->Size = System::Drawing::Size(161, 26);
			this->button_Add->Text = L"Добавить";
			this->button_Add->Click += gcnew System::EventHandler(this, &MyForm::button_Add_Click);
			// 
			// button_Update
			// 
			this->button_Update->Name = L"button_Update";
			this->button_Update->Size = System::Drawing::Size(161, 26);
			this->button_Update->Text = L"Обновить";
			this->button_Update->Click += gcnew System::EventHandler(this, &MyForm::button_Update_Click);
			// 
			// button_Delete
			// 
			this->button_Delete->Name = L"button_Delete";
			this->button_Delete->Size = System::Drawing::Size(161, 26);
			this->button_Delete->Text = L"Удалить";
			this->button_Delete->Click += gcnew System::EventHandler(this, &MyForm::button_Delete_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(702, 433);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->result);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SearchALG";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
private: System::Void result_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button_Download_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Update_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Delete_Click(System::Object^ sender, System::EventArgs^ e);
};
}