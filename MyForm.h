#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>
#include "../mp2-lab3-stack/mp2-lab3-stack/TCalculator.h"

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ calculateButton;
	protected:

	protected:

	private: System::Windows::Forms::TextBox^ expressionInput;

	private: System::Windows::Forms::Label^ expressionLabel;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ XLabel;
	private: System::Windows::Forms::TextBox^ XIntput;


	private: System::Windows::Forms::Label^ ansLabel;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->calculateButton = (gcnew System::Windows::Forms::Button());
			this->expressionInput = (gcnew System::Windows::Forms::TextBox());
			this->expressionLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->XLabel = (gcnew System::Windows::Forms::Label());
			this->XIntput = (gcnew System::Windows::Forms::TextBox());
			this->ansLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// calculateButton
			// 
			this->calculateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif",12,System::Drawing::FontStyle::Regular,System::Drawing::GraphicsUnit::Point,
																	   static_cast<System::Byte>(204)));
			this->calculateButton->Location = System::Drawing::Point(384,95);
			this->calculateButton->Name = L"calculateButton";
			this->calculateButton->Size = System::Drawing::Size(75,34);
			this->calculateButton->TabIndex = 0;
			this->calculateButton->Text = L"=";
			this->calculateButton->UseVisualStyleBackColor = true;
			this->calculateButton->Click += gcnew System::EventHandler(this,&MyForm::button1_Click);
			// 
			// expressionInput
			// 
			this->expressionInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif",14,System::Drawing::FontStyle::Regular,System::Drawing::GraphicsUnit::Point,
																	   static_cast<System::Byte>(204)));
			this->expressionInput->Location = System::Drawing::Point(176,94);
			this->expressionInput->Name = L"expressionInput";
			this->expressionInput->Size = System::Drawing::Size(202,34);
			this->expressionInput->TabIndex = 1;
			// 
			// expressionLabel
			// 
			this->expressionLabel->AutoSize = true;
			this->expressionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif",14));
			this->expressionLabel->Location = System::Drawing::Point(15,95);
			this->expressionLabel->Name = L"expressionLabel";
			this->expressionLabel->Size = System::Drawing::Size(155,29);
			this->expressionLabel->TabIndex = 2;
			this->expressionLabel->Text = L"Выражение:";
			this->expressionLabel->Click += gcnew System::EventHandler(this,&MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif",14));
			this->label2->Location = System::Drawing::Point(446,99);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0,29);
			this->label2->TabIndex = 3;
			// 
			// XLabel
			// 
			this->XLabel->AutoSize = true;
			this->XLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif",14));
			this->XLabel->Location = System::Drawing::Point(134,149);
			this->XLabel->Name = L"XLabel";
			this->XLabel->Size = System::Drawing::Size(36,29);
			this->XLabel->TabIndex = 4;
			this->XLabel->Text = L"X:";
			// 
			// XIntput
			// 
			this->XIntput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif",14,System::Drawing::FontStyle::Regular,System::Drawing::GraphicsUnit::Point,
															   static_cast<System::Byte>(204)));
			this->XIntput->Location = System::Drawing::Point(176,149);
			this->XIntput->Name = L"XIntput";
			this->XIntput->Size = System::Drawing::Size(84,34);
			this->XIntput->TabIndex = 5;
			// 
			// ansLabel
			// 
			this->ansLabel->AutoSize = true;
			this->ansLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif",14));
			this->ansLabel->Location = System::Drawing::Point(465,94);
			this->ansLabel->Name = L"ansLabel";
			this->ansLabel->Size = System::Drawing::Size(0,29);
			this->ansLabel->TabIndex = 6;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8,16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(615,419);
			this->Controls->Add(this->ansLabel);
			this->Controls->Add(this->XIntput);
			this->Controls->Add(this->XLabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->expressionLabel);
			this->Controls->Add(this->expressionInput);
			this->Controls->Add(this->calculateButton);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender,System::EventArgs^ e){
		std::string infix;
		std::string xStr ;

		infix = msclr::interop::marshal_as<std::string>(expressionInput->Text);
		xStr = msclr::interop::marshal_as<std::string>(XIntput->Text);

		double x = std::stod(xStr);
		
		TCalculator calc(infix);
		
		double res = calc.calc(x);

		ansLabel->Text = Convert::ToString(res);
	}
	private: System::Void label1_Click(System::Object^ sender,System::EventArgs^ e){}
	};
}
