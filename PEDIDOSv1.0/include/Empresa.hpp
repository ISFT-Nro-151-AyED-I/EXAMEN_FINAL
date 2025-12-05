#pragma once

#include <iostream>
#include <string>

namespace Pedidos 
    {
        class Sucursal; // Declaración anticipada.

        class Empresa 
            {
                private:
                    std::string nombre;
                    Sucursal** sucursales;
                    int cantidadSucursales;
                    int capacidadSucursales;

                public:
                    // Constructor y destructor.
                    Empresa(const std::string& nombre);
                    ~Empresa();

                    // Métodos públicos.
                    Sucursal* crearSucursal(const std::string& nombre, const std::string& direccion);
                    void agregarSucursal(Sucursal* sucursal);
                    void listarSucursales() const;

                    // Getters.
                    std::string getNombre() const;
                    int getCantidadSucursales() const;
            };
    }