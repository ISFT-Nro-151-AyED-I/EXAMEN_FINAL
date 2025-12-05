#include <iostream>
#include <string>

#include "VendedorParticular.hpp"

using namespace Pedidos;

// Constructor.
VendedorParticular::VendedorParticular(const std::string& nombre, const std::string& email,
                                       double salarioBase, const std::string& areaAsignada)
                   : Empleado(nombre, email, salarioBase, areaAsignada), tieneVehiculoPropio(false)
    {
        std::cout << "🚗 Vendedor Particular '" << nombre << "' creado.\n";
        std::cout << "   ¿Tiene vehículo propio? (s/n): ";
        
        char respuesta;
        std::cin >> respuesta;
        std::cin.ignore();
        
        tieneVehiculoPropio = (respuesta == 's' || respuesta == 'S');
        
        if (tieneVehiculoPropio) 
            {
                std::cout << "   ✅ Se registrará con bono por vehículo propio (+$150)\n";
            } 
            else 
                {
                    std::cout << "   ❌ No tiene vehículo propio\n";
                }
    }

// Destructor.
VendedorParticular::~VendedorParticular() 
    {
        std::cout << "🗑️  Vendedor Particular '" << nombre << "' eliminado.\n";
    }

// Método trabajar.
void VendedorParticular::trabajar() 
    {
        std::cout << "👨‍💼 " << nombre << " (Vendedor Particular): ";
        std::cout << "Atendiendo clientes en " << areaAsignada;
        
        if (tieneVehiculoPropio) 
            {
                std::cout << " 🚗 (con vehículo propio)";
            }
        std::cout << ".\n";
    }

// Muestra datos.
void VendedorParticular::mostrarDatos() const 
    {
        std::cout << "   📝 Nombre: " << nombre << std::endl;
        std::cout << "   📧 Email: " << email << std::endl;
        std::cout << "   💰 Salario Base: $" << salarioBase << std::endl;
        std::cout << "   📍 Área: " << areaAsignada << std::endl;
        std::cout << "   🚗 Vehículo Propio: " << (tieneVehiculoPropio ? "Sí ✅" : "No ❌") << std::endl;
    }

// Recibe notificación.
void VendedorParticular::recibirNotificacion(const std::string& mensaje) 
    {
        std::cout << "📩 " << nombre << " (Particular) recibió: " << mensaje << std::endl;
    }

// Calcula salario total (con bono por vehículo propio).
double VendedorParticular::calcularSalarioTotal() const 
    {
        double bonoVehiculo = tieneVehiculoPropio ? 150.0 : 0.0;
        return salarioBase + bonoVehiculo;
    }

// Obtiene tipo.
std::string VendedorParticular::obtenerTipo() const 
    {
        return "Vendedor Particular";
    }

// Getter.
bool VendedorParticular::getTieneVehiculoPropio() const 
    {
        return tieneVehiculoPropio;
    }