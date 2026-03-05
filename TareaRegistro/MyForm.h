#pragma once

// Librería necesaria para el manejo de archivos (escritura de datos)
using namespace System::IO;

namespace TareaRegistro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
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

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
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
			this->SuspendLayout();

			// Configuramos los textos de las etiquetas según la solicitud
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 13);
			this->label1->Text = L"Nombre(s):";

			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 13);
			this->label2->Text = L"Apellido Paterno:";

			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 90);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 13);
			this->label3->Text = L"Apellido Materno:";

			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 120);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 13);
			this->label4->Text = L"Fecha de nacimiento:";

			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 150);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->Text = L"CURP:";

			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 180);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(52, 13);
			this->label6->Text = L"Domicilio:";

			// Posicionamiento de cuadros de texto
			this->textBox1->Location = System::Drawing::Point(130, 27); // Nombre
			this->textBox2->Location = System::Drawing::Point(130, 57); // ApP
			this->textBox3->Location = System::Drawing::Point(130, 87); // ApM
			this->textBox4->Location = System::Drawing::Point(130, 117); // Fecha
			this->textBox5->Location = System::Drawing::Point(130, 147); // CURP
			this->textBox6->Location = System::Drawing::Point(130, 177); // Dom

			// Botón de registro
			this->button1->Location = System::Drawing::Point(80, 220);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 30);
			this->button1->Text = L"Guardar Registro";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);

			// Configuración de la Ventana (MyForm)
			this->ClientSize = System::Drawing::Size(300, 280);
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
			this->Text = L"Registro de Datos Personales";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Proceso para almacenar datos en un archivo .txt
		try {
			// Creamos el archivo registro.txt o lo abrimos para añadir datos (true)
			StreamWriter^ objetoArchivo = gcnew StreamWriter("datos_alumnos.txt", true);

			// Escribimos línea por línea la información capturada de los TextBox
			objetoArchivo->WriteLine("--- Nuevo Registro ---");
			objetoArchivo->WriteLine("Nombre(s): " + textBox1->Text);
			objetoArchivo->WriteLine("Apellido Paterno: " + textBox2->Text);
			objetoArchivo->WriteLine("Apellido Materno: " + textBox3->Text);
			objetoArchivo->WriteLine("Fecha Nacimiento: " + textBox4->Text);
			objetoArchivo->WriteLine("CURP: " + textBox5->Text);
			objetoArchivo->WriteLine("Domicilio: " + textBox6->Text);
			objetoArchivo->WriteLine("----------------------");

			// Cerramos el archivo para liberar recursos y guardar cambios
			objetoArchivo->Close();

			// Mensaje de éxito al usuario
			MessageBox::Show("¡Los datos se guardaron correctamente en datos_alumnos.txt!", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

			// Limpiar los cuadros de texto para un nuevo ingreso
			textBox1->Clear(); textBox2->Clear(); textBox3->Clear();
			textBox4->Clear(); textBox5->Clear(); textBox6->Clear();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al guardar el archivo: " + ex->Message);
		}
	}
	};
}