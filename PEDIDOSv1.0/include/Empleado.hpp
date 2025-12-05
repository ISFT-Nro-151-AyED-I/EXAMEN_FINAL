#pragma once

#include <iostream>
#include <string>

namespace Pedidos 
    {
        class Empleado 
            {
                protected:
                    std::string nombre;
                    std::string email;
                    double salarioBase;
                    std::string areaAsignada;

                public:
                    // Constructor y destructor.
                    Empleado(const std::string& nombre, const std::string& email, 
                             double salarioBase, const std::string& areaAsignada);
                    virtual ~Empleado();

                    // Métodos virtuales puros (clase abstracta).
                    virtual void trabajar() = 0;
                    virtual void mostrarDatos() const = 0;
                    virtual void recibirNotificacion(const std::string& mensaje) = 0;
                    virtual double calcularSalarioTotal() const = 0;
                    virtual std::string obtenerTipo() const = 0;

                    // Getters (no virtuales).
                    std::string getNombre() const;
                    std::string getEmail() const;
                    double getSalarioBase() const;
                    std::string getAreaAsignada() const;
            };
    }