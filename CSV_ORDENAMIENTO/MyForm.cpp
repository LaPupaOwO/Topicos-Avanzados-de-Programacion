#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(cli::array<String^>^ args) { // Agregamos cli:: para evitar confusión
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Asegúrate que el namespace sea el correcto (sin el guion bajo)
    CSVORDENAMIENTO::MyForm^ form = gcnew CSVORDENAMIENTO::MyForm();
    Application::Run(form);
    return 0;
}