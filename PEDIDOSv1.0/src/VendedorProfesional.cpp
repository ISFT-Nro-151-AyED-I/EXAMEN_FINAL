#include <iostream>
#include <string>

#include "VendedorProfesional.hpp"

using namespace Pedidos;

// Constructor.
VendedorProfesional::VendedorProfesional(const std::string& nombre, const std::string& email,
                                         double salarioBase, const std::string& areaAsignada)
                    : Empleado(nombre, email, salarioBase, areaAsignada) 
    {
        std::cout << "🎓 Vendedor Profesional '" << nombre << "' creado.\n";
        
        // Solicita matrícula profesional.
        std::cout << "   Ingresa matrícula profesional (ej: MP-1234): ";
        std::getline(std::cin, matriculaProfesional);
        
        std::cout << "   ✅ Matrícula registrada: " << matriculaProfesional << std::endl;
    }

// Destructor.
VendedorProfesional::~VendedorProfesional() 
    {
        std::cout << "🗑️  Vendedor Profesional '" << nombre << "' eliminado.\n";
    }

// Método trabajar.
void VendedorProfesional::trabajar() 
    {
        std::cout << "👨‍🎓 " << nombre << " (Vendedor Profesional): ";
        std::cout << "Realizando asesoramiento técnico en " << areaAsignada;
        std::cout << " [Matrícula: " << matriculaProfesional << "].\n";
    }

// Muestra datos.
void VendedorProfesional::mostrarDatos() const 
    {
        std::cout << "   📝 Nombre: " << nombre << std::endl;
        std::cout << "   📧 Email: " << email << std::endl;
        std::cout << "   💰 Salario Base: $" << salarioBase << std::endl;
        std::cout << "   📍 Área: " << areaAsignada << std::endl;
        std::cout << "   🎓 Matrícula: " << matriculaProfesional << std::endl;
    }

// Recibe notificación.
void VendedorProfesional::recibirNotificacion(const std::string& mensaje) 
    {
        std::cout << "📩 " << nombre << " (Profesional) recibió: " << mensaje << std::endl;
    }

// Calcula salario total (con bono por profesionalización).
double VendedorProfesional::calcularSalarioTotal() const 
    {
        double bonoProfesional = 300.0; // Bono fijo por ser profesional.
        return salarioBase + bonoProfesional;
    }

// Obtiene tipo.
std::string VendedorProfesional::obtenerTipo() const 
    {
        return "Vendedor Profesional";
    }

// Getter.
std::string VendedorProfesional::getMatriculaProfesional() const        
    {
        return matriculaProfesional;
    }