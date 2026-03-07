#include <iostream>
#include <string>

#include "../include/VendedorEmpresa.hpp"

using namespace Pedidos;

// Constructor.
VendedorEmpresa::VendedorEmpresa(const std::string& nombre, const std::string& email,
                                 double salarioBase, const std::string& areaAsignada)
                : Empleado(nombre, email, salarioBase, areaAsignada) 
    {
        std::cout << "🏢 Vendedor de Empresa '" << nombre << "' creado.\n";
        
        // Solicita razón social de la empresa.
        std::cout << "   Ingresa razón social de la empresa: ";
        std::getline(std::cin, razonSocialEmpresa);
        
        std::cout << "   ✅ Razón social registrada: " << razonSocialEmpresa << std::endl;
    }

// Destructor.
VendedorEmpresa::~VendedorEmpresa() 
    {
        std::cout << "🗑️  Vendedor de Empresa '" << nombre << "' eliminado.\n";
    }

// Método trabajar.
void VendedorEmpresa::trabajar() 
    {
        std::cout << "👨‍💼 " << nombre << " (Vendedor de Empresa): ";
        std::cout << "Gestionando cuentas corporativas en " << areaAsignada;
        std::cout << " [Empresa: " << razonSocialEmpresa << "].\n";
    }

// Muestra datos.
void VendedorEmpresa::mostrarDatos() const 
    {
        std::cout << "   📝 Nombre: " << nombre << std::endl;
        std::cout << "   📧 Email: " << email << std::endl;
        std::cout << "   💰 Salario Base: $" << salarioBase << std::endl;
        std::cout << "   📍 Área: " << areaAsignada << std::endl;
        std::cout << "   🏢 Razón Social: " << razonSocialEmpresa << std::endl;
    }

// Recibe notificación.
void VendedorEmpresa::recibirNotificacion(const std::string& mensaje) 
    {
        std::cout << "📩 " << nombre << " (Empresa/" << razonSocialEmpresa 
                  << ") recibió: " << mensaje << "\n";
    }

// Calcula salario total (con bono por representar empresa).
double VendedorEmpresa::calcularSalarioTotal() const 
    {
        double bonoEmpresa = 250.0; // Bono por representar empresa.
        return salarioBase + bonoEmpresa;
    }

// Obtiene tipo.
std::string VendedorEmpresa::obtenerTipo() const 
    {
        return "Vendedor de Empresa";
    }

// Getter.
std::string VendedorEmpresa::getRazonSocialEmpresa() const 
    {
        return razonSocialEmpresa;
    }