#pragma once

#include <iostream>
#include <string>

namespace Pedidos 
    {
        class Empleado; // Declaración anticipada.

        class Sucursal 
            {
                private:
                    std::string nombre;
                    std::string direccion;
                    Empleado* vendedores[10];  // Array fijo de 10 punteros a Empleado.
                    int cantidadVendedores;
                    static const int MAX_VENDEDORES = 10;

                public:
                    // Constructor y destructor.
                    Sucursal(const std::string& nombre, const std::string& direccion);
                    ~Sucursal();

                    // Métodos públicos.
                    void agregarVendedor(Empleado* vendedor);
                    void listarVendedores() const;
                    void enviarNotificacionATodos(const std::string& mensaje) const;

                    // Getters.
                    std::string getNombre() const;
                    std::string getDireccion() const;
                    int getCantidadVendedores() const;
            };
    }