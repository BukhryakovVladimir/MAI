#pragma once


namespace KPOLR2ex1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form_ex1
	/// </summary>
	
	public ref class Form_ex1 : public System::Windows::Forms::Form
	{
	public:
		Form_ex1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form_ex1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button2;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox1->Location = System::Drawing::Point(12, 31);
			this->textBox1->MaxLength = 100;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(500, 30);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form_ex1::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form_ex1::textBox1_KeyPress);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button1->Location = System::Drawing::Point(520, 30);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(132, 43);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Çàëîæèòü";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form_ex1::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->richTextBox1->Location = System::Drawing::Point(12, 150);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(500, 500);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Form_ex1::richTextBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button2->Location = System::Drawing::Point(520, 150);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(132, 41);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Äîñòàòü";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form_ex1::button2_Click);
			// 
			// Form_ex1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(748, 408);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form_ex1";
			this->Text = L"Form_ex1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:

	
		cli::array<String^>^ zalozh = gcnew cli::array<String^>(100);
		
		

	int top = 0;
	



	

	System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (top < 100)
		{
			zalozh[top] = textBox1->Text;
			textBox1->Text = "";
			top++;
		}
		else textBox1->Text = "ÑÒÅÊ ÏÅÐÅÏÎËÍÅÍ!";
		}
	
	
	System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		if (top > 0)
		{
			top--;
			richTextBox1->Text += zalozh[top] + "\n";
		}
		else
		{
			richTextBox1->Text += "ÑÒÅÊ ÏÓÑÒ!" + "\n";
		}
	}

//	System::Void transfer(System::Object^ sender, System::EventArgs^ e) {
//		richTextBox1->Text = zalozh;
//	}

	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
			if (e->KeyChar == (char)13) button1_Click(sender, e);
	}
	};

}
