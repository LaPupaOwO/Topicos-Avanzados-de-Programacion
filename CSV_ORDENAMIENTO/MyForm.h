#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct Persona {
	string nombre;
	string apPaterno;
	string apMaterno;
	string matricula;
	string curp;
};

// Funciones de comparación
inline bool compararPorNombre(const Persona& a, const Persona& b) { return a.nombre < b.nombre; }
inline bool compararPorApellido(const Persona& a, const Persona& b) { return a.apPaterno < b.apPaterno; }
inline bool compararPorMatricula(const Persona& a, const Persona& b) { return a.matricula < b.matricula; }

namespace CSVORDENAMIENTO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		vector<Persona>* listaPersonas;
		System::Windows::Forms::ComboBox^ comboOrden;
		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::Button^ button1; // Cargar
		System::Windows::Forms::Button^ button2; // Ordenar
		System::Windows::Forms::Button^ button3; // Borrar
		System::Windows::Forms::Label^ label1;
		System::ComponentModel::Container^ components;

	public:
		MyForm(void)
		{
			InitializeComponent();
			listaPersonas = new vector<Persona>();
			ConfigurarTabla();

			comboOrden->Items->Add("Nombre");
			comboOrden->Items->Add("Apellido Paterno");
			comboOrden->Items->Add("Matrícula");
			comboOrden->SelectedIndex = 0;
		}

	protected:
		~MyForm() { if (components) delete components; if (listaPersonas) delete listaPersonas; }

	private:
		void ConfigurarTabla() {
			dataGridView1->ColumnCount = 5;
			dataGridView1->Columns[0]->Name = "Nombre";
			dataGridView1->Columns[1]->Name = "Ap. Paterno";
			dataGridView1->Columns[2]->Name = "Ap. Materno";
			dataGridView1->Columns[3]->Name = "Matrícula";
			dataGridView1->Columns[4]->Name = "CURP";
			dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			dataGridView1->AllowUserToAddRows = false;
		}

		void ActualizarTabla() {
			dataGridView1->Rows->Clear();
			for (const auto& p : *listaPersonas) {
				dataGridView1->Rows->Add(gcnew String(p.nombre.c_str()), gcnew String(p.apPaterno.c_str()),
					gcnew String(p.apMaterno.c_str()), gcnew String(p.matricula.c_str()), gcnew String(p.curp.c_str()));
			}
		}

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->comboOrden = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();

			// --- DataGridView ---
			this->dataGridView1->Location = System::Drawing::Point(20, 20);
			this->dataGridView1->Size = System::Drawing::Size(640, 240);
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;

			// --- Fila Superior de Controles (Ordenamiento) ---
			this->label1->Text = L"Criterio de Orden:";
			this->label1->Location = System::Drawing::Point(350, 283);
			this->label1->Size = System::Drawing::Size(100, 20);

			this->comboOrden->Location = System::Drawing::Point(455, 280);
			this->comboOrden->Size = System::Drawing::Size(205, 25);
			this->comboOrden->DropDownStyle = ComboBoxStyle::DropDownList;

			// --- Fila de Botones Alineada ---
			// Botón 1: Cargar
			this->button1->Location = System::Drawing::Point(20, 280);
			this->button1->Size = System::Drawing::Size(100, 30);
			this->button1->Text = L"Cargar CSV";
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);

			// Botón 2: Ordenar
			this->button2->Location = System::Drawing::Point(130, 280);
			this->button2->Size = System::Drawing::Size(100, 30);
			this->button2->Text = L"Ordenar";
			this->button2->BackColor = System::Drawing::Color::LightBlue;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);

			// Botón 3: Borrar
			this->button3->Location = System::Drawing::Point(240, 280);
			this->button3->Size = System::Drawing::Size(100, 30);
			this->button3->Text = L"Limpiar";
			this->button3->BackColor = System::Drawing::Color::MistyRose;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);

			// --- Propiedades del Formulario ---
			this->ClientSize = System::Drawing::Size(680, 340);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboOrden);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"Sistema de Ordenamiento de Alumnos";
			this->StartPosition = FormStartPosition::CenterScreen; // Centrar en pantalla al abrir

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		listaPersonas->clear();
		ifstream archivo("datos.csv");
		string linea;
		if (!archivo.is_open()) { MessageBox::Show("Archivo no encontrado"); return; }
		getline(archivo, linea);
		while (getline(archivo, linea)) {
			if (linea.empty()) continue;
			stringstream ss(linea);
			Persona p;
			getline(ss, p.nombre, ','); getline(ss, p.apPaterno, ','); getline(ss, p.apMaterno, ',');
			getline(ss, p.matricula, ','); getline(ss, p.curp, ',');
			listaPersonas->push_back(p);
		}
		archivo.close();
		ActualizarTabla();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (listaPersonas->empty()) return;
		int op = comboOrden->SelectedIndex;
		if (op == 0) sort(listaPersonas->begin(), listaPersonas->end(), compararPorNombre);
		else if (op == 1) sort(listaPersonas->begin(), listaPersonas->end(), compararPorApellido);
		else if (op == 2) sort(listaPersonas->begin(), listaPersonas->end(), compararPorMatricula);
		ActualizarTabla();
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		listaPersonas->clear();
		dataGridView1->Rows->Clear();
	}
	};
}