#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>
#include "../TQueue.h"

namespace VisualProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		int MaxSize;
		int Size;
		int CurrentSize;
		double AddChance;
		double RemoveChance;
		TQueue<int>* pQueue;
		Graphics^ gr;
		int grX;
		int grY;
		Pen^ PenDraw;
		Pen^ PenClear;
		Random^ VBR;
		int countPush;
		int countPop;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			gr = this->CreateGraphics();
			grX = label1->Location.X;
			grY = label6->Location.Y + label6->Location.Y - label5->Location.Y;

			PenDraw = gcnew Pen(Color::Black);
			PenDraw->Width = 8.0F;
			PenClear = gcnew Pen(this->BackColor);
			PenClear->Width = 8.0F;

			VBR = gcnew Random();

			countPush = countPop = 0;
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
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	protected:

	protected:




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(81, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Максимальная длина очереди";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(81, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(175, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Исходная длина очереди";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(81, 175);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(175, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Вероятность извлечения";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(81, 139);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(176, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Вероятность добавления";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(81, 212);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(152, 17);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Добавлено в очередь";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(81, 249);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(159, 17);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Извчечено из очереди";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(309, 67);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(175, 22);
			this->textBox1->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(309, 101);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(175, 22);
			this->textBox2->TabIndex = 7;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(309, 136);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(175, 22);
			this->textBox3->TabIndex = 8;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(309, 172);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(175, 22);
			this->textBox4->TabIndex = 9;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(309, 209);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(175, 22);
			this->textBox5->TabIndex = 10;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(309, 246);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(175, 22);
			this->textBox6->TabIndex = 11;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(584, 104);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Старт";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(584, 206);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Стоп";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 300;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(796, 634);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: void DrawQueue() {
		int start = 360 * pQueue->GetHead() / pQueue->GetMaxSize();
		int stop = 360 * pQueue->GetCountEl() / pQueue->GetMaxSize();

		gr->DrawArc(PenDraw, grX, grY, 200, 200, start, stop);
	}

	private: void Clear() {
		int start = 360 * pQueue->GetHead() / pQueue->GetMaxSize();
		int stop = 360 * pQueue->GetCountEl() / pQueue->GetMaxSize();

		gr->DrawArc(PenClear, grX, grY, 200, 200, start, stop);
	}

#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		if (countPush - countPop == MaxSize)
			timer1->Enabled = false;

		Clear();
		try {
			if (VBR->NextDouble() < AddChance)
			{
				pQueue->Push(1);
				countPush++;
			}
			if (VBR->NextDouble() < RemoveChance)
			{
				pQueue->Pop();
				countPop++;
			}
		}
		catch (int)
		{

		}

		DrawQueue();
		textBox5->Text = Convert::ToString(countPush);
		textBox6->Text = Convert::ToString(countPop);
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = false;
	}

	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		MaxSize = Convert::ToInt32(textBox1->Text);
		Size = Convert::ToInt32(textBox2->Text);
		AddChance = Convert::ToDouble(textBox3->Text);
		RemoveChance = Convert::ToDouble(textBox4->Text);
		pQueue = new TQueue<int>(MaxSize);

		for (int i = 0; i < Size; i++)
			pQueue->Push(1);

		DrawQueue();
		countPush = countPop = 0;

		timer1->Enabled = true;
	}
};
}
