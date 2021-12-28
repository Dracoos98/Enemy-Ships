#pragma once
#include "Controladora.h";
namespace EjercicioNaves {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			objcontroladora = new Controladora();
			bmpnave = gcnew Bitmap("Nave.jpg");
			bmpnavee = gcnew Bitmap("NaveE.png");
			bmpbala = gcnew Bitmap("balas.png");
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete objcontroladora, bmpnave,bmpnavee,bmpbala;
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Controladora* objcontroladora;
		Bitmap^ bmpnave;
		Bitmap^ bmpnavee;
		Bitmap^ bmpbala;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(862, 691);
			this->Name = L"MyForm";
			this->Text = L"X";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForms_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);
		bf->Graphics->Clear(Color::White);
		objcontroladora->Dibujar_Nave(bf->Graphics, bmpnave);
		objcontroladora->Dibujar_NaveE(bf->Graphics, bmpnavee);
		objcontroladora->Dibujar_Bala(bf->Graphics, bmpbala);
		if (objcontroladora->Colision2() == true) timer1->Enabled = false;
		bf->Render(g);
		delete bf, espacio, g;
	}
	private: System::Void MyForms_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left) objcontroladora->Desplazar_Nave(direccion::izquierda);
		if (e->KeyCode == Keys::Right)objcontroladora->Desplazar_Nave(direccion::derecha);
		if (e->KeyCode == Keys::Up) objcontroladora->Desplazar_Nave(direccion::arriba);
		if (e->KeyCode == Keys::Down)objcontroladora->Desplazar_Nave(direccion::abajo);
		if (e->KeyCode == Keys::Space)objcontroladora->Disparar();
	}
	};
}
