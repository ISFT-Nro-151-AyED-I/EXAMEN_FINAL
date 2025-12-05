#pragma once

#include "Empleado.hpp"

namespace Pedidos 
    {
        class VendedorProfesional : public Empleado 
            {
                private:
                    std::string matriculaProfesional;

                public:
                    // Constructor y destructor.
                    VendedorProfesional(const std::string& nombre, const std::string& email,
                                    double salarioBase, const std::string& areaAsignada);
                    ~VendedorProfesional() override;

                    // Implementación de métodos virtuales.
                    void trabajar() override;
                    void mostrarDatos() const override;
                    void recibirNotificacion(const std::string& mensaje) override;
                    double calcularSalarioTotal() const override;
                    std::string obtenerTipo() const override;

                    // Getter.
                    std::string getMatriculaProfesional() const;
            };
    }