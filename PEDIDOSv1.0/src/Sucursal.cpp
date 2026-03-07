#include <iostream>
#include <string>

#include "../include/Sucursal.hpp"
#include "../include/Empleado.hpp"

using namespace Pedidos;

// Constructor.
Sucursal::Sucursal(const std::string& nombre, const std::string& direccion)
         : nombre(nombre), direccion(direccion), cantidadVendedores(0)
    {
        // Inicializa todos los punteros a nullptr.
        for (int i = 0; i < MAX_VENDEDORES; i++) 
            {
                vendedores[i] = nullptr;
            }
    
        std::cout << "📍 Sucursal '" << nombre << "' creada en " << direccion << ".\n";
    }

// Destructor.
Sucursal::~Sucursal() 
    {
        std::cout << "🗑️  Sucursal '" << nombre << "' eliminada.\n";
        
        // AGREGACIÓN PURA: NO elimina los objetos Empleado.
        // Main.cpp es responsable de eliminar los Empleados.
    }

// Agrega un vendedor.
void Sucursal::agregarVendedor(Empleado* vendedor) 
    {
        if (cantidadVendedores >= MAX_VENDEDORES) 
            {
                std::cout << "❌ Capacidad máxima de vendedores alcanzada (10).\n";
                return;
            }
        
        vendedores[cantidadVendedores] = vendedor;  // Agrega puntero al objeto existente.
        cantidadVendedores++;
        
        std::cout << "👤 Vendedor '" << vendedor->getNombre() 
                  << "' agregado a la sucursal '" << nombre << "'.\n";
    }

// Lista los vendedores.
void Sucursal::listarVendedores() const 
    {
        if (cantidadVendedores == 0) 
            {
                std::cout << "📭 La sucursal '" << nombre << "' no tiene vendedores.\n";
                return;
            }
        
        std::cout << "\n👥 VENDEDORES DE SUCURSAL '" << nombre << "':\n";
        std::cout << "===============================================\n";
        
        for (int i = 0; i < cantidadVendedores; i++) 
        {
            std::cout << "Vendedor #" << (i + 1) << ":\n";
            vendedores[i]->mostrarDatos();

            std::cout << "   💵 Salario Total: $" << vendedores[i]->calcularSalarioTotal() << std::endl;
            std::cout << "   🏷️  Tipo: " << vendedores[i]->obtenerTipo() << std::endl;
            std::cout << "   -------------------------------\n";
        }
    }

// Envia notificación a todos los vendedores.
void Sucursal::enviarNotificacionATodos(const std::string& mensaje) const 
    {
        std::cout << "\n📢 ENVIANDO NOTIFICACIÓN A TODOS LOS VENDEDORES DE '" << nombre << "':\n";
        std::cout << "========================================================================\n";
        
        for (int i = 0; i < cantidadVendedores; i++) 
            {
                vendedores[i]->recibirNotificacion(mensaje);
            }
    }

// Getters.
std::string Sucursal::getNombre() const 
    {
        return nombre;
    }

std::string Sucursal::getDireccion() const
    {
        return direccion;
    }

int Sucursal::getCantidadVendedores() const 
    {
        return cantidadVendedores;
    }