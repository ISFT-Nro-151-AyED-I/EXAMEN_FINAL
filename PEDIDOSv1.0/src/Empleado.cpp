#include <iostream>
#include <string>

#include "Empleado.hpp"

using namespace Pedidos;

// Constructor.
Empleado::Empleado(const std::string& nombre, const std::string& email,
                   double salarioBase, const std::string& areaAsignada)
         : nombre(nombre), email(email), salarioBase(salarioBase), areaAsignada(areaAsignada) 
    {
        std::cout << "👤 Empleado base '" << nombre << "' creado.\n";
    }

// Destructor.
Empleado::~Empleado() {} // Destructor base - las clases derivadas añadirán su lógica específica.

// Getters.
std::string Empleado::getNombre() const 
    {
        return nombre;
    }

std::string Empleado::getEmail() const 
    {
        return email;
    }

double Empleado::getSalarioBase() const 
    {
        return salarioBase;
    }

std::string Empleado::getAreaAsignada() const 
    {
        return areaAsignada;
    }