#pragma once

#include "Empleado.hpp"

namespace Pedidos 
    {
        class VendedorEmpresa : public Empleado 
            {
                private:
                    std::string razonSocialEmpresa;

                public:
                    // Constructor y destructor.
                    VendedorEmpresa(const std::string& nombre, const std::string& email,
                                double salarioBase, const std::string& areaAsignada);
                    ~VendedorEmpresa() override;

                    // Implementación de métodos virtuales.
                    void trabajar() override;
                    void mostrarDatos() const override;
                    void recibirNotificacion(const std::string& mensaje) override;
                    double calcularSalarioTotal() const override;
                    std::string obtenerTipo() const override;

                    // Getter.
                    std::string getRazonSocialEmpresa() const;
            };
    }