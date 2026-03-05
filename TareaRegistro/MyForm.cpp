#include "MyForm.h" // Verifica que el nombre del archivo sea igual (mayúsculas/minúsculas)

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Si tu proyecto se llama TareaRegistro, cámbialo aquí:
    TareaRegistro::MyForm form;

    Application::Run(% form);
    return 0;
}