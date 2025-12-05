#include <iostream>
#include <string>

#include "Empresa.hpp"
#include "Sucursal.hpp"

using namespace Pedidos;

// Constructor.
Empresa::Empresa(const std::string& nombre) 
        : nombre(nombre), cantidadSucursales(0), capacidadSucursales(5) 
    {
        sucursales = new Sucursal*[capacidadSucursales];

        std::cout << "🏢 Empresa '" << nombre << "' creada exitosamente.\n";
    }

// Destructor.
Empresa::~Empresa() 
    {
        std::cout << "\n🗑️  Empresa '" << nombre << "' eliminando sus " 
                  << cantidadSucursales << " sucursales...\n";
        
        // COMPOSICIÓN: Empresa elimina sus Sucursales.
        for (int i = 0; i < cantidadSucursales; i++) 
            {
                if (sucursales[i] != nullptr) 
                    {
                        std::cout << "   🗑️  Eliminando sucursal: " 
                                  << sucursales[i]->getNombre() << "\n";
                        delete sucursales[i];  // Elimina cada Sucursal.

                        sucursales[i] = nullptr;
                    }
            }

        delete[] sucursales;

        std::cout << "🗑️  Empresa '" << nombre << "' eliminada.\n";
    }

// Crea una nueva sucursal (Composición).
Sucursal* Empresa::crearSucursal(const std::string& nombre, const std::string& direccion) 
    {
        Sucursal* nuevaSucursal = new Sucursal(nombre, direccion);
        agregarSucursal(nuevaSucursal);
        return nuevaSucursal;
    }

// Agrega una sucursal existente al arreglo.
void Empresa::agregarSucursal(Sucursal* sucursal) 
    {
        if (cantidadSucursales >= capacidadSucursales) 
            {
                // Redimensiona el array.
                capacidadSucursales *= 2;
                Sucursal** nuevoArray = new Sucursal*[capacidadSucursales];
                
                for (int i = 0; i < cantidadSucursales; i++) 
                    {
                        nuevoArray[i] = sucursales[i];
                    }
                
                delete[] sucursales;
                sucursales = nuevoArray;
            }
        
        sucursales[cantidadSucursales] = sucursal;
        cantidadSucursales++;

        std::cout << "📍 Sucursal '" << sucursal->getNombre() 
                  << "' agregada a la empresa '" << this->nombre << "'.\n";
    }

// Lista las sucursales.
void Empresa::listarSucursales() const 
    {
        if (cantidadSucursales == 0) 
            {
                std::cout << "📭 La empresa '" << nombre << "' no tiene sucursales.\n";
                return;
            }
        
        std::cout << "\n📋 SUCURSALES DE '" << nombre << "':\n";
        std::cout << "====================================\n";
        
        for (int i = 0; i < cantidadSucursales; i++) 
            {
                std::cout << "🏪 Sucursal #" << (i + 1) << ":\n";
                std::cout << "   Nombre: " << sucursales[i]->getNombre() << "\n";
                std::cout << "   Dirección: " << sucursales[i]->getDireccion() << "\n";
                std::cout << "   Vendedores: " << sucursales[i]->getCantidadVendedores() << "\n";
                std::cout << "   ---------------------------\n";            
            }
    }

// Getters.
std::string Empresa::getNombre() const 
    {
        return nombre;
    }

int Empresa::getCantidadSucursales() const 
    {
        return cantidadSucursales;
    }