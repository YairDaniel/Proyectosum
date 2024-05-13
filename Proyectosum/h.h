#include "stdafx.h"
#include "Form1.h"

using namespace proyecto;

[STAThread]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Form1());
    return 0;
}

namespace proyecto {

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
            //
            //TODO: Konstruktorcode hier hinzufügen.
            //
        }

    private: System::Windows::Forms::Button^ button1;

    protected:
        /// <summary>
        /// Verwendete Ressourcen bereinigen.
        /// </summary>
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        /// <summary>
        /// Erforderliche Designervariable.
        /// </summary>
        System::ComponentModel::Container^ components;

        __declspec(naked) int sum_asm(int* numbers, int length) {  //__declspec(naked)  indica que la función no usará la pila de llamadas de forma predeterminada,
            __asm {                                                // lo que permite escribir código ensamblador inline.
                push ebp                                           // Guardar el puntero de pila anterior
                mov ebp, esp                                       // Establecer el puntero de pila actual
                mov eax, 0                                         // Inicializar el resultado en 0
                mov ecx, [ebp + 12]                                // Obtener la longitud del arreglo
                mov esi, [ebp + 8]                                 // Obtener el puntero al arreglo
                loop_start:
                add eax, [esi]                                  // Agregar el valor actual del arreglo al resultado
                    add esi, 4                                      // Avanzar al siguiente elemento del arreglo
                    loop loop_start                                 // Repetir hasta que se haya recorrido todo el arreglo
                    pop ebp                                            // Restaurar el puntero de pila anterior
                    ret                                                 // Devolver el resultado
            }
        }

        void InitializeComponent(void)
        {
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            //
            // button1
            //
            this->button1->Location = System::Drawing::Point(12, 12);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(260, 23);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Comenzar";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
            //
            // Form1
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(284, 262);
            this->Controls->Add(this->button1);
            this->Name = L"Form1";
            this->Text = L"Form1";
            this->ResumeLayout(false);

        }

    private: System::Void button1_Click(System::